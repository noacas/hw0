#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int getBase();
int getA();
int getB();
int getNum(int);
void printRes(int, int);
int reverseGetNum(int);
int charToDigit(int, char);
void reversePrintNum(int, int);

int main() {
    int a = getA();
    getchar();
    int b = getB();
    getchar();
    int num = getNum(a);
    printRes(b, num);
    return 0;
}
int getBase() {
    int a;
    char a1 = getchar();
    if (isdigit(a1) == 1) {
        if (a1 == '1') {
            char a2 = getchar();
            if (isdigit(a2) == 1) {
                a = 10 + a2 - '0';
                if ((a >= 10) && (a <= 16)) {
                    return a;
                }
            }
        } else {
            a = a1 - '0';
            if ((a >= 2) && (a <= 9)) {
                return a;
            }
        }
    }
    return 0;
}


int getA() {
    printf("Please enter the numbers base:\n");
    int a = getBase();
    if (a == 0) {
        printf("Invalid input base\n");
        exit(2);
    }
    return a;
}

int getB() {
    printf("Please enter the desired base:\n");
    int a = getBase();
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
        sum += charToDigit(a, c) * pow(a, i);
        i++;
    }
    return sum;
}

int charToDigit(int a, char c) {
    int n;
    if (isdigit(c) == 1) {
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

char digitToChar(int b, int d) {
    char c;
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
}

void reversePrintNum(int b, int num) {
    if (num > 0) {
        int d = num % b;
        reversePrintNum(b, num / b);
        printf("%c", digitToChar(b, d));
    }
}