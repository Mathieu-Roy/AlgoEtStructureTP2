/**
 * \file Trajet.cpp
 * \brief Implémentation de la classe Trajet (arc orienté pondéré)
 * \author Support pédagogique
 * \version 1.0
 * \date Juin 2025
 */

#include "Trajet.h"

#include "ContratException.h"

/**
 * Constructeur de la classe Trajet.
 *
 * @param p_origine Nom de la borne d'origine.
 * @param p_destination Nom de la borne de destination.
 * @param p_distance Distance du trajet.
 * @param p_temps Temps estimé pour effectuer le trajet.
 * @param p_cout Coût associé au trajet.
 */

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

/**
 * @param p_autre l'autre borne avec laquelle comparer
 *
 * @return true si les bornes ont le même nom, false sinon
 */
bool Trajet::operator==(const Trajet& p_autre) const {
    return m_origine == p_autre.m_origine &&
           m_destination == p_autre.m_destination &&
           m_distance == p_autre.m_distance &&
           m_temps == p_autre.m_temps &&
           m_cout == p_autre.m_cout;
}


/**
 * Retourne le nom de la borne d'origine
 *
 * @return le nom de la borne d'origine
 */
std::string Trajet::reqOrigine() const {
    return m_origine;
}

/**
 * Retourne le nom de la borne de destination
 *
 * @return le nom de la borne de destination
 */
std::string Trajet::reqDestination() const {
    return m_destination;
}

/**
 * Retourne la distance du trajet
 *
 * @return la distance du trajet
 */
double Trajet::reqDistance() const {
    return m_distance;
}

/**
 * Retourne le temps du trajet
 *
 * @return le temps du trajet
 */
double Trajet::reqTemps() const {
    return m_temps;
}

/**
 * Retourne le cout du trajet
 *
 * @return le cout du trajet
 */
double Trajet::reqCout() const {
    return m_cout;
}
