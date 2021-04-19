#include <Code.h>
#include <iostream>
#include <cstring>

using namespace std;

/**
* Constructeur de la calsse code
* Permet d'initialiser le mot de passe de base
**/
Code::Code(){
    code = "8934";
    ReinitialiserSaisie();
}

/**
 * Permet de réinitialiser la chiane saisie afin que l'utilisateur puisse reprendre à 0
 **/
int Code::EntrerCaractere(char nouveauCaractere){
    if('*' == nouveauCaractere){
        // il s'agit d'une validation de code, on lance donc la reconnaissance
        return VerifierCode();
    }else if(('*' == nouveauCaractere) && (4 == chaineSaisie.size())){
        //Si 4 caracteres plus le # = changement de code
        ModifierCode();
        return 3; // code 3 veut dire que le code a été modifié
    }else{
        chaineSaisie = chaineSaisie + nouveauCaractere;
        return 2; // code 2 veut dire que le caractere a été ajouté
    }

}

/**
 * Permet de réinitialiser la chiane saisie afin que l'utilisateur puisse reprendre à 0
 **/
void Code::ReinitialiserSaisie(){
    chaineSaisie = "";
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