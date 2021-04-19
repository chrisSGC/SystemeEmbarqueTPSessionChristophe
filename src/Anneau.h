#include <Adafruit_NeoPixel.h>

class Anneau{
    public:
        Adafruit_NeoPixel pixels = Adafruit_NeoPixel(nbrPixels, pin, NEO_GRB + NEO_KHZ800);

        Anneau(){}
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
        int delais = 100; // Time (in milliseconds) to pause between pixels
        int pin = 14; // Which pin on the Arduino is connected to the NeoPixels?
        int registre = 0xff; // abcd efgh a: premier Del, b: second del, c: troisieme del, d: quatrieme del, e: cinquième del, f: sixième Del, g: septième Del, h: huitième Del 
};