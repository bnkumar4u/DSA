#include <stdio.h>
void initstack(int *top)
{
	*top=-1;
}
int emptystack(int top)
{
	if (top==-1)
		return 1;
	else
		return 0;
}
int fullstack(int top)
{
	if (top==49)
		return 1;
	else return 0;
}
void push(char *stack,int *top,char x)
{
	*top=*top+1;
	stack[*top]=x;
}
void pop(char *stack,int *top,char *p)
{
	*p=stack[*top];
	*top=*top-1;
}

int priority(char x)
{
	if(x=='=')
		return 0;
	if(x=='+'||x=='-')
		return 1;
	if(x=='*'||x=='/')
		return 2;
	if(x=='^')
		return 3;
}
int main()
{
	char s[50],x[50],p;
	int top,i;
	initstack(&top);
	gets(s);
	i=0;
	while(s[i]!='\0')
	{
		if(s[i]>='a'&&s[i]<='z')
			printf("%c",s[i] );
		
		else if(s[i]=='(')
			push(x,&top,s[i]);
		
		else if(s[i]==')')
		{
			pop(x,&top,&p);
			while(p!='(')
			{
				printf("%c",p );
				pop(x,&top,&p);
			}
		}
		else
		{
			if(!emptystack(top))
			{
				pop(x,&top,&p);
				push(x,&top,p);
				while(!emptystack(top)&& p!='('&&priority(s[i])<=priority(p))
				{
					pop(x,&top,&p);
					printf("%c",p );
					if(!emptystack(top))
					{
						pop(x,&top,&p);
						push(x,&top,p);
					}
				}
			}
			push(x,&top,s[i]);
		}

		i++;
	}
	while(!emptystack(top))
	{
		pop(x,&top,&p);
		printf("%c",p );
	}

	return 0;
}