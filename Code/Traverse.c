#include "stdlib.h"
#include "stdio.h"
#include "Traverse.h"
#include "SymTable.h"

void printTypeInSymTable(){
    for(int i=0;i<SymTableSize;i++){
        if(SymTable[i]->type!=NULL){
           printf("index:%d type :",i);
           if(SymTable[i]->type->kind==BASIC){
                printf("basic->%s\n",SymTable[i]->type->name);
           }
           else if(SymTable[i]->type->kind==ARRAY){
                printf("array->");
                Type p=SymTable[i]->type;
                while(p->kind==ARRAY){
                    printf("%d ",p->u.array.size);
                    p=p->u.array.elem;
                }
                printf("%s\n",p->name);
           }
           else if(SymTable[i]->type->kind==STRUCTURE){
                printf("structure->%s field: \n",SymTable[i]->type->name); 
                FieldList p=SymTable[i]->type->u.structure;
                while(p!=NULL){
                    if(p->name==NULL){
                        printf("NULL\n");
                    }
                    else
                        printf("%s ",p->name);
                    p=p->tail;
                    printf("next\n");
                }
           }
        }
        else{
            printf("empty\n");
        }
    }
    return;
}
int findTnodeInTable(struct Tnode* node){
    for(int i=0;i<SymTableSize;i++){
        if(SymTable[i]->node==node){
            return i;
        }
    }
    return -1;
}
FieldList addOneField(struct Tnode* root){  //root Type=T_Def
    if(root->Type!=T_Def)
        return NULL;
    struct Tnode* specifier=kthChild(root,1);
    struct Tnode* declist=kthChild(root,2);
    FieldList head=NULL;
    FieldList tail=NULL;
    //if(specifier->FirstChild->Type==T_TYPE){
        struct Tnode* p=declist;
        while(true){
            struct Tnode* dec=p->FirstChild;
            struct Tnode* vardec=dec->FirstChild;
            if(childrenNum(vardec)==1){//VarDec->ID
                FieldList f=(FieldList)malloc(sizeof(struct FieldList_));
                f->name=strdup(SymTable[vardec->FirstChild->SymIndex]->SymName);
                Type t=NULL;
                if(specifier->FirstChild->Type==T_TYPE){
                    t=(Type)malloc(sizeof(struct Type_));  //--------->
                    t->kind=BASIC;      //----------->
                    t->name=strdup(SymTable[specifier->FirstChild->SymIndex]->TypeName);//---->
                }
                else{
                    t=(Type)malloc(sizeof(struct Type_));
                    t->kind=STRUCTURE;
                    t->name=strdup(SymTable[vardec->FirstChild->SymIndex]->TypeName);
                    int res=getDesc(SymTable[vardec->FirstChild->SymIndex]->TypeName,false);
                    if(res<0){
                        printf("error in Traverse.c --lgy\n");
                        return NULL;
                    }
                    else{
                        if(SymTable[res]->type==NULL){
                            SymTable[res]->type=(Type)malloc(sizeof(struct Type_));
                            SymTable[res]->type->kind=STRUCTURE;
                            SymTable[res]->type->name=strdup(SymTable[res]->SymName);
                            constructStructure(SymTable[res]->type,SymTable[res]->node);
                        }
                        t->u.structure=SymTable[res]->type->u.structure;
                    }
                }
                f->type=t;
                f->tail=NULL;
                if(head==NULL){
                    head=tail=f;
                }
                else{
                    tail->tail=f;
                    tail=f;
                }
            }
            else{   //VarDec->VarDec LB INT RB
                Type t_end=NULL;
                t_end=(Type)malloc(sizeof(struct Type_));  //--------->
                if(specifier->FirstChild->Type==T_TYPE){
                    t_end->kind=BASIC;      //----------->
                    t_end->name=strdup(SymTable[specifier->FirstChild->SymIndex]->TypeName);//---->
                }
                FieldList f=(FieldList)malloc(sizeof(struct FieldList_));
                Type t_tail=NULL;
                f->tail=NULL;
                while(true){
                    struct Tnode* num=kthChild(vardec,3);
                    Type temp=(Type)malloc(sizeof(struct Type_));
                    temp->kind=ARRAY;
                    temp->u.array.size=num->val_int;
                    if(t_tail==NULL){
                        temp->u.array.elem=t_end;
                        t_tail=temp;
                    }
                    else{
                        temp->u.array.elem=t_tail;
                        t_tail=temp;
                    }
                    vardec=vardec->FirstChild;
                    if(childrenNum(vardec)==1){
                        if(specifier->FirstChild->Type!=T_TYPE){
                            t_end->kind=STRUCTURE;
                            t_end->name=strdup(SymTable[vardec->FirstChild->SymIndex]->TypeName);
                            int res=getDesc(SymTable[vardec->FirstChild->SymIndex]->TypeName,false);
                            if(res<0){
                                printf("error in Traverse.c --lgy\n");
                                return NULL;
                            }
                            else{
                                if(SymTable[res]->type==NULL){
                                    SymTable[res]->type=(Type)malloc(sizeof(struct Type_));
                                    SymTable[res]->type->kind=STRUCTURE;
                                    SymTable[res]->type->name=strdup(SymTable[res]->SymName);
                                    constructStructure(SymTable[res]->type,SymTable[res]->node);
                                }
                                t_end->u.structure=SymTable[res]->type->u.structure;
                            }
                        }
                        f->name=strdup(SymTable[vardec->FirstChild->SymIndex]->SymName);
                        f->type=t_tail;
                        break;
                    }
                }
                if(head==NULL){
                    head=tail=f;
                }
                else{
                    tail->tail=f;
                    tail=f;
                }
            }
            if(childrenNum(p)==1)
                break;
            else
                p=kthChild(p,3);
        } 
    //}
    //else{//Specifier is struct
        
    //}
    return head;
}
FieldList addFieldInStructure(struct Tnode* root){ //root Type=T_DefList
    if(root==NULL || root->Type!=T_DefList)
        return NULL;
    if(root->FirstChild==NULL || childrenNum(root)!=2)
        return NULL;
    if(root->FirstChild->Type!=T_Def)
        return NULL;
    FieldList head=NULL;
    FieldList tail=NULL;
    while(true){
        if(root->FirstChild==NULL)
            break;
        else{
            FieldList f=addOneField(root->FirstChild);
            root=kthChild(root,2);
            if(head==NULL){
                head=f;
                FieldList temp=f;
                while(temp->tail!=NULL)
                    temp=temp->tail;
                tail=temp;
            }
            else{
                tail->tail=f;
                FieldList temp=f;
                while(temp->tail!=NULL)
                    temp=temp->tail;
                tail=temp;
            }
        }
    }
    return head;
}
void constructStructure(Type type,struct Tnode* root){
    if(root->FirstChild==NULL)
        return;
    if(childrenNum(root->FirstChild)!=5)
        return;
    struct Tnode* p=kthChild(root->FirstChild,4);
    if(p->Type!=T_DefList)
        return;
    FieldList f=addFieldInStructure(p);
    type->u.structure=f;
}
void addDetailTypeInTable(){
    for(int i=0;i<SymTableSize;i++)
    {
        //printf("%s\n",SymTable[i]->TypeName);
        if(SymTable[i]->type!=NULL)
            continue;
        if(strcmp(SymTable[i]->TypeName,"INT")==0 && (SymTable[i]->node==NULL || SymTable[i]->node->Dimension==0)){
            SymTable[i]->type=(Type)malloc(sizeof(struct Type_));
            SymTable[i]->type->kind=BASIC;
            SymTable[i]->type->name=strdup("INT");
        }
        else if(strcmp(SymTable[i]->TypeName,"FLOAT")==0 && (SymTable[i]->node==NULL ||SymTable[i]->node->Dimension==0)){
            SymTable[i]->type=(Type)malloc(sizeof(struct Type_));
            SymTable[i]->type->kind=BASIC;
            SymTable[i]->type->name=strdup("FLOAT");
        }
        else if(strcmp(SymTable[i]->TypeName,"StructObj")==0){ 
            SymTable[i]->type=(Type)malloc(sizeof(struct Type_));
            SymTable[i]->type->kind=STRUCTURE;
            SymTable[i]->type->name=strdup(SymTable[i]->SymName);
            constructStructure(SymTable[i]->type,SymTable[i]->node);
        }
        else{
            if(SymTable[i]->node->Dimension==0){   //struct variable
                int t=getDesc(SymTable[i]->TypeName,false);
                if(t<0){
                    printf("Something error in addDetailTypeInTable function!!!\n");
                    return 0;
                }
                if(SymTable[t]->type==NULL){ 
                    SymTable[t]->type=(Type)malloc(sizeof(struct Type_));
                    SymTable[t]->type->kind=STRUCTURE;
                    SymTable[t]->type->name=strdup(SymTable[t]->SymName);
                    constructStructure(SymTable[t]->type,SymTable[t]->node);
                }
                SymTable[i]->type=SymTable[t]->type;
            }
            else{   //array
                //printf("\n");
                //SymTable[i]->type=(Type)malloc(sizeof(struct Type_));
                //SymTable[i]->type->kind=ARRAY;
                struct Tnode* vardec=SymTable[i]->node;
                char* n=strdup(SymTable[i]->TypeName);
                Type t_end=(Type)malloc(sizeof(struct Type_));
                if(strcmp(n,"INT")==0){
                    t_end->kind=BASIC;
                    t_end->name=strdup("INT");
                }
                else if(strcmp(n,"FLOAT")==0){
                    t_end->kind=BASIC;
                    t_end->name=strdup("FLOAT");
                }
                else{
                    int t=getDesc(n,false);
                    if(t<0){
                        printf("Something error in addDetailTypeInTable function!!!\n");
                        return 0;
                    }
                    if(SymTable[t]->type==NULL){ 
                        SymTable[t]->type=(Type)malloc(sizeof(struct Type_));
                        SymTable[t]->type->kind=STRUCTURE;
                        SymTable[t]->type->name=strdup(SymTable[t]->SymName);
                        constructStructure(SymTable[t]->type,SymTable[t]->node);
                    }
                    t_end=SymTable[t]->type;
                }
                Type t_tail=NULL;
                while(true){
                    struct Tnode* num=kthChild(vardec,3);
                    Type temp=(Type)malloc(sizeof(struct Type_));
                    temp->kind=ARRAY;
                    temp->u.array.size=num->val_int;
                    if(t_tail==NULL){
                        temp->u.array.elem=t_end;
                        t_tail=temp;
                    }
                    else{
                        temp->u.array.elem=t_tail;
                        t_tail=temp;
                    }
                    vardec=vardec->FirstChild;
                    if(childrenNum(vardec)==1){
                        break;
                    }
                }
                SymTable[i]->type=t_tail;
            }
        }
        
    }
}
void SecondTraverse()
{
    addDetailTypeInTable();
    printTypeInSymTable();
    secondTraverse(ROOT);
}
void secondTraverse(struct Tnode* root)
{
    if(root==NULL)
        return;
    for(struct Tnode* p=root->FirstChild;p!=NULL;p=p->NextSibling)
    {
        secondTraverse(p);
    }
    switch(root->Type)
    {
        case T_Exp:
            processExp(root);
            break;
        default:
            break;
    }
    //if(root->Type==T_TYPE){
    //    printf("%d-line:%d\n",root->SymIndex,root->lineno);
    //}
    //printf("%d--%s\n",root->SymIndex,TypeName[root->Type]);
    return; 
}
int childrenNum(struct Tnode* root){
    int res=0;
    if(root==NULL)
        return res;
    struct Tnode* p=root->FirstChild;
    while(p!=NULL){
        p=p->NextSibling;
        res++;
    }
    return res;
}
struct Tnode* kthChild(struct Tnode* root,int k){
    if(root==NULL || k==0)
        return NULL;
    struct Tnode* p=root->FirstChild;
    int count=1;
    while(count<k){
        if(p==NULL)
            return p;
        p=p->NextSibling;
        count++;
    }
    return p;
}
void processExp(struct Tnode* root){
    if(root==NULL)
        return;
     int res=childrenNum(root);
     switch(res){
        case 1:
            if(root->FirstChild->Type==T_ID){//Exp->ID
                if(getDesc(root->FirstChild->Desc,false)<0){
                    ShowError(1,root->FirstChild->lineno);
                    printf("Undefined variable \"%s\"\n\n",root->FirstChild->Desc);
                }
            }
            break;
        case 3:
            if(root->FirstChild->Type==T_ID){//Exp->ID LP RP
                if(getDesc(root->FirstChild->Desc,true)<0 && getDesc(root->FirstChild->Desc,false)<0){
                    ShowError(2,root->FirstChild->lineno);
                    printf("Undefined function \"%s\"\n\n",root->FirstChild->Desc);
                }
                else if(getDesc(root->FirstChild->Desc,true)<0 && getDesc(root->FirstChild->Desc,false)>=0){
                    ShowError(11,root->FirstChild->lineno);
                    printf("\"%s\" is not a function\n\n",root->FirstChild->Desc);
                }    
            }
            else if(root->FirstChild->NextSibling->Type==T_ASSIGNOP){ //Exp->Exp ASSIGNOP Exp
                if(root->FirstChild->FirstChild->Type==T_ID){ //Exp->ID
                
                }
                else if(childrenNum(root->FirstChild)==4 && kthChild(root->FirstChild,2)->Type==T_LB){ //Exp->Exp LB Exp RB
                
                }
                else if(childrenNum(root->FirstChild)==3 && kthChild(root->FirstChild,2)->Type==T_DOT){ //Exp->Exp DOT ID
                
                }
                else{
                    ShowError(6,root->FirstChild->lineno);
                    printf("The left-hand side of an assignment must be a variable\n\n");
                }
            }
            break;
        case 4:
            if(root->FirstChild->Type==T_ID){//Exp->ID LP Args RP
                if(getDesc(root->FirstChild->Desc,true)<0 && getDesc(root->FirstChild->Desc,false)<0){
                    ShowError(2,root->FirstChild->lineno);
                    printf("Undefined function \"%s\"\n\n",root->FirstChild->Desc);
                }
                else if(getDesc(root->FirstChild->Desc,true)<0 && getDesc(root->FirstChild->Desc,false)>=0){
                    ShowError(11,root->FirstChild->lineno);
                    printf("\"%s\" is not a function\n\n",root->FirstChild->Desc);
                }
                
            }
            break;
        default:
            break;
     }
     return;
}

