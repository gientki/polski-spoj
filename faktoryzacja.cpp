#include<iostream>
#include<cmath>
#include<vector>

using namespace std;
string iloczynPlus(int x)
{
    return ;
}
void sito(int x)
{
    int dzielniki;
    string iloczyn = "";
    std::vector<int> tablica;

    for(int i=x;i>0;i--)
    {
        dzielniki = 0;
        for(int j=i;j>0;j--)
        {
            if(i%j==0)
                dzielniki++;
        }
        if(dzielniki == 2)
            tablica.push_back(i);
    }

    for(int i=tablica.size()-1;i>=0;i--)
    {
        while(x%tablica[i]==0)
        {
            iloczyn += iloczynPlus(tablica[i]);
            iloczyn += '*';
            cout<<tablica[i]<<' ';
            x/=tablica[i];
        }
    }
    cout<<iloczyn<<endl;  
    iloczyn = "";    
    
}

int main()
{
    int k,x;
    cin>>k;
    string *tab = new string [k];
    for(int i=0;i<k;i++)
    {
        cin>>x;
        sito(x);
    }
    return 0;
}