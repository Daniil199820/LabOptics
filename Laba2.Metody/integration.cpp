#include"integration.h"
Integration::Integration(Function *f)
{
	f = m_f;
}
Integration::~Integration()
{

}
double Integration::NewtonCotes(double a, double b, int count, int order)
{
	int c[6][6] = { 
	{1,0,0,0,0,0},
	{1,1,0,0,0,0},
	{1,4,1,0,0,0},
	{1,3,3,1,0,0},
	{7,32,12,32,7,0},
	{19,75,50,50,75,19} 
	};
	double cof[6] = { 1,	1.0 / 2,	1.0 / 3,	3.0 / 8,	2.0 / 45,	5.0 / 288};
	double Sum, PartSum;
	double h = (b - a) / (count*order);

	Sum = 0;
	for (int j = 0; j<count; j++)
	{
		PartSum = 0;
		for (int i = 0; i <= order; i++)
			PartSum += c[order][i] * m_f->Proba(a + (i + j*order) * h);
		Sum += cof[order] * PartSum*h; 
	}

	return Sum;
}
double Integration::Gausse(double a, double b, int count, int order)
{
	double c[6][6] = {
		{ 2.0,0.0,0.0,0.0,0.0,0.0 },
		{ 1.0,1.0,0.0,0.0,0.0,0.0 },
		{ 0.5555556,0.8888889,0.5555556,0.0,0.0,0.0 },
		{ 0.3478548,0.6521451,0.6521451,0.3478548,0.0,0.0 },
		{ 0.4786287,0.2369269,0.5688888,0.2369269,0.4786287,0.0 },
		{ 0.1713245,0.3607616,0.4679140,0.4679140,0.3607616,0.1713245 }
	};
	double cof[6][6] = {
		{0.0,0.0,0.0,0.0,0.0,0.0},
		{-0.5773503,0.5773503,0.0,0.0,0.0,0.0},
		{-0.7745967,0.0,0.7745967,0.0,0.0,0.0},
		{-0.8611363,-0.3399810,0.3399810,0.8611363,0.0,0.0 },
		{-0.9061798,-0.5384693,0.0,0.5384693,0.9061798},
		{-0.9324700,-0.6612094,-0.2386142,0.2386142,0.6612094,0.9324700}
	};
	double *X = new double[count + 1];
	double Sum, PartSum, step;
	Sum = 0;
	step = (b - a) / count;
	for (int j = 0; j <= count; j++) X[j] = a + j*step;
	PartSum = 0;

	for(int j=1;j<=count;j++)
	{
		for (int i = 0; i < order; i++)
		{
			PartSum += c[order-1][i] * m_f->Proba(X[j-1]+((cof[order-1][i]+1)*(X[j]-X[j-1])/2) );	
		}
		Sum += step * PartSum/2.0;
		PartSum = 0;
	}

	return Sum;
}
