// auteur : Syoan ODOUHA

//description : Ce programme est une calendrier perpétuel
//qui permet de connaitre le jour de la semaine en fonction d'une date donnée
// dans le format jj/mm/aaaa

//date de création : 10/10/2017


#include <iostream>
#include <string>

using namespace std;


// fonction qui recupère une date valide 

void getDate(int &jour, int &mois, int &annee)
{
    cout << "Entrez une date valide (jj/mm/aaaa) : ";
    cin >> jour;
    cin.ignore();
    cin >> mois;
    cin.ignore();
    cin >> annee;

    // année bissextile
    if (annee % 4 == 0 && annee % 100 != 0 || annee % 400 == 0)
    {
        if (mois == 2 && jour > 29)
        {
            cout << "Date invalide" << endl;
            getDate(jour, mois, annee);
        }
    }
    else
    {
        if (mois == 2 && jour > 28)
        {
            cout << "Date invalide" << endl;
            getDate(jour, mois, annee);
        }
    }

    // mois de 30 jours
    if (mois == 4 || mois == 6 || mois == 9 || mois == 11)
    {
        if (jour > 30)
        {
            cout << "Date invalide" << endl;
            getDate(jour, mois, annee);
        }
    }

    // mois de 31 jours
    if (mois == 1 || mois == 3 || mois == 5 || mois == 7 || mois == 8 || mois == 10 || mois == 12)
    {
        if (jour > 31)
        {
            cout << "Date invalide" << endl;
            getDate(jour, mois, annee);
        }
    }

    // mois invalide
    if (mois > 12 || mois < 1)
    {
        cout << "Date invalide" << endl;
        getDate(jour, mois, annee);
    }
}



int main(int argc, char const *argv[])
{
    int jour, mois, annee;
    getDate(jour, mois, annee);
    return 0;
}




