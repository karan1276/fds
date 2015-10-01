/*
Stack Header file
-using structures-

Basic function:-
init- initilizes top of empty stack
is_empty- returns 1 if stack is empty
is_full- returns 1 if stack is full
push- insert element in stack
pop- returns element from stack
display- display content of stack
*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
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
//Palindrome
int ispallindrome(stack *ptr,char ch[10]){
	int i,len=strlen(ch),ascii;
	for(i=len-1;i>=0;i--){
		ascii=(int)ch[i];
		
		if(pop(ptr)==ascii){
			continue;
		}
		else{
			return 0;
		}
		
	}
	return 1;
}
int main(){
	stack str;
	stack *ptr;
	char ch[10];
	int i,len;
	ptr=&str;
	
	//intilizing stack
	init(ptr);
	
	printf("Enter a string:\n");
	gets(ch);
	
	len=strlen(ch);
	for(i=0;i<len;i++){
		push(ch[i],ptr);
	}
	
	if(ispallindrome(ptr,ch)){
		printf("Input string is a pallindrome");
	}
	else{
		printf("Input string is NOT a pallindrome");
	}
	
	//display(ptr);
	return 0;
}
