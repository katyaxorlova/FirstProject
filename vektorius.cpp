#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>
#include <numeric>
#include <stdio.h>     
#include <stdlib.h>    
#include <time.h> 

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

struct studentas 
{
    string vard;
    string pavard;
    vector <int> nd;
    int egz;
    float glt;
};

//tikrina ar ivesta varda/pavarde sudaro tik raides
bool vardTikrinimas(string kint);
//ivedami duomenis, jei neteisingi - prasoma ivesti is naujo
string vardIvedimas(string ivedimas);
////tikrina ar ivestas skaicius
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
//skaiciuoja galutini bala
float galutinis(float, int egz);
//sugeneruoja atsitiktinius duomenis
int atsitiktiniai();
//randa ilgiausia studento pavarde
int ilgPavarde(vector <studentas> St);
//randa ilgiausia studento varda
int ilgVardas(vector <studentas> St);
//duomenu spausdinimui skirta funkcija
void spausdinimas(vector <studentas> St);
//pagalbine funkcija
void pagalbine(vector <studentas> &St);
//tikrina pasirinkima (t/n) - taip/ne
bool patvirtinimas();

int main()
{
    vector <studentas> St;
    srand(time(0));
    pagalbine(St);
    spausdinimas(St);
    St.clear();
}

void pagalbine(vector <studentas> &St)
{
    studentas S;

    do
    {
        S.vard = vardIvedimas("varda");
        S.pavard = vardIvedimas("pavarde");
        cout << "Ar norite pazymius ivesti patys (kitu atveju jie bus sugeneruoti atsitiktinai)? (t/n) ";
        if(patvirtinimas())
        {
        cout << "Ar norite ivesti pazymiu kieki (t/n)? ";
        if(patvirtinimas())
        {
            int n = skIvedimas("pazymiu kieki", false);
            for(int j = 0; j < n; j++)
            {
                S.nd.push_back(skIvedimas("pazymi", true));
            }
        }
        else
        {
            do
            {
                S.nd.push_back(skIvedimas("pazymi", true));
                cout << "Ar norite ivesti dar viena pazymi (t/n)? ";
            } while(patvirtinimas());
            
        }  
        }
        else
        {
            int n = skIvedimas("pazymiu kieki", false);

            for (int j = 0; j < n; j++) S.nd.push_back(atsitiktiniai());
            cout << "Atsitiktinai sugeneruoti pazymiai: ";

            for (int j = 0; j < n - 1; j++) cout << S.nd[j] << ", ";
            cout << S.nd[n - 1] << "." << endl;
        }

        cout << "Ar norite egzamino bala suvesti patys (kitu atveju jis bus sugeneruotas atsitiktinai)? (t/n) ";
        if(patvirtinimas())
        {
            S.egz = skIvedimas("egzamino pazymi", true);
        }
        else
        {
            S.egz = atsitiktiniai();
            cout << "Sugeneruotas egzamino balas: " << S.egz << endl;

        }
        S.glt = 0;
        St.push_back(S);
        S.nd.clear();
        cout << "Ar norite ivesti dar vieno studento duomenis? (t/n) ";
        
    } while(patvirtinimas());

    cout << "Ar norite apskaiciuoti vidurki (kitu atveju bus skaiciuojama mediana)? (t/n) ";

    if(patvirtinimas())
    { 
        for(int j = 0; j < St.size(); j++)
        {
            St[j].glt = galutinis(vidurkis(St[j].nd), St[j].egz);
        }
    }
    else
    {
        for(int j = 0; j < St.size(); j++)
        {
            St[j].glt = galutinis(mediana(St[j].nd), St[j].egz);
        }
    }
    
}

bool patvirtinimas()
{
    bool tiesa = true;
    bool laik = true;
    string tn;

    do
    {
        cin >> tn;
        if(tn.length() == 1 && (tolower(tn[0]) == 't' || tolower(tn[0]) == 'n'))
        {
            laik = true;
            if(tolower(tn[0]) == 't' )
            tiesa = true;
            else tiesa = false;
        }
        else 
        {
            cout << "Iveskite duomenis is naujo! ";
            laik = false;
        }
    } while(!laik);

    return tiesa;
}

