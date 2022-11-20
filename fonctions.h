#include <iostream>
#include <string>


using namespace std;


// fonction qui recupère une date valide 
void getDate(int &jour, int &mois, int &annee)
{
    cout << "Entrez une date valide (jj/mm/aaaa) supérieur ou égale au 20 décembre 1582 : \n";
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

    // date inférieure au 20 décembre 1582
    if (annee < 1582)
    {
        cout << "Date invalide" << endl;
        getDate(jour, mois, annee);
    }
    else if (annee == 1582)
    {
        if (mois < 12)
        {
            cout << "Date invalide" << endl;
            getDate(jour, mois, annee);
        }
        else if (mois == 12)
        {
            if (jour < 20)
            {
                cout << "Date invalide" << endl;
                getDate(jour, mois, annee);
            }
        }
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



//fonction 1 : jour semaine
void option1(int &jour, int &mois, int &annee, int &nbre_secu, int &annuel, int &mensuel, int &quantieme, int &res){
    getDate(jour, mois, annee);
    nbre_seculaire(jour, mois, annee, nbre_secu);
    nbre_annuel(jour, mois, annee, annuel);
    nbre_mensuel(mois, annee, mensuel);
    nbre_quantieme(jour, quantieme);
    jour_semaine(nbre_secu, annuel, mensuel, quantieme, res);
    affiche_jour_semaine(res);
}


// fonction 2 : vendredi 13
void option2(int &jour, int &mois, int &annee, int &nbre_secu, int &annuel, int &mensuel, int &quantieme, int &res){
    // saisir une année
    cout << "Saisir une année : ";
    cin >> annee;

    // calculer le jour de la semaine pour tous les 13 du mois
    for (int i = 1; i <= 12; i++)
    {
        mois = i;
        jour = 13;
        nbre_seculaire(jour, mois, annee, nbre_secu);
        nbre_annuel(jour, mois, annee, annuel);
        nbre_mensuel(mois, annee, mensuel);
        nbre_quantieme(jour, quantieme);
        jour_semaine(nbre_secu, annuel, mensuel, quantieme, res);
        affiche_jour_semaine(res);
    }

    // afficher le nombre de vendredi 13
}



// menu 
void menu(){
    int choix;
    int jour, mois, annee, nbre_secu, annuel, mensuel, quantieme, res;
    cout << "1. Jour de la semaine" << endl;
    cout << "2. Vendredi 13" << endl;
    cout << "3. Quitter" << endl;
    cout << "Votre choix : " << endl;
    cin >> choix;
    switch (choix)
    {
    case 1:
        option1(jour, mois, annee, nbre_secu, annuel, mensuel, quantieme, res);
        break;
    case 2:
        option2(jour, mois, annee, nbre_secu, annuel, mensuel, quantieme, res);
        break;
    case 3:
        exit(0);
        break;
    default:
        cout << "Choix invalide" << endl;
        menu();
        break;
    }
}


