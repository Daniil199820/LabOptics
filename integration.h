#if !defined INTEGRATION_H
#define INTEGRATION_H
#include"sample.h"
#include "function.h"
/////////////////////////////////////////////////////////////////////////////
class Integration
{
	Function *m_f; // интегрируема€ функци€ 

public:
	// конструктор
	Integration(Function *f);
	// деструктор
	~Integration();

	// интегрирование методом Ќьютона- отеса на интервале [a,b]
	// count - число подинтервалов
	// order - пор€док метода
	double NewtonCotes(double a, double b, int count, int order);

	// интегрирование методом √аусса на интервале [a,b]
	// count - число шагов
	// order - пор€док метода
	double Gausse(double a, double b, int count, int order);
};
/////////////////////////////////////////////////////////////////////////////
#endif
