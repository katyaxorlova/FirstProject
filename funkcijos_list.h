#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>
#include <numeric>
#include <stdio.h>     
#include <stdlib.h>    
#include <time.h> 
#include <fstream>
#include <sstream>
#include <chrono>
#include <list>


static std::chrono::steady_clock::time_point pradzia;

using std::cout;
using std::cin;
using std::endl;
using std::string; 
using std::stoi;
using std::setw;
using std::setprecision;
using std::sort;
using std::vector;
using std::left;
using std::fixed;
using std::ifstream;
using std::stringstream; 
using std::ofstream;
using std::to_string;
using std::list;


struct studentas 
{
    string vard;
    string pavard;
    vector <int> nd;
    int egz;
    float glt;
};

struct lyginimasPavard{
    bool operator()(const studentas& a, const studentas& b){return(b.pavard.compare(a.pavard));}
};

//nuskaito duomenis is failo
void nuskaitymas(list <studentas> &St, string failas);
//tikrina ar ivesta varda/pavarde sudaro tik raides
bool vardTikrinimas(string kint);
//ivedami duomenis, jei neteisingi - prasoma ivesti is naujo
string vardIvedimas(string ivedimas);
//tikrina ar ivestas skaicius
bool skKiekioTikrinimas(string laik);
//tikrina ar ivestas skaicius/ar priklauso intervalui [1-10]
bool skTikrinimas(string laik);
//ivedami duomenis, jei neteisingi - prasoma ivesti is naujo
int skIvedimas(string ivedimas, bool);
//skaiciuoja suma
int suma(vector <int> nd);
//skaiciuoja vidurki
float vidurkis(vector <int> nd);
//skaiciuoja mediana
float mediana(vector <int> nd);
//pasirenka arba vidurki, arba mediana
void vidMed(list <studentas> &St);
//skaiciuoja galutini bala
float galutinis(float, int egz);
//sugeneruoja atsitiktinius duomenis
int atsitiktiniai();
//randa ilgiausia studento pavarde
int ilgPavarde(list <studentas> St);
//randa ilgiausia studento varda
int ilgVardas(list <studentas> St);
//duomenu spausdinimui skirta funkcija
void spausdinimas(list <studentas> St, string failas);
//pagalbine funkcija
void pagalbine(list <studentas> &St);
//tikrina pasirinkima (t/n) - taip/ne
bool patvirtinimas();
//isrikiuoja studentu pavardes
void rikiavimas(list <studentas> &St);
//generuoja failus
void generavimas(int sk, string &failas);
//leidzia pasirinkti kokio dydzio failas bus generuojamas
int pasirinkimas();
//ivedami duomenis, jei neteisingi - prasoma ivesti is naujo
int skIvedimas();
//tikrina generavimui ivesta skaiciu
bool skGenTikrinimas(string laik);
//isskirsto studentus pagal galutini bala
void skirstymas(list <studentas> &St, list <studentas> &Genijai);