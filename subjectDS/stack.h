#pragma once
#define MAXSIZE 100

typedef int element;
typedef struct {
	element data[MAXSIZE];
	int top;
} StackType;

void init_s_stack(StackType* s);
int is_s_empty(StackType* s);
int is_s_full(StackType* s);
void push(StackType* s, element item);
element pop(StackType* s);
element s_peek(StackType* s);

int getPriority(char op);
char* infix_to_postfix(char exp[]);
int eval(char exp[]);
int check_matching(char* in);
int check_palin(char* in);