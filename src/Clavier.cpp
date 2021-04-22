/**
    Classe qui permet de gérer le clavier Matrix 4x4 du projet
    @file ecran.cpp
    @author Christophe Ferru
    @version 1.0 - 14 Avril 2021                           
**/
#include <Clavier.h>

/**
 * Constructeur de la classe, on initialise notre propriete clavier qui est une instance de la libriarie Keypad
 * */
Clavier::Clavier(){
    clavier = Keypad(makeKeymap(touches), GPIOLignes, GPIOColonnes, LIGNES, COLONNES); // On initialise notre clavier avec les données préalablement renseignées
}

/**
 * Methode qui permet que récupérer la touche qui a été saisie par l'utilsiateur sur le clavier
 * */
char Clavier::RecupererToucheTapee(){
    return clavier.getKey();
}