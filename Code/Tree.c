#include "stdio.h"
#include "stdarg.h"
#include "stdlib.h"
#include "Tree.h"
typedef struct Tnode Tnode;

char* TypeName[] = {
	/*Terminal Symbol*/
	"SEMI","COMMA","ASSIGNOP","RELOP","PLUS","MINUS",
	"STAR","DIV","AND","OR","DOT","NOT","TYPE","LP","RP",
	"LB","RB","LC","RC","STRUCT","RETURN","IF","ELSE","WHILE",
	"ID","INT","FLOAT",
	/*inTerminal Symbol*/
	"Program","ExtDefList","ExtDef","ExtDecList","Specifier",
	"StructSpecifier","OptTag","Tag","VarDec","FunDec","VarList",
	"ParamDec","CompSt","StmtList","Stmt","DefList","Def",
	"DecList","Dec","Exp","Args",
	/*SelfDefineTypes*/
	"ERROR","DECIMAL","HEX","OCT",
	"ERROR_A","ERROR_B",
	"Obj","StructObj","function",
	/*Debug*/
	"DEFAULT",
};

inline bool IsTerminalType(int Type)
{
	if(Type<=T_FLOAT)
		return true;
	return false;
}

Tnode* ROOT=NULL;

Tnode* Reduction(int Type, char* Desc, int lineno, int n, ...)
{
	//LJY_0322
	if(ISOK==false)
	{
		return NULL;
	}
	Tnode* node = (Tnode*)malloc(sizeof(Tnode));
	node->Parent = NULL;
	node->FirstChild = NULL;
	node->NextSibling = NULL;
	node->Type = Type;
	node->SymIndex = -1;
	node->Dimension=0;
	node->lineno = lineno;
	int type = 0;
	switch(Type)
	{
		case T_INT:
			node->val_int = getNumType(Desc, &type);
			break;
		case T_FLOAT:
			node->val_float = atof(Desc);
			break;
		default:
			node->Desc = Desc;
	}
	if(Type==T_Program){
		ROOT=node;
	}
	if(n==0 || IsTerminalType(Type))
	{
		return node;
	}
	va_list ap;
	va_start(ap,n);
	Tnode* curnode=NULL;
	Tnode* prenode=NULL;
	for(int i=0;i<n;i++)
	{
		prenode = curnode;
        curnode = va_arg(ap, struct Tnode*);
		if(curnode==NULL)
		{
			printf("error retriving param list\n");
			return NULL;
		}
		curnode->Parent = node;
        if(prenode==NULL)
		{
			node->FirstChild = curnode;
			prenode = curnode;
			continue;
		}
		prenode->NextSibling = curnode;
	}
    return node;
}

bool printTree()
{
	if(ROOT==NULL)
		return false;
	Traverse(ROOT,0);
	return true;
}
void Traverse(struct Tnode* root, int depth)
{
    /*LGY_0323*/
    if(root!=NULL && IsTerminalType(root->Type)==false && root->FirstChild==NULL)
        return;
	for(int i=0;i<depth*2;i++)
		printf(" ");
	switch(root->Type)
	{
		case T_ID:
            /*LGY_0323*/
            printf("ID: %s\n",root->Desc);
            break;
		case T_TYPE:
			printf("TYPE: %s\n",root->Desc);
			break;
		case T_INT:
			printf("INT: %d\n",root->val_int);
			break;
		case T_FLOAT:
			printf("FLOAT: %f\n",root->val_float);
			break;
		default:
			if(root->Type<=T_FLOAT)
				printf("%s\n",TypeName[root->Type]);
			else
				printf("%s (%d)\n",TypeName[root->Type],root->lineno);
	}
	for(Tnode* p=root->FirstChild;p!=NULL;p=p->NextSibling)
		Traverse(p,depth+1);
	return;
}
