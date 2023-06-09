#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

// 스택 초기화 함수
void init_s_stack(StackType* s) {
    s->capacity = 1;
    s->top = -1;
    s->data = (element*)malloc(s->capacity * sizeof(element));

    if (s->data == NULL) {
        printf("data 메모리 할당 실패\n");
        exit(1);
    }

}

// 공백 상태 검출 함수
int is_s_empty(StackType* s) {
    return (s->top == -1);
}

// 포화 상태 검출 함수
int is_s_full(StackType* s) {
    return (s->top == s->capacity - 1);
}

// 삽입함수
void push(StackType* s, element item) {
    if (s->data == NULL) {
        printf("data 할당된 공간이 없어서 push 불가\n");
        return;
    }
    else if (s->data != NULL) {
        if (is_s_full(s)) {
            printf("스택이 꽉 찼습니다. 용량 재조정을 시작합니다. [capacity = %d -> ", s->capacity);
            s->capacity *= 2;
            printf("%d]", s->capacity);

            s->data = (element*)realloc(s->data, s->capacity * sizeof(element)); // 메모리 조정

            if (s->data == NULL) {
                printf(" 실패!\n");
                return;
            }
            printf(" 성공!\n");
        }
        s->data[++(s->top)] = item;
    }
}



// 삭제함수
element pop(StackType* s) {
    if (is_s_empty(s)) {
        printf("스택이 비어있습니다.\n");
        return 0;
    }
    else return s->data[(s->top)--];
}

// 피크함수
element s_peek(StackType* s) {
    if (is_s_empty(s)) {
        printf("스택이 비어있습니다.\n");
        return;
    }
    else return s->data[s->top];
}

void display(StackType* s) {
    if (is_s_empty(s)) {
        printf("스택이 비어있습니다.\n");
        return;
    }
    else { // 저장된 내용 보기
        for (int i = s->top; i > -1; i--) {
            printf("[%d] %c\n", i, s->data[i]);
        }
    }
}

void DeleteStack(StackType* s) {
    if (s != NULL) {
        free(s);
    }
    else {
        printf("stack 삭제 실패\n");
        return;
    };
}

void TwoStacksDisplay() {
    StackType* s1; // StackType형 포인터 변수 s1 선언
    StackType* s2; // StackType형 포인터 변수 s2 선언

    s1 = (StackType*)malloc(sizeof(StackType)); // 
    s2 = (StackType*)malloc(sizeof(StackType)); //

    init_s_stack(s1);
    init_s_stack(s2);

    if (s1 == NULL || s2 == NULL)
        printf("스택 메모리 할당 실패\n");
    else {

        printf("s1에서 꺼낸 값: %c\n", pop(s1));

        push(s1, 'U'); //s1에 push
        push(s2, 'R'); //s2에 push
        push(s1, 'O'); //s1에 push
        push(s2, 'H'); //s2에 push

        printf("s2에서 꺼낸 값 : %c\n", pop(s2));

        push(s1, 'Y'); //s1에 push
        push(s2, 'A'); //s2에 push
        push(s1, 'I'); //s1에 push
        push(s2, 'E'); //s2에 push

        printf("s1에서 꺼낸 값 : %c\n", pop(s1));

        push(s2, 'L'); //s2에 push
        push(s2, 'C'); //s2에 push

        printf("===s1에 저장된 내용===\n");
        display(s1);
        printf("===s2에 저장된 내용===\n");
        display(s2);

        DeleteStack(s1);
        DeleteStack(s2);
    }
}

// 연산자 우선순위 지정 함수
int getPriority(char op) {
    switch (op) {
    case '(': case ')': return 0;
    case '+': case '-': return 1;
    case '*': case '/': return 2;
    }
    return -1;
}

// 중위 -> 후위 변환 함수
char* infix_to_postfix(char exp[]) {
    int i = 0;
    char ch, top_op;
    int len = strlen(exp);
    StackType s;
    char* new_exp = (char*)malloc(sizeof(char) * len);
    int k = 0;

    init_s_stack(&s);
    for (i = 0; i < len; i++) {
        ch = exp[i];
        switch (ch) {
        case '+': case '-': case '*': case '/': // 연산자
           // 스택에 있는 연산자의 우선순위가 더 크거나 같으면 출력
            while (!is_s_empty(&s) && (getPriority(ch) <= getPriority(s_peek(&s)))) {
                new_exp[k++] = pop(&s);
            }
            push(&s, ch);
            break;
        case'(': // 왼쪽 괄호
            push(&s, ch);
            break;
        case')': // 오른쪽 괄호
            top_op = pop(&s);
            // 왼쪽 괄호를 만날 때 까지 출력
            while (top_op != '(') {
                new_exp[k++] = top_op;
                top_op = pop(&s);
            }
            break;
        default:
            new_exp[k++] = ch;
            break;
        }
    }
    while (!is_s_empty(&s) && k < strlen(exp)) // 스택에 저장된 연산자들 출력
    {
        new_exp[k++] = pop(&s);
    }

    new_exp[k] = '\0';

    return new_exp;
}

int eval(char exp[]) {
    int op1, op2, value, i = 0;
    int len = strlen(exp);
    char ch;
    StackType s;

    init_s_stack(&s);
    for (i = 0; i < len; i++) {
        ch = exp[i];
        if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
            value = ch - '0';
            push(&s, value);
        }
        else {
            op2 = pop(&s);
            op1 = pop(&s);

            switch (ch) {
            case '+':push(&s, op1 + op2); break;
            case '-':push(&s, op1 - op2); break;
            case '*':push(&s, op1 * op2); break;
            case '/':push(&s, op1 / op2); break;
            }
        }
    }
    return pop(&s);
}

int check_matching(char* in) {
    StackType *s;
    s = (StackType*)malloc(sizeof(StackType));
    char ch, open_ch;
    int i, n = strlen(in);
    init_s_stack(s);

    for (i = 0; i < n; i++) {
        ch = in[i];

        switch (ch) {
        case '(': case '[': case '{':
            push(s, ch);
            break;
        case ')': case ']': case '}':
            if (is_s_empty(s)) return 0;
            else {
                open_ch = pop(s);
                if ((open_ch == '(' && ch != ')') ||
                    (open_ch == '[' && ch != ']') ||
                    (open_ch == '{' && ch != '}')) {
                    return 0;
                }
                break;
            }
        }
    }
    if (!is_s_empty(s)) {
        DeleteStack(s);
        return 0;
    }
    else {
        DeleteStack(s);
        return 1;
    }
}

int check_palin(char* in) {
    StackType *s;
    s = (StackType*)malloc(sizeof(StackType));
    char ch;
    int i, n = strlen(in);
    init_s_stack(s);

    //스택에 매개변수로 받은 문자열을 문자마다 차례차례 삽입해 저장
    for (i = 0; i < n; i++) {
        push(s, in[i]);
    }

    for (i = 0; i < n; i++) {
        //ch에 문자열의 문자를 차례차례 받음
        ch = in[i];

        //ch와 pop(&s)은 문자열 상에서 대칭인 문자, 즉 이 둘이 같지 않으면 회문이 아님 -> 0을 리턴
        if (ch != pop(s)) {
            DeleteStack(s);
            return 0;
        }
    }
    DeleteStack(s);
    return 1;
}

// ===== 스택 코드의 끝 =====
int main9() {

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

        DeleteStack(s1);
        DeleteStack(s2);
    }

    return 0;
}