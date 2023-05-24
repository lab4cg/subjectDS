#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int main() {
    StackType* s1; // StackType�� ����Ű�� ������ ���� ����
    StackType* s2; // StackType�� ����Ű�� ������ ���� ����

    s1 = (StackType*)malloc(sizeof(StackType)); // �޸� �����Ҵ� �� s�� �ּҰ� ����
    s2 = (StackType*)malloc(sizeof(StackType)); // �޸� �����Ҵ� �� s�� �ּҰ� ����

    init_s_stack(s1); // ���� ���� �ʱ�ȭ
    init_s_stack(s2); // ���� ���� �ʱ�ȭ

    if (s1 == NULL || s2 == NULL)
        printf("���� �޸� �Ҵ� ����\n");

    else {
        push(s1, 'A');
        push(s2, 'B');
        push(s1, 'C');
        push(s2, 'D');

        printf("s1���� ���� �� : %c\n", pop(s1));

        push(s1, 'E');
        push(s2, 'F');
        push(s1, 'G');
        push(s2, 'H');

        printf("s2���� ���� �� : %c\n", pop(s2));

        push(s1, 'I');
        push(s2, 'J');

        printf("===s1�� ����� ����===\n");
        display(s1);
        printf("===s2�� ����� ����===\n");
        display(s2);
    }

    /*
    char* p = "{A[(i+1)]=0;}";
    char n[30];

    char* a = "eye";
    char* b = "rear";

    if (check_matching(p)) printf("%s ��ȣ �˻� ����\n", p);
    else printf("%s ��ȣ �˻� ����\n", p);

    if (check_palin(b)) printf("%s�� ȸ��", b);
    else printf("%s�� ȸ��x", b);
    */

    /*
    scanf("%s", n);

    if (check_matcing(n) == 1) printf("%s ����\n", n);
    else printf("%s ����\n", n);
    */

    return 0;
}