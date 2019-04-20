%{
    #include<stdlib.h>
    #include<string.h>
    #include"syntax.tab.h"
    #include"SymTable.h"
    int yycolumn=1;
    #define YY_USER_ACTION \
        yylloc.first_line=yylloc.last_line=yylineno; \
        yylloc.first_column=yycolumn; \
        yylloc.last_column=yycolumn + yyleng -1; \
        yycolumn += yyleng;
%}
%option yylineno
WHITESPACE ((" "|"\t"|"\r"|"\a")+)
DIGIT [0-9]
DECDIGIT [0-9a-fA-F]
DIGITWITHOUTZERO [1-9]
OCTDIGIT [0-7]
DIGITS {DIGIT}+
OCTDIGITS {OCTDIGIT}+
LETTER [A-Za-z]
LETTER_ ({LETTER}|"_")
/*LJY_0322*/

NUM_ALP [0-9A-Za-z]
INT_HEX (("0x"){DECDIGIT}+|("0X"{DECDIGIT}+))
INT_OCT (("0"){OCTDIGIT}+)
INT_DEC ("0"|{DIGITWITHOUTZERO}{DIGIT}*)
INT_HEX_ERROR1 (("0x"){NUM_ALP}+|("0X"{NUM_ALP}+))
INT_HEX_ERROR2 (("0x")({NUM_ALP}|("."))+|("0X"({NUM_ALP}|("."))+))
INT_OCT_ERROR (("0"){NUM_ALP}+)
INT_DEC_ERROR ({DIGIT}{NUM_ALP}*)

INT ({INT_DEC}|{INT_HEX}|{INT_OCT})
FLOAT ({DIGIT}+("."){DIGIT}+)
/*LJY_0322*/
FLOAT_ERROR1 ({DIGIT}+(".")({DIGIT}|("."))+)
FLOAT_ERROR2 ({DIGIT}+("."))
FLOAT_ERROR3 ((".")+({DIGIT}|("."))+)

ID ({LETTER_}({LETTER_}|{DIGIT})*)
SEMI ";"
COMMA ","
ASSIGNOP "="
RELOP (">"|"<"|">="|"<="|"=="|"!=")
PLUS "+"
MINUS "-"
STAR "*"
DIV "/"
AND "&&"
OR "||"
DOT "."
NOT "!"
TYPE ("int"|"float")
LP "("
RP ")"
LB "["
RB "]"
LC "{"
RC "}"
STRUCT "struct"
RETURN "return"
IF "if"
ELSE "else"
WHILE "while"
%%
{WHITESPACE} {}
"\n"    {yycolumn = 1;}
{SEMI}  {//printf("SEMI\n");
            return SEMI;    
        }
{COMMA} {//printf("COMMA\n");
            return COMMA;
        }
{ASSIGNOP}  {//printf("ASSIGNOP\n");
                return ASSIGNOP;
            }
{RELOP} {//printf("RELOP\n");
            return RELOP;
        }
{PLUS}  {//printf("s\n");
            return PLUS;
        }
{MINUS} {//printf("MINUS\n");
            return MINUS;
        }
{STAR}  {//printf("STAR\n");
            return STAR;
        }
{DIV}   {//printf("DIV\n");
            return DIV;
        }
{AND}   {//printf("AND\n");
            return AND;
        }
{OR}    {//printf("OR\n");
            return OR;
        }
{DOT}   {//printf("DOT\n");
            return DOT;
        }
{NOT}   {//printf("NOT\n");
            return NOT;
        }
{TYPE}  {//printf("TYPE\n");
            yylval.type_char_pointer=mstrdup(yytext);
            return TYPE;
        }
{LP}    {//printf("LP\n");
            return LP;
        }
{RP}    {//printf("RP\n");
            return RP;
        }
{LB}    {//printf("LB\n");
            return LB;
        }
{RB}    {//printf("RB\n");
            return RB;
        }
{LC}    {//printf("LC\n");
            return LC;
        }
{RC}    {//printf("RC\n");
            return RC;
        }
{STRUCT}    {//printf("STRUCT\n");
                return STRUCT;
            }
{RETURN}    {//printf("RETURN\n");
                return RETURN;
            }
{IF}    {//printf("IF\n");
            return IF;
        }
{ELSE}  {//printf("ELSE\n");
            return ELSE;
        }
{WHILE} {//printf("WHILE\n");
            return WHILE;
        }
{ID}    {//printf("ID\n");
            yylval.type_char_pointer=mstrdup(yytext);
            return ID;
        }
{INT}   {//printf("INT\n");
            //yylval.type_int=atoi(yytext);
            yylval.type_char_pointer=mstrdup(yytext);
            return INT;
        }
{FLOAT} {//printf("FLOAT\n");
            //yylval.type_float=atof(yytext);
            yylval.type_char_pointer=mstrdup(yytext);
            return FLOAT;
        }
<<EOF>> {return 0;}
 /* LJY_0322 */
{INT_HEX_ERROR1} {
		ISOK=false;
        /*LGY_0323*/
		char desc[100];
        sprintf(desc,"unrecognized hexadecimal character \'%s\'",yytext);
		ShowError(T_ERROR_A,yylineno);
		printf("%s\n",desc);
        /*LGY_0323*/
        yylval.type_char_pointer=mstrdup(yytext);
		return INT;
		}
{INT_HEX_ERROR2} {
		ISOK=false;
		char desc[100];
        sprintf(desc,"cannot define float in hexadecimal format \'%s\'",yytext);
		ShowError(T_ERROR_A,yylineno);
		printf("%s\n",desc);
        yylval.type_char_pointer=mstrdup(yytext);
		return INT;
		}
{INT_OCT_ERROR} {
		ISOK=false;
		char desc[100];
        sprintf(desc,"unrecognized octal character, please use 0-7 \'%s\'",yytext);
		ShowError(T_ERROR_A,yylineno);
		printf("%s\n",desc);
        yylval.type_char_pointer=mstrdup(yytext);
		return INT;
		}
{INT_DEC_ERROR} {
		ISOK=false;
		char desc[100];
        sprintf(desc,"unrecognized character, please use digital characters \'%s\'",yytext);
		ShowError(T_ERROR_A,yylineno);
		printf("%s\n",desc);
        yylval.type_char_pointer=mstrdup(yytext);
		return INT;
		}
{FLOAT_ERROR1} {
		ISOK=false;
		char desc[100];
        sprintf(desc,"too many decimal points in number \'%s\'",yytext);
		ShowError(T_ERROR_A,yylineno);
		printf("%s\n",desc);
        yylval.type_char_pointer=mstrdup(yytext);
		return FLOAT;
		}
{FLOAT_ERROR2} {
		ISOK=false;
		char desc[100];
        sprintf(desc,"there must be at least one number after dot in float\'%s\'",yytext);
		ShowError(T_ERROR_A,yylineno);
		printf("%s\n",desc);
        yylval.type_char_pointer=mstrdup(yytext);
		return FLOAT;
		}
{FLOAT_ERROR3} {
		ISOK=false;
		char desc[100];
        sprintf(desc,"there must be at least one number before dot in float\'%s\'",yytext);
		ShowError(T_ERROR_A,yylineno);
		printf("%s\n",desc);
        yylval.type_char_pointer=mstrdup(yytext);
		return FLOAT;
		}

.       {
            ISOK=false;
			//LJY_0322
			char desc[100];
            sprintf(desc,"Mysterious characters \'%s\'",yytext);
			ShowError(T_ERROR_A,yylineno);
			printf("%s\n",desc);
        }
%%
int yywrap(){
    return 1;
}
