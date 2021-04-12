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

// Données concernant le clavier
#include <Keypad.h>
const byte LIGNES = 4; // On dispose de 4 lignes sur notre clavier donc cette constante sera de 4
const byte COLONNES = 4; // On dispose de 4 lignes, odnc la constante associée est de 4
char touches[LIGNES][COLONNES] = { {'1','2','3','A'}, {'4','5','6','B' }, {'7','8','9','C'}, {'*','0','#','D'} }; // Etant donné que l'on peut personnaliser les touches du clavier, il est necessaire de définir quelle touche correspond à quel caracteres. Dans le cadre du travail, les touches du clavier donneront bel et bien les memes informations qu'affichées dessus.
byte GPIOLignes[LIGNES] = {16, 17, 5, 18}; // Lien entre les lignes du clavier et les GPIO de notre ESP
byte GPIOColonnes[COLONNES] = {15, 2, 0, 4}; // Lien entre les colonnes du clavier et les GPIO de notre ESP

void setup() {
  Keypad clavier = Keypad( makeKeymap(touches), GPIOLignes, GPIOColonnes, LIGNES, COLONNES ); // On initialise notre clavier avec les données préalablement renseignées
}

void loop() {
  // put your main code here, to run repeatedly:
}