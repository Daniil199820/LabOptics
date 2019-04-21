#if !defined INTEGRATION_H
#define INTEGRATION_H
#include"sample.h"
#include "function.h"
/////////////////////////////////////////////////////////////////////////////
class Integration
{
	Function *m_f; // ������������� ������� 

public:
	// �����������
	Integration(Function *f);
	// ����������
	~Integration();

	// �������������� ������� �������-������ �� ��������� [a,b]
	// count - ����� �������������
	// order - ������� ������
	double NewtonCotes(double a, double b, int count, int order);

	// �������������� ������� ������ �� ��������� [a,b]
	// count - ����� �����
	// order - ������� ������
	double Gausse(double a, double b, int count, int order);
};
/////////////////////////////////////////////////////////////////////////////
#endif
