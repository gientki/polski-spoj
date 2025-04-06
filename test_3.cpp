#include<iostream>
#include <vector>

using namespace std;

bool spr(vector <int> wektor)
{
    int czyT=0;
    for(int i=1;i<wektor.size();i++)
    {
        if(wektor[i]==42 && wektor[i-1]!=42)
            czyT++;
    }
    if(czyT==3) 
        return true;

    return false;
}

int main()
{
    vector <int> wektor;
    int x;
    for(int i=0;i<i+1;i++)
    {
        cin>>x;
        wektor.push_back(x);
     
        if(spr(wektor))
           break;
    }
    for(int i=0;i<wektor.size();i++)
        cout<<wektor[i]<<endl;
    return 0;
}