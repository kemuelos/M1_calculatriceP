// auteur : Syoan ODOUHA

//description : Ce programme est une calendrier perpétuel
//qui permet de connaitre le jour de la semaine en fonction d'une date donnée
// dans le format jj/mm/aaaa

//date de création : 10/10/2017


#include <iostream>
#include <string>
#include "fonctions.h"

using namespace std;



int main(){
    int choix;
    int jour, mois, annee, nbre_secu, annuel, mensuel, quantieme, res, nbre, jour2, mois2, annee2;
    cout << "1. Jour de la semaine" << endl;
    cout << "2. Vendredi 13" << endl;
    cout << "3. Edition de calendrier" << endl;
    cout << "4. Quitter" << endl;
    cout << "Votre choix : " << endl;
    cin >> choix;
    switch (choix)
    {
    case 1:
        option1(jour, mois, annee, nbre_secu, annuel, mensuel, quantieme, res);
        main();
        break;
    case 2:
        option2(jour, mois, annee, nbre_secu, annuel, mensuel, quantieme, res);
        main();
        break;
    case 3:
        option3(jour, mois, annee, nbre_secu, annuel, mensuel, quantieme, res);
        main();
        break;
    case 4:
        exit(0);
        break;
    default:
        cout << "Choix invalide" << endl;
        main();
        break;
    }
}




