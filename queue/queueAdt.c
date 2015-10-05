#include<conio.h>
#include<stdio.h>

#define MAX 50
typedef struct queue{
	int data[MAX];
	int front,back;
} queue;

void init(queue *ptr){
	ptr->front=-1;
	ptr->back=-1;
}

int full(queue *ptr){
	if(ptr->back==MAX-1){
		return 1;
	}
	else{
		return 0;
	}
}
void insert(queue *ptr, int elem){
	if(full(ptr)){
		printf("Queue is full, insertion not performed");
	}
	else{
		ptr->back++;
		ptr->data[ptr->back]=elem;
	}
}
int empty(queue *ptr){
	if(ptr->back==ptr->front){
		return 1;
	}
	else{
		return 0;
	}
}
int delete(queue *ptr){
	if(empty(ptr)){
		printf("Queue is empty, nothing to remove");
		ptr->front=ptr->back=-1;
	}
	else{
		ptr->front++;
		return ptr->data[ptr->front-1];
	}
}
int top(queue *ptr){
	if(empty(ptr)){
		printf("Queue is empty, nothing to remove");
	}
	else{
		return ptr->data[ptr->front];
	}
}
void display(queue *ptr){
	int i,j;
	printf("Content of queue is:\n");
	for(i=ptr->back;i>ptr->front;i--){
		printf(" %d",ptr->data[i]);
	}
}
int main(){
	
	queue q;
	init(&q);
	insert(&q,1);
	insert(&q,2);
	insert(&q,3);
	display(&q);
	return 0;
}
