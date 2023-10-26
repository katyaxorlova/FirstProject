Ši programa skaičiuoja studentų galutinį vidurkį ir medianą Galutinis balas skaičiuojamas pagal formule - Galutinis = 0.4 * vidurkis + 0.6 * egzaminas 

Nuskaitymas
Vartotojas renkasi ar nori įvesti duomenis iš file ar įvesti ranka. Ranka gali pasrinkti ar nori duomenis suvesti pats ar nori kad programa jam sugeneruotu atsitiktinius duomenis. Pasirinkus duomenu įvedimą iš file, vartotojas pasirenka kokio dydžio nori sugeneruotą duomenų file. 

Rezultate duomenys yra išvedami į du failus - durni.txt ir protingi.txt. Kiekvienas studentas gavęs pažymį mažesnį už 5 patenka i file durnti.txt, likę studentai patenka į file protingi.txt. Prtigrama taip pat matuoja kokiu greiču duomenys nuskaitomi, rūšiuojami ir spausdinami.

Grečio analizė - 
Konteineris vector:                                    

|              |   1000   |  10000   | 1000000 | 
| ------------ | -------- | -------- | ------- |
| Nuskaitymas  | 0.027 s  | 0.083 s  | 0.726 s | 
| Rūšiavimas   | 0 s      | 0.006 s  | 0.046 s | 
| Bendras      | 0.027 s  | 0.089 s  | 0.772 s | 


Konteineris list:                                    

|              |   1000   |  10000   | 1000000 | 
| ------------ | -------- | -------- | ------- |
| Nuskaitymas  | 0.035 s  | 0.086 s  | 0.733 s | 
| Rūšiavimas   | 0 s      | 0.011 s  | 0.058 s | 
| Bendras      | 0.035 s  | 0.097 s  | 0.791 s | 

