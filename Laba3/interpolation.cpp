#include"interpolation.h"
#include<fstream>
Interpolation::Interpolation()
{

}
Interpolation::~Interpolation()
{

}
void Interpolation::CalcLine(int n)
{
	m_func.SetSample(-4 * PI, 10, PI / 3);// здесь нужно ввести начальное значение, количество точек в выборке и шаг с которым мы идем к конечному значению, это нужно скорректировать во всех setsample
	
	m_inter.m_x.push_back(m_func.m_x[0]);
	m_inter.m_y.push_back(m_func.Y(m_func.m_x[0]));

	for (int i = 1; i < m_func.m_x.size(); i++)
	{
		double a1 = (m_func.Y(m_func.m_x[i]) - m_func.Y(m_func.m_x[i - 1])) / (m_func.m_x[i] - m_func.m_x[i - 1]);
		double a0 = m_func.Y(m_func.m_x[i - 1]) - a1*m_func.m_x[i - 1];

		for (int j = 1; j <= n/(m_func.m_x.size())+1; j++)
		{
			double x = m_func.m_x[i - 1] + j*(m_func.m_x[i] - m_func.m_x[i - 1]) / (m_func.m_x.size()+1);
			m_inter.m_x.push_back(x);
			m_inter.m_y.push_back(a0+a1*x);
		}
	}

}
void Interpolation::CalcSquare(int n)
{
	m_func.SetSample(-4 * PI, 10, PI / 3);

	m_inter.m_x.push_back(m_func.m_x[0]);
	m_inter.m_y.push_back(m_func.Y(m_func.m_x[0]));

	for (int i = 1; i < m_func.m_x.size()-1; i++)
	{
		double a2 = (m_func.Y(m_func.m_x[i + 1]) - m_func.Y(m_func.m_x[i - 1])) / ((m_func.m_x[i + 1] - m_func.m_x[i - 1]) * (m_func.m_x[i + 1] - m_func.m_x[i])) - ((m_func.Y(m_func.m_x[i]) - m_func.Y(m_func.m_x[i - 1]))) / ((m_func.m_x[i] - m_func.m_x[i - 1]) * (m_func.m_x[i + 1] - m_func.m_x[i]));
		double a1 = (m_func.Y(m_func.m_x[i]) - m_func.Y(m_func.m_x[i - 1])) / (m_func.m_x[i] - m_func.m_x[i - 1])-a2*(m_func.m_x[i]+m_func.m_x[i-1]);
		double a0 = m_func.Y(m_func.m_x[i - 1]) - a1*m_func.m_x[i - 1]-a2*m_func.m_x[i-1]* m_func.m_x[i - 1];

		if (i == 1)
		{
			for (int j = 1; j <= n / (m_func.m_x.size()) + 1; j++)
			{
				double x = m_func.m_x[i-1] + j*(m_func.m_x[i] - m_func.m_x[i-1]) / (m_func.m_x.size() + 1);
				m_inter.m_x.push_back(x);
				m_inter.m_y.push_back(a0 + a1*x + a2*x*x);
			}
		}
		for (int j = 1; j <= n / (m_func.m_x.size()) + 1; j++)
		{
			double x = m_func.m_x[i] + j*(m_func.m_x[i+1] - m_func.m_x[i]) / (m_func.m_x.size() + 1);
			m_inter.m_x.push_back(x);
			m_inter.m_y.push_back(a0 + a1*x+a2*x*x);
		}
	}
}
void Interpolation::CalcLagrange(int n)
{
	m_func.SetSample(-4 * PI, 10, PI / 3);
	
	for (double x =-4*PI ; x <=(-PI) ; x+=(-PI+4*PI)/n)// здесь также нужно скорректировать под свои начальные и конечные значения
	{
		double Sum = 0;
		for (int i = 0; i < m_func.m_x.size(); i++)
		{
			double l = 1;

			for (int j = 0; j < n/m_func.m_x.size(); j++)
			{
				if(j!=i)
				l *= ((x - m_func.m_x[j]) / (m_func.m_x[i] - m_func.m_x[j]));
			}
			Sum += m_func.m_y[i] * l;
		}
		m_inter.m_x.push_back(x);
		m_inter.m_y.push_back(Sum);
	}

	
}

