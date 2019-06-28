#pragma once


#include <ostream>
#include <iostream>
#include <fstream>
using namespace std;
//-------------------------------------------------------------------------------------------------
template <class PAR>
class Sample
{
protected:
	// ����� ��������� ������� (���������� �� x � y)
	int m_size_x;
	int m_size_y;
	// ��������� �� ������������ ������ ������
	PAR* m_data;

public:
	// ������ ����������� ��������
	explicit Sample();
	// ������ �����������
	// size - ���������� ���������, ���������� �� x � y (size*size)
	Sample(int size_x,int size_y);
	// ����������
	virtual ~Sample();

	// ������ �������
	int GetSize() const;
	// �������� ��������� �������� �������� � ������� i,j
	PAR& operator()(int i, int j);
	// �������� ��������� const �������� �������� � ������� i,j
	const PAR& operator()(int i, int j) const;

	// ��������� ��������� �� ������ ������
	PAR* GetPointer();

	// ������������� ���� ��������� ������� ���������� ��������� value
	void SetValue(PAR value);

	// �������� � �������� � ������
	// �������� ���� ��������� ������� � �����
	Sample<PAR>& operator+=(PAR value);
	// ��������� ���� ��������� ������� �� �����
	Sample<PAR>& operator*=(PAR value);
	// ������� ���� ��������� ������� �� �����
	Sample<PAR>& operator/=(PAR value);

	// �������� � ����� ���������
	// ������������
	Sample<PAR>& operator= (const Sample<PAR> &temp);
	// ������������ �������� ���� �������
	Sample<PAR>& operator+=(const Sample<PAR> &temp);
	// ������������ ������������ ���� �������
	Sample<PAR>& operator*=(const Sample<PAR> &temp);

	// ���������� ��������� ������ ������� � ����
	friend ostream& operator<< (ostream& out, const Sample& other);

	// ���������� �������� ���������� ����� � ������������ i
	// (������� ����������, ������� ���������� ����� �������)
	// i - ����� �����
	// dx - ��� �� �������
	double CalcCoord(int i, double dx = 1.) const;
};
template<class PAR>
Sample<PAR>::Sample()
{

}
// ������ �����������
template <class PAR>
Sample<PAR>::Sample(int size_x,int size_y)
{
	m_size_x = size_x;
	m_size_y = size_y;
	m_data = new PAR[m_size_x*m_size_y];
}

// ����������
template <class PAR>
Sample<PAR>::~Sample()
{
	delete[] m_data;
}

// ������ �������
template <class PAR>
int Sample<PAR>::GetSize() const
{
	return(m_size_x);
}

// �������� ��������� �������� �������� � ������� i,j
template <class PAR>
PAR& Sample<PAR>::operator()(int i, int j)
{
	return (m_data[j*m_size_x + i]);
}

// �������� ��������� const �������� �������� � ������� i,j
template <class PAR>
const PAR& Sample<PAR>::operator()(int i, int j) const
{
	return (m_data[j*m_size_x + i]);
}

// ��������� ��������� 
template <class PAR>
PAR* Sample<PAR>::GetPointer()
{
	return m_data;
}

// ������������� ���� ��������� ������� ���������� ���������
template <class PAR>
void Sample<PAR>::SetValue(PAR value)
{
	for (int i = 0; i<m_size_x*m_size_x; i++)
	{
		m_data[i] = value;
	}
}

// �������� ���� ��������� ������� � �����
template <class PAR>
Sample<PAR>& Sample<PAR>::operator+=(PAR value)
{
	for (int i = 0; i<m_size_x*m_size_x; i++)
	{
		m_data[i] += value;
	}
	return *this;
}

// ��������� ���� ��������� ������� �� �����
template <class PAR>
Sample<PAR>& Sample<PAR>::operator*=(PAR value)
{
	for (int i = 0; i<m_size_x*m_size_y; i++)
	{
		m_data[i] *= value;
	}
	return *this;
}

// ������� ���� ��������� ������� �� �����
template <class PAR>
Sample<PAR>& Sample<PAR>::operator/=(PAR value)
{
	for (int i = 0; i<m_size_x*m_size_x; i++)
	{
		m_data[i] /= value;
	}
	return *this;
}

// ������������
template <class PAR>
Sample<PAR>& Sample<PAR>::operator=(const Sample<PAR> &temp)
{
	m_size_x = temp.m_size_x;
	m_size_y = temp.m_size_y;
	delete[] m_data;
	m_data = new PAR[m_size_x*m_size_x];

	for (int i = 0; i<m_size_x*m_size_x; i++)
	{
		m_data[i] = temp.m_data[i];
	}
	return *this;
}


// ������������ �������� ���� �������
template <class PAR>
Sample<PAR>& Sample<PAR>::operator+=(const Sample<PAR> &temp)
{
	if (m_size_x != temp.m_size_x)
		throw("Sample::operator+= - samples sizes not valid");

	for (int i = 0; i<m_size_x*m_size_x; i++)
	{
		m_data[i] += temp.m_data[i];
	}
	return *this;
}

// ������������ ������������ ���� �������
//template <class PAR>
//Sample<PAR>& Sample<PAR>::operator*=(const Sample<PAR> &temp)
//{
//	if (m_size_x != temp.m_size_x)
//		throw("Sample::operator+= - samples sizes not valid");
//
//	for (int i = 0; i<m_size_x*m_size_x; i++)
//	{
//		m_data[i] *= temp.m_data[i];
//	}
//	return *this;
//}

// ���������� �������� ���������� �����
// i - ����� �����
// dx - ��� �� �������
template <class PAR>
double Sample<PAR>::CalcCoord(int i, double dx) const
{
	return (i - m_size_x / 2.)*dx;
}
// ���������� ��������� ������ ������� � ����
template <class PAR>
ostream& operator<<(ofstream& out, const Sample<PAR> &other)
{
	for (int i = 0; i<other.GetSize(); i++)
	{
		for (int j = 0; j<other.GetSize(); j++)
		{
			out << other(i, j) << " ";
		}
		out << endl;
	}
	return out;
}

