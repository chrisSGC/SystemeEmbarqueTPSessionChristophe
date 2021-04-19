#include <Clavier.h>


Clavier::Clavier(){
    clavier = Keypad(makeKeymap(touches), GPIOLignes, GPIOColonnes, LIGNES, COLONNES); // On initialise notre clavier avec les données préalablement renseignées
}

char Clavier::RecupererToucheTapee(){
    return clavier.getKey();
}