void Interpolation::CalcNewton(int n)
{
	m_func.SetSample(-4 * PI, 10, PI / 3);
	int z = m_func.m_x.size();
	vector<vector<double>>M(z, vector<double>(z));
	for (int i = 0; i < z; i++)
	{
		M[i][0] = m_func.m_y[i];
	}
	for (int j=1; j < z; j++)
	{
		for (int i = 0; i < z - j; i++)
		{
			M[i][j] = (M[i + 1][j - 1] - M[i][j - 1]) / (m_func.m_x[i + j] - m_func.m_x[i]);
		}
	}
	vector<double> l;
	for (double x = -4 * PI; x <= (-PI); x += (-PI + 4 * PI) / n)// и здесь
	{
		m_inter.m_x.push_back(x);
		m_inter.m_y.push_back(M[0][0]);
		l.push_back(1);
	}
	for (int j=1; j < z; j++)
	{
		for (int i=0; i < m_inter.m_x.size(); i++)
		{
			l[i] *= m_inter.m_x[i] - m_func.m_x[j - 1];
			m_inter.m_y[i] += l[i] * M[0][j];
		}
	}
}
void Interpolation::CalcLineNewChanges(int n)// здесь нужно вместо "v8.txt" подставить свой текстовый файл с выборкой
{
	Sample1D v8;
	ifstream fin("v8.txt");
	fin >> v8;
	m_func = v8;
	m_inter.m_x.push_back(m_func.m_x[0]);
	m_inter.m_y.push_back(m_func.Y(m_func.m_x[0]));

	for (int i = 1; i < m_func.m_x.size(); i++)
	{
		double a1 = (m_func.Y(m_func.m_x[i]) - m_func.Y(m_func.m_x[i - 1])) / (m_func.m_x[i] - m_func.m_x[i - 1]);
		double a0 = m_func.Y(m_func.m_x[i - 1]) - a1*m_func.m_x[i - 1];

		for (int j = 1; j <= n / (m_func.m_x.size()) + 1; j++)
		{
			double x = m_func.m_x[i - 1] + j*(m_func.m_x[i] - m_func.m_x[i - 1]) / (m_func.m_x.size() + 1);
			m_inter.m_x.push_back(x);
			m_inter.m_y.push_back(a0 + a1*x);
		}
	}
}
void Interpolation::CalcSquareChanges(int n)// здесь также нужно подставить свой файл с выборкой
{
	Sample1D v8;
	ifstream fin("v8.txt");
	fin >> v8;
	m_func = v8;
	m_inter.m_x.push_back(m_func.m_x[0]);
	m_inter.m_y.push_back(m_func.Y(m_func.m_x[0]));

	for (int i = 1; i < m_func.m_x.size() - 1; i++)
	{
		double a2 = (m_func.Y(m_func.m_x[i + 1]) - m_func.Y(m_func.m_x[i - 1])) / ((m_func.m_x[i + 1] - m_func.m_x[i - 1]) * (m_func.m_x[i + 1] - m_func.m_x[i])) - ((m_func.Y(m_func.m_x[i]) - m_func.Y(m_func.m_x[i - 1]))) / ((m_func.m_x[i] - m_func.m_x[i - 1]) * (m_func.m_x[i + 1] - m_func.m_x[i]));
		double a1 = (m_func.Y(m_func.m_x[i]) - m_func.Y(m_func.m_x[i - 1])) / (m_func.m_x[i] - m_func.m_x[i - 1]) - a2*(m_func.m_x[i] + m_func.m_x[i - 1]);
		double a0 = m_func.Y(m_func.m_x[i - 1]) - a1*m_func.m_x[i - 1] - a2*m_func.m_x[i - 1] * m_func.m_x[i - 1];

		if (i == 1)
		{
			for (int j = 1; j <= n / (m_func.m_x.size()) + 1; j++)
			{
				double x = m_func.m_x[i - 1] + j*(m_func.m_x[i] - m_func.m_x[i - 1]) / (m_func.m_x.size() + 1);
				m_inter.m_x.push_back(x);
				m_inter.m_y.push_back(a0 + a1*x + a2*x*x);
			}
		}
		for (int j = 1; j <= n / (m_func.m_x.size()) + 1; j++)
		{
			double x = m_func.m_x[i] + j*(m_func.m_x[i + 1] - m_func.m_x[i]) / (m_func.m_x.size() + 1);
			m_inter.m_x.push_back(x);
			m_inter.m_y.push_back(a0 + a1*x + a2*x*x);
		}
	}
}
//double Interpolation::CalcSKW()
//{
//	return 0;
//}
//double Interpolation::CalcDifference(int k, int j)
//{
//	return 80;
//}
