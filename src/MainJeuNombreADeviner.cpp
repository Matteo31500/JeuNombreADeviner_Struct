/*************************************************/
// Nom du projet: Jeu du nombre � deviner
// Nom du fichier: MainJeuNombreAdeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de cr�ation : 25/01/2021
// R�le du fichier: Contient le code jeu
// Nom des composants utilises: JeuNombreADeviner.h
//                              iostream
// Historique du fichier:
/*************************************************/
#include <iostream>
using namespace std;

#include "../include/JeuNombreADeviner.h"

int main()
{
    TJoueur un_joueur;
    cout << "Quel est votre nom ?" << endl;
    cin >> un_joueur.nom;
    JouerPartie(un_joueur, TirerNombreMystere());
    cout << "-------------------------" << endl;
    cout << "Nom : " << un_joueur.nom << endl;
    cout << "Nombre de parties gagn�es : " << un_joueur.nbPartiesGagnees << endl;
    cout << "Nombre de parties jou�es : " << un_joueur.nbPartiesJouees << endl;
    cout << "Nombre de tentatives : " << un_joueur.nbTentatives << endl;

}

