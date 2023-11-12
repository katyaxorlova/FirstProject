#include "funkcijos_list.h"

int main()
{
    list <studentas> St;
    list <studentas> Vargsai;
    list <studentas> Genijai;
    string failas = "";
    srand(time(0));
    cout << "Ar norite duomenis ivesti patys (kitu atveju duomenys bus nuskaityti is failo)? (t/n) ";
    if(patvirtinimas()) pagalbine(St);
    else {
         generavimas(pasirinkimas(), failas);
         nuskaitymas(St, failas);
    }
    vidMed(St);
    cout << "Ar norite studentu rusiavima vykdyti 1 - aja strategija (kitu atveju bus vykdoma 2 - oji strategija)? (t/n) ";
    if(patvirtinimas()) {
        skirstymas1(St, Vargsai, Genijai);
        spausdinimas(Vargsai, "vargsai.txt");
        spausdinimas(Genijai, "genijai.txt");
    }

    else {
        cout << "Ar norite naudoti optimizuota strategija (kitu atveju bus naudojama neoptimizuota strategija)? (t/n) ";
        if(patvirtinimas()) skirstymas2(St, Genijai);
        else skirstymas3(St, Genijai); //neoptimizuotas
        spausdinimas(St, "vargsai.txt");
        spausdinimas(Genijai, "genijai.txt");
    }
    St.clear();
    Vargsai.clear();
    Genijai.clear();
}


