#include<stdio.h>
#include "Traverse.h"
//#include "SymTable.h"
//#include"Tree.h"
//#include"Kits.h"
int main(int argc,char** argv){
    if(argc<=1)
        return 1;
    FILE* f=fopen(argv[1],"r");
    if(!f){
        perror(argv[1]);
        return 1;
    }
    yyrestart(f);
    yyparse();
    fclose(f);
    /*LGY_0324*/
    /*LJY_0414
	 * Lab1 print Tree*/
//	if(ISOK==true && ROOT!=NULL)
//        Traverse(ROOT,0);
	createTable();
    printSymTable();
    ROOT=NULL;
    ISOK=true;
    return 0;
}
