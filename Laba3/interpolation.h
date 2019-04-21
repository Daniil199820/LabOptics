#if !defined  INTERPOLATION_H
#define INTERPOLATION_H


#include "sample1d.h"
/////////////////////////////////////////////////////////////////////////////
class Interpolation
{
	
public:
	Sample1D m_func; // начальна€ выборка
	Sample1D m_inter;// полученна€ выборка

					 //конструктор
	Interpolation();
	//деструктор
	~Interpolation();

	//  усочно-линейна€ интерпол€ци€
	// n - новое количество точек в выборке 
	void CalcLine(int n);
	//  усочно-квадратична€ интерпол€ци€
	// n - новое количество точек в выборке 
	void CalcSquare(int n);

	// интерпол€ци€ многочленами Ћагранжа
	// y[i]=SUM{y[j]*L[j]}, i=0,n, j=0,k
	// n - новое количество точек в выборке 
	void CalcLagrange(int n);
	// интерпол€ци€ многочленами Ќьютона
	// y[i]=SUM{c[j]*N[j]}, j=0,n
	// n - новое количество точек в выборке 
	void CalcNewton(int n);
	void CalcLineNewChanges(int n);
	void CalcSquareChanges(int n);

//	// вычисление среднеквадратического отклонени€ восстановленной функции от аналитически заданной 
//	double CalcSKW();
//private:
//	// рекуррентное вычисление разделенной разности c[j] дл€ метода Ќьютона
//	// k - пор€док разности
//	// j - номер элемента 
//	double CalcDifference(int k, int j);
};
/////////////////////////////////////////////////////////////////////////////
#endif
