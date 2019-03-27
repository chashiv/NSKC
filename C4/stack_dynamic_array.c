/*
   Author : Shivam Chauhan
   Date   : Feb 26 , 2019
   Implementation of Stack Using Dynamic Array
*/
#include <stdio.h>
#include <stdlib.h>

struct DynArrayStack{
	int top ;
	int capacity ;
	int *array ;
};

struct DynArrayStack *createStack();
int isEmptyStack(struct DynArrayStack *S );
int isFullStack(struct DynArrayStack *S );
void push( struct DynArrayStack *S , int data );
int pop( struct DynArrayStack *S);
void display( struct DynArrayStack *S);
void deleteStack( struct DynArrayStack *S);
void doubleStack( struct DynArrayStack *S);

int main(){
	struct DynArrayStack *S = createStack();
	push(S,2);
	display(S);
	
	push(S,3);
	display(S);
	
	push(S,4);
	display(S);

	push(S,5);
	display(S);

	push(S,6);
	display(S);

	deleteStack(S);

	return 0 ;
}

struct DynArrayStack *createStack(){
	struct DynArrayStack *S = ( struct DynArrayStack *)malloc(sizeof(struct DynArrayStack));
	if(!S){
		printf("\nMemory Not Available");
		return NULL ;
	}
	S -> capacity = 1 ;
	S -> top = -1 ;
	S -> array = malloc(S -> capacity * sizeof(int) ) ;
	if(! S -> array ){
		printf("\nMemory Not Available");
		return NULL ;
	}	
	return S ;
}

int isEmptyStack( struct DynArrayStack *S){
	return (S -> top == -1);
}

int isFullStack( struct DynArrayStack *S ){
	return ( S -> top == S -> capacity - 1 );
}

void push( struct DynArrayStack *S , int data ){
	if( isFullStack(S) ){
		doubleStack(S);
	}
	S -> array[++S -> top] = data ;
}

int pop( struct DynArrayStack *S ){
	if( !isEmptyStack(S) ){
		return S -> array[S -> top--];
	}else{
		printf("\nStack is Empty ");
	}
}

void doubleStack(struct DynArrayStack *S){
	printf("Double Stack is called\n");
	S -> capacity *= 2 ;
	S -> array = realloc(S -> array , S -> capacity * sizeof(int));
}

void display(struct DynArrayStack *S){
	int i ;
	if( !isEmptyStack(S) ){
		for( i = S -> top ; i >= 0 ; i-- ){
			printf("%d ",S -> array[i]);
		}
		printf("\n");
	}else{
		printf("\nStack is Empty");
	}
}

void deleteStack(struct DynArrayStack *S){
	if( S ){
		if ( S -> array )
			free(S -> array);
		free(S);
	}
}
