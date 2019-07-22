#include <stdlib.h>

#include <iostream>
#include <fstream>

#include "Simulator.h"
#include "Parser.hpp"

extern FILE *yyin;
using namespace std;


void PrintLicense();
void PrintUsage();


int main(int argc, char *argv[])
{
	PrintLicense();

	if(argv[1] != NULL)
	{
		yyin = fopen(argv[1], "r");
		if(yyin == NULL)
		{
			cout << argv[1] << " is invaild." << endl;
			PrintUsage();
			return 0;
		}
	} 
	else 
	{
		cout << "Please set netlist file" << endl;
		PrintUsage();
		return 0;
	}

	string fileName = argv[1];
	Simulator *simulator = new Simulator(fileName);
	yy::Parser parser(simulator);
	parser.parse();

    //simulator->GetCktPtr()->PrintAllDevice();
    //simulator->GetCktPtr()->PrintAllNode();
    //simulator->GetCktPtr()->PrintAllModel();

    simulator->Simulate();
	
	if(!yyin)
		fclose(yyin);
    return 0;
}


void PrintLicense()
{
	cout << "\n" << endl;
	cout << "******************************* Lark *******************************" << endl;
	cout << "*   Lark is a SPICE-like circuit simulator for research purpose.   *" << endl;
	cout << "*   Author: Hao Limin, Wu Yuntao. MSDA Lab in SJTU. Since 2019.07  *" << endl;
	cout << "*   Copyright (C) 2019, All rights reserved.                       *" << endl;
	cout << "********************************************************************" << endl;
	cout << "\n" << endl;
}


void PrintUsage()
{
	cout << "Usage: lark netlist" << endl;
}
