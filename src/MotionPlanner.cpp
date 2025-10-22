//
// Created by nicolas-roy on 21/10/2025.
//
// Main usage example (intégrer dans ton loop / routine)
#include "Trajectories.h"

// Définitions du losange centré en (0,0)
float d = 0.25f; // demi-distance aux coins (m)
Point2 P1 = { d, 0.0f };   // coin droit
Point2 P2 = { 0.0f, d };   // haut
Point2 P3 = { -d, 0.0f };  // gauche
Point2 P4 = { 0.0f, -d };  // bas
Point2 P0 = { 0.0f, 0.0f }; // origine (position 5)

// Exemple : aller de P1 à P2 en bezier puis P2->P0 en arc etc.
void FollowTrajectorySequence() {
    // Paramètres
    int samples = 12;            // plus -> trajectoire plus lisse
    float speed = 0.9f;          // fractionSpeed pour AdvanceDistance
    // Générer segments
    auto seg1 = generateTrajectory(P1, P2, TRAJ_BEZIER_Q, samples, 0.08f);
    auto seg2 = generateTrajectory(P2, P3, TRAJ_ARC, samples, 0.6f);
    auto seg3 = generateTrajectory(P3, P0, TRAJ_SIN, samples, 0.04f);
    auto seg4 = generateTrajectory(P0, P1, TRAJ_POLY_SMOOTH, samples, 0.0f);

    // Fonction utilitaire qui suit une liste de points en séquence
    auto followPoints = [&](const std::vector<Point2>& pts) {
        for (size_t i = 1; i < pts.size(); ++i) {
            float segmentDistance = dist(pts[i-1], pts[i]);
            if (segmentDistance < 0.001f) continue;
            // calculer fractionSpeed adaptatif selon longueur du segment (optionnel)
            float segSpeed = speed;
            // appelle ta fonction qui se déplace en ligne droite d'une distance donnée
            AdvanceDistance(segmentDistance, segSpeed);
            delay(20); // petit délai pour stabilité
        }
    };

    followPoints(seg1);
    followPoints(seg2);
    followPoints(seg3);
    followPoints(seg4);
}
