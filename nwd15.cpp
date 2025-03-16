#include <iostream>
#include <cmath>

using namespace std;
char minusOne(char x)
{
	int n = (int)x;
	return char(n - 1);
}
string ciach(string x,int Do)
{
	string y="";
	
	for(int i=0;i<Do;i++)
		y+=x[i];
	
	return y;
}
string decrem(string x)
{
		//cout<<x<<" - "<<x.length()<<endl;
	if(x[x.length()-1] == '0')
		x = decrem(ciach(x,x.length()-1))+'9';
	else
		x = ciach(x,x.length()-1) + minusOne(x[x.length()-1]);
	
	if(x[0] == '0')
		x = ciach(x,x.length());
	
	return x;
}
bool mod3(string x)
{
	unsigned long long t=0;
	for(int i=0;i<x.length();i++)
		t+=((int)x[i]-48) * pow(10,x.length()-i-1);
	
	if(t%3==0)
		return true;
	else 
		return false;
}
int main()
{
	int ile;
	string n;
	cin>>ile;
	
	string *tab = new string [ile];
	for(int i=0;i<ile;i++)
	{
		cin>>n;
		if(n=="0") 
			cout<<0<<endl;
		else
		for(int i=0;i<15;i++)
		{
			if(n[n.length()-1] == '0' || n[n.length()-1] == '5')
				if(mod3(n))	
					tab[i] = n;
			
			n = decrem(n);
		} 			
	}
	for(int i=0;i<ile;i++)
		cout<<tab[i]<<endl;
	
	return 0;
}
