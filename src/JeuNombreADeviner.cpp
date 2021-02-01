/*************************************************/
// Nom du projet: Jeu du nombre � deviner
// Nom du fichier: JeuNombreADeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de cr�ation : 25/01/2021
// R�le du fichier: Contient le code des fonctions du jeu
// Nom des composants utilises: JeuNombreADeviner.h
//                              iostream
//                              ctime
// Historique du fichier:
//
// 25/01/2021 : - Ajout de la librairie <ctime>
//              - Fonction InitJoueur complet�e
//              - Fonction TirerNombreMystere complet�e
//
//
/*************************************************/
#include <iostream>
using namespace std;
#include "../include/JeuNombreAdeviner.h"
#include <ctime>

// Nom :InitJoueur
// R�le : Cr�e un joueur. Initialise toutes les informations du joueur.
//        Le nombre de tentatives, de parties gagn�es et de parties jou�es seront � 0.
// Param�tres d'entr�e : un_nom
// Param�tres de sortie : joueurAcreer
// Param�tres d'entr�e/sortie :

void InitJoueur(TJoueur& joueurAcreer, string un_nom)
{
        joueurAcreer.nbTentatives = 0;
        joueurAcreer.nbPartiesGagnees = 0;
        joueurAcreer.nbPartiesJouees = 0;
        joueurAcreer.nom = un_nom;

}


// Nom :TirerNombreMystere
// R�le : Tire al�atoirement un nombre � deviner entre 0 et 10
// Valeur de retour : nombre � deviner

int TirerNombreMystere()
{
        srand((unsigned int) time(0));
        int nombre=(rand()%10) + 0;
        return nombre;
}


// Nom :JouerPartie
// R�le : Fait jouer une partie au joueur pass� en param�tre
//        A la fin, met � jour les informations du joueur
// Param�tres d'entr�e: nombreADeviner
// Param�tres de sortie:
// Param�tres d'entr�e/sortie : un_joueur

void JouerPartie(TJoueur& un_joueur, int nombreADeviner)
{
        int i = 0;
        int v = 0;
        int d = 0;
        int valeur = 0;

        cout << "Trouve le nombre myst�re" << endl;
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
                cout << "Vous avez trouv� le juste prix !" << endl;
                cout << "Nombre d'essais : " << essai << endl;
                MajResultatsJoueur(un_joueur, essai, true);
                cout << "Nombre de victoire : " << joueurAcreer.nbPartiesGagnees;
                cout << "Nombre de d�faite : " << nbechec;
            }
            if(i == 4) {
                cout << "Vous n'avez pas r�ussi � trouv� le juste prix..." << endl;
                cout << "Nombre d'essais : " << essai << endl;
                MajResultatsJoueur(un_joueur, essai);
                cout << "Nombre de victoire : " << joueurAcreer.nbPartiesGagnees;
                cout << "Nombre de d�faite : " << nbechec;
            }
        }
}


// Nom : MajResultatsJoueur
// R�le : met � jour les informations du joueur pass� en param�tre
// Param�tres d'entr�e:
// Param�tres de sortie:
// Param�tres d'entr�e/sortie :

void MajResultatsJoueur(TJoueur joueur, int nbEssais, bool gagne)
{
   joueurAcreer.nbTentatives = nbEssais;
   joueurAcreer.nbPartiesGagnees = gagne;
}

// Nom : ResultatsJoueur
// R�le : indique les r�sultats du joueur pass� en param�tre
//        le nombre de parties gagn�es, le nombre de parties perdues, le nombre d'essais total
//        La fonction N'affiche PAS les informations � l'�cran
// Param�tres d'entr�e:
// Param�tres de sortie:
// Param�tres d'entr�e/sortie :

void ResultatsJoueur(TJoueur joueur, int& nbsucces, int& nbechec, int& nbessais)
{
    joueurAcreer.nbPartiesGagnees = nbsucces;
}

// Nom :Nom
// R�le : retourne le nom du joueur
// Param�tres d'entr�e: le joueur dont on veut le nom
// Valeur de retour : nom du joueur

string Nom(TJoueur joueur){

    return joueur.nom;
}

