#ifndef __KIT_H__
#define __KIT_H__


#define bool char
#define false 0
#define true 1
enum{
	/*Terminal Symbol*/
	T_SEMI,T_COMMA,T_ASSIGNOP,T_RELOP,T_PLUS,T_MINUS,
	T_STAR,T_DIV,T_AND,T_OR,T_DOT,T_NOT,T_TYPE,T_LP,T_RP,
	T_LB,T_RB,T_LC,T_RC,T_STRUCT,T_RETURN,T_IF,T_ELSE,T_WHILE,
	T_ID,T_INT,T_FLOAT,

	/*inTerminal Symbol*/
	T_Program,T_ExtDefList,T_ExtDef,T_ExtDecList,T_Specifier,
	T_StructSpecifier,T_OptTag,T_Tag,T_VarDec,T_FunDec,T_VarList,
	T_ParamDec,T_CompSt,T_StmtList,T_Stmt,T_DefList,T_Def,
	T_DecList,T_Dec,T_Exp,T_Args,
	
	/*SelfDefineTypes*/
	T_ERROR,T_DECIMAL,T_HEX,T_OCT,
	T_ERROR_A,T_ERROR_B,
	T_Obj,T_StructObj,T_FUNC,
	/*Debug*/
	T_DEFAULT,

};

extern bool ISOK;
extern bool curOK;

extern char* curFuncName;

extern int getNumType(char* str, int* type);
extern char* int2str(int val, int* len);
extern char* mstrdup(char* str);

/*output format*/
extern void ShowError(int type, int lineno);
extern void ShowNote();
extern void ShowQuote(char* q, bool end);
extern void EndError();
#endif
