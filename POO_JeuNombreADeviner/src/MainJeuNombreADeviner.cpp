/*************************************************/
// Nom du projet: Jeu du nombre � deviner
// Nom du fichier: MainJeuNombreAdeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de cr�ation : 05/02/2021
// R�le du fichier: Contient le code jeu
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

    //Cr�ation du joueur 1
    cout << "Vous allez jouer pour deviner un nombre secret" << endl;
    cout << "----------------------------------------------"<< endl;
    cout << "Veuillez entrer le nom du joueur 1 : ";
    string un_nom;
    cin >> un_nom;
    CJoueur joueur (un_nom);
    //Cr�ation du joueur 2
    cout << "----------------------------------------------"<< endl;
    cout << "Veuillez entrer le nom du joueur 2 : ";
    cin >> un_nom;
    CJoueur joueur2 (un_nom);

    cout << "----------------------------------------------"<< endl;
    cout << "Combien de parties voulez-vous jouer ?" << endl;
    int nbParties;
    cin >> nbParties;


    for (int i = 0; i <nbParties; i++)
    {
        cout << "----------------------------------------------"<< endl;
        cout <<"Partie Numero : " << i+1 << endl;
        cout << "----------------------------------------------"<< endl;

        CPartie partie (0,10,4); // nombre � deviner entre 0 et 10, nombre de tentatives maximum 4

        partie.Jouer(joueur); // ex�cution d'une partie pour le joueur 1
        partie.Jouer(joueur2); // ex�cution d'une partie pour le joueur 2
    }


    cout << "----------------------------------------------"<< endl;
    cout << "Affichage des resultats de "<< joueur.Nom() << endl;
    cout << "----------------------------------------------"<< endl;

    // R�cup�ration des r�sultats du joueur 1
    int nbsucces, nbechecs, nbessais, joueurw, joueur2w;
    float nbessaismoy;
    joueur.Resultats(nbsucces, nbechecs, nbessais);  // les param�tres sont pass�s par r�f�rence
    joueur.ResultatsMoy(nbessaismoy);

    // Affichage des r�sultats du joueur 1
    cout << "Nombre de parties gagnees : " << nbsucces << endl;
    cout << "Nombre de parties perdues : " << nbechecs << endl;
    cout << "Nombre de tentatives totales : " << nbessais << endl;
    cout << "Nombre de tentatives moyennes : " << nbessaismoy << endl;
    joueurw = nbsucces;

    cout << endl;
    cout << "----------------------------------------------"<< endl;
    cout << "Affichage des resultats de "<< joueur2.Nom() << endl;
    cout << "----------------------------------------------"<< endl;

    // R�cup�ration des r�sultats du joueur 2
    joueur2.Resultats(nbsucces, nbechecs, nbessais);  // les param�tres sont pass�s par r�f�rence
    joueur2.ResultatsMoy(nbessaismoy);

    // Affichage des r�sultats  du joueur 2
    cout << "Nombre de parties gagnees : " << nbsucces << endl;
    cout << "Nombre de parties perdues : " << nbechecs << endl;
    cout << "Nombre de tentatives totales : " << nbessais << endl;
    cout << "Nombre de tentatives moyennes : " << nbessaismoy << endl;
    joueur2w = nbsucces;

    // Indication de quel joueur a gagn�
    cout << endl;
    cout << "----------------------------------------------"<< endl;
    cout << "Score final" << endl;
    cout << "----------------------------------------------"<< endl;

    if(joueurw == joueur2w) {
        cout << joueur.Nom() << " et " << joueur2.Nom() << " sont ex-aequo !" << endl;
    }

    if(joueurw > joueur2w) {
        cout << joueur.Nom() << " a gagne !" << endl;
    }
    else{
        cout << joueur2.Nom() << " a gagne !" << endl;
    }

    // Cr�er un 3�me joueur dynamiquement
    CJoueur * joueur3;
    joueur3=new CJoueur("Paul");

    // Cr�er une partie dynamiquement (nombre � trouver entre 1 et
    // 10, 3 essais max)

    CPartie * partie2;
    partie2 = new CPartie (1,10,3);

    // Ex�cuter la partie pour le 3�me joueur.
    partie2->Jouer(*joueur3);

    // Afficher les r�sultats du 3�me joueur.
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