void FirstTraverse()
{
	firstTraverse(ROOT);
	for(int i=0;i<SymTableSize;i++)
	{
		if(SymTable[i]!=NULL)
		{
			if(SymTable[i]->Type==T_FUNC && SymTable[i]->defined==false)
			{
				ShowError(18,SymTable[i]->node->lineno);
				printf("Undefined function ");
				ShowQuote(SymTable[i]->SymName,false);
				EndError();
			}
		}
	}
}

void firstTraverse(struct Tnode* root)
{
	if(root==NULL)
		return;
	for(struct Tnode* p=root->FirstChild;p!=NULL;p=p->NextSibling)
		firstTraverse(p);
	switch(root->Type)
	{
		case T_ExtDef:
			Gen4ExtDef(root);
			break;
		case T_Def:
			Gen4Def(root);
			break;
		case T_StructSpecifier:
			Gen4Struct(root);
			break;
		case T_ParamDec:
			Rec2Gen(root,root->FirstChild->SymIndex);
			break;
		case T_TYPE:
			if(root->Desc[0]=='i')
				/*int value*/
				root->SymIndex = 0;
			else
				/*float value*/
				root->SymIndex = 1;
			break;
		case T_Specifier:
		case T_Tag:
			root->SymIndex = root->FirstChild->SymIndex;
			break;
		default:
			break;
	}
}

