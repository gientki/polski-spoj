#include<iostream>
#include<cmath>

using namespace std;

float d(int x,int y,int X,int Y)
{
	X-=x;
	Y-=y;
	Y*=Y;
	X*=X;
	return sqrt(X+Y);
}

int main()
{
	int X,Y,x,y,r,n;
	
	cin>>x>>y>>r;
	cin>>n;
	char *t = new char [n];
	for(int i=0;i<n;i++)
	{
		cin>>X>>Y;
		
		if(d(x,y,X,Y)<r)
			t[i] = 'I';
		else if(d(x,y,X,Y)>r)
			t[i] = 'O';
		else 
			t[i] = 'E';
	}
	for(int i=0;i<n;i++)
		cout<<t[i]<<endl;
	return 0;
}
