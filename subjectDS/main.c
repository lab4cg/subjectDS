#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int main() {
    StackType* s1; // StackType를 가리키는 포인터 변수 선언
    StackType* s2; // StackType를 가리키는 포인터 변수 선언

    s1 = (StackType*)malloc(sizeof(StackType)); // 메모리 동적할당 후 s에 주소값 저장
    s2 = (StackType*)malloc(sizeof(StackType)); // 메모리 동적할당 후 s에 주소값 저장

    init_s_stack(s1); // 스택 정보 초기화
    init_s_stack(s2); // 스택 정보 초기화

    if (s1 == NULL || s2 == NULL)
        printf("스택 메모리 할당 실패\n");

    else {
        push(s1, 'A');
        push(s2, 'B');
        push(s1, 'C');
        push(s2, 'D');

        printf("s1에서 꺼낸 값 : %c\n", pop(s1));

        push(s1, 'E');
        push(s2, 'F');
        push(s1, 'G');
        push(s2, 'H');

        printf("s2에서 꺼낸 값 : %c\n", pop(s2));

        push(s1, 'I');
        push(s2, 'J');

        printf("===s1에 저장된 내용===\n");
        display(s1);
        printf("===s2에 저장된 내용===\n");
        display(s2);
    }

    /*
    char* p = "{A[(i+1)]=0;}";
    char n[30];

    char* a = "eye";
    char* b = "rear";

    if (check_matching(p)) printf("%s 괄호 검사 성공\n", p);
    else printf("%s 괄호 검사 실패\n", p);

    if (check_palin(b)) printf("%s는 회문", b);
    else printf("%s는 회문x", b);
    */

    /*
    scanf("%s", n);

    if (check_matcing(n) == 1) printf("%s 성공\n", n);
    else printf("%s 실패\n", n);
    */

    return 0;
}