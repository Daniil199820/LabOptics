#include"sample1d.h"
using namespace std;
Sample1D::Sample1D()
{

}
Sample1D::~Sample1D()
{

}
void Sample1D::SetSample(double x1, int n, double dx)
{
	for (int i = 0; i < n; i++)
	{
		m_x.push_back(x1 + i*dx);
		m_y.push_back(Y(x1 + i*dx));
	}
}
double Sample1D::Y(double x)
{
	return (sin(x) / x);
}
Sample1D &Sample1D:: operator=(const Sample1D &temp)
{
	if (this != &temp)
	{
		for (size_t i = 0; i < temp.m_x.size(); i++)
		{
			m_x.push_back(temp.m_x[i]);	
		}
		for (size_t i = 0; i < temp.m_y.size(); i++)
		{
			m_y.push_back(temp.m_y[i]);
		}
	}
	return *this;
}
/////////////////////////////////////////////////////////////////////////////
// Функция вывода выборки
ostream& operator<<(ostream& out, Sample1D &one)
{
	for (size_t i = 0; i<one.m_y.size(); i++)
	{
		out << one.m_x[i] << " " << one.m_y[i] << endl;
	}
	return out;
}
/////////////////////////////////////////////////////////////////////////////
// Функция чтения выборки
istream& operator>>(istream& in, Sample1D &one)
{
	double x, y;
	// цикл будет выполняться до тех пор, пока не встретиться конец файла
	while (!in.eof())
	{
		// читаем данные из файла
		in >> x >> y;
		// записываем прочитанное число в конец контейнеров
		one.m_x.push_back(x);
		one.m_y.push_back(y);
	}
	return in;
}
