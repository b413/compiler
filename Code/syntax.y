%{
    #include<stdio.h>
    #include<malloc.h>
    #include<string.h>
    #include"lex.yy.c"
    #include"Tree.h"
	#include"Kits.h"
%}
%union{
    int type_int;
    float type_float;
    struct Tnode* type_Node_pointer;
    char* type_char_pointer;
}
%token <type_char_pointer> INT
%token <type_char_pointer> FLOAT
%token <type_char_pointer> ID
%token <type_char_pointer> TYPE
%token <type_Node_pointer> SEMI COMMA ASSIGNOP RELOP
%token <type_Node_pointer> PLUS MINUS STAR DIV 
%token <type_Node_pointer> AND OR DOT NOT
%token <type_Node_pointer> LP RP LB RB LC RC
%token <type_Node_pointer> STRUCT RETURN IF ELSE WHILE

%type <type_Node_pointer> Program ExtDefList ExtDef ExtDecList
%type <type_Node_pointer> Specifier StructSpecifier OptTag Tag
%type <type_Node_pointer> VarDec FunDec VarList ParamDec
%type <type_Node_pointer> CompSt StmtList Stmt
%type <type_Node_pointer> DefList Def DecList Dec
%type <type_Node_pointer> Exp Args

%right ASSIGNOP
%left OR
%left AND
%left RELOP
%left PLUS MINUS
%left STAR DIV
%right NOT TAKENEGATIVE 
%left LP RP LB RB DOT

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%
Program : ExtDefList { $$=Reduction(T_Program, NULL, @$.first_line, 1, $1); /*if(ISOK==true && ROOT!=NULL) Traverse(ROOT,0);*/ }
        ;
		
ExtDefList : ExtDef ExtDefList { $$=Reduction(T_ExtDefList, NULL, @$.first_line, 2, $1, $2);}
           |    /* empty */ { $$=Reduction(T_ExtDefList, NULL, @$.first_line, 0);}
           ;
/*LGY_0324*/
/*ExtDef : error SEMI {};*/
/*ExtDef : Specifier error SEMI {};*/
ExtDef : Specifier ExtDecList SEMI error ID SEMI{};

ExtDef : Specifier ExtDecList SEMI { $3=Reduction(T_SEMI, NULL, @$.first_line, 0);
									$$=Reduction(T_ExtDef, NULL, @$.first_line, 3,$1,$2,$3);}
       | Specifier SEMI { $2=Reduction(T_SEMI, NULL, @$.first_line, 0);
							$$=Reduction(T_ExtDef, NULL, @$.first_line, 2,$1,$2);}
       | Specifier FunDec CompSt { $$=Reduction(T_ExtDef, NULL, @$.first_line, 3,$1,$2,$3);}
       | Specifier FunDec SEMI { $3=Reduction(T_SEMI, NULL, @$.first_line, 0);
									$$=Reduction(T_ExtDef, NULL, @$.first_line, 3,$1,$2,$3);}
       ;
	   
ExtDecList : VarDec { $$=Reduction(T_ExtDecList, NULL, @$.first_line, 1,$1);}
           | VarDec COMMA ExtDecList { $2=Reduction(T_COMMA, NULL, @$.first_line, 0);
										$$=Reduction(T_ExtDecList, NULL, @$.first_line, 3,$1,$2,$3);}
           ;

Specifier : TYPE { struct Tnode* n=Reduction(T_TYPE, $1, @$.first_line, 0);
					$$=Reduction(T_Specifier, NULL, @$.first_line, 1,n);}
          | StructSpecifier { $$=Reduction(T_Specifier, NULL, @$.first_line, 1,$1); }
          ;
		 
StructSpecifier : STRUCT OptTag LC DefList RC { $1=Reduction(T_STRUCT, NULL, @$.first_line, 0);
												$3=Reduction(T_LC, NULL, @$.first_line, 0);
												$5=Reduction(T_RC, NULL, @$.first_line, 0);
												$$=Reduction(T_StructSpecifier, NULL, @$.first_line, 5,$1,$2,$3,$4,$5); }

                | STRUCT Tag { $1=Reduction(T_STRUCT, NULL, @$.first_line, 0); 
								$$=Reduction(T_StructSpecifier, NULL, @$.first_line, 2,$1,$2);}
                ;

