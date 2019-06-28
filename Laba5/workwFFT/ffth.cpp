#include <cmath>
#include"stdafx.h"
#include "ffth.h"

FFT::FFT(int size_x, int size_y, EDirection direction , EDimentions dimension)
{
	m_dimension = dimension;
	m_direction = direction;
	m_size_x = size_x;
	m_size_y = size_y;
	
}

FFT::~FFT(void)
{
}
//Вычисление фурье преобразования 
void FFT::Run(SampleComplex& sample)
{
	ShiftSample(sample);
	if (m_dimension == FFT::e2D)
		m_plan = fftw_plan_dft_2d(m_size_x, m_size_y, (fftw_complex*)sample.GetPointer(),
		(fftw_complex*)sample.GetPointer(),
			m_direction, FFTW_ESTIMATE);
	else
		m_plan = fftw_plan_dft_1d(m_size_x, (fftw_complex*)sample.GetPointer(),
		(fftw_complex*)sample.GetPointer(),
			m_direction, FFTW_ESTIMATE);
	fftw_execute(m_plan);
	double size = m_size_x*m_size_y;
	std::complex<double>k((1 / sqrt(size)), 0);
	sample *= k;
	ShiftSample(sample);
	fftw_destroy_plan(m_plan);
}
//сдвиг выборки
void FFT::ShiftSample(SampleComplex& sample)
{
	for (int x = 0; x < m_size_x; x++)
		for (int y = 0; y < m_size_y; y++)
		{
			double k = (-PI*x) + (-PI*y);
			std::complex<double> kk(cos(k), sin(k));
			sample(x, y) *= kk;
		}
}


