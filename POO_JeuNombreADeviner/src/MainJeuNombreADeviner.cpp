/*************************************************/
// Nom du projet: Jeu du nombre à deviner
// Nom du fichier: MainJeuNombreAdeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de création : 05/02/2021
// Rôle du fichier: Contient le code jeu
// Nom des composants utilises: CPartie
//                              CJoueur
//                              iostream
// Historique du fichier:
/*************************************************/
#include <iostream>
using namespace std;

#include "../include/Partie.h"

int main()
{

    //Création du joueur 1
    cout << "Vous allez jouer pour deviner un nombre secret" << endl;
    cout << "----------------------------------------------"<< endl;
    cout << "Veuillez entrer le nom du joueur 1 : ";
    string un_nom;
    cin >> un_nom;
    cout << "Veuillez entrer le prenom du joueur 1 : ";
    string un_prenom;
    cin >> un_prenom;
    CJoueur joueur (un_nom, un_prenom);
    //Création du joueur 2
    cout << "----------------------------------------------"<< endl;
    cout << "Veuillez entrer le nom du joueur 2 : ";
    cin >> un_nom;
    cout << "Veuillez entrer le prenom du joueur 2 : ";
    cin >> un_prenom;
    CJoueur joueur2 (un_nom, un_prenom);

    cout << "----------------------------------------------"<< endl;
    cout << "Combien de parties voulez-vous jouer ?" << endl;
    int nbParties;
    cin >> nbParties;


    for (int i = 0; i <nbParties; i++)
    {
        cout << "----------------------------------------------"<< endl;
        cout <<"Partie Numero : " << i+1 << endl;
        cout << "----------------------------------------------"<< endl;

        CPartie partie (0,10,4); // nombre à deviner entre 0 et 10, nombre de tentatives maximum 4

        partie.Jouer(joueur); // exécution d'une partie pour le joueur 1
        partie.Jouer(joueur2); // exécution d'une partie pour le joueur 2
    }


    cout << "----------------------------------------------"<< endl;
    cout << "Affichage des resultats de "<< joueur.Nom() << endl;
    cout << "----------------------------------------------"<< endl;

    // Récupération des résultats du joueur 1
    int nbsucces, nbechecs, nbessais, joueurw, joueur2w;
    float nbessaismoy;
    joueur.Resultats(nbsucces, nbechecs, nbessais);  // les paramètres sont passés par référence
    joueur.ResultatsMoy(nbessaismoy);

    // Affichage des résultats du joueur 1
    cout << "Nombre de parties gagnees : " << nbsucces << endl;
    cout << "Nombre de parties perdues : " << nbechecs << endl;
    cout << "Nombre de tentatives totales : " << nbessais << endl;
    cout << "Nombre de tentatives moyennes : " << nbessaismoy << endl;
    joueurw = nbsucces;

    cout << endl;
    cout << "----------------------------------------------"<< endl;
    cout << "Affichage des resultats de "<< joueur2.Nom() << endl;
    cout << "----------------------------------------------"<< endl;

    // Récupération des résultats du joueur 2
    joueur2.Resultats(nbsucces, nbechecs, nbessais);  // les paramètres sont passés par référence
    joueur2.ResultatsMoy(nbessaismoy);

    // Affichage des résultats  du joueur 2
    cout << "Nombre de parties gagnees : " << nbsucces << endl;
    cout << "Nombre de parties perdues : " << nbechecs << endl;
    cout << "Nombre de tentatives totales : " << nbessais << endl;
    cout << "Nombre de tentatives moyennes : " << nbessaismoy << endl;
    joueur2w = nbsucces;

    // Indication de quel joueur a gagné
    cout << endl;
    cout << "----------------------------------------------"<< endl;
    cout << "Score final" << endl;
    cout << "----------------------------------------------"<< endl;

    if(joueurw == joueur2w) {
        cout << joueur.Nom() << " " << joueur.Prenom() << " et " << joueur2.Nom() << " " << joueur2.Prenom() << " sont ex-aequo !" << endl;
    }

    if(joueurw > joueur2w) {
        cout << joueur.Nom() << " " << joueur.Prenom() << " a gagne !" << endl;
    }
    else{
        cout << joueur2.Nom() << " " << joueur2.Prenom() << " a gagne !" << endl;
    }

    // Créer un 3ème joueur dynamiquement
    CJoueur * joueur3;
    joueur3=new CJoueur("Paul", "Dumont");

    // Créer une partie dynamiquement (nombre à trouver entre 1 et
    // 10, 3 essais max)

    CPartie * partie2;
    partie2 = new CPartie (1,10,3);

    // Exécuter la partie pour le 3ème joueur.
    partie2->Jouer(*joueur3);

    // Afficher les résultats du 3ème joueur.
    int nbsucces3, nbechecs3, nbessais3;
    float nbessaismoy3;

    joueur3->Resultats(nbsucces3, nbechecs3, nbessais3);
    joueur3->ResultatsMoy(nbessaismoy3);

    cout << "Nombre de parties gagnees : " << nbsucces3 << endl;
    cout << "Nombre de parties perdues : " << nbechecs3 << endl;
    cout << "Nombre de tentatives totales : " << nbessais3 << endl;
    cout << "Nombre de tentatives moyennes : " << nbessaismoy3 << endl;

    return 0;
}

