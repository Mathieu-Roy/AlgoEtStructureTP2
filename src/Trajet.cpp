/**
 * \file Trajet.cpp
 * \brief Implémentation de la classe Trajet (arc orienté pondéré)
 * \author Support pédagogique
 * \version 1.0
 * \date Juin 2025
 */

#include "Trajet.h"

Trajet::Trajet(const std::string& p_origine,
               const std::string& p_destination,
               double p_distance,
               double p_temps,
               double p_cout)
    : m_origine(p_origine),
      m_destination(p_destination),
      m_distance(p_distance),
      m_temps(p_temps),
      m_cout(p_cout) {}

// TODO: Vérifier les préconditions

bool Trajet::operator==(const Trajet& p_autre) const {
    // TODO: Comparer deux trajets
    return false;
}

std::string Trajet::reqOrigine() const {
    // TODO: Retourner l'origine
    return "";
}

std::string Trajet::reqDestination() const {
    // TODO: Retourner la destination
    return "";
}

double Trajet::reqDistance() const {
    // TODO: Retourner la distance
    return 0.0;
}

double Trajet::reqTemps() const {
    // TODO: Retourner le temps
    return 0.0;
}

double Trajet::reqCout() const {
    // TODO: Retourner le coût
    return 0.0;
}
