#include"medium.h"
#include"perevorot.h"
#include<iostream>

void main()
{
	std::vector<double>l;
	std:: vector<double>n;
	n.push_back(1.567959);
	n.push_back(1.552822);
	n.push_back(1.548860);
	n.push_back(1.544111);
	n.push_back(1.542578);
	n.push_back(1.536686);
	l.push_back(0.36501);
	l.push_back(0.48613);
	l.push_back(0.54607);
	l.push_back(0.65628);
	l.push_back(0.70652);
	l.push_back(1.01398);
	Medium c(l, n);

	std::cout<<"n(lambda=0.45561) = "<<" "<<c.GetN(0.45561)<< "\n";
	std::cout << "n(lambda=0.64380) = " << " " << c.GetN(0.64380)<< "\n";
	std::cout << "n(lambda=0.58930) = " << " " <<  c.GetN(0.58930)<< "\n";
	system("pause");
}