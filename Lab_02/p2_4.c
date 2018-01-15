#include <stdio.h>

void printMenu();
int add(int, int);
int sub(int, int);
int mul(int, int);
int div(int, int);

int main() {
    int a, b;
    int sw;
    int (*funcPointer)(int, int);

    while(1) {
        printMenu();
        printf("Select Operation : ");
        scanf("%d", &sw);
        if(sw == 4) break;
        else if (sw > 4 || sw < 0)
            puts("!! Wrong input !!");
        else {
            switch(sw) {
            case 0:
                funcPointer = add;
                break;
            case 1:
                funcPointer = sub;
                break;
            case 2:
                funcPointer = mul;
                break;
            default:
                funcPointer = div;
            }
            printf("Input 2 operand: ");
            scanf("%d %d", &a, &b);
            printf("Result: %d\n", funcPointer(a, b));
        }
    }

    return 0;
}

void printMenu() {
    puts("====================");
    puts("0. add");
    puts("1. sub");
    puts("2. mul");
    puts("3. div");
    puts("4. exit");
    puts("====================");
}

int add(int a, int b) {
    return a+b;
}
int sub(int a, int b) {
    return a-b;
}
int mul(int a, int b) {
    return a*b;
}
int div(int a, int b) {
    return a/b;
}
