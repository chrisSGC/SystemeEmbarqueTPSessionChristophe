/**
    Projet de session Systèmes embarqués
    Expérimentations sur l'utilisation des classes et d'un écran Oled (avec un bouton) sur un ESP32
    @file main.cpp
    @author Christophe Ferru
    @version 0.1 12 Avril 2021
    
    Historique des versions:
      Versions  Date          Auteur      Description
      0.1       12 Avril 21   Chris       Mise en place des fichiers de base
                            
    platform: espressif32
    board: esp32doit-devkit-v1
    framework: arduino
    lib_deps:
      adafruit/Adafruit GFX Library @ ^1.10.1     (Pour la classe MyOled)
      adafruit/Adafruit SSD1306 @ ^2.4.0          (Pour la classe MyOled)
      adafruit/Adafruit NeoPixel @ ^1.7.0         (Pour la classe MyOled)

    Autres librairies (à copier dans le répertoire lib)
      Aucune
    Classes du système:
        MyOled      V1.0    Pour interfacer le Oled
            Résolution 128 x 64
            Protocole I2C, Adresse : 0x3C 
            GPIO21 : SDA
            GPIO22 : SCL
**/

// Includes généraux
#include <Arduino.h>

//Classe MyOled 
#include <wire.h>
#define SCREEN_WIDTH 128        // OLED display width, in pixels
#define SCREEN_HEIGHT 64        // OLED display height, in pixels
#define OLED_RESET 4            // Reset pin # (or -1 if sharing Arduino reset pin)
#define OLED_I2C_ADDRESS 0x3C   // Adresse I2C de l'écran Oled
#include "MyOled.h"
MyOled *ecranDels = NULL;

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}