/*LGY_0324*/
StructSpecifier : STRUCT OptTag LC error RC {};

/*LJY_0414 add SymbleCount due to struct defination*/
OptTag : ID { struct Tnode* n=Reduction(T_ID, $1, @$.first_line, 0);$$=Reduction(T_OptTag, NULL, @$.first_line, 1,n); 
	   		SymTableSize++; }
       | /* empty */ { $$=Reduction(T_OptTag, NULL, @$.first_line, 0);SymTableSize++; }
       ;
	   
Tag : ID {struct Tnode* n=Reduction(T_ID, $1, @$.first_line, 0);$$=Reduction(T_Tag, NULL, @$.first_line, 1,n); } 
    ;
/*LJY_0414 add SymbleCount due to global var*/
VarDec : ID {   struct Tnode* n=Reduction(T_ID, $1, @$.first_line, 0);
				$$=Reduction(T_VarDec, NULL, @$.first_line, 1,n);
				SymTableSize++;	}
       | VarDec LB INT RB { $2=Reduction(T_LB, NULL, @$.first_line, 0);
							struct Tnode* n=Reduction(T_INT,$3,@$.first_line,0);
							$4=Reduction(T_RB, NULL, @$.first_line, 0);
							$$=Reduction(T_VarDec, NULL, @$.first_line, 4,$1,$2,n,$4);}
       ;

/*LGY_0324*/
VarDec : VarDec LB error RB {};

/*LJY_0414 add SymbleCount due to global */
FunDec : ID LP VarList RP { struct Tnode* n=Reduction(T_ID, $1, @$.first_line, 0);
							$2=Reduction(T_LP, NULL, @$.first_line, 0);
							$4=Reduction(T_RP, NULL, @$.first_line, 0);
							$$=Reduction(T_FunDec, NULL, @$.first_line, 4,n,$2,$3,$4);
							SymTableSize++; }
       | ID LP RP {struct Tnode* n=Reduction(T_ID, $1, @$.first_line, 0);
							$2=Reduction(T_LP, NULL, @$.first_line, 0);
							$3=Reduction(T_RP, NULL, @$.first_line, 0);
							$$=Reduction(T_FunDec, NULL, @$.first_line, 3,n,$2,$3);
							SymTableSize++; }
       ;

/*LGY_0324*/
/*FunDec : ID LP error RP {yyerrok;};*/
	   
VarList : ParamDec COMMA VarList { $2=Reduction(T_COMMA, NULL, @$.first_line, 0);
									$$=Reduction(T_VarList, NULL, @$.first_line, 3,$1,$2,$3);}
        | ParamDec { $$=Reduction(T_VarList, NULL, @$.first_line, 1,$1);}
        ;
		
ParamDec : Specifier VarDec { $$=Reduction(T_ParamDec, NULL, @$.first_line, 2,$1,$2);} 
         ;

CompSt : LC DefList StmtList RC { $1=Reduction(T_LC, NULL, @$.first_line, 0);
									$4=Reduction(T_RC, NULL, @$.first_line, 0);
									$$=Reduction(T_CompSt, NULL, @$.first_line, 4,$1,$2,$3,$4);} 
       ;

	   
StmtList : Stmt StmtList { $$=Reduction(T_StmtList, NULL, @$.first_line, 2,$1,$2);}
         | /* empty */ { $$=Reduction(T_StmtList, NULL, @$.first_line, 0);}
         ;
		 
Stmt : error SEMI {};


