/**
    Classe Code
    @file Code.h
    @author Christophe Ferru
    @version 1.0 17/03/21  
    
    Historique des versions   
        Versions  Date          Auteur      Description
        1.0       22 Avril 21   Chris       Première version de la classe
                            
    platform = espressif32
    board = esp32doit-devkit-v1
    framework = arduino
    lib_deps = Aucune
    Autres librairies
        Aucune
**/

#ifndef CODE_H
#define CODE_H

#include <iostream>
using namespace std;

class Code{
    public:
        // Propriétés publiques
        int nombreCaracteres; // nombre de caractères saisis par l'utilisateur dans l'essai actuel
        int mode; // Mode dans lequel se trouve la saisie du code. PErmettant de savoir si on est en mode ouverture ou edition

        // Méthodes publiques de la classe
        Code(); // Constructeur de la classe
        bool VerifierCode(); // Methode permettant de vérifier le code entré
        int EntrerCaractere(char nouveauCaractere); // Methode permettant d'ajouter un caractere à la chaine saisie
        void ReinitialiserSaisie(); // Methode qui réinitialise le code, nombreCaracteres et mode
        void ModifierCode(); // Methode qui permet de modifier le code
    
    private:
        // attributs privés
        string code; // Code permettant l'ouverture de la porte
        string chaineSaisie; // Chaine représentant les touches saisies par l'utilisateur
};

#endif