#include"integration.h"
#include"function.h"
#include<fstream>
#include"sample.h"
#include <iostream>
using namespace std;
int main()
{
	ofstream cd;
	cd.open("Danilka.txt");
	Function f;
	Integration integration(&f);
	/*for (int i = 1; i < 5000; i++)
	{
		cd<< i <<" "<< (integration.NewtonCotes(-1, 1,i,1)-f.ProbaIntegral(-1,1)) <<" "<< (integration.NewtonCotes(-1, 1, i, 2) - f.ProbaIntegral(-1,1)) <<" "<< (integration.NewtonCotes(-1, 1, i, 3) - f.ProbaIntegral(-1,1)) <<" "<< (integration.NewtonCotes(-1, 1, i, 4) - f.ProbaIntegral(-1,1)) <<" "<< (integration.NewtonCotes(-1, 1, i, 5) - f.ProbaIntegral(-1,1)) <<endl;
	}
	cd.close();*/
	cout<<integration.NewtonCotes(-1, 1, 50, 5)<<endl;
	cout << integration.Gausse(-1, 1, 2, 2)<<endl;
	cout << f.ProbaIntegral(-1, 1);
	Sample<double> frt;
	ifstream fin("p.txt");
	istream& s = fin;

	frt >> s;

	system("pause");
	return 0;
}