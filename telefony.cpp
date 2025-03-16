#include<iostream>

using namespace std;
int jakaLiczba(char litera)
{
	int tab[26];
	int numer=2;
	for(int i=0;i<26;i++)	{	
			tab[i] = numer;
		if((i+1)%3 == 0)
		numer++;
	}
	tab[25] = 9;
	tab[18] = 7;
	tab[21] = 8;
	tab[24] = 9;
	return tab[litera-65];
}
int main()
{
	int n;
	cin>>n;
	string* wyraz = new string[n];
	for(int i=0;i<n;i++)
			cin>>wyraz[i];

	for(int i=0;i<n;i++)	{
		for(int j=0;j<wyraz[i].length();j++)
				cout<<jakaLiczba(wyraz[i][j]);
	cout<<endl;}
	return 0;
}
