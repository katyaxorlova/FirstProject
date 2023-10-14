#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <numeric>
#include <stdio.h>     
#include <stdlib.h>    
#include <time.h> 
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string; 
using std::stoi;
using std::setw;
using std::setprecision;
using std::sort;
using std::left;
using std::fixed;

struct studentas 
{
    string vard;
    string pavard;
    int nd[1000];
    int egz;
    float glt;
    int n;
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
int suma(int nd[], int n);
//skaiciuoja vidurki
float vidurkis(int nd[], int n);
//skaiciuoja mediana
float mediana(int nd[], int n);
//skaiciuoja galutini bala
float galutinis(float, int egz);
//sugeneruoja atsitiktinius duomenis
int atsitiktiniai();
//randa ilgiausia studento pavarde
int ilgPavarde(studentas St[], int ilgis);
//randa ilgiausia studento varda
int ilgVardas(studentas St[], int ilgis);
//duomenu spausdinimui skirta funkcija
void spausdinimas(studentas St[], int ilgis);
//pagalbine funkcija
void pagalbine(studentas St[], int &ilgis);
//tikrina pasirinkima (t/n) - taip/ne
bool patvirtinimas();

int main()
{
    studentas St[100];
    int ilgis = 0;
    srand(time(0));
    pagalbine(St, ilgis);
    spausdinimas(St, ilgis);
 
}

void pagalbine(studentas St[], int &ilgis)
{
    ilgis;
    int n;

    do
    {
        St[ilgis].vard = vardIvedimas("varda");
        St[ilgis].pavard = vardIvedimas("pavarde");
        cout << "Ar norite pazymius ivesti patys (kitu atveju jie bus sugeneruoti atsitiktinai)? (t/n) ";
        if(patvirtinimas())
        {
        cout << "Ar norite ivesti pazymiu kieki (t/n)? ";
        if(patvirtinimas())
        {
            int n = skIvedimas("pazymiu kieki", false);

            for(int j = 0; j < n; j++)
            {
                St[ilgis].nd[j] = skIvedimas("pazymi", true);
            }
        }
        else
        {
            n = 0;

            do
            {
                St[ilgis].nd[n] = skIvedimas("pazymi", true);
                cout << "Ar norite ivesti dar viena pazymi (t/n)? ";
                n++;
            } while(patvirtinimas());
            
        }  
        }
        else
        {
            n = skIvedimas("pazymiu kieki", false);

            for (int j = 0; j < n; j++) St[ilgis].nd[j] = atsitiktiniai();
            cout << "Atsitiktinai sugeneruoti pazymiai: ";

            for (int j = 0; j < n - 1; j++) cout << St[ilgis].nd[j] << ", ";
            cout << St[ilgis].nd[n - 1] << "." << endl;
        }

        cout << "Ar norite egzamino bala suvesti patys (kitu atveju jis bus sugeneruotas atsitiktinai)? (t/n) ";
        if(patvirtinimas())
        {
            St[ilgis].egz = skIvedimas("egzamino pazymi", true);
        }
        else
        {
            St[ilgis].egz = atsitiktiniai();
            cout << "Sugeneruotas egzamino balas: " << St[ilgis].egz << endl;

        }
        St[ilgis].glt = 0;
        St[ilgis].n = n;
        cout << "Ar norite ivesti dar vieno studento duomenis? (t/n) ";
        ilgis++;
    } while(patvirtinimas());

    cout << "Ar norite apskaiciuoti vidurki (kitu atveju bus skaiciuojama mediana)? (t/n) ";

    if(patvirtinimas())
    { 
        for(int j = 0; j < ilgis; j++)
        {
            St[j].glt = galutinis(vidurkis(St[j].nd, St[j].n), St[j].egz);
        }
    }
    else
    {
        for(int j = 0; j < ilgis; j++)
        {
            St[j].glt = galutinis(mediana(St[j].nd, St[j].n), St[j].egz);
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

int suma(int nd[], int n) 
{
    int sum = 0;

    for (int i = 0; i < n; i ++) 
    {
        sum += nd[i];
    }

    return sum;
}

float vidurkis(int nd[], int n)
{

    float vid = suma(nd, n) / n;

    return vid;
}

float mediana(int nd[], int n)
{
    float median;

    sort(nd, nd + n);

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

int ilgPavarde(studentas St[], int ilgis)
{
    int max = 0;
    
    for(int i = 0; i < ilgis; i++)
    {
        if(St[i].pavard.length() > max)
        max = St[i].pavard.length();
    }

    return max;
}

int ilgVardas(studentas St[], int ilgis)
{
    int max = 0;
    
    for(int i = 0; i < ilgis; i++)
    {
        if(St[i].vard.length() > max)
        max = St[i].vard.length();
    }

    return max;
}


void spausdinimas(studentas St[], int ilgis)
{
    string pnktr = "";
    int maxpavard = ilgPavarde(St, ilgis);
    int maxvard = ilgVardas(St, ilgis);
    pnktr.append(maxpavard + maxvard + 30, '-'); 
    cout << left << setw(maxpavard + 10) << "Pavarde" << setw(maxvard + 10) << "Vardas" << "Galutinis" << endl; 
    cout << pnktr << endl;

    for(int i = 0; i < ilgis; i++)
    {
        cout << left << setw(maxpavard + 10) << St[i].pavard << setw(maxvard + 10) << St[i].vard << fixed << setprecision(2) << St[i].glt << endl;

    }
}
