#include"interpolation.h"
#include"sample1d.h"
#include<fstream>
#include<numeric>
void main()
{
	//первая часть лабы
	ofstream Newton;
	ofstream Line;
	ofstream Square;
	ofstream Lagrange;
	ofstream skv;
	skv.open("skv.txt");
	Newton.open("Newton.txt");
	Line.open("Line.txt");
	Square.open("Square.txt");
	Lagrange.open("Lagrange.txt");
	Interpolation interpolationNewt;
	Interpolation interpolationLine;
	Interpolation interpolationSquare;
	Interpolation interpolationLagrange;
	interpolationLine.CalcLine(100);
	interpolationSquare.CalcSquare(100);
	interpolationLagrange.CalcLagrange(100);
	interpolationNewt.CalcNewton(100);
	Newton << interpolationNewt.m_inter;
	Lagrange << interpolationLagrange.m_inter;
	Line << interpolationLine.m_inter;
	Square << interpolationSquare.m_inter;
	Newton.close();
	Line.close();
	Square.close();
	Lagrange.close();
	vector<double>x;
	vector<double>x_2;
	for (int i = 0; i < interpolationLine.m_inter.m_x.size(); i++)
	{
		x.push_back(interpolationLine.m_inter.m_y[i] - sin(interpolationLine.m_inter.m_x[i]) / interpolationLine.m_inter.m_x[i]);
		x_2.push_back((interpolationLine.m_inter.m_y[i] - sin(interpolationLine.m_inter.m_x[i]) / interpolationLine.m_inter.m_x[i])*(interpolationLine.m_inter.m_y[i] - sin(interpolationLine.m_inter.m_x[i]) / interpolationLine.m_inter.m_x[i]));
	}
	skv<< sqrt((accumulate(x_2.begin(), x_2.end(), 0.0) / interpolationLine.m_inter.m_x.size()) - accumulate(x.begin(), x.end(), 0.0) / interpolationLine.m_inter.m_x.size()*accumulate(x.begin(), x.end(), 0.0) / interpolationLine.m_inter.m_x.size())<<endl ;
	
	vector<double>y;
	vector<double>y_2;
	for (int i = 0; i < interpolationSquare.m_inter.m_x.size(); i++)
	{
		y.push_back(interpolationSquare.m_inter.m_y[i] - sin(interpolationSquare.m_inter.m_x[i]) / interpolationSquare.m_inter.m_x[i]);
		y_2.push_back((interpolationSquare.m_inter.m_y[i] - sin(interpolationSquare.m_inter.m_x[i]) / interpolationSquare.m_inter.m_x[i])*(interpolationSquare.m_inter.m_y[i] - sin(interpolationSquare.m_inter.m_x[i]) / interpolationSquare.m_inter.m_x[i]));
	}
	skv << sqrt((accumulate(y_2.begin(), y_2.end(), 0.0) / interpolationSquare.m_inter.m_x.size()) - accumulate(y.begin(), y.end(), 0.0) / interpolationSquare.m_inter.m_x.size()*accumulate(y.begin(), y.end(), 0.0) / interpolationSquare.m_inter.m_x.size()) << endl;

	vector<double>k;
	vector<double>k_2;
	for (int i = 0; i < interpolationNewt.m_inter.m_x.size(); i++)
	{
		k.push_back(interpolationNewt.m_inter.m_y[i] - sin(interpolationNewt.m_inter.m_x[i]) / interpolationNewt.m_inter.m_x[i]);
		k_2.push_back((interpolationNewt.m_inter.m_y[i] - sin(interpolationNewt.m_inter.m_x[i]) / interpolationNewt.m_inter.m_x[i])*(interpolationNewt.m_inter.m_y[i] - sin(interpolationNewt.m_inter.m_x[i]) / interpolationNewt.m_inter.m_x[i]));
	}
	skv << sqrt((accumulate(k_2.begin(), k_2.end(), 0.0) / interpolationNewt.m_inter.m_x.size()) - accumulate(k.begin(), k.end(), 0.0) / interpolationNewt.m_inter.m_x.size()*accumulate(k.begin(), k.end(), 0.0) / interpolationNewt.m_inter.m_x.size()) << endl;

	vector<double>z;
	vector<double>z_2;
	for (int i = 0; i < interpolationLagrange.m_inter.m_x.size(); i++)
	{
		z.push_back(interpolationLagrange.m_inter.m_y[i] - sin(interpolationLagrange.m_inter.m_x[i]) / interpolationLagrange.m_inter.m_x[i]);
		z_2.push_back((interpolationLagrange.m_inter.m_y[i] - sin(interpolationLagrange.m_inter.m_x[i]) / interpolationLagrange.m_inter.m_x[i])*(interpolationLagrange.m_inter.m_y[i] - sin(interpolationLagrange.m_inter.m_x[i]) / interpolationLagrange.m_inter.m_x[i]));
	}
	skv << sqrt((accumulate(z_2.begin(), z_2.end(), 0.0) / interpolationLagrange.m_inter.m_x.size()) - accumulate(z.begin(), z.end(), 0.0) / interpolationLagrange.m_inter.m_x.size()*accumulate(z.begin(), z.end(), 0.0) / interpolationLagrange.m_inter.m_x.size()) << endl;

	skv.close();
	// вторая часть лабы 
	Interpolation calcLineChange;
	calcLineChange.CalcLineNewChanges(1024);
	ofstream NewLine;
	NewLine.open("NewLine.txt");
	NewLine << calcLineChange.m_inter;
	NewLine.close();
	Interpolation calcSquareChange;
	ofstream NewSquare;
	NewSquare.open("NewSquare.txt");
	calcSquareChange.CalcSquareChanges(1024);
	NewSquare << calcSquareChange.m_inter;
	NewSquare.close();

}
