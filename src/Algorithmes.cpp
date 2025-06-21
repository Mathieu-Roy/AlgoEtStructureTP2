/**
 * \file Algorithmes.cpp
 * \brief Implémentation des algorithmes de graphe (Dijkstra, Bellman-Ford)
 *        À COMPLÉTER : utiliser les conteneurs vus en cours (vector/list).
 * \author Support pédagogique
 * \version 1.0
 * \date Juin 2025
 */

#include "Algorithmes.h"
#include <vector>
#include <queue>     // file de priorité pour Dijkstra
#include <limits>    // std::numeric_limits
#include <algorithm> // std::find, std::reverse

bool Algorithmes::dijkstra(const ReseauBorne& p_reseau,
                           const std::string& p_origine,
                           const std::string& p_destination,
                           const CritereRecherche& p_critere,
                           std::vector<std::string>& p_chemin,
                           double& p_coutTotal)
{
    // TODO: Implémenter Dijkstra.
    return false;
}

bool Algorithmes::bellmanFord(const ReseauBorne& p_reseau,
                              const std::string& p_origine,
                              const std::string& p_destination,
                              const CritereRecherche& p_critere,
                              std::vector<std::string>& p_chemin,
                              double& p_coutTotal)
{
    // TODO: Implémenter Bellman-Ford.
    return false;
}
