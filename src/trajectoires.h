//
// Created by nicolas-roy on 21/10/2025.
//

#endif //SESSION1DANCINGROBOT_TRAJECTOIRES_H

// Trajectoires.h
#pragma once
#include <Arduino.h>
#include <vector>

struct Point2 {
    float x;
    float y;
};

enum TrajType {
    TRAJ_LINE,
    TRAJ_ARC,        // arc de cercle passant par 2 points avec rayon donné
    TRAJ_BEZIER_Q,   // bezier quadratique (p0,p1,p2)
    TRAJ_SIN,        // sinusoïde entre p0/p1
    TRAJ_POLY_SMOOTH // interpolation polynomiale simple (cosine easing)
};

// Génère une séquence de points entre p0 et p1 selon type.
// samples = nombre de sous-points (>=2)
std::vector<Point2> generateTrajectory(Point2 p0, Point2 p1, TrajType type, int samples, float param = 0.0f);

// Utilitaires
float dist(Point2 a, Point2 b);
//s