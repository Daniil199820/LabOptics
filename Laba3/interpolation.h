#if !defined  INTERPOLATION_H
#define INTERPOLATION_H


#include "sample1d.h"
/////////////////////////////////////////////////////////////////////////////
class Interpolation
{
	
public:
	Sample1D m_func; // ��������� �������
	Sample1D m_inter;// ���������� �������

					 //�����������
	Interpolation();
	//����������
	~Interpolation();

	// �������-�������� ������������
	// n - ����� ���������� ����� � ������� 
	void CalcLine(int n);
	// �������-������������ ������������
	// n - ����� ���������� ����� � ������� 
	void CalcSquare(int n);

	// ������������ ������������ ��������
	// y[i]=SUM{y[j]*L[j]}, i=0,n, j=0,k
	// n - ����� ���������� ����� � ������� 
	void CalcLagrange(int n);
	// ������������ ������������ �������
	// y[i]=SUM{c[j]*N[j]}, j=0,n
	// n - ����� ���������� ����� � ������� 
	void CalcNewton(int n);
	void CalcLineNewChanges(int n);
	void CalcSquareChanges(int n);

//	// ���������� ��������������������� ���������� ��������������� ������� �� ������������ �������� 
//	double CalcSKW();
//private:
//	// ������������ ���������� ����������� �������� c[j] ��� ������ �������
//	// k - ������� ��������
//	// j - ����� �������� 
//	double CalcDifference(int k, int j);
};
/////////////////////////////////////////////////////////////////////////////
#endif
