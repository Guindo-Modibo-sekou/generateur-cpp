#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

int longueur;
string nombre = "0123456789";
string majuscules = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string minuscules = "abcdefghijklmnopqrstuvwxyz";
string caracteres_speciaux = "!@#$%^&*()_+{}|:<>?-=[]';.,/";
string elements = nombre + majuscules + minuscules + caracteres_speciaux;
int decision;
string mot_de_passe;
int nbre;
int choix;
string motdepasse;
string aleatoire(int longueur)
{
    string motdepasse;
    motdepasse += majuscules[rand() % majuscules.size()];
    motdepasse += minuscules[rand() % minuscules.size()];
    motdepasse += nombre[rand() % nombre.size()];
    motdepasse += caracteres_speciaux[rand() % caracteres_speciaux.size()];
    int reste = longueur - 4;

    for(int j=0; j<reste; j++)
        {
        motdepasse += elements[rand() % elements.size()];
        }
    random_shuffle(motdepasse.begin(), motdepasse.end());
    return motdepasse;
}
vector<string> tableau;
int evaluerForceMotDePasse(const string& mot_de_passe)
{
    int score =0;
    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;

    // Vérifier chaque caractère
    for(size_t i = 0; i < mot_de_passe.size(); i++)
{
    char c = mot_de_passe[i];
    if(isupper(c)) hasUpper = true;
    else if(islower(c)) hasLower = true;
    else if(isdigit(c)) hasDigit = true;
    else hasSpecial = true;
}


    // Longueur
    if(mot_de_passe.size() >= 8) score += 2;
    if(mot_de_passe.size() >= 12) score += 2;

    // Diversité
    if(hasUpper) score++;
    if(hasLower) score++;
    if(hasDigit) score++;
    if(hasSpecial) score++;

    return score; // Score max = 9
}

string niveauForce(int score) {
    if(score <= 3) return "Faible";
    else if(score <= 6) return "Moyen";
    else return "Fort";
}


int main()
{
     srand(time(NULL));
    cout<<"==GENERATEUR DE MOT DE PASSE=="<<endl;
    do
    {
        cout<<"choisir l'option 1 ou l'option 2"<<endl;
        cout<<"1 - saisir votre propre mot de passe"<<endl;
        cout<<"2 - laisser l'ordinateur vous suggerer un mot de passe"<<endl;
        cin>>decision;
        int score ;

    switch(decision)
    {
        case 1 :
        do {
        cout << "==Vous allez vous-meme saisir votre mot de passe==" << endl;
        cout << "Veuillez saisir votre mot de passe : ";
        cin >> mot_de_passe;

        if(mot_de_passe.size() < 8 || mot_de_passe.size() > 16) {
            cout << "La longueur n'est pas valide (entre 8 et 16 caracteres)." << endl;
            continue; // recommence directement
        }

        int score = evaluerForceMotDePasse(mot_de_passe);
        cout << "Score : " << score << " / 10" << endl;
        cout << "Force du mot de passe : " << niveauForce(score) << endl;

        if(niveauForce(score) == "Faible") {
    string voie;
    cout << "Votre mot de passe est faible. Voulez-vous en saisir un autre ? (oui ou non) : ";
    cin >> voie;
    if(voie == "oui") {
        continue; // recommence la saisie
    } else {
        break; // accepte le mot de passe faible
    }
} else {
    break; // mot de passe moyen ou fort → on sort
}

    } while(true);

    cout << "Votre mot de passe final est : " << mot_de_passe << endl;
    break;

    case 2 :
        do
        {
            cout<<"==Vous allez laisser l'ordinateur vous suggerer des mots de passe=="<<endl;
            cout<<"Quel longueur souhaitez-vous donner a votre mot de passe(Il doit contenir entre 8 et 16 caracteres)"<<endl;
            cin>>longueur;
            if(longueur<8||longueur>16)
            {
                cout<<"la longueur n'est pas valide ,recommencez svp."<<endl;
            }
        }while(longueur<8||longueur>16);
        cout<<"Combien de passe souhaitez-vous que l'on vous suggere"<<endl;
        cin>>nbre;

        for(int i=0;i<nbre;i++)
        {
          motdepasse=aleatoire(longueur);
          cout<<i+1<<"-le mot de passe N_"<<i+1<<" est "<<motdepasse<<endl;
          tableau.push_back(motdepasse);
        }
        do
        {
            cout<<"Quel  mot de passe choisissez-vous?(ecrire le numero)"<<endl;

            cin>>choix;
             if(choix<1 || choix>nbre)
                {
                    cout << "Saisie invalide, recommencez !" << endl;
                }
        } while(choix<1 || choix >nbre);
        cout<<"Votre mot de passe sera "<<tableau[choix-1]<<endl;
        break;

    default :
        cout << "ERREUR ! Entrez une option valide (1 ou 2)." << endl;
        }

    }while(decision!=1 && decision!=2);
}

