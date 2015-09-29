/*
Stack Implimentation
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
			printf(" %d ",ptr->item[i]);
		}
		printf("\n");
	}
}
int main(){
	int flag=1,ch,elem;
	stack s;
	stack *ptr;
	
	ptr=&s;
	init(ptr);
	
	do{
		printf("====================\n");
		printf("Stack Implementation\n");
		printf("====================\n");
		printf("Enter you choice:\n");
		printf("0.exit\n");
		printf("1.push\n");
		printf("2.pop\n");
		printf("3.display\n");
		
		scanf("%d",&ch);
		printf("You entered :%d\n",ch);
		
		switch(ch){
			case 0:
				flag = 0;
				printf("Aborting program\n");
				display(ptr);
			break;
			case 1:
				printf("Enter Element to push\n");
				scanf("%d",&elem);
				push(elem,ptr);
				display(ptr);
			break;
			case 2:
				printf("Poped element is : %d\n",pop(ptr));
				display(ptr);
			break;
			case 3:
				display(ptr);
			break;
			default:
				printf("Something went wrong...Aborting program\n");
				flag = 0;
				display(ptr);
			break;
		}	
	}while(flag);
	
	return 0;
}
