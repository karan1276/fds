#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
void merge(int *ptr,int *left,int llength,int *right,int rlength){
	printf("\nMerge called");
	int i=0,j=0,k=0;
	
	while((i<llength)&&(j<rlength)){
		printf("\n Condition (i<llength)&&(j<rlength) is true");
		if(*(left+i)<=*(right+j)){
			*(ptr+k)=*(left+i);
			i++;
			k++;
		}
		if(*(left+i)>*(right+j)){
			*(ptr+k)=*(right+j);
			j++;
			k++;
		}
	}
	while(i<llength){
		printf("\n Condition (i<llength) is true");
		*(ptr+k)=*(left+i);
		i++;
		k++;
	}
	while(j<rlength){
		printf("\n Condition (i<rlength) is true");
		*(ptr+k)=*(right+j);
		j++;
		k++;
	}
	
	//feedback
		printf("\nMain array: ");
		for(i=0;i<(rlength+llength);i++){                 
			printf(" %d ",*(ptr+i));
		}
		printf("\nMain array Lenght: %d",(rlength+llength));
		printf("\nLeft array: ");
		for(i=0;i<llength;i++){                 
			printf(" %d ",*(left+i));
		}
		printf("\nLeft Lenght: %d",llength);
		printf("\nRight array: ");
		for(i=0;i<rlength;i++){                 
			printf(" %d ",*(right+i));
		}
		printf("\nRight Lenght: %d",rlength);
}
void bubbleSort(int *ptr,int length){
	
	if(length>1){
		int *left,*right;
		int i,mid=length/2;                    
		                                       
		left=(int*)calloc(mid,sizeof(int));    
		right=(int*)calloc((length-mid),sizeof(int));
		                                       
		for(i=0;i<length;i++){                 
			if(i<mid){                         
				*(left+i)=*(ptr+i);            
			}                                     
			if(i>=mid){                         
				*(right+i-mid)=*(ptr+i);       
			}                                     
		}         
		                             
		//feedback
		printf("\nBubble Sort Called");
		printf("\nMain array: ");
		for(i=0;i<length;i++){                 
			printf(" %d ",*(ptr+i));
		}
		printf("\nMain array Lenght: %d",length);
		printf("\nLeft array: ");
		for(i=0;i<mid;i++){                 
			printf(" %d ",*(left+i));
		}
		printf("\nLeft Lenght: %d",mid);
		printf("\nRight array: ");
		for(i=0;i<(length-mid);i++){                 
			printf(" %d ",*(right+i));
		}
		printf("\nRight Lenght: %d",length-mid);
		
		
		//resursive calls                      
		bubbleSort(left,mid);                  
		bubbleSort(right,length-mid);      
		
		//feedback
		printf("\nJust Before Merge call");
		printf("\nMain array: ");
		for(i=0;i<length;i++){                 
			printf(" %d ",*(ptr+i));
		}
		printf("\nMain array Lenght: %d",length);
		printf("\nLeft array: ");
		for(i=0;i<mid;i++){                 
			printf(" %d ",*(left+i));
		}
		printf("\nLeft Lenght: %d",mid);
		printf("\nRight array: ");
		for(i=0;i<(length-mid);i++){                 
			printf(" %d ",*(right+i));
		}
		printf("\nRight Lenght: %d",length-mid);   
		                                       
		//merge calls                          
		merge(ptr,left,mid,right,(length-mid));	
	}
	
}
int main(){
	int a[]={0,6,9,2,5,8,3,7,1,4};
	bubbleSort(a,10);
	return 0;
}
