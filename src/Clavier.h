/**
    Classe Clavier qui gere le clavier en se basant sur les methodes de la librairie Keypad déclarée en tant que propriété
    @file Clavier.h
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
        Keypad
**/

#ifndef CLAVIER_H
#define CLAVIER_H

#include <Keypad.h>
#include <string.h>

#define LIGNES 4
#define COLONNES 4

class Clavier{
    public:   
        char touches[LIGNES][COLONNES] = { {'1','2','3','A'}, {'4','5','6','B' }, {'7','8','9','C'}, {'*','0','#','D'} }; // Etant donné que l'on peut personnaliser les touches du clavier, il est necessaire de définir quelle touche correspond à quel caracteres. Dans le cadre du travail, les touches du clavier donneront bel et bien les memes informations qu'affichées dessus.
        byte GPIOLignes[LIGNES] = {16, 17, 5, 18}; // Lien entre les lignes du clavier et les GPIO de notre ESP
        byte GPIOColonnes[COLONNES] = {15, 2, 0, 4}; // Lien entre les colonnes du clavier et les GPIO de notre ESP

        Keypad clavier;
        
        Clavier();
        char RecupererToucheTapee();
};

#endif