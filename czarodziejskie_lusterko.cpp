#include<iostream>
#include<cmath>


using namespace std;

string odwrBinarka(unsigned long long x)
{
	string bin;
	
	while(x>=1)
	{
		if(x%2 == 1)
			bin+='1';
		else
			bin+='0';
		
		x=x/2;
	}
	
	return bin;
}
unsigned long long dz(string bin)
{
	unsigned long long x=0;
	unsigned long long j=0;
	
	for(int i=bin.length()-1;i>=0;i--)
		{
			if(bin[i]=='1')
				x+=pow(2,j);
			
			j++;
		}
	
	return x;
}
int main()
{
	unsigned long long x;
	while(cin>>x)
		cout<<dz(odwrBinarka(x))<<endl;
	return 0;
}
