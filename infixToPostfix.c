#include<stdio.h>
#include<ctype.h>
#define SIZE 10
char s[SIZE];
int top=-1;
push(char e)
{
    s[++top]=e;
}
char pop()
{
    return(s[top--]);
}
int pr(char symbol)
{
    if(symbol== '^')
    {
    return(3);
    }
    else if(symbol== '*' || symbol== '/' )
    {
        return(2);
    }
    else if(symbol== '+' || symbol== '-')
    {
        return(1);
    }
    else
    {
        return(0);
    }
}
int main()
{
    char infix[50],postfix[50],ch,elem;
    int i=0,k=0;
    printf("enter Infix expression");
    scanf("%s",infix);
    int l = strlen(infix);
    
    //Parentheses Matching
    int o=0, c=0;
    for(i=0;i<l;i++)
    {
        if(infix[i] == '(') o++;
        if(infix[i] == ')') c++;
    }
    if(o!=c)
    {
        printf("Parentheses mismatch");
        exit(0);
    }
    //////
    push('#');
    while((ch=infix[i++])!='\0' )
    {
        if(ch == '(') push(ch);
        else
            if(isalnum(ch)) postfix[k++]=ch;
        else if(ch==')')
        {
            while(s[top] !='(')
            postfix[k++]=pop();
            elem=pop();
        }
        else
        {
            while(pr(s[top]) >=pr(ch))
            postfix[k++]=pop();
        push(ch);
        }
    }
    while(s[top]!='#')
        postfix[k++]=pop();
    postfix[k]='\0';
    printf("\nPostfixexpression=%s\n",postfix);
    return 0;
}
