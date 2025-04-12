#include<iostream>

using namespace std;

int main()
{
	int n,x,y;
	cin>>n;
	string *t = new string [n]; 
	for(int i=0;i<n;i++)
	{
		cin>>x>>y;
		if((x-1)%y == 0)
			t[i] = "NIE";
		else 
			t[i] = "TAK";
	}
	for(int i=0;i<n;i++)
		cout<<t[i]<<endl;
	return 0;
}
