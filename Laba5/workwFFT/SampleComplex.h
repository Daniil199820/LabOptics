#if !defined  SAMPLE_COMPLEX_H
#define SAMPLE_COMPLEX_H
#include <complex>
#include "Sample.h"

using namespace std;

#define PI 3.14159265358979
//-------------------------------------------------------------------------------------------------
class SampleComplex : public Sample<complex<double> >
{
public:
	// ������ �����������
	// size - ���������� ���������, ���������� �� x � y (size*size)
	SampleComplex(int size_x,int size_y=1);
	// ����������
	virtual ~SampleComplex();

	// ���������� ������������� ������� (������� ������) 
	// ������������ � ������������ �����, ������ ����� ����������
	void CalcIntens();

	// ����� � ���� ������ ������������ ����� �������
	ostream& PrintReal(ostream& out);
	// ����� � ���� ������ ������ ����� �������
	ostream& PrintImag(ostream& out);

	// ����� � ���� ������ �������
	ostream& PrintModule(ostream& out);
	// ����� � ���� ���� �������
	ostream& PrintPhase(ostream& out);
	// ����� � ���� ������������� ������� (������� ������)
	ostream& PrintIntens(ostream& out);
	SampleComplex& operator*(const SampleComplex &temp);
	// �������� ���������� �������
	void Create1DFunc(double dx);

	 //�������� �������-������� circ(ro) 
	void CreateCirc(double dx);
	// �������� ������� ��������� ������� 
	void CreatePupil(double dx);
};
//-------------------------------------------------------------------------------------------------
#endif