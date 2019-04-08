#if !defined  SAMPLE_H
#define SAMPLE_H

#include <iostream>
#include <vector>
#include <cmath>
#include <exception>
/////////////////////////////////////////////////////////////////////////////
template <class PAR>
class Sample
{
protected:
	// ����� ��������� ������� �� x � y
	int m_size_x, m_size_y;
	// ��������� �� ������������ ������ ������
	std::vector<PAR> m_data;

public:
	// ������ ����������� ��������
	explicit Sample();
	// ������ �����������
	Sample(int size_x, int size_y);
	// ����������
	~Sample();

	// ������ ������� �� X
	int GetSizeX() const;
	// ������ ������� �� Y
	int GetSizeY() const;
	// �������� ��������� �������� �������� � ������� i,j
	PAR& operator()(int i, int j);
	// �������� ��������� const �������� �������� � ������� i,j
	const PAR& operator()(int i, int j) const;

	// ��������� ��������� �� ��� �������
	PAR* GetPointer();

	// ������������� ���� ��������� ������� ���������� ���������
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
	template <class PAR>
	friend std::ostream& operator<<(std::ostream& out, Sample<PAR>& other);
	// ���������� ��������� ������ ������� �� ����� (����������� �� X � Y ������� �����������)
	template <class PAR>
	friend std::istream& operator>>(std::istream& out, Sample<PAR>& other);

