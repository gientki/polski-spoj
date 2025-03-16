#include <iostream>
#include <iomanip>   
#include <cmath>

using namespace std;

unsigned long long sil(int x)
{
		if(x == 0)
			return 1;
		else 
			return 	x*sil(x-1);
}
int main()
{
	int n,ile,z,d;
	cin>>ile;
	int *t = new int [ile];

	for(int i=0;i<ile;i++)
	{	
		z=1;
		d=10;
		cin>>n;
		while(sil(n)%d == 0)
		{
			d*=10;
			z++;
		}		
		t[i] = z-1;	
//		cout<<t[i];
	}
	for(int i=0;i<ile;i++)
	cout<<t[i]<<endl;
	return 0;
}
