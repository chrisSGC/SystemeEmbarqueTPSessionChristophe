#include <iostream>
using namespace std;

class Code{
    public:
        int nombreCaracteres;
        Code();
        bool VerifierCode();
        int EntrerCaractere(char nouveauCaractere);
        void ReinitialiserSaisie();
        void ModifierCode();
    
    private:
        string code;
        string chaineSaisie;
};