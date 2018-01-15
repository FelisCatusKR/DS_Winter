#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

typedef struct Stack {
    int* key;
    int top;
    int max_stack_size;
} Stack;

Stack* CreateStack(int max);
void Push(Stack* S, int X);
bool IsFull(Stack *S);
bool IsEmpty(Stack *S);
int Pop(Stack* S);
void DeleteStack(Stack* S);

int main(int argc, char* argv[])
{
    int max, i=0, a, b, result;
    char input_str[101];
    Stack* stack;
    FILE* in;

    in = fopen(argv[1], "r");
    if(in == NULL) {
        puts("File open error: no such file");
        return -1;
    }
    fgets(input_str, 101, in);
    max = strlen(input_str);
    printf("Pushed numbers: ");

    stack = CreateStack(max);
    while(input_str[i] != '#') {
        if(isdigit(input_str[i]))
            Push(stack, (int)(input_str[i]-'0'));
        else {
            b = Pop(stack);
            a = Pop(stack);
            switch(input_str[i]) {
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '*':
                result = a * b;
                break;
            case '/':
                result = a / b;
                break;
            default:
                result = a % b;
            }
            Push(stack, result);
        }
        i++;
    }
    printf("\nevaluation result: %d\n", result);
    fclose(in);
    DeleteStack(stack);

    return 0;
}

Stack* CreateStack(int max) {
    Stack* new;
    new = (Stack*)malloc(sizeof(Stack));
    new->key = (int*)malloc(max*sizeof(int));
    new->max_stack_size = max;
    new->top = -1;
    return new;
}
void Push(Stack* S, int X) {
    if(IsFull(S)) {
        puts("Push error: stack is full");
        exit(-1);
    }
    S->key[++(S->top)] = X;
    printf("%d ", S->key[S->top]);
}

bool IsFull(Stack *S) {
    return S->top == S->max_stack_size-1;
}

bool IsEmpty(Stack *S) {
    return S->top == -1;
}

int Pop(Stack* S) {
    if(IsEmpty(S)) {
        puts("Pop error: stack is empty");
        exit(-1);
    }
    return S->key[S->top--];
}

void DeleteStack(Stack* S) {
    free(S->key);
    free(S);
}
