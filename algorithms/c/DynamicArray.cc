#include <iostream>
#include <stdlib.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */


struct DynamicArray{
	int capacity ;
	int length ;
	int *array;
};


DynamicArray createDynamicArray(){
	DynamicArray dr;
	
	int *newArray;
	newArray = (int *) malloc (1);
	dr.capacity = 1;
	dr.length = 0;
	dr.array = newArray;
	return dr;
}

int getItem(DynamicArray arr, int index){
	
	if ( index < 0 || index > arr.length-1 )
	{
//		printf ("invalid index \n");
		return -1;
	}
	return arr.array[index];
}

void resize(DynamicArray *arr, int newCap){
	
	
	int *newArray ;
	newArray = (int *) malloc(newCap);
	for (int i=0; i< arr->length; i++){
//		printf ("value resize : %d \n",arr->array[i]);
		newArray[i] = arr->array[i];
	}
	
	
	arr->array = newArray;
	//printf ("value resize : %d \n",arr->array[0]);

	arr->capacity = newCap;
}


void append(DynamicArray *arr, int newvalue){
	if (arr->length == arr->capacity){
//		printf ("before resize ....\n");
		resize(arr, 2*(arr->capacity));
	}
	//printf ("    length ....%d\n",arr->length);
	
	arr->array[arr->length] = newvalue;
	arr->length = arr->length + 1;
	
}



int length(DynamicArray arr){
	return arr.length;
}



int main(int argc, char** argv) {
	DynamicArray da;
	da = createDynamicArray();
	printf ("Dynamic Array testing starts ......\n");

	append(&da, 4444);
	
//	printf ("value : %d \n",da.array[0]);
	append(&da, 3226);
//	printf ("value : %d \n",da.array[1]);
	append(&da, 1238);
//	printf ("value : %d \n",da.array[2]);
	append(&da, 12218);
//	printf ("value : %d \n",da.array[3]);
	
	append(&da, 20000);
//	printf ("    value : %d\n",da.array[4]);
	
	
	printf (" Number at position [%d] =  %d\n", 2, getItem(da,2));

    printf (" Number at position [%d] =  %d\n", 0, getItem(da,0));

	printf (" Number at position [%d] =  %d\n", 4, getItem(da,4));
	
		//printf ("value : %d \n",da.array[2]);


}
