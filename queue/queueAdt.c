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
		back++;
		ptr->data[ptr->back]=elem;
	}
}

int main(){
	
	return 0;
}
