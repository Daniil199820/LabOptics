#define _SCL_SECURE_NO_WARNINGS

#include"medium.h"

using namespace boost::numeric::ublas;
Medium::Medium(std::vector<double> lambda_list, std::vector<double> n_list)
{
	m_mL.resize(6, 6);
	m_mQ.resize(6, 6);
	m_vN.resize(6);
	m_vMu.resize(6);
	for (int i = 0; i < lambda_list.size(); i++)
	{
		m_mL.insert_element(i, 0, 1);
		m_mL.insert_element(i, 1, lambda_list[i]*lambda_list[i]);
		m_mL.insert_element(i, 2, lambda_list[i] * lambda_list[i]* lambda_list[i] * lambda_list[i]);
		double L = 1 / (lambda_list[i] * lambda_list[i]-0.028);
		m_mL.insert_element(i, 3, L);
		m_mL.insert_element(i, 4, L*L);
		m_mL.insert_element(i, 5, L*L*L);

		m_mQ.insert_element(i, i, 1/(sqrt(0.05*n_list[i])));
		m_vN.insert_element(i, n_list[i]);

		
			
	}
	ublas::matrix<double> temp;
	temp = prod(trans(m_mL), m_mQ);
	temp = prod(temp, m_mQ);
	temp = prod(temp, m_mL);
	bool flag = false;
	temp = gjinverse<double>(temp, flag);
	temp = prod(temp, trans(m_mL));
	temp = prod(temp, m_mQ);
	temp = prod(temp, m_mQ);
	m_vMu = prod(temp, m_vN);

}
double Medium::GetN(double lambda)
{
	double first = *m_vMu.find_element(1);
	double second = *m_vMu.find_element(2);
	double third = *m_vMu.find_element(3);
	double fouth = *m_vMu.find_element(4);
	double fifth = *m_vMu.find_element(5);
	double L = 1 / (lambda * lambda - 0.028);
	return(*m_vMu.find_element(0) + first*lambda*lambda + second*lambda*lambda*lambda*lambda + third*L + fouth*L*L + fifth*L*L*L);
}
Medium::~Medium()
{

}