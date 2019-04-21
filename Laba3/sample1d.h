#if !defined  SAMPLE1D_H
#define SAMPLE1D_H

#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
/////////////////////////////////////////////////////////////////////////////
#define PI 3.14159265358979
#define E  2.71828182845905
/////////////////////////////////////////////////////////////////////////////
class Sample1D
{
public:
	// �������� ��������� x
	std::vector<double> m_x;
	// �������� ������� 
	std::vector<double> m_y;
	//����� ��������
	int m_variant;

	//�����������
	Sample1D();
	//����������
	~Sample1D();

	// ��������� ������� �� �������
	// x1 - �������� x ������ �����
	// n - ���������� �����
	// dx - ��� �� x 
	void SetSample(double x1, int n, double dx);

	//  ���������� �������� ������� � ����� x
	double Y(double x);

	// ������������ �������
	Sample1D& operator= (const Sample1D &temp);

	// ������� ����� � ������ �������
	friend std::ostream& operator<<(std::ostream& out, Sample1D &one);
	friend std::istream& operator>>(std::istream& out, Sample1D &one);
};
#endif