Stmt : Exp SEMI { $2=Reduction(T_SEMI, NULL, @$.first_line, 0);
					$$=Reduction(T_Stmt, NULL, @$.first_line, 2,$1,$2);}
     | CompSt { $$=Reduction(T_Stmt, NULL, @$.first_line, 1,$1);}
     | RETURN Exp SEMI { $1=Reduction(T_RETURN, NULL, @$.first_line, 0);
						$3=Reduction(T_SEMI, NULL, @$.first_line, 0);
						$$=Reduction(T_Stmt, NULL, @$.first_line, 3,$1,$2,$3);}
     | IF LP Exp RP Stmt %prec LOWER_THAN_ELSE { $1=Reduction(T_IF, NULL, @$.first_line, 0);
												$2=Reduction(T_LP, NULL, @$.first_line, 0);
												$4=Reduction(T_RP, NULL, @$.first_line, 0);
												$$=Reduction(T_Stmt, NULL, @$.first_line, 5,$1,$2,$3,$4,$5);}
     | IF LP Exp RP Stmt ELSE Stmt { $1=Reduction(T_IF, NULL, @$.first_line, 0);
									$2=Reduction(T_LP, NULL, @$.first_line, 0);
									$4=Reduction(T_RP, NULL, @$.first_line, 0);
									$6=Reduction(T_ELSE, NULL, @$.first_line, 0);
									$$=Reduction(T_Stmt, NULL, @$.first_line, 7,$1,$2,$3,$4,$5,$6,$7);}
     | WHILE LP Exp RP Stmt { $1=Reduction(T_WHILE, NULL, @$.first_line, 0);
							$2=Reduction(T_LP, NULL, @$.first_line, 0);
							$4=Reduction(T_RP, NULL, @$.first_line, 0);
							$$=Reduction(T_Stmt, NULL, @$.first_line, 5,$1,$2,$3,$4,$5);}
     ;

/*LGY_0324*/
Stmt : RETURN Exp error{};
Stmt : IF LP error RP Stmt %prec LOWER_THAN_ELSE {};
Stmt : IF LP error RP Stmt ELSE Stmt {};
Stmt : WHILE LP error RP Stmt{};
	
DefList : Def DefList { $$=Reduction(T_DefList, NULL, @$.first_line, 2,$1,$2);}
        | /* empty */ { $$=Reduction(T_DefList, NULL, @$.first_line, 0);}
        ;
		
Def : Specifier DecList SEMI { $3=Reduction(T_SEMI, NULL, @$.first_line, 0);
							$$=Reduction(T_Def, NULL, @$.first_line, 3,$1,$2,$3);} 
    ;
	
/*LGY_0324*/
/*Def : Specifier error SEMI {};*/

DecList : Dec {$$=Reduction(T_DecList, NULL, @$.first_line, 1,$1); }
        | Dec COMMA DecList { $2=Reduction(T_COMMA, NULL, @$.first_line, 0);
							$$=Reduction(T_DecList, NULL, @$.first_line, 3,$1,$2,$3);}
        ;
		
/*LJY_0414 already add SymbleCount via VarDec*/
Dec : VarDec { $$=Reduction(T_Dec, NULL, @$.first_line, 1,$1); }
    | VarDec ASSIGNOP Exp { $2=Reduction(T_ASSIGNOP, NULL, @$.first_line, 0);
							$$=Reduction(T_Dec, NULL, @$.first_line, 3,$1,$2,$3); }
    ;
	
