/*
Stack Header file
-using structures-

Basic function:-
init- initilizes top of empty stack
is_empty- returns 1 if stack is empty
is_full- returns 1 if stack is full
push- insert element in stack
pop- returns element from stack delets the element
display- display content of stack
top- returns element from stack retains the element
*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
# define stack_size 20

typedef struct stack{
	char item[stack_size];
	int top;
} stack;

void init(stack *ptr){
	ptr->top=-1;
}

int is_empty(stack *ptr){
	if(ptr->top==-1){
		return 1;
	}
	else{
		return 0;
	}
}

int is_full(stack  *ptr){
	if(ptr->top==(stack_size-1)){
		return 1;
	}
	else{
		return 0;
	}
}

void push(char elem,stack *ptr){
	if(is_full(ptr)){
		printf("Stack is full, element not inserted.\n");
	}
	else{
		ptr->top++;
		ptr->item[ptr->top]=elem;
	}
}

char pop(stack *ptr){
	if(is_empty(ptr)){
		printf("stack is empty, nothing to pop.\n");
	}
	else{
		return ptr->item[(ptr->top--)];
	}
}
char top(stack *ptr){
	if(is_empty(ptr)){
	//	printf("stack is empty, no top.\n");
	}
	else{
		return ptr->item[ptr->top];
	}
}

void display(stack *ptr){
	int i;
	if(is_empty(ptr)){
		printf("stack is empty, nothing to display.\n");
	}
	else{
		printf("Content of stack are:\n");
		for(i=0;i<=(ptr->top);i++){
			printf(" i:%d %c ",i,ptr->item[i]);
		}
		printf("\n");
	}
}
//infix to postfix
int priority(char x)
{
   if(x == '(' || x == '\0')
 return(0);
   if(x == '+' || x == '-')
 return(1);
   if(x == '*' || x == '/' || x == '%')
 return(2);
 	if( x == ')')
   return(3);
}
int main(){
	stack oprators;
	stack *ptr;
	ptr=&oprators;
	init(&oprators);
	char infixExp[stack_size],temp,tempOp;
	int length,i;
	
	printf("Enter Infix Expression:\n");
	gets(infixExp);
	length=strlen(infixExp);
	
	printf("Postfix Expression is:\n");
	for(i=0;i<length;i++){
		temp=infixExp[i];
		if(isalnum((int)temp)){
			printf("%c",temp);
		}
		else{
			if(is_empty(&oprators)){
				push(temp,&oprators);
			}
			else{
				if(temp == '('){
					push('(',&oprators);
				}
				if(temp == ')'){
					while(top(&oprators)!='('){
						printf("%c",pop(&oprators));
					}
					pop(&oprators);
				}
           		if(temp != '(' && temp != ')'){
           			while(priority(temp)<=priority(top(&oprators)) && !is_empty(&oprators)){
						//printf(" Stack top:%d \n",(&oprators)->top);
						printf("%c",pop(&oprators));
						
					}
					push(temp,&oprators);	
           		}
			}
			
		}
	}
	while(!is_empty(&oprators)){
		printf("%c",pop(&oprators));
	}
	
	return 0;
}