void Rec2Gen(struct Tnode* node, int TypeIndex)
{
	if(node==0)
		return;
	for(struct Tnode*p=node->FirstChild;p!=0;p=p->NextSibling)
	{
		if(p->Type==T_ASSIGNOP)
			break;
		Rec2Gen(p,TypeIndex);
	}
	if(node->Type==T_ID)
	{
		if(TypeIndex<0)
		{
			ShowError(-1,node->lineno);
			printf("storage size of ");
			ShowQuote(node->Desc,false);
			printf(" isn’t known");
			EndError();
			return;
		}
		int redef = getDesc(node->Desc,false);
		if(redef>=0)
		{
			ShowError(3,node->lineno);
			printf("Redefined variable ");
			ShowQuote(node->Desc,true);
			ShowNote();
			printf("previous defination at line %d",SymTable[redef]->lineno);
			EndError();
			return;
		}
		if(SymTable[TypeIndex]->Type==T_StructObj)
		{
			/*Struct Dec*/
			struct SymDesc* vdesc = newDesc(node->Desc,SymTable[TypeIndex]->SymName,T_STRUCT,node->lineno,node,-1);
			node->SymIndex = createDesc(vdesc);
		}
		else
		{
			/*Basic Type*/
			struct SymDesc* vdesc = newDesc(node->Desc,SymTable[TypeIndex]->TypeName,SymTable[TypeIndex]->Type,node->lineno,node,-1);
			if(TypeIndex==0)
				vdesc->Type=T_INT;
			else if(TypeIndex==1)
				vdesc->Type=T_FLOAT;
			node->SymIndex = createDesc(vdesc);
		}
	}
	if(node->Type==T_VarDec)
	{
		if(node->FirstChild->Type==T_VarDec)
		{
			/*Array Dec*/
			//printf("Arr(%s)[%d],Index:%d\n",TypeName[node->FirstChild->Type],node->FirstChild->Dimension+1,node->FirstChild->SymIndex);
			node->Dimension = node->FirstChild->Dimension+1;
			node->SymIndex = node->FirstChild->SymIndex;
			struct SymDesc* vdesc = SymTable[node->SymIndex];
			if(vdesc==0)
			{
				printf("Rec2Gen Error: null desc\n");
				return;
			}
			vdesc->lineno=node->lineno;
			vdesc->node = node;
		}
	}
	if(node->FirstChild!=0)
		node->SymIndex = node->FirstChild->SymIndex;
}

