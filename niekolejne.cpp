#include<iostream>

using namespace std;

int main()
{
  	int n;
	cin>>n;
	if(n == 0)
		cout<<n;
	else if(n<=3)
		cout<<"NIE";
	else
	{
		char bs=8;

		for(int i=0;i<=n;i+=2)
			cout<<i<<' ';

		for(int i=1;i<=n;i+=2)
			cout<<i<<' ';
		
	cout<<bs;
		}

    	return 0;
}
