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
	// ����������� �������������� �����:
	enum EDirection
	{
		eDirect,   // ������ 
		eReverse   // �������� 
	};
	// ����������� �������������� �����:
	enum EDimentions
	{
		e1D,      // ���������� 
		e2D       // ��������� 
	};
	//-----------------------

private:
	// ���� ���������� �������������� �����
	fftw_plan m_plan;
	// ����������� (������ | ��������)
	EDirection m_direction;
	// ����������� (���������� | ���������)
	EDimentions m_dimension;
	// ������ ������� �� X, Y
	int m_size_x, m_size_y;


public:
	//����������� 
	// size_x, size_y - ������� �������, �� ��������� size_y=1 (���������� �������)
	// direction - ����������� (������ | ��������), �� ��������� ������
	// dimension - ����������� (���������� | ���������), �� ��������� ����������

	FFT(int size_x, int size_y = 1, EDirection direction = eDirect, EDimentions dimension = e1D);
	//����������
	~FFT();

	// ������� ������� ���������� �������������� ����� 
	//		(����� ������� � ������� � ���� ����-�� 1/sqrt(n*m) )
	// sample - �������� ������� � ��������� �������������� 
	void Run(SampleComplex& sample);

private:
	// ����� ������� ��� ������� �� size/2 
	// sample - ������� 

	void ShiftSample(SampleComplex& sample);
};
/////////////////////////////////////////////////////////////////////////////
#endif