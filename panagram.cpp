#include<iostream>
#include<cstdlib>

using namespace std; 

int main()
{
	int max=0;
	string wynik = "PANGRAM PERFEKCYJNY";
	unsigned int *t = new unsigned int [26];
	string wyraz;
	
	for(int i=0;i<26;i++)
		t[i]=0;
		
	cin>>wyraz;
	
	for(int i=0;i<wyraz.length();i++)
		t[wyraz[i]-97]++;
	
	//for(int i=0;i<24;i++)
	//	cout<<i<<'-'<<t[i]<<'-'<<char(i+97)<<endl;
		
	for(int i=0;i<26;i++)
		if(t[i]>max)
			max = t[i];
	
	for(int i=0;i<26;i++)
		if(t[i] != max)
			wynik = "PANGRAM";
			
	for(int i=0;i<26;i++)
		if(t[i]==0)
			wynik = "NIE";
			
	cout<<wynik;
	
	return 0;
}
//26
//a-97
