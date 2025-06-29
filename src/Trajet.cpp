/**
 * \file Trajet.cpp
 * \brief Implémentation de la classe Trajet (arc orienté pondéré)
 * \author Support pédagogique
 * \version 1.0
 * \date Juin 2025
 */

#include "Trajet.h"

#include "ContratException.h"

Trajet::Trajet(const std::string& p_origine,
               const std::string& p_destination,
               double p_distance,
               double p_temps,
               double p_cout)
    : m_origine(p_origine),
      m_destination(p_destination),
      m_distance(p_distance),
      m_temps(p_temps),
      m_cout(p_cout) {

    PRECONDITION(!p_origine.empty());
    PRECONDITION(!p_destination.empty());
    PRECONDITION(p_distance >= 0);
    PRECONDITION(p_temps >= 0);
    PRECONDITION(p_origine != p_destination);
}

// TODO: Vérifier les préconditions

bool Trajet::operator==(const Trajet& p_autre) const {
    return m_origine == p_autre.m_origine &&
           m_destination == p_autre.m_destination &&
           m_distance == p_autre.m_distance &&
           m_temps == p_autre.m_temps &&
           m_cout == p_autre.m_cout;
}

std::string Trajet::reqOrigine() const {
    return m_origine;
}

std::string Trajet::reqDestination() const {
    return m_destination;
}

double Trajet::reqDistance() const {
    return m_distance;
}

double Trajet::reqTemps() const {
    return m_temps;
}

double Trajet::reqCout() const {
    return m_cout;
}
