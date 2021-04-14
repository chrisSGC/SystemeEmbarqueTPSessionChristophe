#include <Arduino.h>
#include "Ecran.h"

int Ecran::lancement(uint8_t addrI2C) {
    if(afficheur.begin(SSD1306_SWITCHCAPVCC, addrI2C)){
        afficheur.cp437(true);
        afficheur.clearDisplay();
        afficheur.setTextColor(SSD1306_WHITE);

        return(0); // Initialisation effectuée
    }else{
        return(1); // Il y a une erreur
    }

}

void Ecran::MettreEnVeille(){
    afficheur.clearDisplay();
}

void Ecran::InitialiserAffichage(int hauteur){
    MettreEnVeille();
    afficheur.setTextSize(1);
    afficheur.setTextColor(SSD1306_WHITE);
    afficheur.setCursor(0, hauteur);
}

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