	// ���������� �������� ���������� ����� �� x
	// i - ����� �����
	// dx - ��� �� �������
	double CalcCoordX(int i, double dx = 1.) const;
	// ���������� �������� ���������� ����� �� y
	// i - ����� �����
	// dy - ��� �� �������
	double CalcCoordY(int i, double dy = 1.) const;
};
/////////////////////////////////////////////////////////////////////////////
//������ �����������
template<class PAR>
Sample<PAR>::Sample()
{

}
// ������ �����������
template <class PAR>
Sample<PAR>::Sample(int size_x, int size_y)
{
	m_size_x = size_x;
	m_size_y = size_y;
	m_data.resize(m_size_x*m_size_y);
}
/////////////////////////////////////////////////////////////////////////////
// ����������
template <class PAR>
Sample<PAR>::~Sample()
{
}
/////////////////////////////////////////////////////////////////////////////
// ������ ������� �� X
template <class PAR>
int Sample<PAR>::GetSizeX() const
{
	return(m_size_x);
}
/////////////////////////////////////////////////////////////////////////////
// ������ ������� �� Y
template <class PAR>
int Sample<PAR>::GetSizeY() const
{
	return(m_size_y);
}
/////////////////////////////////////////////////////////////////////////////
// �������� ��������� �������� �������� � ������� i,j
template <class PAR>
PAR& Sample<PAR>::operator()(int i, int j)
{
	return (m_data[j*m_size_x + i]);
}
/////////////////////////////////////////////////////////////////////////////
// �������� ��������� const �������� �������� � ������� i,j
template <class PAR>
const PAR& Sample<PAR>::operator()(int i, int j) const
{
	return (m_data[j*m_size_x + i]);
}
/////////////////////////////////////////////////////////////////////////////
// ��������� ��������� �� ��� �������
template <class PAR>
PAR* Sample<PAR>::GetPointer()
{
	return &m_data[0];
}
/////////////////////////////////////////////////////////////////////////////
// ������������� ���� ��������� ������� ���������� ���������
template <class PAR>
void Sample<PAR>::SetValue(PAR value)
{
	for (size_t i = 0; i < m_data.size(); i++)
	{
		m_data[i] = value;
	}
}
/////////////////////////////////////////////////////////////////////////////
// �������� ���� ��������� ������� � �����
template <class PAR>
Sample<PAR>& Sample<PAR>::operator+=(PAR value)
{
	for (size_t i = 0; i < m_data.size(); i++)
	{
		m_data[i] += value;
	}
	return *this;
}
/////////////////////////////////////////////////////////////////////////////
// ��������� ���� ��������� ������� �� �����
template <class PAR>
Sample<PAR>& Sample<PAR>::operator*=(PAR value)
{
	for (size_t i = 0; i < m_data.size(); i++)
	{
		m_data[i] *= value;
	}
	return *this;
}
/////////////////////////////////////////////////////////////////////////////
// ������� ���� ��������� ������� �� �����
template <class PAR>
Sample<PAR>& Sample<PAR>::operator/=(PAR value)
{
	for (size_t i = 0; i < m_data.size(); i++)
	{
		m_data[i] /= value;
	}
	return *this;
}
/////////////////////////////////////////////////////////////////////////////
// ������������
template <class PAR>
Sample<PAR>& Sample<PAR>::operator=(const Sample<PAR> &temp)
{
	m_size_x = temp.m_size_x;
	m_size_y = temp.m_size_y;
	m_data = temp.m_data;

	return *this;
}
/////////////////////////////////////////////////////////////////////////////
// ������������ �������� ���� �������
template <class PAR>
Sample<PAR>& Sample<PAR>::operator+=(const Sample<PAR> &temp)
{
	if (m_size_x != temp.m_size_x || m_size_y != temp.m_size_y)
		throw("Sample::operator+= - samples sizes not valid");

	for (size_t i = 0; i < m_data.size(); i++)
	{
		m_data[i] += temp.m_data[i];
	}
	return *this;
}
/////////////////////////////////////////////////////////////////////////////
// ������������ ������������ ���� �������
template <class PAR>
Sample<PAR>& Sample<PAR>::operator*=(const Sample<PAR> &temp)
{
	if (m_size_x != temp.m_size_x || m_size_y != temp.m_size_y)
		throw("Sample::operator+= - samples sizes not valid");

	for (size_t i = 0; i < m_data.size(); i++)
	{
		m_data[i] *= temp.m_data[i];
	}
	return *this;
}
/////////////////////////////////////////////////////////////////////////////
// ���������� �������� ���������� ����� �� X
// i - ����� �����
// dx - ��� �� �������
template <class PAR>
double Sample<PAR>::CalcCoordX(int i, double dx) const
{
	return (i - m_size_x / 2.)*dx;
}
/////////////////////////////////////////////////////////////////////////////
// ���������� �������� ���������� ����� �� Y
// i - ����� �����
// dy - ��� �� �������
template <class PAR>
double Sample<PAR>::CalcCoordY(int i, double dy) const
{
	return (i - m_size_y / 2.)*dy;
}
/////////////////////////////////////////////////////////////////////////////
// ���������� ��������� ������ ������� � ����
template <class PAR>
std::ostream& operator<<(std::ostream& out, Sample<PAR> &other)
{
	for (size_t i = 0; i < other.m_size_x; i++)
	{
		for (size_t j = 0; j < other.m_size_y; j++)
		{
			out << other(i, j) << " ";
		}
		out << endl;
	}
	return out;
}
/////////////////////////////////////////////////////////////////////////////
// ���������� ��������� ������ ������� �� ����� (����������� �� X � Y ������� �����������)
template <class PAR>
std::istream& operator>>(std::istream& out, Sample<PAR> &other)
{
	// ������ ���������� ��������� �� �����
	std::vector<PAR> data;
	PAR value;
	// ���� ����� ����������� �� ��� ���, ���� �� ����������� ����� �����
	while (!out.eof())
	{
		out >> value;           // ������ ����� �� �����
		data.push_back(value);// ���������� ����������� ����� � ����� ����������
	}

	// �������� ����������� ������������ ����������
	size_t size = size_t(std::sqrt(double(data.size())));
	if (size*size != data.size())
		throw std::runtime_error("Wrong file size: impossible create square array.");

	// �������� ������� ������������ �������
	other.m_size_x = other.m_size_y = size;
	other.m_data = data;
	return out;
}
/////////////////////////////////////////////////////////////////////////////

#endif
