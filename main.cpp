// auteur : Syoan ODOUHA

//description : Ce programme est une calendrier perpétuel
//qui permet de connaitre le jour de la semaine en fonction d'une date donnée
// dans le format jj/mm/aaaa

//date de création : 10/10/2017


#include <iostream>
#include <string>

using namespace std;

int main(){
    int jour, mois, annee;

    //vérfier si le mois est compris entre 1 et 12 
    cout << "Entrez le mois : ";
    cin >> mois;
    while (mois < 1 || mois > 12){
        cout << "Le mois doit être compris entre 1 et 12" << endl;
        cout << "Entrez le mois : ";
        cin >> mois;
    }

    // verifier si le jour est compris entre 1 et 31
    // cout << "Entrez le jour : ";
    // cin >> jour;
    // while (jour < 1 || jour > 31){
    //     cout << "Entrez un jour valide : ";
    //     cin >> jour;
    // }


    // cout << "Entrez l'année : ";
    // cin >> annee;
}
