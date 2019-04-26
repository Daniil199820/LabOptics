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
	// Матрица L коэффициентов при мю. (Размер 6х6)
	ublas::matrix<double> m_mL;
	// Матрица весов Q (Размер 6х6)
	ublas::matrix<double> m_mQ;
	// Вектор-столбец показателей преломления (размер 6)
	ublas::vector<double> m_vN;
	// вычисленный вектор коэффициентов формулы Герцбергера  (размер 6)
	// (заполняется первый раз при вычислении показателя преломления)
	ublas::vector<double> m_vMu;

public:

	// Конструктор. Инициализация матриц и векторов.
	// lambda_list - список длин волн, мкм (размер 6)
	// n_list - список известных показателей преломления, соответствующих длинам волн (размер 6)
	Medium(std::vector<double> lambda_list, std::vector<double> n_list);
	// Деструктор
	virtual ~Medium();

	// Вычисление показателя преломления оптической среды для произвольной длины волны
	// medium - среда, показатель преломления которой нужно вычислить
	// lambda - длина волны (в мкм)
	// Возвращаемое значение: показатель преломления 
	double GetN(double lambda);
};
/////////////////////////////////////////////////////////////////////////////
#endif
