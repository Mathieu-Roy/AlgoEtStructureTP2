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
#include <unordered_map>
/**
 * Algo de Dijstra qui suit le pseudo code donné dans le PWPT 2 sur les graphs
 *
 * @param p_reseau
 * @param p_origine
 * @param p_destination
 * @param p_critere
 * @param p_chemin
 * @param p_coutTotal
 * @return
 */
bool Algorithmes::dijkstra(const ReseauBorne& p_reseau,
                           const std::string& p_origine,
                           const std::string& p_destination,
                           const CritereRecherche& p_critere,
                           std::vector<std::string>& p_chemin,
                           double& p_coutTotal)
{

    struct MemoireBorne {
        int longeur;
        std::string predecesseur;
    };

    // POUR tout 𝑣 dans 𝑆 FAIRE //initialisation de 𝑑 et 𝑝
        // 𝑑(𝑣) = +∞;
        // 𝑝(𝑣) = 𝑁𝐼𝐿;
    std::unordered_map<std::string, MemoireBorne> memoire_Borne;
    for (const Borne &borne: p_reseau.reqBornes()) {
        memoire_Borne[borne.reqNom()].longeur = 10000;
        memoire_Borne[borne.reqNom()].predecesseur = "";
    }

    // 𝑑(𝑠) = 0;
    // 𝑇 = { }; // 𝑇 est l’ensemble des nœuds solutionnés
    // 𝑄 = 𝑆; //𝑄 est l’ensemble des nœuds non solutionnés
    memoire_Borne[p_origine].longeur = 0;
    std::vector<Borne> bornes_solutionnees = {};
    std::vector<Borne> bornes_non_solutionnees = p_reseau.reqBornes();

    //  RÉPÉTER |𝑆| FOIS
    for (int i = 0; i < memoire_Borne.size(); i++) {
        // 𝑢∗ = Le nœud 𝑢 dans 𝑄 tel que 𝑑(𝑢) est minimal
        int min_Longeur = 10000;
        std::string borneEvaluee;
        for (const auto borne: bornes_non_solutionnees) {
            if (memoire_Borne[borne.reqNom()].longeur < min_Longeur) {
                min_Longeur = memoire_Borne[borne.reqNom()].longeur;
                borneEvaluee = borne.reqNom();
            }
        }

        // 𝑄 = 𝑄 \{𝑢∗}; //enlever de 𝑄 le nœud solutionné 𝑢∗
        // 𝑇 = 𝑇 ∪ {𝑢∗}; //mettre 𝑢∗ dans l’ensemble des nœuds solutionnés 𝑇
        for (auto it = bornes_non_solutionnees.begin(); it != bornes_non_solutionnees.end(); ++it) {
            if (it->reqNom() == borneEvaluee) {
                bornes_non_solutionnees.erase(it);
                break;
            }
        }
        bornes_solutionnees.push_back(Borne(borneEvaluee));

        // POUR tout 𝑢 dans 𝑄 (= 𝑆 \ 𝑇) adjacent à 𝑢∗ FAIRE
        std::vector<Trajet> trajets_Depuis_Borne = p_reseau.reqTrajetsDepuis(borneEvaluee);
        for (Trajet& trajet : trajets_Depuis_Borne) {
            // • 𝑡𝑒𝑚𝑝 = 𝑑(𝑢∗) + 𝑤(𝑢∗, 𝑢);
            double temps_Trajet;
            switch (p_critere.type) {
                // 1: distance, 2: temps, 3: coût
                case 1:
                    temps_Trajet = trajet.reqDistance();
                    break;
                case 2:
                    temps_Trajet = trajet.reqTemps();
                    break;
                case 3:
                    temps_Trajet = trajet.reqCout();
                    break;
            }
            double temps =  memoire_Borne[borneEvaluee].longeur + temps_Trajet;

            // • Si 𝑡𝑒𝑚𝑝 < 𝑑(𝑢) ALORS //relâchement pour (𝑢∗, 𝑢)
            // • 𝑑(𝑢) = 𝑡𝑒𝑚𝑝;
            // • 𝑝(𝑢) = 𝑢∗;
            if (temps < memoire_Borne[trajet.reqDestination()].longeur) {
                memoire_Borne[trajet.reqDestination()].longeur = temps;
                memoire_Borne[trajet.reqDestination()].predecesseur = borneEvaluee;
            }
        }
    }

    // Calcul des valeurs de retour si on a un chemin qui fonctionne
    // std::vector<std::string> &p_chemin
    // double &p_coutTotal
    if (memoire_Borne[p_destination].longeur < 10000) {
        p_coutTotal = (memoire_Borne[p_destination].longeur);

        //Pushback les prédécésseurs jusqu'à arriver à l'origine, renverser à la fin pour avoir le bon ordre
        std::string borne_En_Cours = p_destination;
        bool origine_trouvee = false;
        while (!origine_trouvee){
            p_chemin.push_back(borne_En_Cours);
            borne_En_Cours = memoire_Borne[borne_En_Cours].predecesseur;
            if (borne_En_Cours == p_origine) {
                p_chemin.push_back(borne_En_Cours);
                origine_trouvee = true;
            }
        } while (borne_En_Cours != p_origine);
        std::reverse(p_chemin.begin(), p_chemin.end());
        return true;
    }
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
    /*
• POUR tout 𝑣 dans S FAIRE //initialisation de d et p
     𝑑(𝑣) = +∞ ; 𝑝(𝑣) = 𝑁𝐼𝐿;
• 𝑑(𝑠) = 0;
• RÉPÉTER |𝑆| − 1 FOIS //partie principale de l’algorithme
     POUR tout (𝑢, 𝑣) de 𝐴 FAIRE
         𝑡𝑒𝑚𝑝 = 𝑑(𝑢) + 𝑤(𝑢, 𝑣);
         SI 𝑡𝑒𝑚𝑝 < 𝑑(𝑣) //relâchement pour (u.v)
            • 𝑑(𝑣) = 𝑡𝑒𝑚𝑝; 𝑝(𝑣) = 𝑢;
• POUR tout (𝑢, 𝑣) de 𝐴 FAIRE //vérification de l’existence d’un cycle de longueur < 0
     Si 𝑑(𝑣) > 𝑑(𝑢) + 𝑤(𝑢, 𝑣) ALORS retourner FAUX;
• retourner VRAI;
• POUR tout 𝑣 dans S FAIRE //initialisation de d et p
*/
    return false;

}
