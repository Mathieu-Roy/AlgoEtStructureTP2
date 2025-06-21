/**
 * \file Borne.cpp
 * \brief Implémentation de la classe Borne (borne de recharge)
 * \author Support pédagogique
 * \version 1.0
 * \date Juin 2025
 */

#include "Borne.h"

Borne::Borne() : m_nom("") {}

Borne::Borne(const std::string& p_nom) : m_nom(p_nom) {
    // TODO: Vérifier la précondition
}

bool Borne::operator==(const Borne& p_autre) const {
    // TODO: Comparer deux bornes
    return false;
}

std::string Borne::reqNom() const {
    // TODO: Retourner le nom
    return ""; 
}
