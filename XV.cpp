#include<iostream>
#include<vector>

using namespace std;

bool czyliczbajestpodzielnaprzeztrzy(string liczba)
{
    int x=0;
    
    for(int i=0;i<liczba.length();i++)
    {
        x+= liczba[i] - '0';
    
    }
    return (x%3==0) ? true : false;
}

int main()
{
    vector < string > wektor;
    string liczba;
    int x;
    while (cin >> liczba && liczba != "0") 
    {
        if(czyliczbajestpodzielnaprzeztrzy(liczba))
        {
            if(liczba[liczba.length()-1]=='0')
                wektor.push_back("TAK");
            else if(liczba[liczba.length()-1]=='5')
                wektor.push_back("TAK");
            else
                wektor.push_back("NIE");
        }
        else    
            wektor.push_back("NIE");
    }
    for(int i=0;i<wektor.size();i++)
        cout<<wektor[i]<<endl;

    
    return 0;
}