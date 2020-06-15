#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pr (char c)
{
	if (c=='+'||c=='-')
		{
			return 1;
		}
	else if (c=='*'||c=='/')
		{
			return 2;
		}
	else if (c=='^')
		{
			return 3;
		}
	else
		{
			return -1;
		}
}

char stack[1000];
int top;

int main()
{
	system ("cls");
	top = -1;
	char a[1000],b[1000],c;
	int temp,k=0;
	
	printf ("\t\tINFIX TO PREFIX\n\n");
	printf ("Enter the expression : ");
	fflush (stdin);
	gets(a);
	fflush (stdin);
	strrev(a);
	
	for (int i=0;i<strlen(a);i++)
		{
			if ((a[i]>='A'&&a[i]<='Z')||(a[i]>='a'&&a[i]<='z'))
				{
					b[k]=a[i];
					k++;
				}
			else if (a[i]==')')
				{
					if (top==1000)
					{
						printf ("\nStack is full.");
					}
					else
					{
						top++;
						stack[top]=a[i];
					}
				
				}
			else if (a[i]=='(')
				{
					while (stack[top]!=')')
						{
							b[k]=stack[top];
							k++;
							top--;
						}
					top--;
				}
			else 
				{
					if (stack[top]=='(')
						{
							if (top==1000)
							{
								printf ("\nStack is full.");
							}
							else
							{
								top++;
								stack[top]=a[i];
							}
						}
					else
						{
							while (pr(stack[top])>=pr(a[i]))
								{
									b[k]=stack[top];
									k++;
									top--;
								}
							top++;
							stack[top]=a[i];
						}
				}
		}
	for (int i=top;i>=0;i--)
		{
			b[k]=stack[i];
			k++;	
		}
	strrev(b);
	puts(b);
	
	
	printf ("\n\nDo you want to continue? Y/N\nEnter your choice: ");
	fflush (stdin);
	scanf ("%c",&c);
	fflush (stdin);
	
	if (c=='y'||c=='Y')
		{
			main();
		}
	else 
		{
			exit(0);
		}
}
