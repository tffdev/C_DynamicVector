#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int* mallocPointer;
	int size;
	int usedSize;
} dynamicArray;

void initDynamicArray(dynamicArray* array) {
	array->mallocPointer = (int*)malloc(0);
	array->size = 2;
	array->usedSize = 0;
}

void appendToArray(dynamicArray* array, int data) {
	// if vector is full, realloc with double its previous size
	if(array->usedSize >= array->size){
		array->mallocPointer = realloc(array->mallocPointer, (array->size*2) * sizeof(int));
		array->size *= 2;
	}
	*(array->mallocPointer + array->usedSize) = data;
	array->usedSize++;
}

void destroyDynamicArray(dynamicArray* array) {
	free(array->mallocPointer);
}

void printDynamicArray(dynamicArray* array) {
	for (int i = 0; i < array->usedSize; ++i)
		printf("%i\n", *(array->mallocPointer + i));

	printf("size: %i, used: %i", array->size, array->usedSize);
}


void main() {
	dynamicArray ary;
	initDynamicArray(&ary);
	
	for(int i=0;i<10;++i)
		appendToArray(&ary, (i + 1)*10);
		
	printDynamicArray(&ary);
	destroyDynamicArray(&ary);
}

