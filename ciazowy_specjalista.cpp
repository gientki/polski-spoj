#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int x,y,z,d;
	float C;
	
	cin>>d;
	int *tab = new int [d];
	for(int i=0;i<d;i++)
	{
		cin>>x>>y>>z;
		C = -1*y*z;
		//cout<<D<<endl;
		C=C+x+y;
		//cout<<D+x+y<<endl;
		C/=(z-1);
		
		C*=-12;
		
		tab[i]=round(C);
	}
	
	for(int i=0;i<d;i++)
		cout<<tab[i]<<endl;
	return 0;
}
/*Matka jest o X lat starsza od swojego dziecka. 
Za Y lat dziecko będzie Z razy młodsze od matki*/
