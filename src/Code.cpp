/**
    Classe qui permet de gérer le code PIN et sa modification
    @file ecran.cpp
    @author Christophe Ferru
    @version 1.0 - 14 Avril 2021                           
**/
#include <Code.h>
#include <iostream>
#include <cstring>

using namespace std;

/**
* Constructeur de la calsse code
* Permet d'initialiser le mot de passe de base
**/
Code::Code(){
    code = "8934"; // code de base au lancement de l'application
    mode = 1; // le mode par défaut est 1 à savoir: mode classique
    ReinitialiserSaisie();
}

/**
 * Permet de réinitialiser la chiane saisie afin que l'utilisateur puisse reprendre à 0
 **/
int Code::EntrerCaractere(char nouveauCaractere){
    if(('#' == nouveauCaractere) && (4 == chaineSaisie.size())){
        // il s'agit d'une validation de code, on lance donc la reconnaissance
        return VerifierCode();
    }else if(('*' == nouveauCaractere) && (4 == chaineSaisie.size()) && (2 == mode)){
        //Si 4 caracteres plus le # = changement de code
        ModifierCode();
        return 3; // code 3 veut dire que le code a été modifié
    }else if(('B' == nouveauCaractere) && (4 == chaineSaisie.size())){ //Si 4 caracteres plus le B, on vérifie si le code est bon et si tel est le cas, on entre en mode edition, ce qui veut dire que l'on va faire appel à la methode ReinitialiserSaisie et retourner un code 5.
        // Si le code entré n'est pas bon, on renvoi un code 0
        if(VerifierCode()){
            ReinitialiserSaisie();
            mode = 2;

            return 5; // code 5 veut dire que la personne entre en mode edition
        }else{
            return 0;
        }        
    }else{
        chaineSaisie = chaineSaisie + nouveauCaractere;
        nombreCaracteres++;
        return 2; // code 2 veut dire que le caractere a été ajouté
    }

}

/**
 * Permet de réinitialiser la chiane saisie afin que l'utilisateur puisse reprendre à 0
 **/
void Code::ReinitialiserSaisie(){
    chaineSaisie = "";
    nombreCaracteres = 0;
    mode = 1; // On remet le mode à 1 au cas ou il ai été changé
}

/**
 * Permet de vérifier si le code saisi par l'utilisateur est bon ou pas
 * 
 * @return true si le code saisie est le code demandé, false si ce n'est pas le cas
 **/
bool Code::VerifierCode(){
    return (code == chaineSaisie) ? true : false;
}

/**
 * Permet de modifier le code demandé pour valider l'ouverture
 **/ 
void Code::ModifierCode(){
    code = chaineSaisie;
}