//Bai 1 & 3

#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
class Phanso
{
private:
	int tuso;
	int mauso;
public:
	Phanso(){
		tuso = 1;
		mauso = 1;
	}
	Phanso(int a)
	{
		tuso = a;
		mauso = 1;
	}
	Phanso(int a, int b)
	{
		tuso = a;
		mauso = b;
	}
	friend ostream& operator << (ostream &out, Phanso a)
	{
		out << a.tuso << '/' << a.mauso;
		return out;
	}
	void setTuso(int a)
	{
		tuso = a;
	}
	void setMauso(int b)
	{
		mauso = b;
	}
	int getTuso()
	{
		return tuso;
	}
	int getMauso()
	{
		return mauso;
	}
	Phanso operator + (Phanso a)
	{
		Phanso b;
		b.tuso = tuso*a.mauso + mauso*a.tuso;
		b.mauso = mauso*a.mauso;
		return b;
	}
	friend Phanso  operator * (int a,Phanso b)
	{
		Phanso c;
		c.tuso = b.tuso*a;
		c.mauso = b.mauso;
		return c;
	}
	friend Phanso operator * (Phanso ps1,Phanso ps2)
	{
		Phanso c;
		c.tuso = ps1.getTuso()*ps2.getTuso();
		c.mauso = ps1.getMauso()*ps2.getMauso();
		return c;
	}
	friend bool operator > (Phanso ps1,Phanso ps2)
	{
		float veTrai = ps1.getTuso() / (float)ps1.getMauso();
		float vePhai = ps2.getTuso() / (float)ps2.getMauso();
		//cout<<veTrai<<"&"<<vePhai<<endl;
		//cout<<(veTrai<vePhai)<<endl;
		return veTrai>vePhai;
	}
};
/*int main()
{
	Phanso p1(1, 2), p2(3), p3;
	cout << p1 << p2 << p3;
	p3 = p1 + p2;
	cout << p3;
	Phanso t = 4 * p2;
	cout<<t;

	
}
*/
//bai 2

//#include <iostream>
//#include <stdio.h>

//using namespace std;
#define maxsize 100

template <class T>
class List
{
private:
	int n;
	T a[100];
public:
	List()
	{
		n = 0;
	};
	List(int k, T value)
	{
		n = k;
		for (int i = 0; i < k; i++)
			a[i] = value;
	}
	void add(T value)
	{
		a[n] = value;
		n++;
	}
	T Get(int i)
	{
		return a[i];
	}
	int dem()
	{
		return n;
	}
	void Insert(int b, T value)
	{
		for (int i = n; i >= b-1; i--)
		{
			a[i] = a[i - 1];
		}
		a[b-1] = value;
		n++;
	}
	void Delete(int b)
	{
		for (int i = b; i < n; i++)
		{
			a[i] = a[i + 1];
		}
		n--;
	}
	void Replace(T oldVal, T newVal)
	{
		for (int i = 0; i < n; ++i)
		{
			if (a[i] == oldVal)
				a[i] = newVal;
		}
	}
	void SapXep()
	{
		for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
        	//cout<<a[i]<<"&"<<a[j]<<endl;
            if(a[i] > a[j]){
                // Hoan vi 2 so a[i] va a[j]
                T temp;
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;        
            }
        }
    }
	}
	friend ostream& operator << (ostream&out, List &a)
	{
		for (int i = 0; i < a.dem(); i++)
		{
			out << a.Get(i) ;
			cout<<endl;
		}
	
	}
};


/*
int main(int argc, char const *argv[])
{
	List<float> ds;
	ds.add(10.5); ds.add(12); ds.add(14);
	
	cout<<ds;
	cout<<endl;
	ds.Insert(2,11);
	cout<<ds;
	//ds.delete(2);
	cout<<endl;
	ds.Replace(14,20);
	cout<<ds;
	return 0;
}*/

//Bai 3 
int main(int argc, char const *argv[])
{
	fstream f; 
	string line;

	f.open("data.txt", ios::in);
	List<Phanso> ds;
	Phanso tich(1,1);
	while (!f.eof())
	{
		int a =0;
		f>>a;
		int b = 0;
		f>>b;
		
		if (a!=0 && b!= 0)
		{
			Phanso ps(a,b);
			tich = tich*ps;
			ds.add(ps);
		}
	}
	cout<<ds;
	cout<<tich;
	ds.SapXep();
	cout<<ds;
	return 0;
}