#if !defined MEDIUM_H
#define MEDIUM_H
/////////////////////////////////////////////////////////////////////////////

#include "boost/numeric/ublas/matrix.hpp"
#include "boost/numeric/ublas/vector.hpp"
#include "perevorot.h"
/////////////////////////////////////////////////////////////////////////////

using namespace boost;
using namespace numeric;
using namespace ublas;
class Medium
{
private:
	// ������� L ������������� ��� ��. (������ 6�6)
	ublas::matrix<double> m_mL;
	// ������� ����� Q (������ 6�6)
	ublas::matrix<double> m_mQ;
	// ������-������� ����������� ����������� (������ 6)
	ublas::vector<double> m_vN;
	// ����������� ������ ������������� ������� �����������  (������ 6)
	// (����������� ������ ��� ��� ���������� ���������� �����������)
	ublas::vector<double> m_vMu;

public:

	// �����������. ������������� ������ � ��������.
	// lambda_list - ������ ���� ����, ��� (������ 6)
	// n_list - ������ ��������� ����������� �����������, ��������������� ������ ���� (������ 6)
	Medium(std::vector<double> lambda_list, std::vector<double> n_list);
	// ����������
	virtual ~Medium();

	// ���������� ���������� ����������� ���������� ����� ��� ������������ ����� �����
	// medium - �����, ���������� ����������� ������� ����� ���������
	// lambda - ����� ����� (� ���)
	// ������������ ��������: ���������� ����������� 
	double GetN(double lambda);
};
/////////////////////////////////////////////////////////////////////////////
#endif
