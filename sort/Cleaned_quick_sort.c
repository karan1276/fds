#include <stdio.h>
#include <conio.h>
void display(int *ptr,int front, int back){
	int i;
	//printf("Array:\n");
	for(i=front;i<=back;i++){
		printf(" %d ",*(ptr+i));
	}
}
int partition(int *ptr,int front, int back){
	int pindex,i,temp;

	//put pivot logic(start, middle, end), this case chooses the end.
	int pivot = (back+front)/2;
		
	pindex=front;
	for(i=front;i<back+1;i++){
		
		if(*(ptr+i)<=*(ptr+pivot)){
			temp=*(ptr+i);
			*(ptr+i)=*(ptr+pindex);
			*(ptr+pindex)=temp;
			
			
			if(i==pivot){
				pivot=pindex;
			}
			
			pindex++;
		}
		
	}
	
	//Swaping pivot to correct position
	temp = *(ptr+pindex-1);
	*(ptr+pindex-1)=*(ptr+pivot);
	*(ptr+pivot)=temp;
	pivot=pindex-1;
	
	
	return pivot;
}
void quicksort(int *ptr,int front, int back){
	
	int pivot;
	if(front<back){
		
		pivot = partition(ptr,front,back);
	
		quicksort(ptr,front,pivot-1);
		quicksort(ptr,pivot+1,back);
	}
}
int main(){
	int a[]={5,4,7,0,6,2,9,3,8,1};
	int *p;
	p=a;
	printf("Orignal Array:\n");
	display(p,0,9);
	quicksort(p,0,9);
	printf("\nSorted Array:\n");
	display(p,0,9);
	return 0;
}
