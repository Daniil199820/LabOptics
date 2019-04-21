#if !defined  SAMPLE1D_H
#define SAMPLE1D_H

#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
/////////////////////////////////////////////////////////////////////////////
#define PI 3.14159265358979
#define E  2.71828182845905
/////////////////////////////////////////////////////////////////////////////
class Sample1D
{
public:
	// значения координат x
	std::vector<double> m_x;
	// значения функции 
	std::vector<double> m_y;
	//номер варианта
	int m_variant;

	//конструктор
	Sample1D();
	//деструктор
	~Sample1D();

	// генерация выборки по функции
	// x1 - значение x первой точки
	// n - количество точек
	// dx - шаг по x 
	void SetSample(double x1, int n, double dx);

	//  вычисление значения функции в точке x
	double Y(double x);

	// присваивание выборки
	Sample1D& operator= (const Sample1D &temp);

	// функция ввода и вывода выборки
	friend std::ostream& operator<<(std::ostream& out, Sample1D &one);
	friend std::istream& operator>>(std::istream& out, Sample1D &one);
};
#endif
