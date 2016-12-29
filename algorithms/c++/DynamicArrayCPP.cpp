#include <iostream>
#include <stdlib.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


class DynamicArray{
	int capacity ;
	int length ;
	int *array;

	public :
		DynamicArray();
		int getItem(int);
		void resize(int);
		void append(int n);
		int getLength();
};

	DynamicArray::DynamicArray (){
		this->array = new int[1];
		this->capacity = 1;
		this->length = 0;
	}

	int DynamicArray::getItem(int index){
	
		if ( index < 0 || index > (this->length)-1 )
		{
	//		printf ("invalid index \n");
			return -1;
		}
		return array[index];
	}

	void DynamicArray::resize(int newCap){

		int *newArray ;
		newArray = new int[newCap];
		for (int i=0; i< this->length; i++){
	//		printf ("value resize : %d \n",arr->array[i]);
			newArray[i] = this->array[i];
		}
		this->array = newArray;
		//printf ("value resize : %d \n",arr->array[0]);
		this->capacity = newCap;
	}
	
	
	void DynamicArray::append( int newvalue){
		if (this->length == this->capacity){
	//		printf ("before resize ....\n");
			resize(2*(this->capacity));
		}
		//printf ("    length ....%d\n",arr->length);
		
		this->array[this->length] = newvalue;
		this->length = this->length + 1;
		
	}
	
	
	
	int DynamicArray::getLength(){
		return this->length;
	}
	

	
int main(int argc, char** argv) {
	DynamicArray da;
	//da = new DynamicArray();
	printf ("Dynamic Array testing starts ......\n");
	
	da.append(3333);
	da.append(4444);
	da.append(3232);
	
	da.append(3889);
	
	
	cout<< " Number at position " <<  2 << " : " << da.getItem(2) << "\n";

    cout<< " Number at position " <<  3 << " : " << da.getItem(3) << "\n";

	cout<< " Number at position " <<  1 << " : " << da.getItem(1) << "\n";

		//printf ("value : %d \n",da.array[2]);


}
