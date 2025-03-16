#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

bool beetwen(int x,int from,int to)
{
	if((x>=from)&&(x<=to))
		return true;
	else 
		return false; 
}

int main()
{
	int x,y;
	string str,str0;
	
	cin>>y>>str;
	
	x = floor(str.length()/2);
	
	for(int i=0;i<str.length();i++)
		str0[i]='.';
	
	//cout<<x<<endl;
	for(int i=0;i<x+1;i++)
	{
		for(int j=0;j<str.length();j++)
		{
			if(beetwen(j,x-i,x+i))
			{
				cout<<str[j];
			}
			else
				cout<<str0[j];
		}	
		cout<<endl;
	
	}
	return 0;
}
