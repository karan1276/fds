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

int main(){
	
	return 0;
}
