/*******************************************

Emīls Lipšāns, el20054

C28. Naturālam skaitlim n atrast visus skaitļu a(1..n) trijniekus, kuri veido trījstūrus un aprēķināt to laukumus.

*******************************************/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool der(int x, int y, int z) {

    if (x + y > z && x + z > y && y + z > x) return true;       // Funkcija pārbauda vai ievadītie skaitļi var izveidot trijstūri.
    else return false;

}

double herona(double a, double b, double c) {               // Funkcija aprēķina 3 taišņu veidotā trijstūra laukumu.

    double p, S;
    p = (a + b + c) / 2;
    S = sqrt(p * (p - a) * (p - b) * (p - c));
    return S;
}

int main()
{
                             
    int n=0, v;
    int x, y, z;   
    int ok;
    int atk;                                        // Mainīgais tiek izmantots vērtību atkārtošanās noteikšanai (for ciklā 69-78 rindiņā).
    int taisnes[1000];
    int k, daudz;                                   // Masīva "taisnes" vērtības - k, mainīgais "daudz" tiek izmantots, lai pierakstītu masīva "taisnes" izmantoto vietu daudzumu.


    do
    {
        vector<int>mas;
        cout << "Ievadiet naturalu skaitli" << endl;
        fill_n(taisnes, 1000, 0);                           // Pēc programmas atkārtojuma nomaina vecās masīva vērtības uz 0.                             
       
        x = y = z = k = daudz = atk = 0;
        cin >> n;
        if (n > 2) {
            cout << "Ievadiet " << n << " nogriznus" << endl;
            for (int i = 0; i < n; i++) {
                cin >> v;               
                mas.push_back(v);                           
            }
            for (int a = 0; a < n; a++) {                                   // Cikls izveido visas iespējamās x,y,z kombinācijas un pārbauda vai tās atbilst nosacījumam (x + y > z && x + z > y && y + z > x).
                x = mas[a];
                for (int b = a+1; b < n; b++) {
                    y = mas[b];
                    for (int c = b+1; c < n; c++) {
                        z = mas[c];

                        if (der(x, y, z)) {
                            atk = 0;
                            for (int k = 0; k < daudz + 1; k += 3) {

                                if ((x == taisnes[k] and y == taisnes[k + 1] and z == taisnes[k + 2]) ||
                                    (x == taisnes[k] and z == taisnes[k + 1] and y == taisnes[k + 2]) ||                                 //Pārbauda vai skaitļu kombinācijas neatkārtojas citā secībā. Piemēram(1,1,2 vai 2,1,1).
                                    (y == taisnes[k] and z == taisnes[k + 1] and x == taisnes[k + 2]) ||
                                    (y == taisnes[k] and x == taisnes[k + 1] and z == taisnes[k + 2]) ||
                                    (z == taisnes[k] and x == taisnes[k + 1] and y == taisnes[k + 2]) ||
                                    (z == taisnes[k] and y == taisnes[k + 1] and x == taisnes[k + 2])) atk += 1;
                                if (atk != 0) break;
                            }
                            if (atk == 0) {                                                                                      // Ja skaitļu kombinācija nav tikusi izmantota to izvada un aprēķina trijstūra laukumu.
                                cout << "Nogriezniem " << x << " " << y << " " << z << endl;
                                cout << "Trijstura laukums ir " << herona(x, y, z) << endl;

                                k = daudz;
                                taisnes[k] = x;                                                                                      // Izmantotās vērtības saglabā masīvā, lai spētu novērst atkārtošanos.
                                taisnes[k + 1] = y;
                                taisnes[k + 2] = z;
                                daudz += 3;
                            }

                        }
                    }
                }
            }
            if (daudz == 0) cout << "Ievaditie nogriezni nevar izveidot trijsturi." << endl;
        }
        else cout << "Ievaditais skaitlis ir mazaks par 3, nav iespejams izveidot trijsturi." << endl;
        
                    

     cout << " Vai turpinat (1) vai beigt (0)?" << endl;
     cin >> ok;             
     
    } while (ok == 1);
   
}


/**************************************************** Testu plāns **********************************************
 Ievads n                    Ievads nogriežņi                           Rezultāts                     

 5                           1;2;3;4;5                                  Nogriezniem 2 3 4
                                                                        Trijstura laukums ir 2.90474
                                                                        Nogriezniem 2 4 5
                                                                        Trijstura laukums ir 3.79967
                                                                        Nogriezniem 3 4 5
                                                                        Trijstura laukums ir 6


3                            3;3;5                                      Nogriezniem 3 3 5
                                                                        Trijstura laukums ir 4.14578

3                            2;9;11                                     Ievaditie nogriezni nevar izveidot trijsturi.    

2                            -                                          Ievaditais skaitlis ir mazaks par 3, nav iespejams izveidot trijsturi.
                    

 
*****************************************************************************************************************/