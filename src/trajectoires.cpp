//
// Created by nicolas-roy on 21/10/2025.
//

// Trajectories.cpp
#include "Trajectories.h"
#include <math.h>

std::vector<Point2> generateTrajectory(Point2 p0, Point2 p1, TrajType type, int samples, float param) {
    if (samples < 2) samples = 2;
    std::vector<Point2> pts;
    pts.reserve(samples);

    switch(type) {
        case TRAJ_LINE:
            for (int i = 0; i < samples; ++i) {
                float t = (float)i / (samples - 1);
                pts.push_back({ p0.x + (p1.x - p0.x)*t, p0.y + (p1.y - p0.y)*t });
            }
            break;

        case TRAJ_ARC: {
            // param = curvature: positive => arc bulge to left of vector p0->p1
            // Construire arc passant par p0->p1 avec angle theta en fonction de param.
            // Approche simple : construire cercle centre à mi-point déplacé perpendiculairement.
            float midx = 0.5f*(p0.x + p1.x);
            float midy = 0.5f*(p0.y + p1.y);
            float dx = p1.x - p0.x;
            float dy = p1.y - p0.y;
            float L = sqrtf(dx*dx + dy*dy);
            float nx = -dy / (L + 1e-9f);
            float ny = dx / (L + 1e-9f);
            // param en [-1,1] contrôle amplitude ; rayon calculé pour produire bulge
            float bulge = clampf(param, -1.0f, 1.0f);
            float h = (L/2.0f) * bulge; // distance du milieu vers centre
            float cx = midx + nx * h;
            float cy = midy + ny * h;
            float r = sqrtf((p0.x-cx)*(p0.x-cx) + (p0.y-cy)*(p0.y-cy));
            float a0 = atan2f(p0.y - cy, p0.x - cx);
            float a1 = atan2f(p1.y - cy, p1.x - cx);
            // s'assurer que parcours court
            float da = a1 - a0;
            if (da > M_PI) da -= 2.0f*M_PI;
            if (da < -M_PI) da += 2.0f*M_PI;
            for (int i=0;i<samples;++i) {
                float t = (float)i / (samples-1);
                float ang = a0 + t * da;
                pts.push_back({ cx + r * cosf(ang), cy + r * sinf(ang) });
            }
        } break;

        case TRAJ_BEZIER_Q: {
            // param unused. Control point = midpoint + offset perpendicular * param
            float midx = 0.5f*(p0.x + p1.x);
            float midy = 0.5f*(p0.y + p1.y);
            float dx = p1.x - p0.x;
            float dy = p1.y - p0.y;
            float L = sqrtf(dx*dx + dy*dy) + 1e-9f;
            float nx = -dy / L;
            float ny = dx / L;
            float offset = param; // meters
            Point2 c = { midx + nx * offset, midy + ny * offset };
            for (int i=0;i<samples;++i) {
                float t = (float)i/(samples-1);
                float u = 1.0f - t;
                float x = u*u*p0.x + 2.0f*u*t*c.x + t*t*p1.x;
                float y = u*u*p0.y + 2.0f*u*t*c.y + t*t*p1.y;
                pts.push_back({x,y});
            }
        } break;

        case TRAJ_SIN: {
            // param = amplitude (m) of perpendicular oscillation, frequency implicit = 1 half-wave
            float A = param;
            float dx = p1.x - p0.x;
            float dy = p1.y - p0.y;
            float L = sqrtf(dx*dx + dy*dy) + 1e-9f;
            float ux = dx / L;
            float uy = dy / L;
            float nx = -uy;
            float ny = ux;
            for (int i=0;i<samples;++i) {
                float s = (float)i/(samples-1);
                float baseX = p0.x + ux * (s*L);
                float baseY = p0.y + uy * (s*L);
                float wave = sinf(M_PI * s); // one half-wave
                pts.push_back({ baseX + nx * (A*wave), baseY + ny * (A*wave) });
            }
        } break;

        case TRAJ_POLY_SMOOTH: {
            // cosine easing between p0 and p1 (param unused)
            for (int i=0;i<samples;++i) {
                float t = (float)i/(samples-1);
                float te = (1 - cosf(t * M_PI)) * 0.5f; // ease in/out
                pts.push_back({ p0.x + (p1.x - p0.x)*te, p0.y + (p1.y - p0.y)*te });
            }
        } break;
    }

    return pts;
}

float dist(Point2 a, Point2 b) {
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    return sqrtf(dx*dx + dy*dy);
}

// small clampf for file-local use
static inline float clampf(float v, float lo, float hi) {
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}
//s