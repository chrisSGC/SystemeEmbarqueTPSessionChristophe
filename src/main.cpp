/**
    Projet de session Systèmes embarqués
    Expérimentations sur l'utilisation des classes et d'un écran Oled (avec un bouton) sur un ESP32
    @file main.cpp
    @author Christophe Ferru
    @version 0.4 21 Avril 2021
    
    Historique des versions       :
      Versions  Date          Auteur      Description
      0.1       12 Avril 21   Chris       Mise en place des fichiers de base
	  0.2		19 Avril 21   Chris		  Reinitialisation du fichier main
      0.3       20 Avril 21   Chris       Mise en place de l'algorythme principal
      0.4       21 Avril 21   Chris       Mise en place de l'anneau de Dels
                            
    platform                      : espressif32
    board                         : esp32doit-devkit-v1
    framework                     : arduino
    lib_deps                      : 
		- Aucun
    Autres librairies (à copier dans le répertoire lib)
		- Adafruit_GFX
		- Adafruit_GrayOLED
		- Adafruit_NeoPixel
		- Adafruit_SSD1306
		- Key
		- Keypad
    Classes du système            :
		Anneau		v1.0	Interface l'anneau Del
			8 Del
			GPIO14
		Clavier		v1.0	Interface le clavier
			GPIO0, 2, 4, 5, 15, 16,17 et 18
		Ecran		v1.0	Interface l'écran Del
			Résolution 128 x 64
            Protocole I2C, Adresse: 0x3C 
            GPIO21                : SDA
            GPIO22                : SCL
		Code		v1.0	Gestion du code PIN
			Controle et modification du code
**/

// Includes généraux
#include <Arduino.h>

// Includes classes personnelles
#include <Clavier.h>
#include <Code.h>
#include <Anneau.h>
#include <Ecran.h>

// Objets personnalisés
Ecran *ecranDel = NULL;
Anneau *anneauDel = NULL;
Clavier *clavier = NULL;
Code *code = NULL;

// Variables necesaires au programme
int leCode;

void setup() {
    code = new Code(); // Initialisation de l'objet Code pour gérer le code PIN
    clavier = new Clavier(); // Initialisation de l'objet Clavier
    anneauDel = new Anneau(); // Initialisation de l'objet Anneau
    ecranDel = new Ecran(); // Initialisation de l'objet Ecran

    Serial.begin(9600);
    leCode = 4;

    anneauDel->Initialiser(); // Appel de la methode initialiser qui permet de demarrer l'anneau et réinitiliser le registre
    ecranDel->lancement(); // Appel de la methode lancement qui permet d'initialiser l'affichage sur l'écran
}

void loop() {
    ecranDel->EffacerEcran();
    anneauDel->ReinitialiserRegistre();

    char toucheSaisie = clavier->RecupererToucheTapee(); // récupere la touche saisie sur le clavier

    // Partie non prévue au programme mais necessaire pour vérifier que le tout fonctionne
    if(toucheSaisie != NO_KEY){
        // On affiche la ligne de l'écran
        leCode = code->EntrerCaractere(toucheSaisie); // Fait appel à la methode pour ajouter le caractére saisi à la chaine et retourne le code
        Serial.println(toucheSaisie);
        anneauDel->FaireTournerAnneau();
    }

    if(1 == leCode){
        anneauDel->AllumerDelRegistre(0b11111111, 0, 25, 0);
        // le code est bon, leds vertes
        ecranDel->AfficherDeverrouillage(true);
    }else if(0 == leCode){
        anneauDel->AllumerDelRegistre(0b11111111, 25, 0, 0);
        // code erroné, leds rouges
        ecranDel->AfficherDeverrouillage(false);
    }else if(3 == leCode){
        anneauDel->AllumerDelRegistre(0b11111111, 25, 0, 13);
        // Code modifié, leds violettes
        ecranDel->AfficherModification();
    }else if(2 == leCode){
        ecranDel->AfficherSaisie(code->nombreCaracteres);
        anneauDel->AllumerDelSaisie(code->nombreCaracteres);
    }else{
        // Cas par défaut, on eteind des Del et on affiche le cas par defaut
        anneauDel->EteindreDel();
        anneauDel->AllumerDel();
        ecranDel->AfficherSaisie(code->nombreCaracteres);
    }

    if((2 != leCode) && (4 != leCode)){
        code->ReinitialiserSaisie(); // On réinitialise la saisie
        delay(4000);
        leCode = 4; // On réinitialise le code de déajout des commentairespart à 4
    }
}