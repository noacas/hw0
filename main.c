#include <stdio.h>
#include <stdlib.h>

int getBase();
int getA();
int getB();
int getNum(int);
void printRes(int, int);
int reverseGetNum(int);
int charToDigit(int, char);
void reversePrintNum(int, int);
char digitToChar(int);
int isCharDigit(char);
int power(int, int);

int main() {
    int a, b, num;
    a = getA();
    b = getB();
    num = getNum(a);
    printRes(b, num);
    return 0;
}

int isCharDigit(char c) {
    if ((c >= '0') && (c <= '9')) {
        return 1;
    }
    return 0;
}

int getBase() {
    int a;
    char a1, a2, a3;
    a1 = getchar();
    if (a1 == '\n') {
        return 0;
    }
    a2 = getchar();
    if (isCharDigit(a1) == 1) {
        if (a1 == '1') {
            if (isCharDigit(a2) == 1) {
                a = 10 + a2 - '0';
                a3 = getchar();
                if ((a3 == '\n') && (a >= 10) && (a <= 16)) {
                    return a;
                }
            }
        } else {
            a = a1 - '0';
            if ((a2 == '\n') && (a >= 2) && (a <= 9)) {
                return a;
            }
        }
    }
    return 0;
}


int getA() {
    int a;
    printf("Please enter the numbers base:\n");
    a = getBase();
    if (a == 0) {
        printf("Invalid input base\n");
        exit(2);
    }
    return a;
}

int getB() {
    int a;
    printf("Please enter the desired base:\n");
    a = getBase();
    if (a == 0) {
        printf("Invalid desired base\n");
        exit(2);
    }
    return a;
}

int getNum(int a) {
    printf("Please enter a number in base %d:\n", a);
    return reverseGetNum(a);
}

int reverseGetNum(int a)
{
    static int sum = 0;
    static int i = 0;
    char c;
    if((c = getchar()) != '\n'){
        reverseGetNum(a);
        sum += charToDigit(a, c) * power(a, i);
        i++;
    }
    return sum;
}

int charToDigit(int a, char c) {
    int n;
    if (isCharDigit(c) == 1) {
        n = c - '0';
    }
    else {
        n = c - 'a' + 10;
    }
    if (n >= a) {
        printf("Invalid number!\n");
        exit(2);
    }
    return n;
}

char digitToChar(int d) {
    if (d >= 10) {
        return 'a' + d - 10;
    }
    else {
        return '0' + d;
    }
}

void printRes(int b, int num) {
    printf("The result is: ");
    reversePrintNum(b, num);
    printf("\n");
}

void reversePrintNum(int b, int num) {
    if (num > 0) {
        int d = num % b;
        reversePrintNum(b, num / b);
        printf("%c", digitToChar(d));
    }
}

int power(int base, int exponent)
{
    int i, result=1;
    for (i = exponent; i>0; i--)
    {
        result = result * base;
    }
    return result;
}