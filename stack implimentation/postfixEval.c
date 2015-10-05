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
	int item[stack_size];
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

void push(int elem,stack *ptr){
	if(is_full(ptr)){
		printf("Stack is full, element not inserted.\n");
	}
	else{
		ptr->top++;
		ptr->item[ptr->top]=elem;
	}
}

int pop(stack *ptr){
	if(is_empty(ptr)){
		printf("stack is empty, nothing to pop.\n");
	}
	else{
		return ptr->item[(ptr->top--)];
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
			printf(" i:%d %d ",i,ptr->item[i]);
		}
		printf("\n");
	}
}
//Postfix eval
int calc(char t2,char t1, char op){
	int ans,i;
	if(op=='+'){
		ans= t1+t2;
		
	}
	else if(op=='-'){
		ans= t1-t2;
		
	}
	else if(op=='*'){
		ans= t1*t2;
		
	}
	else if(op=='/'){
		ans= t1/t2;
		
	}
	else if(op=='^'){
		ans= t1;
		for(i=0;i<t2;i++){
			ans=ans+t1;
		}
	}
	return ans;
}
main(){
	
	stack answer;
	stack *ptr;
	ptr=&answer;
	init(&answer);
	char postfixExp[stack_size];
	int length,i,t1,t2;
	
	printf("Enter Postfix Expression:\n");
	gets(postfixExp);
	length=strlen(postfixExp);
	
	for(i=0;i<length;i++){
		//display(ptr);
		if(isalnum(postfixExp[i])){
			t1=postfixExp[i] -'0';
			push(t1,ptr);
		}
		else{
			t1=pop(ptr);
			t2=pop(ptr);
			push(calc(t1,t2,postfixExp[i]),ptr);
		}
	}
	printf("Answer is: %d",pop(ptr));
}
