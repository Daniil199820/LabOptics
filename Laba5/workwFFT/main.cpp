#include<iostream>
#include<fstream>
#include"stdafx.h"
#include"sample.h"
#include"SampleComplex.h"
#include"ffth.h"

void main()
{
	ofstream file1("sample.txt");//выборка
	ofstream file2("spektreal.txt");//спектр
	ofstream file3("spektrimg.txt");
	ofstream file4("ftwoid.txt");
	ofstream file5("ftwo.txt");
	ofstream file6("fur2did.txt");
	ofstream file7("fur2d.txt");
	SampleComplex asd(256);
	SampleComplex ftwoid(256, 256);
	SampleComplex ftwo(256, 256);
	ftwoid.CreateCirc(0.0625);
	ftwoid.PrintIntens(file4);
	ftwo.CreatePupil(0.0625);
	ftwo.PrintReal(file5);
	file5.close();
	asd.Create1DFunc(0.0625);
	asd.PrintReal(file1);
	file1.close();
	FFT furje(256, 1, FFT::eDirect, FFT::e1D);
	furje.Run(asd);
	asd.PrintReal(file2);
	asd.PrintImag(file3);
	FFT furje2(256, 256, FFT::eReverse, FFT::e2D);
	furje2.Run(ftwoid);
	ftwoid * ftwoid;
	double d = 1 / PI/PI ;
	std::complex<double>s(d, 0);
	ftwoid *= s;
	ftwoid.PrintReal(file6);
	furje2.Run(ftwo);
	ftwo * ftwo;
	double d2 = 1 / PI/PI;
	std::complex<double>s2(d2, 0);
	ftwo *= s2;
	ftwo.PrintReal(file7);
	file3.close();
	file2.close();

}