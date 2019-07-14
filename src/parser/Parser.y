%language "C++"
%require "3.2"
%defines
%locations

%define api.parser.class {Parser}

%{
    /*********** Parser for Lark using bison **************/
    #include <stdio.h>
    #include <stdlib.h>

    #include <iostream>
    #include <string>
    #include <map>

    #include "Manager.h"
    #include "Global.h"

    extern FILE *yyin;

    using std::cout;
    using std::endl;
    using std::string;
    using std::map;
    using std::pair;
%}

%output "Parser.cpp"
%verbose

%parse-param {Manager *manager}

%union
{
    double f;
    char *s;
    int n;
};

%{
    map<int, string> outList;
%}

// %left '+' '-'
// %left '*' '/'
// %nonassoc '|' UMINUS

%token<f> FLOAT
%token<s> STRING
%token<n> INTEGER
%token<s> RESISTOR CAPACITOR INDUCTOR ISOURCE VSOURCE
%token<f> VALUE

%type<s> resistor capacitor inductor vsource isource node
%type<f> value 
%type<s> print plot
%type<s> dc_output

%token QUOTES QUOTED LP RP COMMA EQUAL END EOL
%token DOT_DC DOT_PRINT DOT_PLOT
%token DC V I GND

%{
    extern int yylex(yy::Parser::semantic_type *yylval, yy::Parser::location_type *yylloc);
%}

%initial-action {
    @$.begin.filename = @$.end.filename = new std::string("stdin");
}

%%

spice: netlist end 
;

end: END
   | END EOL
;

netlist: line
       | netlist line
;

line: component EOL
    | method EOL
    | output EOL 
    | EOL
;

component: resistor 
         | capacitor 
         | inductor
         | vsource
         | isource
;

method: dc
;

output: print
      | plot
;

resistor: RESISTOR node node value
        {
            manager->GetCktPtr()->ParseRes($1, $2, $3, $4);
        }
;

capacitor: CAPACITOR node node value
        {
           manager->GetCktPtr()->ParseCap($1, $2, $3, $4);
        }
;

inductor: INDUCTOR node node value
        {
            manager->GetCktPtr()->ParseInd($1, $2, $3, $4);
        }
;

vsource: VSOURCE node node DC value
       {
           manager->GetCktPtr()->ParseVSource($1, $2, $3, $5, 0);
       }
       | VSOURCE node node value
       {
           manager->GetCktPtr()->ParseVSource($1, $2, $3, $4, 0);
       }
;

isource: ISOURCE node node DC value
       {
           manager->GetCktPtr()->ParseISource($1, $2, $3, $5, 0);
       }
       | ISOURCE node node value
       {
           manager->GetCktPtr()->ParseISource($1, $2, $3, $4, 0);
       }
;

dc: DOT_DC VSOURCE value value value
  {
      manager->ParseDCAnalysis($2, $3, $4, $5);
  }
  | DOT_DC VSOURCE value value value VSOURCE value value value
  {
      manager->ParseDCAnalysis($2, $3, $4, $5, $6, $7, $8, $9);
  }
;

print: DOT_PRINT DC dc_output
     {
         manager->ParsePrint(DC_TYPE, outList);
         outList.clear();
     }
;

plot: DOT_PLOT DC dc_output
    {
        manager->ParsePlot(DC_TYPE, outList);
        outList.clear();
    }
;

dc_output: V LP node RP
          {
              outList.insert(pair<int, string>(V_TYPE, $3));
          }
          | I LP node RP
          {
              outList.insert(pair<int, string>(I_TYPE, $3));
          }
          | V LP node COMMA node RP
          {
              string out = $3;
              out += ",";
              out += $5;
              outList.insert(pair<int, string>(V_TYPE, out));
          }
          | I LP node COMMA node RP
          {
              string out = $3;
              out += ",";
              out += $5;
              outList.insert(pair<int, string>(I_TYPE, out));
          }  
          | dc_output V LP node RP
          {
              outList.insert(pair<int, string>(V_TYPE, $4));
          }
          | dc_output I LP node RP
          {
              outList.insert(pair<int, string>(I_TYPE, $4));
          }
          | dc_output V LP node COMMA node RP
          {
              string out = $4;
              out += ",";
              out += $6;
              outList.insert(pair<int, string>(V_TYPE, out));
          }
          | dc_output  I LP node COMMA node RP
          {
              string out = $4;
              out += ",";
              out += $6;
              outList.insert(pair<int, string>(I_TYPE, out));
          } 
;

node: INTEGER
    {
        char s[35];
        sprintf(s, "%d", $1);
        $$ = new char[strlen(s) + 1];
        strcpy($$, s);
        $$[strlen(s) + 1] = '\0';
    }
    | STRING
    {
        $$ = new char[strlen($1) + 1];
        strcpy($$, $1);
        $$[strlen($1) + 1] = '\0';
    }
    | GND
    {
        $$ = new char[2];
        $$[0] = '0';
        $$[1] = '\0';
    }
;

value: INTEGER
     {
         $$ = $1;
     }
     | FLOAT
     {
         $$ = $1;
     }
     | VALUE
     {
         $$ = $1;
     }
;

%%

namespace yy 
{
	void Parser::error(location const &loc, const string &s) 
	{
        cout << s << endl;
    }
}

