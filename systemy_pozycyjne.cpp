#include<iostream>
#include<string>

using namespace std;

string odwracanko(string wyraz)
{
    string odwr;
    for(int i=wyraz.length()-1; i>=0; i--)
        odwr += wyraz[i];
    return odwr;
}

string sys(unsigned int x, int s)
{
    char tab[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    string wynik = "";
    while (x > 0)  
    {
        wynik += tab[x % s];
        x /= s;
    }
    
    return odwracanko(wynik);
}

int main()
{
    int n;
    unsigned int x;
    
    cin >> n;
    
    int *tab = new int[n];
    
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        tab[i] = x;
    }
    
    for(int i = 0; i < n; i++)
        cout << sys(tab[i],16) << ' ' << sys(tab[i], 11) << endl;
    
    delete[] tab;  // Zwolnij zaalokowaną pamięć
    
    return 0;
}

