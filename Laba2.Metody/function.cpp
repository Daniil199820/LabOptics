#include "function.h"
Function::Function()
{

}
Function::~Function()
{

}
double Function::Proba(double x)
{
	return (x*x + 1);
}
double Function::ProbaIntegral(double a, double b)
{
	return((b*b*b / 3 + b) - (a*a*a / 3 + a));
}

