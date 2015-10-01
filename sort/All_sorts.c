#include<stdio.h>
#include<conio.h>
void display(int *ptr,int front,int back){
	int i;
	for(i=front;i<back+1;i++){
		printf(" %d ",*(ptr+i));
	}
	printf("\n");
}
void bubbleSort(int *ptr,int front,int back){
	int i,j,temp;
	for(i=front;i<back+1;i++){
		for(j=front;j<back;j++){
			if(*(ptr+j)>*(ptr+j+1)){
				temp=*(ptr+j);
				*(ptr+j)=*(ptr+j+1);
				*(ptr+j+1)=temp;
			}
		}
	}
}
void insert(int *ptr,int front,int back){
	int i,elem,temp;
	elem=*(ptr+back);
	back--;
	for(i=back;i>front-1;i--){
		if(*(ptr+i)>elem){
			*(ptr+i+1)=*(ptr+i);
			*(ptr+i)=elem;
		}
		else{
			break;
		}
	}
}
void insertionSort(int *ptr,int front,int back){
	int i,sorted_pos;
	sorted_pos=1;
	for(i=1;i<back+1;i++){
		insert(ptr,front,i);
	}
}
void selection(int *ptr,int front,int back){
	int i,min_pos=front,temp;
	
	for(i=front;i<back+1;i++){
		if(*(ptr+i)<*(ptr+min_pos)){
			min_pos=i;
		}
	}
	
	temp=*(ptr+front);
	*(ptr+front)=*(ptr+min_pos);
	*(ptr+min_pos)=temp;
}
void selectionSort(int *ptr,int front,int back){
	int i;
	for(i=front;i<back+1;i++){
		selection(ptr,i,back);
	}
}
void mergeSort(int *ptr,int front,int back){
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
	int a[]={2,1,5,9,6,3,8,4,7,0};
	display(a,0,9);
	quicksort(a,0,9);
	display(a,0,9);
	return 0;
}
