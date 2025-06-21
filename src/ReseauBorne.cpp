/**
 * \file ReseauBorne.cpp
 * \brief Implémentation de la classe ReseauBorne (graphe de bornes et trajets)
 * \author Support pédagogique
 * \version 1.0
 * \date Juin 2025
 */

#include "ReseauBorne.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>


ReseauBorne::ReseauBorne() 
{
    // Constructeur par défaut, initialise un réseau vide
}

/* ReseauBorne::ReseauBorne(const ReseauBorne& p_autre) {} */

ReseauBorne& ReseauBorne::operator=(const ReseauBorne& p_autre)
{
    // TODO: Copier les données
    return *this;
}

void ReseauBorne::ajouterBorne(const std::string& p_nom)
{
    // TODO: Ajouter une borne.
}

void ReseauBorne::ajouterTrajet(const std::string& p_origine, const std::string& p_destination,
                                double p_distance, double p_temps, double p_cout)
{
    // TODO: Ajouter un trajet.
}

std::vector<Borne> ReseauBorne::reqBornes() const
{
    // TODO: Retourner la liste des bornes
    return {};
}

std::vector<Trajet> ReseauBorne::reqTrajets() const
{
    // TODO: Retourner la liste des trajets
    return {};
}

std::vector<Trajet> ReseauBorne::reqTrajetsDepuis(const std::string& p_origine) const
{
    // TODO: Retourner les trajets depuis une borne
    return {};
}

bool ReseauBorne::existeBorne(const std::string& p_nom) const
{
    // TODO: Vérifier si la borne existe
    return false;
}

void ReseauBorne::afficherReseau() const
{
    // -------------------------------------------------------------------
    // NOTE AUX ÉTUDIANT·E·S :
    // Cette fonction d'affichage est fournie afin de faciliter le débogage
    // et la visualisation de votre graphe. NE LA MODIFIEZ PAS.
    // Les autres méthodes marquées TODO demeurent à compléter.
    // -------------------------------------------------------------------

     std::cout << "\n========== TOPOLOGIE DU RÉSEAU ==========" << std::endl;
    for (const auto& elem : m_adjacence) {
        const std::string& nom = elem.first.reqNom();
        std::cout << "Borne : " << nom << std::endl;
        
        // Chercher les trajets depuis cette borne directement dans m_trajets
        std::vector<const Trajet*> trajetsDepuisBorne;
        for (const auto& trajet : m_trajets) {
            if (trajet.reqOrigine() == nom) {
                trajetsDepuisBorne.push_back(&trajet);
            }
        }
        
        if (!trajetsDepuisBorne.empty()) {
            for (const Trajet* t : trajetsDepuisBorne) {
                if (t != nullptr) {
                    try {
                        std::cout << "    → "
                                  << std::left << t->reqDestination()
                                  << " | Distance : " << t->reqDistance() << " km"
                                  << " | Temps : " << t->reqTemps() << " min"
                                  << " | Coût : " << t->reqCout() << " $" << std::endl;
                    } catch (const std::exception& e) {
                        std::cout << "    → [ERREUR] : " << e.what() << std::endl;
                    }
                } else {
                    std::cout << "    → [ERREUR] : Pointeur de trajet null" << std::endl;
                }
            }
        } else {
            std::cout << "    (aucun trajet sortant)" << std::endl;
        }
    }
    std::cout << "==========================================\n" << std::endl;
}

void ReseauBorne::verifieInvariant() const
{
    // TODO : Vérifier les invariants du graphe.
}
