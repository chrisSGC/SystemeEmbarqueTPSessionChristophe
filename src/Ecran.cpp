/**
    Classe qui permet de gérer l'écran DEL du projet
    @file ecran.cpp
    @author Christophe Ferru
    @version 1.0 - 14 Avril 2021                           
**/
#include <Arduino.h>
#include "Ecran.h"

/**
 * Methode qui met la configuration de l'écran en place
 * 
 * @param addrI2C Adresse I2C de l'écran DEL
 * @return 1 en cas d'erreur | 0 si tout va bien
 **/
int Ecran::lancement(uint8_t addrI2C) {
    if(afficheur.begin(SSD1306_SWITCHCAPVCC, addrI2C)){
        afficheur.cp437(true);
        EffacerEcran(); // On appele la fonction EffacerEcran() pour effacer l'écran

        return(0); // Initialisation effectuée
    }else{
        return(1); // Il y a une erreur
    }

}

/**
 * Methode qui permet d'effacer le contenu affiché à l'écran
 * 
 * @return void
 **/ 
void Ecran::EffacerEcran(){
    afficheur.clearDisplay();
}

/**
 * 
 * 
 * @param hauteur int qui determine la hauteur à laquelle se trouve la ligne
 * @return void
 **/ 
void Ecran::InitialiserAffichage(int hauteur){
    EffacerEcran(); // On appele la fonction EffacerEcran() pour effacer l'écran
    afficheur.setTextSize(1);
    afficheur.setTextColor(SSD1306_WHITE);
    afficheur.setCursor(0, hauteur);
}

/**
 * 
 * 
 * @param nbrCharSaisis nombre de caractères saisis par l'utilisateur afin d'afficher le bon nombe d'étoiles
 * @return void 
 **/
void Ecran::AfficherSaisie(byte nbrCharSaisis){
    byte nbrLocal = 0;
    String affichageCode = "";

    while(nbrLocal < nbrCharSaisis){
        affichageCode = affichageCode + "*";
        nbrLocal++;
    }

    afficheur.println(enTete);
    afficheur.println(affichageCode);
    afficheur.display();
}

void Ecran::AfficherDeverrouillage(bool ouverture){
    InitialiserAffichage(15);

    if(ouverture == true){
        afficheur.print("OUVERTURE");
    }else{
        afficheur.print("ACCES REFUSE");
    }

    afficheur.display();
}