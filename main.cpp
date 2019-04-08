#include"integration.h"
#include"function.h"
#include<fstream>
#include"sample.h"
#include <iostream>
#include<clocale>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	ofstream cd;
	cd.open("Cotes.txt");
	Function f;
	Integration integration(&f);
	// ���������� �������� � ������ i= 100, ��� ��� � ���� ��������� ����������, � ������� �������� ���������� �������� 5000, ��� ��� ��� ������� ������ �������� ����
	// ����� ����� ������� ������� ��������������: � ���� -1 �� 1
	for (int i = 1; i < 100; i++)
	{
		cd<< i <<" "<< (integration.NewtonCotes(-1, 1,i,1)-f.ProbaIntegral(-1,1)) <<" "<< (integration.NewtonCotes(-1, 1, i, 2) - f.ProbaIntegral(-1,1)) <<" "<< (integration.NewtonCotes(-1, 1, i, 3) - f.ProbaIntegral(-1,1)) <<" "<< (integration.NewtonCotes(-1, 1, i, 4) - f.ProbaIntegral(-1,1)) <<" "<< (integration.NewtonCotes(-1, 1, i, 5) - f.ProbaIntegral(-1,1)) <<endl;
	}
	cd.close();
	ofstream cp;
	cp.open("Gausse.txt");
	for (int i = 1; i < 100; i++)
	{
		cp<< i<< " " << (integration.Gausse(-1, 1, i, 1) - f.ProbaIntegral(-1, 1)) << " " << (integration.Gausse(-1, 1, i, 2) - f.ProbaIntegral(-1, 1)) << " " << (integration.Gausse(-1, 1, i, 3) - f.ProbaIntegral(-1, 1)) << " " << (integration.Gausse(-1, 1, i, 4) - f.ProbaIntegral(-1, 1)) << " " << (integration.Gausse(-1, 1, i, 5) - f.ProbaIntegral(-1, 1)) << (integration.Gausse(-1, 1, i, 6) - f.ProbaIntegral(-1, 1)) <<endl;
	}
	cp.close();
	Sample<double> frt;
	ifstream fin("p.txt");
	fin >> frt;
	//������ �������� �� ������������� ������ ��������� ��� �������� �� �����
	double I;
	I = 0.0;
	int Y_size,X_size;
	Y_size = int(frt.GetSizeY());
	X_size = int(frt.GetSizeX());
	for (int i = 0; i < Y_size; i++)
	{
		for (int j = 0; j < X_size; j++)
		{
			I = I + frt.operator()(i, j);
		}
	}
	//������ ��������� ������ �����, ����������� ������� ����������, ����� 128, ��� ��� 6.375/0.05=127.5 
	double partI;
	double N;
	N = 0.0;
	ofstream fout;
	fout.open("mas.txt");
	for(int k =0; k<128; k++)
	{
		partI = 0.0;
		for (int i = -128; i <=128; i++)
		{
			for (int j = -128; j <=128; j++)
			{
				if (sqrt(i*i + j*j) < k/2)
				{
					partI = partI + frt.operator()((i+128), (j+128));
				}
			}
		}
		fout << partI / I <<" ";
	}
	fout.close();
	cout << I;
	system("pause");
	return 0;
}