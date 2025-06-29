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
#include <set>
#include <string>
#include <vector>


ReseauBorne::ReseauBorne() 
{
    // Constructeur par défaut, initialise un réseau vide
}

/**
 * Constructeur de copie du réseau de bornes
 *
 * @param p_autre le réseau de bornes à copier
 * @return la copie du réseau de borne entré
 */
ReseauBorne& ReseauBorne::operator=(const ReseauBorne& p_autre)
{
    if (this != &p_autre) {
        m_adjacence = p_autre.m_adjacence;
        m_trajets = p_autre.m_trajets;
    }
    return *this;
}

/**
 * Ajouteur de borne au réseau
 *
 * @param p_nom le nom de la borne à ajouter
 */
void ReseauBorne::ajouterBorne(const std::string& p_nom)
{
    if (!existeBorne(p_nom)){
        Borne nouvelleBorne(p_nom);
        m_adjacence.push_back(std::make_pair(nouvelleBorne,std::list<Borne>{}));
    }
}

/**
 * Ajouteur de trajet au réseau de borne
 *
 * @param p_origine le nom de la borne d'origine
 * @param p_destination le nom de la borne de destination
 * @param p_distance la distance du trajet
 * @param p_temps le temps du trajet
 * @param p_cout le coût du trajet
 */
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

/**
 * Retourne l'ensembe des bornes du réseau, en vecteur
 *
 * @return un vecteur de bornes
 */
std::vector<Borne> ReseauBorne::reqBornes() const
{
    std::vector<Borne> toutes_Bornes;
    for (auto it = m_adjacence.begin(); it != m_adjacence.end(); ++it) {
        toutes_Bornes.push_back(it->first);
    }
    return toutes_Bornes;
}

/**
 * Retourne l'ensembe des trajets du réseau, en vecteur
 *
 * @return un vecteur de trajets
 */
std::vector<Trajet> ReseauBorne::reqTrajets() const
{
    return m_trajets;
}

/**
 * Retourne l'ensembe des trajets depuis une borne (origine) du réseau, en vecteur
 *
 * @return un vecteur de trajets
 */
std::vector<Trajet> ReseauBorne::reqTrajetsDepuis(const std::string& p_origine) const
{
    std::vector<Trajet> trajetsDepuisOrigine;
    for (auto trajet = m_trajets.begin(); trajet != m_trajets.end(); ++trajet) {
       if (trajet->reqOrigine()==p_origine) {
           trajetsDepuisOrigine.push_back(*trajet);
       }
    }
    return trajetsDepuisOrigine;
}

/**
 * Vérificateur si une borne existe dans le réseau de bornes
 *
 * @param p_nom le nom de la borne à vérifier
 * @return true si la borne est dans le réseau, false sinon
 */
bool ReseauBorne::existeBorne(const std::string& p_nom) const
{
    Borne borneRecherche(p_nom);
    for (const Borne &borne: reqBornes()) {
        if (borne == borneRecherche) {
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


/**
 * Vérificatuer de le réseau reste invariant pour la théorie du contrat
 */
void ReseauBorne::verifieInvariant() const
{
    // TODO mieux comprendre et refaire ça, généré

    /*
    std::set<std::string> nomsBornes;
    for (const auto& paire : m_adjacence) {
        const std::string& nom = paire.first.reqNom();
        INVARIANT(nomsBornes.find(nom) == nomsBornes.end());
        nomsBornes.insert(nom);
    }

    for (const auto& trajet : m_trajets) {
        INVARIANT(nomsBornes.find(trajet.reqOrigine()) != nomsBornes.end());
        INVARIANT(nomsBornes.find(trajet.reqDestination()) != nomsBornes.end());
    }

    std::list<Trajet> trajetsUniques;
    for (const auto& trajet : m_trajets) {
        INVARIANT(trajetsUniques.find(trajet) == trajetsUniques.end());
        trajetsUniques.insert(trajet);
    }
    */
}
