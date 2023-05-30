#pragma once

typedef char element;
typedef struct {
	element* data;
	int capacity;
	int top;
} StackType;

void init_s_stack(StackType* s);
int is_s_empty(StackType* s);
int is_s_full(StackType* s);
void push(StackType* s, element item);
element pop(StackType* s);
element s_peek(StackType* s);
void display(StackType* s);
void DeleteStack(StackType* s);

void TwoStacksDisplay();

int getPriority(char op);
char* infix_to_postfix(char exp[]);
int eval(char exp[]);
int check_matching(char* in);
int check_palin(char* in);