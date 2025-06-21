/**
 * \file Borne.cpp
 * \brief Implémentation de la classe Borne (borne de recharge)
 * \author Support pédagogique
 * \version 1.0
 * \date Juin 2025
 */

#include "Borne.h"

#include <stdexcept>

Borne::Borne() : m_nom("") {}

Borne::Borne(const std::string& p_nom) : m_nom(p_nom) {
    // TODO vérifier si on gère les exceptions comme ça pour ce projet
    if (p_nom.empty()) {
        throw std::invalid_argument("Le nom de la borne ne peut pas être vide.");
    }
}

bool Borne::operator==(const Borne& p_autre) const {
    return m_nom == p_autre.m_nom;
}

std::string Borne::reqNom() const {
    return m_nom;
}
