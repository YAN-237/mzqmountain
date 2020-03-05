#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
char CharEncoding(char ch);
void SentenceEncoding(char* soure, char* code);

int main(){
	int a;
	printf("enter 1 to start,enter a new line to end!\n");
	scanf("%d", &a);
	while (a==1) {

		a = getchar();
		char source[N], code[N];
		printf("Input source sentence:");
		gets(source);//用户可能会输入空格，不能使用scanf
		SentenceEncoding(source, code);
		printf("Encoded sentence:");
		puts(code);
		printf("to continue enter 1,to end enter 0.\n");
		
		if (scanf("%d", &a)!=1)
			break;
	}
	return 0;
}
void SentenceEncoding(char* source, char* code)
{
	int i;
	for (i = 0; source[i] != '\0'; i++)
	{
		code[i] = CharEncoding(source[i]);
	}
	code[i] = '\0';
}
char CharEncoding(char ch)
{
	char encode = 0;
	if (ch >= 'A' && ch <= 'Z')
	{
		encode = ('A' + 'Z'+1) - ch;
	}
	else if (ch >= 'a' && ch <= 'z')
	{
		encode = 'a' + 'z'+1 - ch;
	}
	else
	{
		switch (ch)
		{
		case ' ': encode = '@';
			break;
		case '.': encode = '#';
			break;
		default: encode = '.';
			break;
		}
	}
	return encode;
}

