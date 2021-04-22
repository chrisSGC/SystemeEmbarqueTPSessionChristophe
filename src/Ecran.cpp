/**
    Classe qui permet de gérer l'écran DEL du projet
    @file ecran.cpp
    @author Christophe Ferru
    @version 1.0 - 14 Avril 2021                           
**/
#include "Ecran.h"

/**
 * Méthode qui met la configuration de l'écran en place
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
 * Méthode qui permet d'effacer le contenu affiché à l'écran
 * 
 * @return void
 **/ 
void Ecran::EffacerEcran(){
    afficheur.clearDisplay();
}

/**
 * Méthode qui initialise l'affichage de l'écran
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
 * Méthode qui affiche le message de modification du code secret
 * 
 * @return void
 **/ 
void Ecran::AfficherModification(){
    EffacerEcran();
    InitialiserAffichage(10);
    
    afficheur.println("CODE MODIFIE!");
    afficheur.println("REDEMARRAGE SYSTEME");
    afficheur.display();
}

/**
 * Méthode qui permet d'afficher le nombre d'étoiles correspondant au nombre de caracteres saisis
 * 
 * @param nbrCharSaisis nombre de caractères saisis par l'utilisateur afin d'afficher le bon nombe d'étoiles
 * @return void 
 **/
void Ecran::AfficherSaisie(byte nbrCharSaisis){
    EffacerEcran();
    InitialiserAffichage(10);
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

/**
 * Méthode qui permet d'afficher sur l'écran si la porte est dévérouillée ou non
 * 
 * @param ouverture true si la dévérouillage est un succes, false si ce n'est pas le cas
 * @return void 
 **/
void Ecran::AfficherDeverrouillage(bool ouverture){
    EffacerEcran();
    InitialiserAffichage(15);

    if(ouverture == true){
        afficheur.println("OUVERTURE");
    }else{
        afficheur.println("ACCES REFUSE");
    }

    afficheur.display();
}