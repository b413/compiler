#include "stdio.h"
#include "stdlib.h"
#include "SymTable.h"

int SymTableSize=0;
struct SymDesc** SymTable=0;

int Hash(char* str)
{
	unsigned int seed = 131;
	unsigned int hash = 0;
	int i=0;
	while(str[i]!='\0')
	{
		hash = hash * seed + str[i];
		i++;
	}	
	return hash % SymTableSize;
}


struct SymDesc* newDesc(char* sname, char* tname, int type, int lineno, struct Tnode* tnode, int rType)
{
	struct SymDesc* d = (struct SymDesc*)malloc(sizeof(struct SymDesc));
	d->SymName=sname;
	d->TypeName=tname;
	d->Type=type;
	d->lineno=lineno;
	d->node=tnode;
	d->retTypeIndex=rType;
	d->defined=false;
    //LGY_417
	d->type=NULL;
    return d;

}
struct SymDesc* newEmptyDesc()
{
	struct SymDesc* d = (struct SymDesc*)malloc(sizeof(struct SymDesc));
	d->SymName=NULL;
	d->TypeName=NULL;
	d->Type=T_DEFAULT;
	d->lineno=-1;
	d->node=NULL;
	d->retTypeIndex=-1;
	d->defined=false;
    //LGY_417
    d->type=NULL;
	return d;
}

int createDesc(struct SymDesc* desc)
{
	if(desc == 0)
		return -1;
	int hash = Hash(desc->SymName);
	for(int i=0;i<SymTableSize;i++)
	{
		if(SymTable[hash]==0)
		{
			SymTable[hash]=desc;
			return hash;
		}
		hash = (hash+1)%SymTableSize;
	}
	printf("hash error\n");
	return -1;
}

int getDesc(char* symName,bool function)
{
	int hash = Hash(symName);
	int hashraw = hash;
	for(int i=0;i<SymTableSize;i++,hash = (hash+1)%SymTableSize)
	{
		if(SymTable[hash]==0)
			return -1;
		else
		{
			if(SymTable[hash]->Type==T_FUNC && !function)
				continue;
			if(SymTable[hash]->Type!=T_FUNC && function)
				continue;
			int j=0;
			if(SymTable[hash]->SymName==NULL)
				continue;
			bool eq=true;
			while(SymTable[hash]->SymName!=NULL &&  SymTable[hash]->SymName!=NULL && SymTable[hash]->SymName[j]!='\0')
			{
				if(symName[j]!=SymTable[hash]->SymName[j])
				{
					eq=false;
					break;
				}
				j=j+1;
			}
			if(eq==true)
				return hash;
		}
	}
	return -1;
}


void createTable()
{
	SymTableSize += 2;
	SymTable = (struct SymDesc**)malloc(sizeof(struct SymDesc*)*SymTableSize);
	for(int i=0;i<SymTableSize;i++)
	{
		SymTable[i]=0;
	}
	//printf("Table Size: %d\n",SymTableSize);
	struct SymDesc* intdesc=newDesc(NULL,TypeName[T_INT],T_Obj,-1,NULL,-1);
	struct SymDesc* floatdesc = newDesc(NULL,TypeName[T_FLOAT],T_Obj,-1,NULL,-1);
	SymTable[0]=intdesc;
	SymTable[1]=floatdesc;
	FirstTraverse();
    SecondTraverse();
}

void printSymTable()
{
	printf("%-*s%-*s%-*s%-*s%-*s%-*s%-*s\n",6,"No",16,"SymName",16,"TypeName",6,"Type",8,"Lineno",12,"node",12,"RetType");
	for(int i=0;i<SymTableSize;i++)
	{
		if(SymTable[i]==0)
			;
		else
		{
			printf("%-*d",6,i);
			printf("%-*s",16,SymTable[i]->SymName);
			if(SymTable[i]->node!=0 && SymTable[i]->node->Dimension!=0)
			{
				int applen=0;
				char* app = int2str(SymTable[i]->node->Dimension, &applen);
				int len=0;
				for(;SymTable[i]->TypeName[len]!='\0';len++);
				len += 1+applen;
				printf("%s[%d%-*s",SymTable[i]->TypeName,SymTable[i]->node->Dimension,16-len,"]");
			}
			else
				printf("%-*s",16,SymTable[i]->TypeName);
			printf("%-*d%-*d",6,SymTable[i]->Type,8,SymTable[i]->lineno);
			if(SymTable[i]->node!=0)
				printf("%-*x",12,SymTable[i]->node);
			else
				printf("%-*s",12,"-");
			printf("%d\n",SymTable[i]->retTypeIndex);
		}
	}
}
