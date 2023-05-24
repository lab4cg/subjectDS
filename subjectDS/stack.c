#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

// ���� �ʱ�ȭ �Լ�
void init_s_stack(StackType* s) {
    s->top = -1;
}

// ���� ���� ���� �Լ�
int is_s_empty(StackType* s) {
    return (s->top == -1);
}

// ��ȭ ���� ���� �Լ�
int is_s_full(StackType* s) {
    return (s->top == (MAXSIZE - 1));
}

// �����Լ�
void push(StackType* s, element item) {
    if (is_s_full(s)) {
        fprintf(stderr, "���� ��ȭ ����\n");
        return;
    }
    else s->data[++(s->top)] = item;
}



// �����Լ�
element pop(StackType* s) {
    if (is_s_empty(s)) {
        fprintf(stderr, "���� ���� ����\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}

// ��ũ�Լ�
element s_peek(StackType* s) {
    if (is_s_empty(s)) {
        fprintf(stderr, "���� ���� ����\n");
        exit(1);
    }
    else return s->data[s->top];
}


// ������ �켱���� ���� �Լ�
int getPriority(char op) {
    switch (op) {
    case '(': case ')': return 0;
    case '+': case '-': return 1;
    case '*': case '/': return 2;
    }
    return -1;
}

// ���� -> ���� ��ȯ �Լ�
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
        case '+': case '-': case '*': case '/': // ������
           // ���ÿ� �ִ� �������� �켱������ �� ũ�ų� ������ ���
            while (!is_s_empty(&s) && (getPriority(ch) <= getPriority(s_peek(&s)))) {
                new_exp[k++] = pop(&s);
            }
            push(&s, ch);
            break;
        case'(': // ���� ��ȣ
            push(&s, ch);
            break;
        case')': // ������ ��ȣ
            top_op = pop(&s);
            // ���� ��ȣ�� ���� �� ���� ���
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
    while (!is_s_empty(&s) && k < strlen(exp)) // ���ÿ� ����� �����ڵ� ���
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

int check_matcing(char* in) {
    StackType s;
    char ch, open_ch;
    int i, n = strlen(in);
    init_s_stack(&s);

    for (i = 0; i < n; i++) {
        ch = in[i];

        switch (ch) {
        case '(': case '[': case '{':
            push(&s, ch);
            break;
        case ')': case ']': case '}':
            if (is_s_empty(&s)) return 0;
            else {
                open_ch = pop(&s);
                if ((open_ch == '(' && ch != ')') ||
                    (open_ch == '[' && ch != ']') ||
                    (open_ch == '{' && ch != '}')) {
                    return 0;
                }
                break;
            }
        
        }
        
    }
    if (!is_s_empty(&s)) return 0;

    return 1;
}

int check_palin(char* in) {
    StackType s;
    char ch;
    int i, n = strlen(in);
    init_s_stack(&s);

    //���ÿ� �Ű������� ���� ���ڿ��� ���ڸ��� �������� ������ ����
    for (i = 0; i < n; i++) {
        push(&s, in[i]);
    }

    for (i = 0; i < n; i++) {
        //ch�� ���ڿ��� ���ڸ� �������� ����
        ch = in[i];

        //ch�� pop(&s)�� ���ڿ� �󿡼� ��Ī�� ����, �� �� ���� ���� ������ ȸ���� �ƴ� -> 0�� ����
        if (ch != pop(&s)) return 0;

    }

    return 1;
}

// ===== ���� �ڵ��� �� =====
int main9() {

    //char* p = "{A[(i+1)]=0;}";
    char n[30];

    scanf("%s", n);
    printf("%s\n", n);

    //if (check_matcing(n) == 1) printf("%s ����\n", p);
    //else printf("%s ����\n", p);
    /*
    char* s = "3+6/2+2*(1+3)";
    char new_s[20];
    printf("����ǥ����� %s \n", s);
    printf("����ǥ����� ");
    strcpy(new_s, infix_to_postfix(s));
    printf("%s\n", new_s);

    printf("��� ���: %d\n", eval(new_s));
    */
    return 0;
}