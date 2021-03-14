#include<iostream>

using namespace std;

int nwd(int p,int d)
{
	int n,e;
	if(p<=d) n=p;
	else if(p>d) n=d;
	int i=1;
	while(i<=n)
	{
		if((p%i==0)&&(d%i==0))
		e=i;
		i++;
	}
	return e;
}
int main()
{
	int ile,pierwsza,druga;
	cin>>ile;
	for (int i=0;i<ile;i++)
	{
		cin>>pierwsza>>druga;
		cout<<nwd(pierwsza,druga)<<endl;
	}
	return 0;
}
