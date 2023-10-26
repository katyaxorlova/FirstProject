#include "funkcijos.h"

int main()
{
    vector <studentas> St;
    vector <studentas> Genijai;
    string failas = "";
    srand(time(0));
    cout << "Ar norite duomenis ivesti patys (kitu atveju duomenys bus nuskaityti is failo)? (t/n) ";
    if(patvirtinimas()) pagalbine(St);
    else {
        generavimas(pasirinkimas(), failas);
        nuskaitymas(St, failas);
    }
    vidMed(St);
    skirstymas(St, Genijai);
    spausdinimas(St, "vargsai.txt");
    spausdinimas(Genijai, "genijai.txt");
    St.clear();
    Genijai.clear();
}
//    ./myprogram