void Gen4ExtDef(struct Tnode* node)
{
	struct Tnode* Specifier = node->FirstChild;
	int type = node->FirstChild->NextSibling->Type;
	if(type == T_SEMI)
		;
	else if(type == T_FunDec)
	{
		struct Tnode* func = node->FirstChild->NextSibling;
		int redef = getDesc(func->FirstChild->Desc,true);
		if(redef>=0 && (SymTable[redef]->defined==false || func->NextSibling->Type==T_SEMI))
		{
			if(func->NextSibling->Type!=T_SEMI)
				SymTable[redef]->defined=true;
			return;
		}
		if(redef>=0)
		{
			/*redefine error*/
			ShowError(4,func->lineno);
			printf("Redefined function ");
			ShowQuote(func->FirstChild->Desc, true);
			ShowNote();
			printf("previous defination at line %d",SymTable[redef]->lineno);
			EndError();
			return;
		}
		struct SymDesc* fdesc = newDesc(func->FirstChild->Desc,TypeName[T_FUNC],T_FUNC,func->lineno,func,Specifier->SymIndex);
		if(func->NextSibling->Type!=T_SEMI)
			fdesc->defined = true;
		func->SymIndex = createDesc(fdesc);
		node->SymIndex = func->SymIndex;
	}
	else if(type == T_ExtDecList)
	{
		Rec2Gen(node->FirstChild->NextSibling,Specifier->SymIndex);
	}
	else
	{
		printf("Gen4ExtDef Error: Error Type\n");
	}
}


