# SystemeEmbarqueTPSessionChristophe
    Projet de session Systèmes embarqués
    Expérimentations sur l'utilisation des classes et d'un écran Oled (avec un bouton) sur un ESP32
    @file main.cpp
    @author Christophe Ferru
    @version 2.0 23 Avril 2021
    
    Historique des versions       :
      Versions  Date          Auteur      Description
      0.1       12 Avril 21   Chris       Mise en place des fichiers de base
	    0.2		    19 Avril 21   Chris		   Reinitialisation du fichier main
      0.3       20 Avril 21   Chris       Mise en place de l'algorythme principal
      0.4       21 Avril 21   Chris       Mise en place de l'anneau de Dels
      1.0       23 Avril 21   Chris       Premier version stable
      2.0       23 Avril 21   Chris       Sécurisation du changement de code pin
                            
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
			GPIO 14
		Clavier		v1.0	Interface le clavier
			GPIO 0, 2, 4, 5, 15, 16,17 et 18
		Ecran		v1.0	Interface l'écran Del
			Résolution 128 x 64
            Protocole I2C, Adresse: 0x3C 
            GPIO 21                : SDA
            GPIO 22                : SCL
		Code		v1.0	Gestion du code PIN
			Controle et modification du code