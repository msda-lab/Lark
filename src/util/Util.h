#ifndef UTIL_H
#define UTIL_H

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#include <iostream>
#include <string>
#include <map>

#include "Global.h"

using std::string;
using std::map;
using std::cout;
using std::endl;

double StringToValue(char *s);

void DisplayAnalysis(int anaType, const map<int, string> &_output);

Complex GetComplexValue(double _mag, double _phase);

#endif
