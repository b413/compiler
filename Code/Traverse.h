#ifndef __TRAVERSE_H__
#define __TRAVERSE_H__
#include "SymTable.h"
extern void FirstTraverse();
extern void SecondTraverse();
extern struct Tnode* kthChild(struct Tnode* root,int k);
extern int childrenNum(struct Tnode* root);
extern void constructStructure(Type type,struct Tnode* root);
#endif
