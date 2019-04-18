#include "stdio.h"
#include "Kits.h"
bool ISOK = true;
bool curOK = true;

char* curFuncName=0;

char* int2str(int val, int* retlen)
{
	if(val < 0)
	{
		*retlen=-1;
		return NULL;
	}
	char* ret = NULL;
	if(val == 0)
	{
		ret = (char*)malloc(sizeof(char)*(2));
		ret[0]='0';
		ret[1]='\0';
		*retlen=1;
		return ret;
	}
	int t = val;
	int len = 0;
	while(t!=0)
	{
		len++;
		t=t/10;
	}
	t=val;
	ret = (char*)malloc(sizeof(char)*(len+1));
	for(int i=0;i<len;i++)
	{
		ret[len-i-1]='0'+t%10;
		t=t/10;
	}
	ret[len]='\0';
	*retlen = len;
	return ret;
}

int hex2int(char* str, int len)
{
	int val = 0;
	for(int i=2;i<len;i++)
	{
		val *= 16;
		if(str[i]>='0' && str[i]<='9')
			val += str[i]-'0';
		else if(str[i]>='A' && str[i]<='F')
			val += str[i]-'A'+10;
		else
			val += str[i]-'a'+10;
	}
	return val;
}

int oct2int(char* str, int len)
{
	int val = 0;
	for(int i=1;i<len;i++)
		val = val*8 + (str[i]-'0');
	return val;
}

int dec2int(char* str, int len)
{
	int val = 0;
	for(int i=0;i<len;i++)
		val = val*10 + str[i]-'0';
	return val;
}

int getNumType(char* str, int *type)
{
	if(str[0]=='\0')
	{
		*type = T_ERROR;
		return 0;
	}
	int len = 0;
	*type = T_DEFAULT;
	for(int i=0;str[i]!='\0';i++)
	{
		if(str[i]=='x' || str[i]=='X')
			*type = T_HEX;
		else if(str[i]=='.')
			*type = T_FLOAT;
		len++;
	}
	if(*type == T_DEFAULT)
	{
		if(str[0]=='0')
			*type = T_OCT;
		else
			*type = T_DECIMAL;
	}
	switch(*type)
	{
		case T_DECIMAL:
			return dec2int(str, len);
		case T_OCT:
			return oct2int(str, len);
		case T_HEX:
			return hex2int(str, len);
		default:
			return 0;
	}
}

void ShowError(int type, int lineno)
{
	if(type<0)
		printf("\033[31mError\033[0m at Line %d: ", lineno);
	else
		printf("\033[31mError\033[0m type %d at Line %d: ", type, lineno);
}
void ShowNote()
{
	printf("    \033[36mnote:\033[0m ");
}
void ShowQuote(char* q, bool end)
{
	printf("\e[1m\"%s\"\e[0m",q);
	if(end)
		printf(".\n");
}
void EndError()
{
	printf(".\n\n");
}
