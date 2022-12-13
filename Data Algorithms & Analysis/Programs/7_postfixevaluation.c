#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct Stack{
    int size, top;
    float *ptr;
}Stack;

Stack createStack(int size){
    Stack st;
    st.size = size;
    st.top = -1;
    st.ptr = (float *)malloc(st.size*sizeof(float));
    return st;
}

void push(Stack *st, float data){
    if(st->top == st->size-1)
        printf("Stack Overflown\n");
    else{
        st->top++;
        st->ptr[st->top] = data;
    }
}

float pop(Stack *st){
    float x = -1;
    if(st->top == -1)
        printf("Stack Underflown\n");
    else{
        x = st->ptr[st->top];
        st->top--;
    }
    return x;
}

int prec(char x){
    if(x=='+' || x=='-')
        return 1;
    else if(x=='*' || x=='/')
        return 2;
    else if(x=='^')
        return 3;
}

int isOperand(char x){
    if(x=='+' || x=='-' || x=='*' || x=='/' || x=='^')
        return 0;
    else
        return 1;
}

void displayStack(Stack st){
    printf("Stack: ");
    for(int i=0; i<=st.top; i++)
        printf("%f ", st.ptr[i]);
    printf("\n");
}

// int Eval(char *postfix){
//     Stack st = createStack(strlen(postfix));
//     int i, x1, x2, res;
//     for(i=0; postfix[i]!=0; i++){
//         if(isOperand(postfix[i]))
//             push(&st, postfix[i]-48);
//         else{
//             x2 = pop(&st);
//             x1 = pop(&st);
//             switch(postfix[i]){
//                 case '+':
//                     res = x1+x2;
//                     push(&st, res);
//                     break;
//                 case '-':
//                     res = x1-x2;
//                     push(&st, res);
//                     break;
//                 case '/':
//                     res = x1/x2;
//                     push(&st, res);
//                     break;
//                 case '*':
//                     res = x1*x2;
//                     push(&st, res);
//                     break;
//                 case '^':
//                     res = pow((int)x1, (int)x2);
//                     push(&st, res);
//                     break;
//                 default:
//                     printf("Invalid Input\n");
//                     return 0;
//             }
//         }
//     }
//     return pop(&st);
// }

float Evaluate(char *postfix){
    Stack st = createStack(strlen(postfix));
    for(int i=0; i<strlen(postfix); i++){
        while(postfix[i]!=' ' && postfix[i]!=0)
            i++;
        int j=i-1, num=0, flag=0;
        while(j>=0 && postfix[j]!=' ' && postfix[i-1]>='0' && postfix[i-1]<='9'){
            num += (postfix[j]-48)*(int)pow(10, i-j-1);
            flag=1;
            j--;
        }
        printf("num: %d\n", num);
        if(flag){
            push(&st, num);
            displayStack(st);
        }
        else{
            float x2 = pop(&st);
            displayStack(st);
            float x1 = pop(&st);
            displayStack(st);
            float res;
            switch(postfix[i-1]){
                case '+':
                    res = x1+x2;
                    break;
                case '-':
                    res = x1-x2;
                    break;
                case '/':
                    res = x1/x2;
                    break;
                case '*':
                    res = x1*x2;
                    break;
                case '^':
                    res = pow((int)x1, (int)x2);
                    break;
                default:
                    printf("Invalid Input\n");
                    return 0;
            }
            push(&st, res);
            displayStack(st);
        }
    }
    return pop(&st);
}

void main(){
    char *postfix = (char *)malloc(sizeof(char)*100);
    printf("Enter expression: ");
    // gets(postfix);
    scanf("%[^\n]s", postfix);
    printf("Evaluation: %f\n", Evaluate(postfix));
}