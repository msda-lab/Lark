%option noyywrap

%{
    /*********** lexer for Lark parser using flex **************/
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #include "Simulator.h"
    #include "Parser.hpp"
    #include "Util.h"

    #define YY_DECL int yylex(yy::Parser::semantic_type *yylval, yy::Parser::location_type *yylloc)
    #define YY_USER_ACTION yylloc->columns(yyleng);

    typedef yy::Parser::token token;

%}

%option outfile="Scanner.cpp"


ALPHA           [A-Za-z_]
DIGIT           [0-9]
ALPHANUM        [A-Za-z_0-9]
INTEGER         [-+]?{DIGIT}+
FLOAT           [-+]?({DIGIT}*\.?{DIGIT}+|{DIGIT}+\.)([Ee][-+]?{DIGIT}+)?
RESISTOR        [Rr]{ALPHANUM}+
CAPACITOR       [Cc]{ALPHANUM}+
INDUCTOR        [Ll]{ALPHANUM}+
ISOURCE         [Ii]{ALPHANUM}+
VSOURCE         [Vv]{ALPHANUM}+
V               [Vv]
I               [Ii]
GND             [Gg][Nn][Dd]|[Gg][Rr][Oo][Uu][Nn][Dd]|0
DOTDC           [\.][Dd][Cc]
DC              [Dd][Cc]
PRINT           [\.][Pp][Rr][Ii][Nn][Tt]
PLOT            [\.][Pp][Ll][Oo][Tt]
VALUE           ({FLOAT}|{INTEGER})\s*{UNIT}
UNIT            [Ff]|[Pp]|[Nn]|[Uu]|[Mm]|[Kk]|[Mm][Ee][Gg]|[Gg][Tt]
STRING          {ALPHANUM}+
COMMENT         ^\*.*|\$.*
LP              \(
RP              \)
COMMA           ,
EQUAL           [=]
EOL             [\n\r]+
QUOTES          [\']
QUOTED          [\"]
DELIMITER       [ \t]+
END             [\.][Ee][Nn][Dd][Ss]?

%%

%{
    yylloc->step();
%}

{INTEGER}       {yylval->n = atoi(yytext); return token::INTEGER;}
{FLOAT}         {yylval->f = atof(yytext); return token::FLOAT;}
{GND}           {return token::GND;}
{V}             {return token::V;}
{I}             {return token::I;}
{DOTDC}         {return token::DOT_DC;}
{DC}            {return token::DC;}
{PRINT}         {return token::DOT_PRINT;}
{PLOT}          {return token::DOT_PLOT;}
{EQUAL}         {return token::EQUAL;}

{RESISTOR}      {yylval->s = (char*)malloc((strlen(yytext) + 1) * sizeof(char));
                strcpy(yylval->s, yytext);
                yylval->s[strlen(yytext)] = '\0';
                return token::RESISTOR;}
{CAPACITOR}     {yylval->s = (char*)malloc((strlen(yytext) + 1) * sizeof(char));
                strcpy(yylval->s, yytext);
                yylval->s[strlen(yytext)] = '\0';
                return token::CAPACITOR;}
{INDUCTOR}      {yylval->s = (char*)malloc((strlen(yytext) + 1) * sizeof(char));
                strcpy(yylval->s, yytext);
                yylval->s[strlen(yytext)] = '\0';
                return token::INDUCTOR;}
{ISOURCE}       {yylval->s = (char*)malloc((strlen(yytext) + 1) * sizeof(char));
                strcpy(yylval->s, yytext);
                yylval->s[strlen(yytext)] = '\0';
                return token::ISOURCE;}
{VSOURCE}       {yylval->s = (char*)malloc((strlen(yytext) + 1) * sizeof(char));
                strcpy(yylval->s, yytext);
                yylval->s[strlen(yytext)] = '\0';
                return token::VSOURCE;}
{VALUE}         {yylval->f = StringToValue(yytext);
                return token::VALUE;}

{COMMENT}       {}
{STRING}        {yylval->s = (char*)malloc((strlen(yytext) + 1) * sizeof(char));
                strcpy(yylval->s, yytext);
                yylval->s[strlen(yytext)] = '\0';
                return token::STRING;}
{END}           {return token::END;}
{EOL}           {return token::EOL;}
<<EOF>>         {yyterminate();}
{LP}            {return token::LP;}
{RP}            {return token::RP;}
{COMMA}         {return token::COMMA;}
{DELIMITER}     {}
{QUOTES}        {return token::QUOTES;}
{QUOTED}        {return token::QUOTED;}
.               {printf("UNKNOWN %s ", yytext);}

%%