Exp : Exp ASSIGNOP Exp { $2=Reduction(T_ASSIGNOP, NULL, @$.first_line, 0);
							$$=Reduction(T_Exp, NULL, @$.first_line, 3,$1,$2,$3);}
    | Exp AND Exp { $2=Reduction(T_AND, NULL, @$.first_line, 0);
					$$=Reduction(T_Exp, NULL, @$.first_line, 3,$1,$2,$3);}
    | Exp OR Exp { $2=Reduction(T_OR, NULL, @$.first_line, 0);
				   $$=Reduction(T_Exp, NULL, @$.first_line, 3,$1,$2,$3);}
    | Exp RELOP Exp { $2=Reduction(T_RELOP, NULL, @$.first_line, 0);
					$$=Reduction(T_Exp, NULL, @$.first_line, 3,$1,$2,$3);}
    | Exp PLUS Exp { $2=Reduction(T_PLUS, NULL, @$.first_line, 0);
					$$=Reduction(T_Exp, NULL, @$.first_line, 3,$1,$2,$3);}
    | Exp MINUS Exp { $2=Reduction(T_MINUS, NULL, @$.first_line, 0);
					$$=Reduction(T_Exp, NULL, @$.first_line, 3,$1,$2,$3);}
    | Exp STAR Exp { $2=Reduction(T_STAR, NULL, @$.first_line, 0);
					$$=Reduction(T_Exp, NULL, @$.first_line, 3,$1,$2,$3);}
    | Exp DIV Exp { $2=Reduction(T_DIV, NULL, @$.first_line, 0);
					$$=Reduction(T_Exp, NULL, @$.first_line, 3,$1,$2,$3);}
    | LP Exp RP { $1=Reduction(T_LP, NULL, @$.first_line, 0);
				  $3=Reduction(T_RP, NULL, @$.first_line, 0);
				  $$=Reduction(T_Exp, NULL, @$.first_line, 3,$1,$2,$3);}
    | MINUS Exp %prec TAKENEGATIVE { $1=Reduction(T_MINUS, NULL, @$.first_line, 0);$$=Reduction(T_Exp, NULL, @$.first_line, 2,$1,$2);}
    | NOT Exp { $1=Reduction(T_NOT, NULL, @$.first_line, 0);$$=Reduction(T_Exp, NULL, @$.first_line, 2,$1,$2);}
    | ID LP Args RP { struct Tnode* n=Reduction(T_ID, $1, @$.first_line, 0); 
						$2=Reduction(T_LP, NULL, @$.first_line, 0);
						$4=Reduction(T_RP, NULL, @$.first_line, 0);
						$$=Reduction(T_Exp, NULL, @$.first_line, 4,n,$2,$3,$4);}
    | ID LP RP { struct Tnode* n=Reduction(T_ID, $1, @$.first_line, 0); 
				$2=Reduction(T_LP, NULL, @$.first_line, 0);
				$3=Reduction(T_RP, NULL, @$.first_line, 0);
				$$=Reduction(T_Exp, NULL, @$.first_line, 3,n,$2,$3);}
    | Exp LB Exp RB { $2=Reduction(T_LB,NULL,@$.first_line,0);
                        $4=Reduction(T_RB,NULL,@$.first_line,0);
                        $$=Reduction(T_Exp,NULL,@$.first_line,4,$1,$2,$3,$4);} 
    | Exp DOT ID {struct Tnode* n=Reduction(T_ID, $3, @$.first_line, 0); 
					$2=Reduction(T_DOT, NULL, @$.first_line, 0);
					$$=Reduction(T_Exp, NULL, @$.first_line, 3,$1,$2,n); }
    | ID {struct Tnode* n=Reduction(T_ID, $1, @$.first_line, 0); 
		 $$=Reduction(T_Exp, NULL, @$.first_line, 1,n); }
    | INT { struct Tnode* n=Reduction(T_INT, $1, @$.first_line, 0); 
		 $$=Reduction(T_Exp, NULL, @$.first_line, 1,n);}
    | FLOAT { struct Tnode* n=Reduction(T_FLOAT, $1, @$.first_line, 0); 
		 $$=Reduction(T_Exp, NULL, @$.first_line, 1,n);}
    ;

/*LGY_0324*/
Exp : ID LP error RP {};
Exp : Exp LB error RB {};

Args : Exp COMMA Args { $2=Reduction(T_COMMA, NULL, @$.first_line, 0); 
						$$=Reduction(T_Args, NULL, @$.first_line, 3,$1,$2,$3);}
     | Exp { $$=Reduction(T_Args, NULL, @$.first_line, 1,$1);}
     ;
%%
yyerror(char* msg){
    ISOK=false;
	//LJY_0322
    char a[200];
    if(yytext!=NULL && yytext[0]!='\0')
        sprintf(a,"something wrong near \'%s\'",yytext);
    else
        sprintf(a,"something wrong");
	ShowError(T_ERROR_B,yylineno);
	printf("%s\n",a);
}





