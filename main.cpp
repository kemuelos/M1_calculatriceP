// auteur : Syoan ODOUHA

//description : Ce programme est une calendrier perpétuel
//qui permet de connaitre le jour de la semaine en fonction d'une date donnée
// dans le format jj/mm/aaaa

//date de création : 10/10/2017


#include <iostream>
#include <string>
#include "fonctions.h"

using namespace std;




int main(int argc, char const *argv[])
{
    int jour, mois, annee;
    getDate(jour, mois, annee);
    nbre_seculaire(jour, mois, annee);
    
    return 0;
}




