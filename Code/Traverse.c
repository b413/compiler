#include "stdlib.h"
#include "stdio.h"
#include "Traverse.h"
#include "SymTable.h"

int curFunctionIndex=-1;

int isSameType(struct Type_* a,struct Type_* b){//yes->0 No->1
    if(a==NULL || b==NULL)
        return 1;
    if(a->kind!=b->kind)
        return 1;
    if(a->kind==BASIC){
        if(strcmp(a->name,b->name)==0)
            return 0;
        else 
            return 1;
    }
    else if(a->kind==ARRAY){
        int a1=0;
        struct Type_* t1=a;
        while(t1->kind==ARRAY){
            a1++;t1=t1->u.array.elem;
        }
        int b1=0;
        struct Type_* t2=b;
        while(t2->kind==ARRAY){
            b1++;t2=t2->u.array.elem;
        }
        if(a1!=b1 || strcmp(t1->name,t2->name)!=0)
            return 1;
        else
            return 0;
    }
    else if(a->kind==STRUCTURE){
        if(strcmp(a->name,b->name)==0)
            return 0;
        else
            return 1;
    }
    else if(a->kind==FUNCTION){
        if(strcmp(a->name,b->name)==0)
            return 0;
        else
            return 1;
    }
}
//for debug
void printTypeInSymTable(){
    for(int i=0;i<SymTableSize;i++){
        if(SymTable[i]==NULL)
            continue;
        if(SymTable[i]->type!=NULL){
           printf("index:%d type :",i);
           if(SymTable[i]->type->kind==BASIC){
                printf("basic->%s\n",SymTable[i]->type->name);
           }
           else if(SymTable[i]->type->kind==ARRAY){
                printf("array->");
                struct Type_* p=SymTable[i]->type;
                while(p->kind==ARRAY){
                    printf("%d ",p->u.array.size);
                    p=p->u.array.elem;
                }
                printf("%s\n",p->name);
           }
           else if(SymTable[i]->type->kind==FUNCTION){
                printf("return->%s ",SymTable[i]->type->u.function.return_value->name);
                FieldList f=SymTable[i]->type->u.function.params;
                printf("params-> ");
                while(f!=NULL){
                    printf("name:%s type:%s ",f->name,f->type->name);
                    f=f->tail;
                }
                printf("\n");
           }
           else if(SymTable[i]->type->kind==STRUCTURE){
                printf("structure->%s field: ",SymTable[i]->type->name); 
                FieldList p=SymTable[i]->type->u.structure;
                if(p==NULL){
                    printf("error\n");
                }
                while(p!=NULL){
                    printf("name:%s ",p->name);
                    if(p->type->kind==BASIC)
                        printf("type:%s ",p->type->name);
                    else if(p->type->kind==ARRAY){    
                        printf("array->");
                        struct Type_* q=p->type;
                        while(q->kind==ARRAY){
                            printf("%d ",q->u.array.size);
                            q=q->u.array.elem;
                        }
                        printf("%s ",q->name);
                    }
                    else if(p->type->kind=STRUCTURE)
                        printf("type:%s ",p->type->name);
                    p=p->tail;
                }
                printf("\n");
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
int isHaveField(FieldList head,char* name){//yes 0 no 1
    //printf("get here-%s\n",name);
    if(head==NULL){
       //printf("return 1\n");
        return 1;
    }
    else{
        while(head!=NULL){
            //printf("+\n");
            if(strcmp(head->name,name)==0){
                //printf("return 0\n");
                return 0;
            }
            head=head->tail;
        }
        //printf("return 1\n");
        return 1;
    }
}
FieldList addOneField(struct Tnode* root,FieldList top_head){  //root Type=T_Def
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
            struct Tnode* mytemp=vardec;
            while(childrenNum(mytemp)!=1)
                mytemp=mytemp->FirstChild;
            //printf("%s-%d-%d\n",mytemp->FirstChild->Desc,isHaveField(head,mytemp->FirstChild->Desc),isHaveField(top_head,mytemp->FirstChild->Desc));
            if(isHaveField(head,mytemp->FirstChild->Desc)==0 || isHaveField(top_head,mytemp->FirstChild->Desc)==0){
                //printf("yes\n");
            }
            else if(childrenNum(vardec)==1){//VarDec->ID changed
                FieldList f=(FieldList)malloc(sizeof(struct FieldList_));
                f->name=mstrdup(SymTable[vardec->FirstChild->SymIndex]->SymName);
                struct Type_* t=NULL;
                if(specifier->FirstChild->Type==T_TYPE){
                    t=(struct Type_*)malloc(sizeof(struct Type_));  //--------->
                    t->kind=BASIC;      //----------->
                    t->name=mstrdup(SymTable[specifier->FirstChild->SymIndex]->TypeName);//---->
                }
                else{
                    t=(struct Type_*)malloc(sizeof(struct Type_));
                    t->kind=STRUCTURE;
                    t->name=mstrdup(SymTable[vardec->FirstChild->SymIndex]->TypeName);
                    int res=getDesc(SymTable[vardec->FirstChild->SymIndex]->TypeName,false);
                    if(res<0){
                        printf("error in Traverse.c --lgy\n");
                        return NULL;
                    }
                    else{
                        if(SymTable[res]->type==NULL){
                            SymTable[res]->type=(struct Type_*)malloc(sizeof(struct Type_));
                            SymTable[res]->type->kind=STRUCTURE;
                            SymTable[res]->type->name=mstrdup(SymTable[res]->SymName);
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
                struct Type_* t_end=NULL;
                t_end=(struct Type_*)malloc(sizeof(struct Type_));  //--------->
                if(specifier->FirstChild->Type==T_TYPE){
                    t_end->kind=BASIC;      //----------->
                    t_end->name=mstrdup(SymTable[specifier->FirstChild->SymIndex]->TypeName);//---->
                }
                FieldList f=(FieldList)malloc(sizeof(struct FieldList_));
                struct Type_* t_tail=NULL;
                f->tail=NULL;
                while(true){
                    struct Tnode* num=kthChild(vardec,3);
                    struct Type_* temp=(struct Type_*)malloc(sizeof(struct Type_));
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
                            t_end->name=mstrdup(SymTable[vardec->FirstChild->SymIndex]->TypeName);
                            int res=getDesc(SymTable[vardec->FirstChild->SymIndex]->TypeName,false);
                            if(res<0){
                                printf("error in Traverse.c --lgy\n");
                                return NULL;
                            }
                            else{
                                if(SymTable[res]->type==NULL){
                                    SymTable[res]->type=(struct Type_*)malloc(sizeof(struct Type_));
                                    SymTable[res]->type->kind=STRUCTURE;
                                    SymTable[res]->type->name=mstrdup(SymTable[res]->SymName);
                                    constructStructure(SymTable[res]->type,SymTable[res]->node);
                                }
                                t_end->u.structure=SymTable[res]->type->u.structure;
                            }
                        }
                        f->name=mstrdup(SymTable[vardec->FirstChild->SymIndex]->SymName);
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
            FieldList f=addOneField(root->FirstChild,head);
            root=kthChild(root,2);
            if(f==NULL){
            }
            else if(head==NULL){
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
void constructStructure(struct Type_* type,struct Tnode* root){
    if(childrenNum(root)!=5){
        //printf("num:%d\n",childrenNum(root->FirstChild));
        return;
    }
    struct Tnode* p=kthChild(root,4);
    if(p->Type!=T_DefList)
        return;
    //printf("constrcut\n");
    FieldList f=addFieldInStructure(p);
    type->u.structure=f;
}
void constructFunction(struct Type_* type,struct Tnode* root,int index){ //root T_FunDec
    //printf("%s\n",TypeName[root->Type]);
    struct Tnode* id=root->FirstChild;
    //printf("1\n");
    //printf("return: %s\n",TypeName[id->Type]);
    if(SymTable[SymTable[index]->retTypeIndex]->type==NULL){
        //printf("11\n");
        addOneType(SymTable[index]->retTypeIndex);
    }
    //printf("2\n");
    type->name=mstrdup(SymTable[index]->SymName);
    //printf("3\n");
    type->u.function.return_value=SymTable[SymTable[index]->retTypeIndex]->type;
    //printf("4\n");
    int len=childrenNum(root);
    FieldList f_head=NULL;
    FieldList f_tail=NULL;
    if(len==3){
        type->u.function.params=NULL;
    }
    else if(len==4){
        //printf("len=4\n");
        struct Tnode* varlist=kthChild(root,3);
        struct Tnode* p=varlist;
    
		while(true){
            struct Tnode* paramdec=p->FirstChild;
            struct Tnode* vardec=kthChild(paramdec,2);
            while(childrenNum(vardec)!=1)
                vardec=vardec->FirstChild;
            struct Tnode* iid=vardec->FirstChild;
			if(iid->SymIndex<0)//check
				return;
            if(SymTable[iid->SymIndex]->type==NULL)
                addOneType(iid->SymIndex);
            FieldList l=(FieldList)malloc(sizeof(struct FieldList_));
            l->tail=NULL;
            l->type=SymTable[iid->SymIndex]->type;
            l->name=mstrdup(SymTable[iid->SymIndex]->SymName);
            if(f_head==NULL)
                f_head=f_tail=l;
            else{
                f_tail->tail=l;
                f_tail=l;
            }
            if(childrenNum(p)==1)
                break;
            else
                p=kthChild(p,3);
            
        }
        type->u.function.params=f_head;
    
	}
    else{
        printf("error in constructFunction function\n");
    }
    //printf("return ok\n");
}
void addOneType(int i){
    if(SymTable[i]==NULL)
        return;
    if(SymTable[i]->type!=NULL)
	    return;
    if(strcmp(SymTable[i]->TypeName,"INT")==0 && (SymTable[i]->node==NULL || SymTable[i]->node->Dimension==0)){
        SymTable[i]->type=(struct Type_*)malloc(sizeof(struct Type_));
        SymTable[i]->type->kind=BASIC;
        SymTable[i]->type->name=TypeName[T_INT];
		//printf("addOneType:%s\n",SymTable[0]->type->name);
    }
    else if(strcmp(SymTable[i]->TypeName,"FLOAT")==0 && (SymTable[i]->node==NULL ||SymTable[i]->node->Dimension==0)){
        SymTable[i]->type=(struct Type_*)malloc(sizeof(struct Type_));
        SymTable[i]->type->kind=BASIC;
        SymTable[i]->type->name=TypeName[T_FLOAT];
    }
    else if(strcmp(SymTable[i]->TypeName,"StructObj")==0){ 
        SymTable[i]->type=(struct Type_*)malloc(sizeof(struct Type_));
        SymTable[i]->type->kind=STRUCTURE;
        SymTable[i]->type->name=mstrdup(SymTable[i]->SymName);
        constructStructure(SymTable[i]->type,SymTable[i]->node);
    }
    else if(strcmp(SymTable[i]->TypeName,"function")==0){
        SymTable[i]->type=(struct Type_*)malloc(sizeof(struct Type_));
        SymTable[i]->type->kind=FUNCTION;
        constructFunction(SymTable[i]->type,SymTable[i]->node,i);
    }
    else{
        if(SymTable[i]->node->Dimension==0){   //struct variable
            int t=getDesc(SymTable[i]->TypeName,false);
            if(t<0){
                printf("Something error in addDetailTypeInTable function!!!\n");
                return;
            }
            if(SymTable[t]->type==NULL){ 
                SymTable[t]->type=(struct Type_*)malloc(sizeof(struct Type_));
                SymTable[t]->type->kind=STRUCTURE;
                SymTable[t]->type->name=mstrdup(SymTable[t]->SymName);
                constructStructure(SymTable[t]->type,SymTable[t]->node);
            }
            SymTable[i]->type=SymTable[t]->type;
        }
        else{   //array
            //printf("\n");
            //SymTable[i]->type=(struct Type_*)malloc(sizeof(struct Type_));
            //SymTable[i]->type->kind=ARRAY;
            struct Tnode* vardec=SymTable[i]->node;
            char* n=mstrdup(SymTable[i]->TypeName);
            struct Type_* t_end=(struct Type_*)malloc(sizeof(struct Type_));
            if(strcmp(n,"INT")==0){
                t_end->kind=BASIC;
                t_end->name=mstrdup("INT");
            }
            else if(strcmp(n,"FLOAT")==0){
                t_end->kind=BASIC;
                t_end->name=mstrdup("FLOAT");
            }
            else{
                int t=getDesc(n,false);
                if(t<0){
                    printf("Something error in addDetailTypeInTable function!!!\n");
                    return ;
                }
                if(SymTable[t]->type==NULL){ 
                    SymTable[t]->type=(struct Type_*)malloc(sizeof(struct Type_));
                    SymTable[t]->type->kind=STRUCTURE;
                    SymTable[t]->type->name=mstrdup(SymTable[t]->SymName);
                    constructStructure(SymTable[t]->type,SymTable[t]->node);
                }
                t_end=SymTable[t]->type;
            }
            struct Type_* t_tail=NULL;
            while(true){
                struct Tnode* num=kthChild(vardec,3);
                struct Type_* temp=(struct Type_*)malloc(sizeof(struct Type_));
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
void addDetailTypeInTable(){
    for(int i=0;i<SymTableSize;i++)
    {
        //printf("start add %d\n",i);
        addOneType(i);
        //printf("finish add %d\n",i);
    }
}
void SecondTraverse()
{
//    printSymTable();
//    printf("start add detail Type in table \n");
    addDetailTypeInTable();
//    printf("add detail Type in table ok\n");
//    printTypeInSymTable();
//    printf("print Type in table ok\n");
    secondTraverse(ROOT);
}
void processCurFunction(struct Tnode* root){//FunDec
    if(root->NextSibling==NULL || root->NextSibling->Type!=T_CompSt)
        return;
    struct Tnode* FunDec=root;
    struct Tnode* ID=kthChild(FunDec,1);
    curFunctionIndex=getDesc(ID->Desc,true);
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
        case T_FunDec:
            processCurFunction(root);
            break;
        case T_Stmt:
            if(kthChild(root,1)->Type==T_RETURN && kthChild(root,2)->type!=NULL && curFunctionIndex>=0){    
            //if(kthChild(root,1)->Type==T_RETURN && kthChild(root,2)->type!=NULL ){
                if(isSameType(SymTable[curFunctionIndex]->type->u.function.return_value,kthChild(root,2)->type)==1){
                    ShowError(8,root->FirstChild->lineno);
                    printf("Type mismatched for return\n\n");
                }
            }
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
                    root->type=NULL;
                }
                else{
                    root->type=SymTable[getDesc(root->FirstChild->Desc,false)]->type;
                }
            }
            else if(root->FirstChild->Type==T_INT){//Exp->INT
                root->type=SymTable[0]->type;
            }
            else if(root->FirstChild->Type==T_FLOAT){//Exp->FLOAT
                root->type=SymTable[1]->type;
            }
            break;
        case 2:
            if(root->FirstChild->Type==T_MINUS){//Exp->MINUS Exp
                root->type=kthChild(root,2)->type;
            }
            else if(root->FirstChild->Type==T_NOT){//Exp->NOT Exp
                root->type=kthChild(root,2)->type;
            }
            break;
        case 3:
            if(root->FirstChild->Type==T_ID){//Exp->ID LP RP
                if(getDesc(root->FirstChild->Desc,true)<0 && getDesc(root->FirstChild->Desc,false)<0){
                    ShowError(2,root->FirstChild->lineno);
                    printf("Undefined function \"%s\"\n\n",root->FirstChild->Desc);
                    root->type=NULL;
                }
                else if(getDesc(root->FirstChild->Desc,true)<0 && getDesc(root->FirstChild->Desc,false)>=0){
                    ShowError(11,root->FirstChild->lineno);
                    printf("\"%s\" is not a function\n\n",root->FirstChild->Desc);
                    root->type=NULL;
                }    
                else{
                    struct Type_* type=SymTable[getDesc(root->FirstChild->Desc,true)]->type;
                    if(type==NULL || type->kind!=FUNCTION){
                        printf("error\n");
                        break;
                    }
                    root->type=type->u.function.return_value;
                    if(type->u.function.params!=NULL){    
                        ShowError(9,root->FirstChild->lineno);
                        printf("Function \"%s\" is not applicable for argument\n\n",root->FirstChild->Desc);
                    }
                }
            }
            else if(root->FirstChild->Type==T_LP){//Exp->LP Exp RP
                root->type=kthChild(root,2)->type;
            }
            else if(kthChild(root,2)->Type==T_DOT){//Exp->Exp DOT ID  
                if(kthChild(root,1)->type==NULL){
                    root->type=NULL;
                    break;
                }
                struct Type_* t=root->FirstChild->type;
                struct Tnode* thisId=kthChild(root,3);
                if(t==NULL){
                    root->type=NULL;
                    break;
                }
                if(t->kind!=STRUCTURE){
                    root->type=NULL;
                    ShowError(13,root->FirstChild->lineno);
                    printf("Illegal use of \".\"\n\n");
                }
                else{
                    FieldList f=t->u.structure;
                    while(f!=NULL){
                        if(strcmp(f->name,thisId->Desc)==0)
                            break;
                        else
                            f=f->tail;
                    }
                    if(f==NULL){
                        root->type=NULL;
                        ShowError(14,root->FirstChild->lineno);
                        printf("Non-existent field \"%s\"\n\n",thisId->Desc);
                    }
                    else{
                        root->type=f->type;
                    }
                }
            }
            else if(root->FirstChild->NextSibling->Type==T_ASSIGNOP){ //Exp->Exp ASSIGNOP Exp
                
                if(kthChild(root,1)->type==NULL || kthChild(root,3)->type==NULL){
                    root->type=NULL;
                    break;
                    //printf("1\n");
                }
                if(childrenNum(root->FirstChild)==1 && root->FirstChild->FirstChild->Type==T_ID){ //Exp->ID
                    //printf("2\n");
                }
                else if(childrenNum(root->FirstChild)==4 && kthChild(root->FirstChild,2)->Type==T_LB){ //Exp->Exp LB Exp RB
                    //printf("3\n");
                }
                else if(childrenNum(root->FirstChild)==3 && kthChild(root->FirstChild,2)->Type==T_DOT){ //Exp->Exp DOT ID
                    //printf("4\n");
                }
                else{
                    //printf("5\n");
                    root->type=NULL;
                    ShowError(6,root->FirstChild->lineno);
                    printf("The left-hand side of an assignment must be a variable\n\n");
                    break;
                }
                if(isSameType(kthChild(root,1)->type,kthChild(root,3)->type)==1){
                    ShowError(5,root->FirstChild->lineno);
                    printf("Type mismatched for assignment\n\n");
                    root->type=NULL;
                }
                else{
                    root->type=root->FirstChild->type;
                }
            }
            else if(kthChild(root,2)->Type==T_AND || kthChild(root,2)->Type==T_OR){
                if(kthChild(root,1)->type==NULL || kthChild(root,3)->type==NULL){
                    root->type=NULL;
                    break;
                }
                if(kthChild(root,1)->type->kind!=BASIC || kthChild(root,3)->type->kind!=BASIC || (strcmp(kthChild(root,1)->type->name,"INT")!=0 && strcmp(kthChild(root,3)->type->name,"FLOAT")!=0)){
                    root->type=NULL;
                    ShowError(7,root->FirstChild->lineno);
                    printf("Type mismatched for operands\n\n");
                }
                else{
                    root->type=kthChild(root,1)->type;
                }
            }
            else{
                if(kthChild(root,1)->type==NULL || kthChild(root,3)->type==NULL){
                    root->type=NULL;
                    break;
                }
                if(kthChild(root,1)->type->kind!=BASIC || kthChild(root,3)->type->kind!=BASIC){
                    root->type=NULL;
                    ShowError(7,root->FirstChild->lineno);
                    printf("Type mismatched for operands\n\n");
                }
                else{
                    if(strcmp(kthChild(root,1)->type->name,kthChild(root,3)->type->name)!=0){
                        root->type=NULL;
                        ShowError(7,root->FirstChild->lineno);
                        printf("Type mismatched for operands\n\n");
                    }
                    else{
                        root->type=kthChild(root,1)->type;
                    }
                }
            }
            break;
        case 4:
            if(root->FirstChild->Type==T_ID){//Exp->ID LP Args RP
                if(getDesc(root->FirstChild->Desc,true)<0 && getDesc(root->FirstChild->Desc,false)<0){
                    root->type=NULL;
                    ShowError(2,root->FirstChild->lineno);
                    printf("Undefined function \"%s\"\n\n",root->FirstChild->Desc);
                }
                else if(getDesc(root->FirstChild->Desc,true)<0 && getDesc(root->FirstChild->Desc,false)>=0){
                    //printf("Desc:%s\n",root->FirstChild->Desc);
                    //printf("%d\n",getDesc(root->FirstChild->Desc,true));
                    //printf("%d\n",getDesc(root->FirstChild->Desc,false));
                    root->type==NULL;
                    ShowError(11,root->FirstChild->lineno);
                    printf("\"%s\" is not a function\n\n",root->FirstChild->Desc);
                }
                else{//Exp->ID LP Args RP
                    struct Type_* type=SymTable[getDesc(root->FirstChild->Desc,true)]->type;
                    if(type==NULL || type->kind!=FUNCTION){
                        printf("error\n");
                        break;
                    }
                    root->type=type->u.function.return_value;
                    FieldList f=type->u.function.params;
                    struct Tnode* Args=kthChild(root,3);
                    int flag=0;
                    while(f!=NULL){    
                        //printf("compare\n");
                        if(Args->FirstChild->type==NULL){
                            flag=1;
                            break;
                        }
                        if(isSameType(f->type,Args->FirstChild->type)!=0)
                            break;
                        f=f->tail;
                        if(childrenNum(Args)==1)
                            break;
                        else if(f!=NULL)
                            Args=kthChild(Args,3);
                    }
                    if(flag==1)
                        break;
                    if(childrenNum(Args)==1 && f==NULL){
                    }
                    else{
                        ShowError(9,root->FirstChild->lineno);
                        printf("Function \"%s\" is not applicable for argument\n\n",root->FirstChild->Desc);
                    }
                }
            }
            else{   //Exp->Exp LB Exp RB
                struct Tnode* child1=kthChild(root,1);
                struct Tnode* child3=kthChild(root,3);
                if(child1->type==NULL || child3->type==NULL)
                    break;
                if(child1->type->kind!=ARRAY){
                    root->type=NULL;
                    ShowError(10,root->FirstChild->lineno);
                    printf("before [ is not an array\n\n");
                }
                else{
                    if(child3->type->kind!=BASIC || strcmp(child3->type->name,"INT")!=0){
                        root->type=NULL;
                        ShowError(12,root->FirstChild->lineno);
                        printf("in [] is not an integer\n\n");
                    }
                    else{
                        root->type=child1->type->u.array.elem;
                    }
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
    firstCheck(ROOT);
}


bool FuncParamCMP(struct Tnode* n1, struct Tnode* n2)
{
    struct Tnode* p=n1;
    struct Tnode* q=n2;
    while(true)
    {
        if(p==NULL && q==NULL)
            break;
        if(p==NULL || q==NULL)
            return false;
        if(p->Type!=q->Type)
            return false;
        if(p->Type==T_TYPE && p->Desc[0] != q->Desc[0])
            return false;
        if(p->Type==T_Tag)
            if(!streq(p->FirstChild->Desc,q->FirstChild->Desc))
            return false;
        if(!FuncParamCMP(p->FirstChild,q->FirstChild))
            return false;
        p=p->NextSibling;
        q=q->NextSibling;
    }
    return true;
}

struct Tnode* findArrID(struct Tnode* root)
{
    struct Tnode* p=root;
    while(p!=NULL && p->Type==T_VarDec)
    {
        p=p->FirstChild;
    }
    return p;
}

void CheckParam(struct Tnode* root)
{
	if(root==NULL)
		return;
	if(root->Type==T_ParamDec)
	{
		CheckParam(root->FirstChild->NextSibling);
	}
	else if(root->Type==T_ID)
	{
		int redef = getDesc(root->Desc, false);
		if(SymTable[redef]->node->Dimension>0)
		{
			struct Tnode* pre = findArrID(SymTable[redef]->node);
			if(pre != root)
			{
		    	ShowError(3,root->lineno);
            	printf("Redefined variable ");
            	ShowQuote(root->Desc,true);
            	ShowNote();
            	printf("previous defination at line %d",pre->lineno);
            	EndError();
			}
		}
		else if(SymTable[redef]->node!=root)
		{
		    ShowError(3,root->lineno);
            printf("Redefined variable ");
            ShowQuote(root->Desc,true);
            ShowNote();
            printf("previous defination at line %d",SymTable[redef]->lineno);
            EndError();
		}
	}
	else
	{
		for(struct Tnode* p = root->FirstChild;p!=NULL;p=p->NextSibling)
			CheckParam(p);
	}
}

int FunIndex = -1;
int StructIndex = -1;
void firstCheck(struct Tnode* root)
{
    if(root==NULL)
        return;
    switch(root->Type)
    {
        case T_FunDec:
            if(root->SymIndex<0)
            {
                //Redefine Function
                int redef = getDesc(root->FirstChild->Desc, true);
                ShowError(4,root->lineno);
                printf("Redefined function ");
                ShowQuote(root->FirstChild->Desc, true);
                ShowNote();
                printf("previous defination at line %d",SymTable[redef]->lineno);
                EndError();
                break;
            }
            if(root->FirstChild->NextSibling->NextSibling->Type==T_VarList)
            {
                int redef = getDesc(root->FirstChild->Desc, true);
                struct Tnode* pre = SymTable[redef]->node;
                if(pre != root)
                {
                    if(pre==NULL)
                    {
                        printf("SymTable Error: NULL Node Pointer\n");
                        break;
                    }
                    if(!FuncParamCMP(pre->FirstChild->NextSibling->NextSibling, root->FirstChild->NextSibling->NextSibling))                
                    {
                        /* declare inconsist*/
                        ShowError(19,root->lineno);
                        printf("Inconsistent declaration of function ");
                        ShowQuote(SymTable[redef]->TypeName,true);
                        ShowNote();
                        printf("previous declared at line %d",SymTable[redef]->lineno);
                        EndError();
                        break;
                    }
                }
				else
					CheckParam(root->FirstChild->NextSibling->NextSibling);
            }
            break;
        
        case T_StructSpecifier:
            if(root->SymIndex<0)
            /* Undefined structure & obj */
                break;
            if(root->FirstChild->NextSibling->Type!=T_OptTag)
                break;
            StructIndex = root->SymIndex;
            firstCheck(root->FirstChild->NextSibling->NextSibling->NextSibling);
            StructIndex = -1;
            break;
        case T_ASSIGNOP:
            if(StructIndex>=0)
            {
                ShowError(15, root->lineno);
                printf("cannot use assignment in STRUCT declaration");
                EndError();
            }
            break;
        case T_ID:
            /*VarDec->ID*/
            if(getDesc(root->Desc, false)<0)
            /*undefine var*/
                break;
            else
            {
                int redef = getDesc(root->Desc, false);
                struct Tnode* pre = SymTable[redef]->node;
                if(pre==root)
                    pre->StructIndex=StructIndex;
                else if(pre->Dimension>0)
                {
                    /*Array*/
                    pre = findArrID(pre);
                    if(pre==NULL)
                    {
                        printf("Array Node Error\n");
                        break;
                    }
                    if(pre!=root)
                    {
                        ShowError(3,root->lineno);
                        printf("Redefined variable ");
                        ShowQuote(root->Desc,true);
                        ShowNote();
                        printf("previous defination at line %d",pre->lineno);
                        EndError();
                    }
                }
                else
                {
                    /*redefine*/
                    if(pre->StructIndex<0 || pre->StructIndex != StructIndex)
                    {
                        ShowError(3,root->lineno);
                        printf("Redefined variable ");
                        ShowQuote(root->Desc,true);
                        ShowNote();
                        printf("previous defination at line %d",pre->lineno);
                        EndError();
                        
                    }
                    else
                    {
                        ShowError(15,root->lineno);
                        printf("Redefined field ");
                        ShowQuote(root->Desc,true);
                        ShowNote();
                        printf("previous defination at line %d",pre->lineno);
                        EndError();
                    }
                }
            }
            break;
        case T_Exp:
            break;
		case T_ExtDef:
			if(root->FirstChild->NextSibling->Type==T_FunDec)
			{
				int rettype=root->FirstChild->SymIndex;
				int redef = getDesc(root->FirstChild->NextSibling->FirstChild->Desc,true);
				if(rettype!=SymTable[redef]->retTypeIndex)
				{
                    ShowError(19,root->lineno);
                    printf("Inconsistent declaration of function ");
                	ShowQuote(SymTable[redef]->TypeName, true);
                	ShowNote();
                	printf("previous declared at line %d",SymTable[redef]->lineno);
                	EndError();
					break;
				}
			}
        default:
            for(struct Tnode* p=root->FirstChild;p!=NULL;p=p->NextSibling)
                firstCheck(p);
            break;
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
            /*prob redefine*/
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
			//if(node->SymIndex = -1)
			//	return;
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
            if(redef<0)
            {
                struct SymDesc* fdesc = newDesc(func->FirstChild->Desc,TypeName[T_FUNC],T_FUNC,func->lineno,func,Specifier->SymIndex);
                if(func->NextSibling->Type!=T_SEMI)
                fdesc->defined = true;
                redef = createDesc(fdesc);
            }
            func->SymIndex = redef;
            node->SymIndex = func->SymIndex;
            return;
        }
        else if(redef>=0)
        {
            /*redefine error*/
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
