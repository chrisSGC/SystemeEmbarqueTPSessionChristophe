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
#include <iostream>
using namespace std;

class Code{
    public:
        // Propriété correspondant au nombre de caracteres saisis
        int nombreCaracteres;

        // Méthode spubliques de la classe
        Code();
        bool VerifierCode();
        int EntrerCaractere(char nouveauCaractere);
        void ReinitialiserSaisie();
        void ModifierCode();
    
    private:
        string code;
        string chaineSaisie;
};