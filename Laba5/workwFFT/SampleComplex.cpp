#include "stdafx.h"
#include "SampleComplex.h"
//-------------------------------------------------------------------------------------------------
// полный конструктор
SampleComplex::SampleComplex(int size_x,int size_y)
	: Sample<complex<double> >(size_x,size_y)
{
}
//-------------------------------------------------------------------------------------------------
// деструктор
SampleComplex::~SampleComplex()
{

}
//-------------------------------------------------------------------------------------------------
// вычисление интенсивности выборки (квадрат модуля) 
// записывается в вещественную часть, мнимая часть обнуляется
void SampleComplex::CalcIntens()
{
	for (int i = 0; i<m_size_y; ++i)
	{
		for (int j = 0; j<m_size_x; ++j)
		{
			double res = operator()(i, j).real()*operator()(i, j).real() +
				operator()(i, j).imag()*operator()(i, j).imag();
			operator()(i, j) = complex<double>(res, 0.);
		}
	}
}
//-------------------------------------------------------------------------------------------------
// вывод в файл только вещественной части выборки
ostream& SampleComplex::PrintReal(ostream& out)
{
	for (int i = 0; i<m_size_x; i++)
	{
		for (int j = 0; j<m_size_y; j++)
		{
			out << operator()(i, j).real() << " ";
		}
		out << endl;
	}
	return out;
}
//-------------------------------------------------------------------------------------------------
// вывод в файл только мнимой части выборки
ostream& SampleComplex::PrintImag(ostream& out)
{
	for (int i = 0; i<m_size_x; i++)
	{
		for (int j = 0; j<m_size_y; j++)
		{
			out << operator()(i, j).imag() << " ";
		}
		out << endl;
	}
	return out;
}
//-------------------------------------------------------------------------------------------------
// вывод в файл модуля выборки
ostream& SampleComplex::PrintModule(ostream& out)
{
	complex<double> x;
	for (int i = 0; i<m_size_x; i++)
	{
		for (int j = 0; j<m_size_y; j++)
		{
			double res = sqrt(operator()(i, j).real()*operator()(i, j).real() +
				operator()(i, j).imag()*operator()(i, j).imag());
			out << res << " ";
		}
		out << endl;
	}
	return out;
}
//-------------------------------------------------------------------------------------------------
// вывод в файл интенсивности выборки (квадрат модуля)
ostream& SampleComplex::PrintIntens(ostream& out)
{
	for (int i = 0; i<m_size_y; i++)
	{
		for (int j = 0; j<m_size_x; j++)
		{
			double res = operator()(i, j).real()*operator()(i, j).real() +
				operator()(i, j).imag()*operator()(i, j).imag();
			out << res << " ";
		}
		out << endl;
	}
	return out;
}

void SampleComplex::Create1DFunc(double dx)
{
	for (int i = 0; i < m_size_x; i++)
	{
		operator()(i, 0)=complex<double>(cos(PI*CalcCoord(i, dx)),0);
	}
}
SampleComplex& SampleComplex::operator*(const SampleComplex &temp)
{
	for (int j = 0; j < m_size_x; j++)
	{
		for (int i = 0; i < m_size_y; i++)
		{
			operator()(i, j) = complex<double>(operator()(i, j).real()*operator()(i, j).real() - operator()(i, j).imag()*temp.operator()(i, j).imag(), temp.operator()(i, j).real()*operator()(i, j).imag() + temp.operator()(i, j).imag()*operator()(i, j).real());

		}
	}
	return(*this);
}
void SampleComplex::CreateCirc(double dx)
{
	for (int i = 0; i < m_size_x; i++)
	{
		for (int j = 0; j < m_size_y; j++)
		{
			if ((CalcCoord(i, dx)*CalcCoord(i, dx) + CalcCoord(j, dx)*CalcCoord(j, dx)) <= 1)
			{
				operator()(i, j) = complex<double>(1, 0);
			}
			else
			{
				operator()(i, j) = complex<double>(0, 0);
			}
		}
	}
}
void SampleComplex::CreatePupil(double dx)
{
	for (int i = 0; i < m_size_x; i++)
	{
		for (int j = 0; j < m_size_y; j++)
		{
			if ((CalcCoord(i, dx)*CalcCoord(i, dx) + CalcCoord(j, dx)*CalcCoord(j, dx)) <= 1)
			{
				operator()(i, j) = complex<double>(cos(2*PI*0.2*(2 * pow((CalcCoord(i, dx)*CalcCoord(i, dx) 
+ CalcCoord(j, dx)*CalcCoord(j, dx)), 2) - 1)), sin(2 * PI*0.2*(2 * pow((CalcCoord(i, dx)*CalcCoord(i, dx) +
	CalcCoord(j, dx)*CalcCoord(j, dx)), 2) - 1)));
			}
			else
			{
				operator()(i, j) = complex<double>(0, 0);
			}
		}
	}
}
//void SampleComplex::CreatePupil(double dx)
//{
//	for (int i = 0; i < m_size_x; i++)
//	{
//		for (int j = 0; j < m_size_y; j++)
//		{
//			if ((CalcCoord(i, dx)*CalcCoord(i, dx) + CalcCoord(j, dx)*CalcCoord(j, dx)) <= 1)
//			{
//				if ((CalcCoord(i, dx)*CalcCoord(i, dx) + CalcCoord(j, dx)*CalcCoord(j, dx)) >= 0.49)
//				{
//					operator()(i, j) = complex<double>(1, 0);
//				}
//			}
//			else
//			{
//				operator()(i, j) = complex<double>(0, 0);
//			}
//		}
//	}
//}

//-------------------------------------------------------------------------------------------------