void Gen4Def(struct Tnode* node)
{
	struct Tnode* Specifier = node->FirstChild;
	int type = node->FirstChild->NextSibling->Type;
	Rec2Gen(node->FirstChild->NextSibling,Specifier->SymIndex);
}

int countAnonys = 0;
const char* AnonysTag = "anonyStruct";
const int AnonysTagLen = 11;

void Gen4Struct(struct Tnode* node)
{
	int Setype=node->FirstChild->NextSibling->Type;
	if(Setype==T_Tag)
	{
		/*struct def*/
		struct Tnode* ID = node->FirstChild->NextSibling->FirstChild;
		ID->SymIndex = getDesc(ID->Desc,false);
		if(ID->SymIndex<0)
		{
			ShowError(17,ID->lineno);
			printf("Undefined structure ");
			ShowQuote(ID->Desc,false);
			EndError();
			return;
		}
		node->FirstChild->NextSibling->SymIndex = ID->SymIndex;
		node->SymIndex = ID->SymIndex;
		return;
	}
	else if(Setype==T_OptTag)
	{
		struct Tnode* stu = node;
		if(stu->FirstChild->NextSibling->FirstChild==0)
		{
			/* Anonymous structobj */
			int len = 0;
			char* head = int2str(countAnonys,&len);
			char* Tname = (char*)malloc(sizeof(char)*(len+1+AnonysTagLen));
			int i=0;
			for(;i<len;i++)
				Tname[i]=head[i];
			for(;i<len+AnonysTagLen;i++)
				Tname[i]=AnonysTag[i-len];
			Tname[i]='\0';

			struct SymDesc* sdesc = newDesc(Tname,TypeName[T_StructObj],T_StructObj,stu->lineno,stu,-1);
			stu->SymIndex = createDesc(sdesc);
			stu->FirstChild->NextSibling->SymIndex = stu->SymIndex;
			countAnonys++;
		}
		else
		{
			/* ordinary strutobj*/
			struct Tnode* ID = stu->FirstChild->NextSibling->FirstChild;
			int redef = getDesc(ID->Desc,false);
			if(redef>=0)
			{
				/*redefine error*/
				ShowError(16,ID->lineno);
				printf("Duplicated name ");
				ShowQuote(ID->Desc,true);
				ShowNote();
				printf("previous defination at line %d",SymTable[redef]->lineno);
				EndError();
				return;

			}
			struct SymDesc* sdesc = newDesc(ID->Desc,TypeName[T_StructObj],T_StructObj,ID->lineno,stu,-1);
			stu->SymIndex = createDesc(sdesc);
			stu->FirstChild->NextSibling->SymIndex = stu->SymIndex;
		}
		return;
	}
	printf("Gen4Struct Type Error\n");
}