bool vardTikrinimas(string kint) 
{
    bool teisingas = true;

    for (int i = 0; i < kint.length(); i++)
    {
        if (isalpha(kint[i]) == false)
        {
            teisingas = false;
            cout << "Klaida, varda/pavarde turi sudaryti tik raides" << endl;
            break;
        }
        else teisingas = true;
    }

    return teisingas;
}

string vardIvedimas(string ivedimas) 
{
    string kint;

    do 
    {
        cout << "Iveskite studento " << ivedimas << ": ";
        cin >> kint;
    } while (!vardTikrinimas(kint));

    return kint;
}

bool skKiekioTikrinimas(string laik)
{
    bool teisingas = true;

    for (int i = 0; i < laik.length(); i++) 
    {
        if (!isdigit(laik[i]) || stoi(laik) == 0)
        {
            teisingas = false;
            cout << "Klaida! Turite ivesti skaiciu (didesni uz nuli)"<<endl;
            break;
        }
    }

    return teisingas;
}

bool skTikrinimas(string laik) 
{
    bool teisingas = true;

    for (int i = 0; i < laik.length(); i++) 
    {
        if (!isdigit(laik[i]))
        {
            teisingas = false;
            cout << "Klaida! Turite ivesti skaiciu" << endl;
            break;
        }
        else if (teisingas == true && (stoi(laik) < 1 || stoi(laik) > 10))
        {
            teisingas = false;
            cout << "Klaida! Skaicius turi is intervalo [1-10]" << endl;
        }
        
    }

    return teisingas;
}

int skIvedimas(string ivedimas, bool tarpinis)
{
    string kint;
    bool laik;

    do 
    {
        cout << "Iveskite " << ivedimas << ": ";
        cin >> kint;
        if(tarpinis)laik = skTikrinimas(kint);
        else laik = skKiekioTikrinimas(kint);
    } while (!laik);

    int skaicius = stoi(kint);

    return skaicius;
}

int suma(vector <int> nd) 
{
    return accumulate(nd.begin(), nd.end(), 0);
}

float vidurkis(vector <int> nd)
{
    int n = nd.size();

    float vid = suma(nd) / n;

    return vid;
}

float mediana(vector <int> nd)
{
    float median;
    int n = nd.size();

    sort(nd.begin(), nd.end());

    if(n / 2 == 0)
    median = (nd[n/2] + nd[n/2 + 1])/2;
    else
    median = nd[n/2];

    return median;
}

float galutinis(float sum, int egz) 
{
    float glt = float(0.4 * sum) + 0.6 * egz;

    return glt;
}

int atsitiktiniai()
{
    int paz;
    paz = 1 + rand() % ((10 + 1) - 1);
    return paz;
}

int ilgPavarde(vector <studentas> St)
{
    int max = 0;
    int ilgis = St.size();
    
    for(int i = 0; i < ilgis; i++)
    {
        if(St[i].pavard.length() > max)
        max = St[i].pavard.length();
    }

    return max;
}

int ilgVardas(vector <studentas> St)
{
    int max = 0;
    int ilgis = St.size();
    
    for(int i = 0; i < ilgis; i++)
    {
        if(St[i].vard.length() > max)
        max = St[i].vard.length();
    }

    return max;
}


void spausdinimas(vector <studentas> St)
{
    int ilgis = St.size(); 
    string pnktr = "";
    int maxpavard = ilgPavarde(St);
    int maxvard = ilgVardas(St);
    pnktr.append(maxpavard + maxvard + 30, '-'); 
    cout << left << setw(maxpavard + 10) << "Pavarde" << setw(maxvard + 10) << "Vardas" << "Galutinis" << endl; 
    cout << pnktr << endl;

    for(int i = 0; i < ilgis; i++)
    {
        cout << left << setw(maxpavard + 10) << St[i].pavard << setw(maxvard + 10) << St[i].vard << fixed << setprecision(2) << St[i].glt << endl;

    }
}
