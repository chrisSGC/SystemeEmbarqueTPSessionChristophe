/**
    Classe Ecran qui gere l'Ecran en se basant sur les methodes de la librairie Adafruit_SSD1306 déclarée en tant que propriété
    @file Ecran.h
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
        Adafruit_GFX
        Adafruit_SSD1306
        Adafruit_I2CDevice
**/
#ifndef ECRAN_H
#define ECRAN_H

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_I2CDevice.h>

class Ecran{
    public:
        int lancement(uint8_t adresse = 0x3C);   //Parfois 0x3D
        Adafruit_SSD1306 afficheur = Adafruit_SSD1306(128, 32, &Wire);

        Ecran(){}
        void InitialiserAffichage(int hauteur);
        void AfficherSaisie(byte nombreCaracteres = 0, int leMode = 1);
        void AfficherDeverrouillage(bool ouverture = false);
        void AfficherModification();

        //Pour les fonctionnalités de veille
        void EffacerEcran();
        
    private:  
        // Attributs privés représentants les en tetes
        String enTete = "Saisissez votre code";
        String enTeteModification = "Nouveau Code";
        String modeEdition = "MODE EDITION";
};

#endif