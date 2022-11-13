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




// fonction qui calcule le nombre seculaire

void nbre_seculaire(int &jour, int &mois, int &annee, int &nbre_seculaire){
    if(annee<1582){
        nbre_seculaire = 19 - annee/100;
        printf("%d", nbre_seculaire);
    }
    else{
        if(annee/100== 15){
            nbre_seculaire = 1;
        }
        if(annee/100== 16){
            nbre_seculaire = 0;
        }
        if(annee/100== 17){
            nbre_seculaire = 5;
        }
        if(annee/100== 18){
            nbre_seculaire = 3;
        }
        if(annee/100== 19){
            nbre_seculaire = 1;
        }
        if(annee/100== 20){
            nbre_seculaire = 0;
        }
        if(annee/100== 21){
            nbre_seculaire = 5;
        }
    } 
}


// fontion qui calcule le nombre mensuel
void nbre_mensuel(int &mois, int &annee,int &nbre_mensuel){
    // si l'année est bisextile
    if(annee % 4 == 0 && annee % 100 != 0 || annee % 400 == 0){
        if(mois == 1){
            nbre_mensuel = 3;
        }
        if(mois == 2){
            nbre_mensuel = 6;
        }
    }
    else{
        if(mois == 1){
            nbre_mensuel = 4;
        }
        if(mois == 2){
            nbre_mensuel = 0;
        }
    }


    // pour les autres mois quelque soit le type de l'année
    if (mois == 3 || mois == 11){
        nbre_mensuel = 0;
    }
    if (mois == 6){
        nbre_mensuel = 1;
    }
    if (mois == 9 || mois == 12){
        nbre_mensuel = 2;
    }
    if (mois == 4 || mois == 7){
        nbre_mensuel = 3;
    }
    if (mois == 10){
        nbre_mensuel = 4;
    }
    if (mois == 5){
        nbre_mensuel = 5;
    }
    if (mois == 8){
        nbre_mensuel = 6;
    }
}


// fonction qui calcule le quantième 
void nbre_quantième(int &jour, int &nbre_quantième){
    nbre_quantième = jour;
}
