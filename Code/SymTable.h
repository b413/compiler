#ifndef __SYMTABLE_H__
#define __SYMTABLE_H__
#include "Tree.h"
struct SymDesc
{
	char* SymName;
	char* TypeName;
	int Type;
	int lineno;
	struct Tnode* node;
	int retTypeIndex;
	bool defined;
    Type type;
};

extern struct SymDesc** SymTable;
extern int SymTableSize;

extern struct SymDesc* newEmptyDesc();
extern struct SymDesc* newDesc(char* sname, char* tname, int type, int lineno, struct Tnode* tnode, int rType);

extern void createTable();
extern int createDesc(struct SymDesc* desc);
extern int getDesc(char* symName, bool function);
extern void printSymTable();
#endif
