#include <iostream>
#include <string>


using namespace std;


// fonction qui recupère une date valide 
void getDate(int &jour, int &mois, int &annee)
{
    // entrer un date supérieur ou égale au 20/12/1582
    cout << "Entrez une date valide (jj/mm/aaaa) supérieur ou égale au 20 décembre 1582 : ";
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
void nbre_seculaire(int &jour, int &mois, int &annee, int &nbre_secu){
    int siecle_ref = 15;
    int nb_sec_ref = 1;
    nbre_secu = nb_sec_ref;
    int s = annee/100;
    while (siecle_ref != s)
    {
        if (nbre_secu == 1)
            nbre_secu = 0;
        else if (nbre_secu == 0)
            nbre_secu = 5;
        else if (nbre_secu == 5)
            nbre_secu = 3;
        else if (nbre_secu == 3)
            nbre_secu = 1;
        siecle_ref++;
    }

    // printf("%d", s);
    // printf("nbre_secu = %d", nbre_secu);

    



}


// nombre annuel 
void nbre_annuel(int &jour, int &mois, int &annee, int &annuel){
     annuel = (annee%100) + (annee%100)/4 - 5;
    
    // printf("annuel = %d", annuel);
}


// fontion qui calcule le nombre mensuel
void nbre_mensuel(int &mois, int &annee,int &mensuel){
    // si l'année est bisextile
    if(annee % 4 == 0 && annee % 100 != 0 || annee % 400 == 0){
        if(mois == 1){
            mensuel = 3;
        }
        if(mois == 2){
            mensuel = 6;
        }
    }
    else{
        if(mois == 1){
            mensuel = 4;
        }
        if(mois == 2){
            mensuel = 0;
        }
    }


    // pour les autres mois quelque soit le type de l'année
    if (mois == 3 || mois == 11){
        mensuel = 0;
    }
    if (mois == 6){
        mensuel = 1;
    }
    if (mois == 9 || mois == 12){
        mensuel = 2;
    }
    if (mois == 4 || mois == 7){
        mensuel = 3;
    }
    if (mois == 10){
        mensuel = 4;
    }
    if (mois == 5){
        mensuel = 5;
    }
    if (mois == 8){
        mensuel = 6;
    }
    // printf("mensuel = %d", mensuel);
}


// fonction qui calcule le quantième 
void nbre_quantieme(int &jour, int &quantieme){
    quantieme = jour;
    // printf("Le quantieme est : %d", quantieme);
}



// fonction qui calcule le jour de la semaine
void jour_semaine(int &nbre_secu, int &annuel, int &mensuel, int &quantieme, int &res){
    res = (nbre_secu + annuel + mensuel + quantieme) % 7;
}

// fonction qui affiche le jour de la semaine
void affiche_jour_semaine(int &res){
    if(res == 0){
        cout << "Dimanche" << endl;
    }
    if(res == 1){
        cout << "Lundi" << endl;
    }
    if(res == 2){
        cout << "Mardi" << endl;
    }
    if(res == 3){
        cout << "Mercredi" << endl;
    }
    if(res == 4){
        cout << "Jeudi" << endl;
    }
    if(res == 5){
        cout << "Vendredi" << endl;
    }
    if(res == 6){
        cout << "Samedi" << endl;
    }
}
