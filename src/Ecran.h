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
        //Ecran(TwoWire *twi, uint8_t RST = 4, uint8_t rawHeight = 32, uint8_t rawWidth = 128){ };
        void InitialiserAffichage(int hauteur);
        void AfficherSaisie(byte nombreCaracteres = 0);
        void AfficherDeverrouillage(bool ouverture = false);
        void AfficherModification();

        //Pour les fonctionnalités de veille
        void EffacerEcran();
        
    private:  
        String enTete = "Saisissez votre code";
};