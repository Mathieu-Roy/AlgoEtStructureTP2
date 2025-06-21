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
    if (this != &p_autre) {
        m_adjacence = p_autre.m_adjacence;
        m_trajets = p_autre.m_trajets;
    }
    return *this;
}

void ReseauBorne::ajouterBorne(const std::string& p_nom)
{
    // TODO: Ajouter une borne.
    if (!existeBorne(p_nom)) {

    }
}

void ReseauBorne::ajouterTrajet(const std::string& p_origine, const std::string& p_destination,
                                double p_distance, double p_temps, double p_cout)
{
    //Créer le nouveau trajet
    Trajet nouveau_trajet(p_origine,p_destination, p_distance, p_temps, p_cout);
    //Vérifier qu'il n'est pas déjà existant et l'ajouter dans le cas contraire
    for (std::vector<Trajet>::iterator trajet = m_trajets.begin(); trajet != m_trajets.end(); ++trajet) {
        if (*trajet==nouveau_trajet) {
            return;
        }
    }
    m_trajets.push_back(nouveau_trajet);
}

std::vector<Borne> ReseauBorne::reqBornes() const
{
    std::list<Borne> toutes_Bornes;

    for (const auto& paire : m_adjacence)
    {
        // Ajouter la clef
        toutes_Bornes.push_back(paire.first);

        // Ajouter toutes les bornes associées à la clef
        for (const auto& borneAdj : paire.second)
        {
            toutes_Bornes.push_back(borneAdj);
        }
    }

    // Retirer les doublons
    toutes_Bornes.sort([](const Borne &a, const Borne &b) {
        return a.reqNom() < b.reqNom();
    });
    toutes_Bornes.unique();

    //Transformer la liste en un vecteur et le retourner
    return std::vector<Borne>(toutes_Bornes.begin(), toutes_Bornes.end());
}

std::vector<Trajet> ReseauBorne::reqTrajets() const
{
    return m_trajets;
}

std::vector<Trajet> ReseauBorne::reqTrajetsDepuis(const std::string& p_origine) const
{
    // TODO: Retourner les trajets depuis une borne
    return {};
}

bool ReseauBorne::existeBorne(const std::string& p_nom) const
{
    Borne borneRecherche(p_nom);

    for (std::vector<Borne>::iterator borne = reqBornes().begin(); borne != reqBornes().end(); ++borne) {
        if (*borne == borneRecherche) {
            return true;
        }
    }
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
