/**
 * \file Borne.cpp
 * \brief Implémentation de la classe Borne (borne de recharge)
 * \author Support pédagogique
 * \version 1.0
 * \date Juin 2025
 */

#include "Borne.h"

#include <stdexcept>

/**
 * Constructeur d'une borne avec sans nom.
 */
Borne::Borne() : m_nom("") {}

/**
 * Constructeur d'une borne avec son nom.
 * @param p_nom le nom de la borne à créer
 */
Borne::Borne(const std::string& p_nom) : m_nom(p_nom) {
    if (p_nom.empty()) {
        throw std::invalid_argument("Le nom de la borne ne peut pas être vide.");
    }
}

/**
 * @param p_autre l'autre borne avec laquelle comparer
 * @return true si les bornes ont le même nom, false sinon
 */
bool Borne::operator==(const Borne& p_autre) const {
    return m_nom == p_autre.m_nom;
}

/**
 * Retourne le nom de la borne
 * @return le nom de la borne
 */
std::string Borne::reqNom() const {
    return m_nom;
}
