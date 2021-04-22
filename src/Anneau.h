/**
    Classe Anneau qui gere l'anneau  en se basant sur les methodes de la librairie Adafruit_NeoPixel déclarée en tant que propriété
    @file Anneau.h
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
        Adafruit_NeoPixel
**/
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 14

class Anneau{
    public:
        // Propriété pixels correspondant à une instance de la librairie neopixel
        Adafruit_NeoPixel pixels = Adafruit_NeoPixel(nbrPixels, PIN, NEO_GRB + NEO_KHZ800);

        // Methodes publiques de la classe
        Anneau(){} ;
        void Initialiser();
        void EteindreDel();
        void AllumerDel();
        void FaireTournerAnneau();
        void TraiterRegistre(int delAAllumer);
        void AllumerDelRegistre(int delAAllumer,int rouge, int vert, int bleu);
        void AllumerDelSaisie(int nombreCaracteres);
        void ReinitialiserRegistre();
        int GetRegistre();

    private:
        int nbrPixels = 8; // NeoPixel ring size
        int delais = 5; // Time (in milliseconds) to pause between pixels
        int registre = 0xff; // abcd efgh a: premier Del, b: second del, c: troisieme del, d: quatrieme del, e: cinquième del, f: sixième Del, g: septième Del, h: huitième Del 
};