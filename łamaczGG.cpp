#include <iostream>
#include <string>

using namespace std;

int main() {
    string kod;
    cin >> kod;
    int dlugoscKodu = kod.length();
    string tablicaZnakow = "ABCDEFGHIJKLMNOP";
    int tablicaWartosciPierwszegoZnakuWparze[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int tablicaWartosciDrugiegoZnakuWparze[] = {0,16,32,48,64,80,96,112,128,144,160,176,192,208,224,240};
    
    if (dlugoscKodu % 2 != 0) {
        cerr << "Błąd: Długość kodu musi być parzysta." << endl;
        return 1; 
    }

    for (int i = 0; i < dlugoscKodu; i += 2) {
        int wartoscPierwszegoZnaku = 0, wartoscDrugiegoZnaku = 0;
        bool znalezionoPierwszyZnak = false, znalezionoDrugiZnak = false;
        
        for (int k = 0; k < 16; k++) {
            if (kod[i] == tablicaZnakow[k]) {
                wartoscPierwszegoZnaku = tablicaWartosciPierwszegoZnakuWparze[k];
                znalezionoPierwszyZnak = true;
                break;
            }
        }
        
        for (int p = 0; p < 16; p++) {
            if (kod[i + 1] == tablicaZnakow[p]) {
                wartoscDrugiegoZnaku = tablicaWartosciDrugiegoZnakuWparze[p];
                znalezionoDrugiZnak = true;
                break;
            }
        }
        
        if (!znalezionoPierwszyZnak || !znalezionoDrugiZnak) {
            cerr << "Błąd: Niewłaściwe znaki w kodzie." << endl;
            return 1;
        }

        int sumaWartosciDwochZnakow = wartoscPierwszegoZnaku + wartoscDrugiegoZnaku;

        cout << (char)sumaWartosciDwochZnakow;
    }
    cout << endl;

    return 0;
}
