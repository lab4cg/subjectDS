#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int main() {
    char* p = "{A[(i+1)]=0;}";
    char n[30];

    char* a = "eye";
    char* b = "rear";

    if (check_palin(b)) printf("%s�� ȸ��", b);
    else printf("%s�� ȸ��x", b);

    /*
    scanf("%s", n);

    if (check_matcing(n) == 1) printf("%s ����\n", n);
    else printf("%s ����\n", n);
    */

    return 0;
}