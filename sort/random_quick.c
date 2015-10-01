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
	printf("\nPartition called\n");
	for(i=front;i<back+1;i++){
		printf("\n\n\ni:%d\n",i);
		printf("pivot index:%d, pivot value:%d\n",pivot,*(ptr+pivot));
		display(ptr,front,back);
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
	
	//swap pivot with pindex
	if(*(ptr+pindex)<=*(ptr+pivot)){
		temp = *(ptr+pindex);
		*(ptr+pindex)=*(ptr+pivot);
		*(ptr+pivot)=temp;
		pivot=pindex-1;
	}
	if(*(ptr+pindex)>*(ptr+pivot)){
		temp = *(ptr+pindex-1);
		*(ptr+pindex-1)=*(ptr+pivot);
		*(ptr+pivot)=temp;
		pivot=pindex-1;
	}
	
	printf("\n\n\ni:%d\n",i);
	printf("pivot index:%d, pivot value:%d\n",pivot,*(ptr+pivot));
	display(ptr,front,back);
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
	int preturn;
	int *p;
	p=a;
	quicksort(p,0,9);
	printf("\n\n\n\n\n\nSorted Array:\n");
	display(p,0,9);
	return 0;
}
