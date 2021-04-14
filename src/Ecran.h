//Pour la gestion de l'écran
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

        //Pour les fonctionnalités de veille
        void MettreEnVeille();
        
    private:  
        String enTete = "Saisissez votre code";
};