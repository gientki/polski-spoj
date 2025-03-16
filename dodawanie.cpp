#include <iostream>
#include <sstream> 
#include <cstring>
#include <cmath>

using namespace std;

int max(int x, int y)
{
	if (x < y)
		return y;
	else
		return x;
}

int min(int x, int y)
{
	if (x > y)
		return y;
	else
		return x;
}

string odejma(string x, string y)
{
	string w = "";
	for (int i = y.length(); i < x.length(); i++)
		w += x[i];

	return w;
}

string odwracanko(string x)
{
    string y = "";  
    for (int i = x.length() - 1; i >= 0; i--) 
        y += x[i];
    
    return y;  
}

void przyrownaj(string* x, string* y)
{
	int ile_max = max(x->length(), y->length());
	int ile_min = min(x->length(), y->length());
	
	// cout<<"min: "<<ile_min<<" max: "<<ile_max<<endl;

	if (ile_min == x->length())
		for (int i = ile_min; i < ile_max; i++)
				x->push_back('0');

	else 
		for (int i = ile_min; i < ile_max; i++)
				y->push_back('0');
}
string upierdol_ewentualne_zero(string x)
{
	string y = "";
	int j=0;
	
	if(x[0] == '0')
		j++;
	for(j;j<x.length();j++)
	{
		y+= x[j];
	}
	
	return y;
}
string dodaj(string x, string y)
{
	// cout << endl << x << endl << y << endl << endl;
	x = odwracanko(x);
	y = odwracanko(y);
	// cout << endl << x << endl << y << endl << endl;
	przyrownaj(&x, &y);
	// cout << endl << x << endl << y << endl << endl;
	x = odwracanko(x);
	y = odwracanko(y);

	// cout << endl << x << endl << y << endl << endl;

	string dodanie;
	int ile_max = max(x.length(), y.length());
	int ile_min = min(x.length(), y.length());
	string Wynik;
	int wynik;
	stringstream ss;

	string w = "", ww = "";

	int j = ile_max;
	int d_x, d_y;

	char* wyraz = new char[ile_max * 2];

	for (int i = 0; i < ile_max * 2 + 1; i++)
		wyraz[i] = '0';

	// cout << wyraz << endl << endl;

	int adres = 0;
	
	int dz = 0;
	for (int i = ile_min - 1; i >= 0; i--)
	{
		// cout << i << '-' << (int)x[i] - 48 << '+' << (int)y[i] - 48 << '=' << (int)x[i] - 48 + (int)y[i] - 48;
		
		if((int)x[i] - 48 + (int)y[i] - 48 > 9)
			dz++;
		
		wynik = (int)x[i] + (int)y[i];

		ss << wynik - 96;
		w = ss.str();
		w = odejma(w, ww);

		// cout << "  " << w << endl;

		if (w.length() == 2)
		{
			wyraz[adres] = w[1];
			wyraz[adres + 1] = w[0];
		}
		else
		{
			wyraz[adres] = w[0];
			wyraz[adres + 1] = '0';
		}
		adres += 2;

		ww = ss.str();
		j--;
	}
	// cout << endl <<"wyraz: " << wyraz << endl;

	// cout<<"ile jedynek: "<<dz<<endl <<endl;
	
	for(int i=0;i<ile_max*2-1;i++)
	{
		for(int j=i;j<ile_max*2-1;j++)
		{
			if(j % 2==1 && wyraz[j]=='1')
				{
					wyraz[j] = '0';
					if(wyraz[j+1] == '9')
					{
						wyraz[j+2]++;
						wyraz[j+1] = '0';
					}
						
					else 
						wyraz[j+1]++;
				}
		}
		//cout<<wyraz<<endl;
	}
	//cout<<wyraz<<endl;
	
		
	for (int i = 1; i < ile_max * 2 + 1; i++)
	{
		if (i % 2 == 1 && wyraz[i] == '1')
		{
			wyraz[i + 1]++;
			
			wyraz[i] = '0';

		}
	}
	
	//cout << wyraz << endl << endl;
	
	// cout<<"--------------"<<endl;
	// for(int i=0;i<ile_max*2+1;i+=2)
	// 	cout<<wyraz[i];
	// cout<<endl;	
	
	Wynik.resize(ile_max);

	int e = 0;
	for (int i = 0; i < ile_max * 2 + 1; i += 2)
	{
		Wynik[e] = wyraz[i]; 
	//	cout << e << '-' << wyraz[i] << " " << (int)Wynik[e]-48 << endl;
		e++;
	}
	//cout<<endl;
	
	e -= 1;
	
	//char *ostateczny_wynik = new char [e];
	string ostateczny_wynik;
	 for (int i = e; i >= 0; i--)
	 {

	 	//ostateczny_wynik[abs(i-e)] = Wynik[i];
	 	ostateczny_wynik+=Wynik[i];
	//	cout<<ostateczny_wynik[abs(i-e)];
	 }
		
	
	// cout<<" "<<ostateczny_wynik<<endl;

	// cout << endl << Wynik <<endl << odwracanko(Wynik)<<' ' <<(float)((ile_max+ile_min)/2)<<' '<<e<<endl;
	
	return ostateczny_wynik;
}
int main()
{
	string x, y;
	int n;

	cin >> n;

	string* t = new string[n];
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		t[i] = upierdol_ewentualne_zero(dodaj(x, y));
	}
	for (int i = 0; i < n; i++)
		cout << t[i] << endl;
	return 0;
}
