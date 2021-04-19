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