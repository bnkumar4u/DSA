#include <stdio.h>
int priority(char x);
void init(int *top);
int emptyStack(int top);
int is_operator(char x);
void pop(char *p,char *stack,int*top);
void push(char x,char *stack,int *top);
int main()
{
	char a[50],stack[50],p,x;
	gets(a);
	int top,i=0;


	init(&top);
	
	while(a[i]!='\0')
	{
		//printf("%s\n",a );
		if(a[i]>='a'&&a[i]<='z')
		{
			printf("%c",a[i] );
		}
		else if(a[i]=='(')
		{
			push(a[i],stack,&top);
		}
		else if(a[i]==')')
		{
			pop(&p,stack,&top);
			while(p!='(')
			{
				printf("%c",p );
				pop(&p,stack,&top);
			}
		}
		else if(is_operator(a[i]))
		{
			if(!emptyStack(top))
			{
				pop(&p,stack,&top);
				push(p,stack,&top);
				while(!emptyStack(top)&& p!='('&&priority(a[i])<=priority(p))
				{
					pop(&p,stack,&top);
					printf("%c",p );
					if(!emptyStack(top))
					{
						pop(&p,stack,&top);
						push(p,stack,&top);
					}
				}
			}
			push(a[i],stack,&top);
		}

		i++;
	}
	while(!emptyStack(top))
	{
		pop(&p,stack,&top);
		printf("%c",p );
	}

	return 0;
}
void init(int *top)
{
	*top=-1;
}
int emptyStack(int top)
{
	if (top==-1)
		return 1;
	else
		return 0;
}
void push(char x,char *stack,int *top)
{
	*top=*top+1;
	stack[*top]=x;
}
void pop(char *p,char *stack,int*top)
{
	*p=stack[*top];
	*top=*top-1;
}
int is_operator(char x)
{
	switch(x)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '=':
		case '^':
		return 1;
		default :
		return 0;
	}
	return 0;
}
int priority(char x)
{
	if(x=='=')
		return 1;
	if(x=='+'||x=='-')
		return 2;
	if(x=='*'||x=='/')
		return 3;
	if(x=='^')
		return 4;
}