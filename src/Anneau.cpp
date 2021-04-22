#include <Anneau.h>

/**
 * Méthode qui permet:
 * 1/ D'initialiser l'anneau de Del
 * 2/ Réinitialiser le registre à 0
 * */
void Anneau::Initialiser(){
    pixels.begin();
    ReinitialiserRegistre();
}

int Anneau::GetRegistre(){
    return registre;
}

/**
 * Méthode qui remet le registre à 0
 * */
void Anneau::ReinitialiserRegistre(){
    registre = 0b00000000;
}

/**
 * Méthode qui permet de couper toutes les Del
 * */
void Anneau::EteindreDel(){
    pixels.clear();
}

/**
 * Méthode qui permet d'allumer des Del pour lesquelles une couleur a été définie
 * */
void Anneau::AllumerDel(){
    pixels.show(); // Envoi la couleur définie à l'anneau
}

/**
 * On défini la couleur de toutes les Del sur "off"
 * */
void Anneau::TraiterRegistre(int delAAllumer){
    registre = registre | delAAllumer;
    
}

void Anneau::AllumerDelSaisie(int nombreCaracteres){
    if(nombreCaracteres == 1){ AllumerDelRegistre(0b11000000, 25, 25, 0); }
    else if(nombreCaracteres == 2){ AllumerDelRegistre(0b11110000, 25, 25, 0); }
    else if(nombreCaracteres == 3){ AllumerDelRegistre(0b11111100, 25, 25, 0); }
    else if(nombreCaracteres == 4){ AllumerDelRegistre(0b11111111, 25, 25, 0); }
}

/**
 * On va définir les Del à allumer en fonction du registre.
 * 
 * On a découpé en 4 blocs nos Dels afin de signifier visuellement à l'utilisateur le nombre de chiffres entrés dans son code
 * 
 * La procédure est simple:
 * Chaque condition correspond à un bloc.
 * On vérifie donc le registre pour chacun des blocs. Si il y a concordance, on pose la couleur sur jaune.
 * 
 * Enfin, on allume les Del qui doivent l'être
 * */
void Anneau::AllumerDelRegistre(int delAAllumer,int rouge, int vert, int bleu){
    TraiterRegistre(delAAllumer);
    EteindreDel();

    if( 0 != (registre & 0b10000000)){ pixels.setPixelColor(7, pixels.Color(rouge, vert, bleu)); }
    if( 0 != (registre & 0b01000000)){ pixels.setPixelColor(6, pixels.Color(rouge, vert, bleu)); }
    if( 0 != (registre & 0b00100000)){ pixels.setPixelColor(5, pixels.Color(rouge, vert, bleu)); }
    if( 0 != (registre & 0b00010000)){ pixels.setPixelColor(4, pixels.Color(rouge, vert, bleu)); }
    if( 0 != (registre & 0b00001000)){ pixels.setPixelColor(3, pixels.Color(rouge, vert, bleu)); }
    if( 0 != (registre & 0b00000100)){ pixels.setPixelColor(2, pixels.Color(rouge, vert, bleu)); }
    if( 0 != (registre & 0b00000010)){ pixels.setPixelColor(1, pixels.Color(rouge, vert, bleu)); }
    if( 0 != (registre & 0b00000001)){ pixels.setPixelColor(0, pixels.Color(rouge, vert, bleu)); }

    AllumerDel(); // On allume les Del pour lesquelles une couleur est définie
}

/**
 * Methode qui permet de simuler une rotation de l'anneau
 * 
 * 1/ on éteind toutes les del allumées
 * 2/ On fait une boucle pour chaque Del de l'anneau (nbrPixels)
 * --- a/ On défini la couleur de la led sur bleu
 * --- b/ On allume la del en question
 * --- c/ On laisse un délais défini dans le .h (par défaut 100ms)
 * --- d/ On éteind tout l'anneau avant de passer dans la prochaine étape de la boucle
 * */
void Anneau::FaireTournerAnneau(){
  EteindreDel();

  for(int i = nbrPixels; i >= 0; i--) {
    // pixels.Color() prend l'index de la Del a allumer (i ici) et une valeur RVB allant de 0,0,0 à 255,255,255
    // Ici on défini un bleu léger afin de ne pas éblouir les utilisateurs
    pixels.setPixelColor(i, pixels.Color(0, 0, 25));

    AllumerDel();
    delay(1);
    EteindreDel();
  }
    EteindreDel();
}