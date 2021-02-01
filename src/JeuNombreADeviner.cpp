/*************************************************/
// Nom du projet: Jeu du nombre à deviner
// Nom du fichier: JeuNombreADeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de création : 25/01/2021
// Rôle du fichier: Contient le code des fonctions du jeu
// Nom des composants utilises: JeuNombreADeviner.h
//                              iostream
//                              ctime
// Historique du fichier:
//
// 25/01/2021 : - Ajout de la librairie <ctime>
//              - Fonction InitJoueur completée
//              - Fonction TirerNombreMystere completée
//
//
/*************************************************/
#include <iostream>
using namespace std;
#include "../include/JeuNombreAdeviner.h"
#include <ctime>

// Nom :InitJoueur
// Rôle : Crée un joueur. Initialise toutes les informations du joueur.
//        Le nombre de tentatives, de parties gagnées et de parties jouées seront à 0.
// Paramètres d'entrée : un_nom
// Paramètres de sortie : joueurAcreer
// Paramètres d'entrée/sortie :

void InitJoueur(TJoueur& joueurAcreer, string un_nom)
{
        joueurAcreer.nbTentatives = 0;
        joueurAcreer.nbPartiesGagnees = 0;
        joueurAcreer.nbPartiesJouees = 0;
        joueurAcreer.nom = un_nom;

}


// Nom :TirerNombreMystere
// Rôle : Tire aléatoirement un nombre à deviner entre 0 et 10
// Valeur de retour : nombre à deviner

int TirerNombreMystere()
{
        srand((unsigned int) time(0));
        int nombre=(rand()%10) + 0;
        return nombre;
}


// Nom :JouerPartie
// Rôle : Fait jouer une partie au joueur passé en paramètre
//        A la fin, met à jour les informations du joueur
// Paramètres d'entrée: nombreADeviner
// Paramètres de sortie:
// Paramètres d'entrée/sortie : un_joueur

void JouerPartie(TJoueur& un_joueur, int nombreADeviner)
{
        int i = 0;
        int v = 0;
        int d = 0;
        int valeur = 0;

        cout << "Trouve le nombre mystère" << endl;
        while(valeur !== nombreADeviner || i!==4) {
            cout << "Valeur : ";
            cin >> valeur;
            i++;
            if(valeur < nombreADeviner) {
                cout << "C'est plus !" << endl;
            }
            if(valeur > nombreADeviner) {
                cout << "C'est moins !" << endl;
            }
            if(valeur == nombreADeviner) {
                cout << "Vous avez trouvé le juste prix !" << endl;
                cout << "Nombre d'essais : " << essai << endl;
                MajResultatsJoueur(un_joueur, essai, true);
                cout << "Nombre de victoire : " << joueurAcreer.nbPartiesGagnees;
                cout << "Nombre de défaite : " << nbechec;
            }
            if(i == 4) {
                cout << "Vous n'avez pas réussi à trouvé le juste prix..." << endl;
                cout << "Nombre d'essais : " << essai << endl;
                MajResultatsJoueur(un_joueur, essai);
                cout << "Nombre de victoire : " << joueurAcreer.nbPartiesGagnees;
                cout << "Nombre de défaite : " << nbechec;
            }
        }
}


// Nom : MajResultatsJoueur
// Rôle : met à jour les informations du joueur passé en paramètre
// Paramètres d'entrée:
// Paramètres de sortie:
// Paramètres d'entrée/sortie :

void MajResultatsJoueur(TJoueur joueur, int nbEssais, bool gagne)
{
   joueurAcreer.nbTentatives = nbEssais;
   joueurAcreer.nbPartiesGagnees = gagne;
}

// Nom : ResultatsJoueur
// Rôle : indique les résultats du joueur passé en paramètre
//        le nombre de parties gagnées, le nombre de parties perdues, le nombre d'essais total
//        La fonction N'affiche PAS les informations à l'écran
// Paramètres d'entrée:
// Paramètres de sortie:
// Paramètres d'entrée/sortie :

void ResultatsJoueur(TJoueur joueur, int& nbsucces, int& nbechec, int& nbessais)
{
    joueurAcreer.nbPartiesGagnees = nbsucces;
}

// Nom :Nom
// Rôle : retourne le nom du joueur
// Paramètres d'entrée: le joueur dont on veut le nom
// Valeur de retour : nom du joueur

string Nom(TJoueur joueur){

    return joueur.nom;
}

