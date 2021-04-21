#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 14

class Anneau{
    public:
        Adafruit_NeoPixel pixels = Adafruit_NeoPixel(nbrPixels, PIN, NEO_GRB + NEO_KHZ800);

        Anneau(){} ;
        void Initialiser();
        void EteindreDel();
        void AllumerDel();
        void FaireTournerAnneau();
        void TraiterRegistre(int delAAllumer, int rouge, int vert, int bleu);
        void AllumerDelRegistre(int rouge, int vert, int bleu);
        void ReinitialiserRegistre();
        int GetRegistre();

    private:
        int nbrPixels = 8; // NeoPixel ring size
        int delais = 5; // Time (in milliseconds) to pause between pixels
        int registre = 0xff; // abcd efgh a: premier Del, b: second del, c: troisieme del, d: quatrieme del, e: cinquième del, f: sixième Del, g: septième Del, h: huitième Del 
};