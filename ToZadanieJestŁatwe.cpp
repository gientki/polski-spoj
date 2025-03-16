#include<iostream>

using namespace std;

int main()
{
	int n;
	string s1,s2;
	cin>>n;
	string *tab = new string [n];
	for(int i=0;i<n;i++)
	{
		cin>>s1>>s2;
		int j = 0;
		for(int i=0;i<s1.length();i++)
			{
				if(s1[i] == s2[j])
				j++;
			}
			//cout<<j<<endl;
		
		if(j == s2.length())
			tab[i] = "Tak";
		else
			tab[i] = "Nie";
	}
	for(int i=0;i<n;i++)
		cout<<tab[i]<<endl;
	return 0;

}
