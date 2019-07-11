#ifndef UTIL_H
#define UTIL_H

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#include <iostream>
#include <string>
#include <map>

#include "GlobalDef.h"

using std::string;
using std::map;
using std::cout;
using std::endl;

double str2val(char *s);

void displayAnalysis(int anaType, const map<int, string> &output);

#endif
