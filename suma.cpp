#include <iostream>

using namespace std;

int main()
{
	int n;
	for(int i=0;i<10;i++)
		if(cin>>n)
			if(n==1)
				cout<<1<<endl;
			else if(n%2==0)
				cout<<(n/2)*(n+1)<<endl;
			else
				cout<<((n-1)/2)*(n+1)+n/2+1<<endl;
	
	return 0;
}
