#if !defined FFT_H
#define FFT_H
#include "stdafx.h"
#include"sample.h"
#include "SampleComplex.h"
/////////////////////////////////////////////////////////////////////////////
class FFT
{
public:
	//-----------------------
	// направление преобразования Фурье:
	enum EDirection
	{
		eDirect,   // прямое 
		eReverse   // обратное 
	};
	// размерность преобразования Фурье:
	enum EDimentions
	{
		e1D,      // одномерное 
		e2D       // двумерное 
	};
	//-----------------------

private:
	// план вычислений преобразования Фурье
	fftw_plan m_plan;
	// направление (прямое | обратное)
	EDirection m_direction;
	// размерность (одномерное | двумерное)
	EDimentions m_dimension;
	// размер выборки по X, Y
	int m_size_x, m_size_y;


public:
	//конструктор 
	// size_x, size_y - размеры выборки, по умолчанию size_y=1 (одномерная выборка)
	// direction - направление (прямое | обратное), по умолчанию прямое
	// dimension - размерность (одномерное | двумерное), по умолчанию одномерное

	FFT(int size_x, int size_y = 1, EDirection direction = eDirect, EDimentions dimension = e1D);
	//деструктор
	~FFT();

	// функция полного сдвигового преобразования Фурье 
	//		(сдвиг выборки и спектра и учет коэф-та 1/sqrt(n*m) )
	// sample - исходная выборка и результат преобразования 
	void Run(SampleComplex& sample);

private:
	// сдвиг выборки или спектра на size/2 
	// sample - выборка 

	void ShiftSample(SampleComplex& sample);
};
/////////////////////////////////////////////////////////////////////////////
#endif