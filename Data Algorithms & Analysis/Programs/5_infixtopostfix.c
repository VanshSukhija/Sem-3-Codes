#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct Stack{
    int size, top;
    char *ptr;
}Stack;

Stack createStack(int size){
    Stack st;
    st.size = size;
    st.top = -1;
    st.ptr = (char *)malloc(st.size*sizeof(char));
    return st;
}

void push(Stack *st, char data){
    if(st->top<st->size){
        st->top++;
        st->ptr[st->top] = data;
    }
}

char pop(Stack *st){
    char x=0;
    if(st->top!=-1)
        x = st->ptr[st->top--];
    return x;
}

int isOperand(char ch){
    if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))
        return 1;
    else
        return 0;
}

// int isOperator(char ch){
//     if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')
//         return 1;
//     else
//         return 0;
// }

int precedence(char ch){
    if(ch=='(')
        return 0;
    else if(ch=='+' || ch=='-')
        return 1;
    else if(ch=='*' || ch=='/')
        return 2;
    else if(ch=='^')
        return 3;
}

int isBalance(char *exp){
    Stack st = createStack(strlen(exp));
    for(int i=0; exp[i]!=0; i++){
        if(exp[i]=='('){
            if(exp[i+1]==')')
                return 0;
            else
                push(&st, exp[i]);
        }
        else if(exp[i]==')'){
            if(st.top==-1)
                return 0;
            pop(&st);
        }
        if(isOperand(exp[i]) && isOperand(exp[i+1]))
            return 0;
    }
    return st.top==-1?1:0;
}

// void displayStack(Stack st){
//     printf("Stack: ");
//     for(int i=0; i<=st.top; i++)
//         printf("%c", st.ptr[i]);
//     printf("\n");
// }

char *infixtopostfix(char *infix){
    char *postfix = (char *)malloc(sizeof(char)*(strlen(infix)));
    if(!isBalance(infix)){
        printf("Invalid Input\n");
        return 0;
    }
    int i=0, j=0;
    Stack st = createStack(strlen(infix));
    while(infix[i]!=0){
        if(isOperand(infix[i])){
            postfix[j++] = infix[i++];
        }
        else{
            if(infix[i]=='(')
                push(&st, infix[i++]);
            else if(infix[i]==')'){
                while(st.ptr[st.top]!='(' && st.top>=0)
                    postfix[j++] = pop(&st);
                pop(&st);
                i++;
            }
            else{
                if(precedence(infix[i])>precedence(st.ptr[st.top]) || st.top==-1)
                    push(&st, infix[i++]);
                else
                    postfix[j++] = pop(&st);
            }
        }
    }
    while(st.top!=-1){
        if(st.ptr[st.top]!='(')
            postfix[j++] = pop(&st);
        else
            pop(&st);
    }
    postfix[j] = '\0';
    return postfix;
}

void main(){
    char *infix = (char *)malloc(100*sizeof(char));
    printf("Enter an infix expression: ");
    // gets(infix);
    scanf("%s", infix);
    printf("Infix: %s\n", infix);
    char *postfix = infixtopostfix(infix);
    printf("Postfix: %s\n", postfix);
}