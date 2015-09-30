#include <stdio.h>
#include <conio.h>
void display(int *ptr,int front, int back){
	int i;
	printf("\n");
	for(i=front;i<=back;i++){
		printf(" %d ",*(ptr+i));
	}
}
int partition(int *ptr,int front, int back){
	int pindex,i,temp;

	//put pivot logic(start, middle, end), this case chooses the end.
	int pivot = back;
	
	pindex=front;
	
	for(i=front;i<back;i++){
		if(*(ptr+i)<*(ptr+pivot)){
			temp=*(ptr+i);
			*(ptr+i)=*(ptr+pindex);
			*(ptr+pindex)=temp;
			pindex++;
		}
		
	}
	
	//swap pivot with pindex
	temp = *(ptr+pindex);
	*(ptr+pindex)=*(ptr+pivot);
	*(ptr+pivot)=temp;
	
	return pindex;
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
	int a[]={1,4,7,0,6,2,9,3,8,5};
	int *p;
	p=a;
	quicksort(p,0,9);
	display(p,0,9);
	return 0;
}
