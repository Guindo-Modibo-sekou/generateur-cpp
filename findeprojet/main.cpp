#include <iostream>
#include <vector>
#include "declaration.h"
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

int main() {
     int valeur;
     srand(time(NULL));
    cout << "== GENERATEUR DE MOT DE PASSE ==" << endl;

    int decision;
    string mot_de_passe;
    vector <string> tableau;
    do
    {
    cout << "Choisir l'option 1 ou 2" << endl;
    cout << "1 - Saisir votre propre mot de passe" << endl;
    cout << "2 - Laisser l'ordinateur vous suggerer un mot de passe" << endl;
    cin >> decision;

    switch(decision) {
        case 1: {
            do {
                do
                {
                    cout << "Veuillez saisir votre mot de passe(entre 8 et 16 caracteres) : ";
                cin >> mot_de_passe;
                if (mot_de_passe.size()<8 ||mot_de_passe.size()>16)
                {
                    cout<<"La longueur du mot de passe est invalide . de 8 a 16 caracteres"<<endl;
                }

                }while(mot_de_passe.size()<8 ||mot_de_passe.size()>16);

                int score = evaluerForceMotDePasse(mot_de_passe);
                //cout << "Score : " << score << " / 10" << endl;
                cout << "Force : " << niveauForce(score) << endl;

                if(niveauForce(score) == "Faible")
                    {
                    string choix;
                    cout << "Mot de passe faible. Voulez-vous en saisir un autre ? (oui/non) : ";
                    cin >> choix;
                    if(choix == "oui") continue;
                }
                break;
            } while(true);

            cout << "Votre mot de passe final est : " << mot_de_passe << endl;
            int besoin;
            cout<<"voulez vous sauvegarder le mot de passe dans un fichier ?"<<endl;
            cout<<"1 - oui"<<endl;
            cout<<"2 - non"<<endl;
            do
            {
                cin>>besoin;
            switch(besoin)
            {
            case 1 :
                {
                    ofstream fichier ("mot de passe.txt",ios::app);
            if(fichier.is_open())
            {
                string application;
                cout<<"Pour quelle application est ce mot de passe"<<endl;
                cin>>application;
                fichier<<"(Le mot de passe de "<<application<<")"<<mot_de_passe<<endl;
                fichier.close();
                cout <<"le mot de passe a ete sauvegarde dans 'mot de passe.txt' "<<endl;
            }
            else
            {
                cout << " Erreur : impossible d'ouvrir le fichier." << endl;
            }
                }

            break;
            case 2 :
                cout<<"merci d'avoir utiliser notre generateur de mot de passe "<<endl;
                break;
            default :
                cout<<"erreur choisir par oui ou par non"<<endl;
            }
            }while(besoin!=1&&besoin!=2);
        }
         break;

        case 2: {
            int longueur;
            do
            {
                 cout << "Longueur du mot de passe (8 a 16 caracteres) : ";
            cin >> longueur;
            if(longueur<8||longueur>16)
            {
                cout<<"La longueur est invalide. recommencez s'il vous plait"<<endl;
            }
            }while(longueur<8||longueur>16);

            cout <<"Combien de mot de passe souhaitez-vous que l'on vous suggere"<<endl;
            cin >> valeur;
            for(int k=0;k<valeur;k++)
            {
                string suggestion = aleatoire(longueur);
            cout <<k+1<< "- Le Mot de passe suggere n_: " <<k+1<<" est "<< suggestion << endl;
            tableau.push_back(suggestion);
            }
            int preference ;
            do
            {
                cout <<"Quel mot de passe preferez-vous?(numero du mot de passe)"<<endl;
                cin >>preference;
                if(preference<1||preference>valeur)
                {
                    cout<<"ERREUR! Entrez un numero valide "<<endl;
                }
            }while(preference<1||preference>valeur);
            cout<<"votre mot de passe sera donc "<<tableau[preference-1]<<endl;

            int besoin;
            cout<<"voulez vous sauvegarder le mot de passe dans un fichier ?"<<endl;
            cout<<"1 - oui"<<endl;
            cout<<"2 - non"<<endl;
            do
            {
                cin>>besoin;
            switch(besoin)
            {
            case 1 :
                {
                    ofstream fichier ("mot de passe.txt",ios::app);
            if(fichier.is_open())
            {
                string application;
                cout<<"Pour quelle application est ce mot de passe"<<endl;
                cin>>application;
                fichier<<"(Le mot de passe de "<<application<<")"<<tableau[preference-1]<<endl;
                fichier.close();
                cout <<"le mot de passe a ete sauvegarde dans 'mot de passe.txt' "<<endl;
            }
            else
            {
                cout << " Erreur : impossible d'ouvrir le fichier." << endl;
            }
                }

            break;
            case 2 :
                cout<<"merci d'avoir utiliser notre generateur de mot de passe "<<endl;
                break;
            default :
                cout<<"erreur choisir par oui ou par non"<<endl;
            }
            }while(besoin!=1&&besoin!=2);
     }
      break;

    default:
            cout << "Option invalide." << endl;
    }

}while(decision!=1 && decision!=2);
return 0;
}
