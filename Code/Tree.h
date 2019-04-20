#ifndef __TREE_H__
#define __TREE_H__
#include "Kits.h"
/*
#define bool char
#define false 0
#define true 1
enum{
	Terminal Symbol
	T_SEMI,T_COMMA,T_ASSIGNOP,T_RELOP,T_PLUS,T_MINUS,
	T_STAR,T_DIV,T_AND,T_OR,T_DOT,T_NOT,T_TYPE,T_LP,T_RP,
	T_LB,T_RB,T_LC,T_RC,T_STRUCT,T_RETURN,T_IF,T_ELSE,T_WHILE,
	T_ID,T_INT,T_FLOAT,
	inTerminal Symbol
	T_Program,T_ExtDefList,T_ExtDef,T_ExtDecList,T_Specifier,
	T_StructSpecifier,T_OptTag,T_Tag,T_VarDec,T_FunDec,T_VarList,
	T_ParamDec,T_CompSt,T_StmtList,T_Stmt,T_DefList,T_Def,
	T_DecList,T_Dec,T_Exp,T_Args,
};
*/
//LGY_417
//typedef struct Type_* Type;
typedef struct FieldList_* FieldList;

struct Type_{
    enum{BASIC,ARRAY,STRUCTURE,FUNCTION}kind;
    char* name; //the struct name or INT or FLOAT
    union{
        int basic;
        struct{struct Type_* elem;int size;}array;
        FieldList structure;
        struct{struct Type_* return_value;FieldList params;}function;
    }u;
};

struct FieldList_{
    char* name;
    struct Type_* type;
    FieldList tail;
};
struct Tnode
{
	int Type;
	int SymIndex;
	int Dimension;
	int StructIndex;
	int lineno;
	union{
			int val_int;
			float val_float;
			char* Desc;
	};
	struct Tnode* Parent;
	struct Tnode* FirstChild;
	struct Tnode* NextSibling;
    struct Type_* type;
};
extern char* TypeName[];
extern struct Tnode *ROOT;
extern inline bool IsTerminalType(int Type);
extern struct Tnode* Reduction(int Type, char* Desc, int lineno, int n, ...);
extern void Traverse(struct Tnode* root,int depth);
extern bool printTree();
extern struct Tnode* ROOT;

#endif
