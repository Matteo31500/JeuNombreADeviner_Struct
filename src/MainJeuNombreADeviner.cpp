/*************************************************/
// Nom du projet: Jeu du nombre à deviner
// Nom du fichier: MainJeuNombreAdeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud, Mattéo Arzel
// Date de création : 25/01/2021
// Rôle du fichier: Contient le code jeu
// Nom des composants utilises: JeuNombreADeviner.h
//                              iostream
// Historique du fichier:
//
// 07/02/2021 : Initialisation du main (Mattéo Arzel)
//
// 08/02/2021 : Permet de rejouer la partie (Mattéo Arzel)
//
/*************************************************/
#include <iostream>
using namespace std;

#include "../include/JeuNombreADeviner.h"

int main()
{
    TJoueur joueur;
    string nom;
    cout << "Quel est votre nom ?" << endl;
    cin >> nom;
    InitJoueur(joueur, nom);
    char rejouer = 'o';
    while(rejouer=='o'){
        JouerPartie(joueur, TirerNombreMystere());
        cout << "-------------------------" << endl;
        cout << "Nom : " << nom << endl;
        cout << "Nombre de parties gagnees : " << joueur.nbPartiesGagnees << endl;
        cout << "Nombre de parties jouees : " << joueur.nbPartiesJouees << endl;
        cout << "Nombre de tentatives : " << joueur.nbTentatives << endl;
        cout << "-------------------------" << endl;
        cout << "Souhaitez vous rejouer ? (o = oui / n = non)" << endl;
        cin >> rejouer;
    }

}

