#include "declaration.h"
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

string nombre = "0123456789";
string majuscules = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string minuscules = "abcdefghijklmnopqrstuvwxyz";
string caracteres_speciaux = "!@#$%^&*()_+{}|:<>?-=[]';.,/";
string elements = nombre + majuscules + minuscules + caracteres_speciaux;

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

int evaluerForceMotDePasse(const string& mot_de_passe)
{
    int score =0;
    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;

    for(size_t i = 0; i < mot_de_passe.size(); i++)
{
    char c = mot_de_passe[i];
    if(isupper(c)) hasUpper = true;
    else if(islower(c)) hasLower = true;
    else if(isdigit(c)) hasDigit = true;
    else hasSpecial = true;
}

    if(mot_de_passe.size() >= 8) score += 2;
    if(mot_de_passe.size() >= 12) score += 2;

    if(hasUpper) score++;
    if(hasLower) score++;
    if(hasDigit) score++;
    if(hasSpecial) score++;

    return score;
}

string niveauForce(int score) {
    if(score <= 3) return "Faible";
    else if(score <= 6) return "Moyen";
    else return "Fort";
}
