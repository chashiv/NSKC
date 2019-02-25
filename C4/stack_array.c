#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

struct ArrayStack{
	int top ;
	int capacity ;
	int *array ;
};

struct ArrayStack *createStack();
int isEmptyStack(struct ArrayStack *S );
int isFullStack(struct ArrayStack *S );
void push( struct ArrayStack *S , int data );
int pop( struct ArrayStack *S);
void display( struct ArrayStack *S);
void deleteStack( struct ArrayStack *S);

int main(){
	struct ArrayStack *S = createStack();
	push(S , 5);
	push(S , 15);
	push(S , 25);
	push(S , 35);
	pop(S);
	display(S);
	deleteStack(S);
	return 0 ;
}

struct ArrayStack *createStack(){
	struct ArrayStack *S = ( struct ArrayStack *)malloc(sizeof(struct ArrayStack));
	if(!S){
		printf("\nMemory Not Available");
		return NULL ;
	}
	S -> capacity = MAXSIZE ;
	S -> top = -1 ;
	S -> array = malloc(S -> capacity * sizeof(int) ) ;
	if(! S -> array ){
		printf("\nMemory Not Available");
		return NULL ;
	}	
	return S ;
}

int isEmptyStack( struct ArrayStack *S){
	return (S -> top == -1);
}

int isFullStack( struct ArrayStack *S ){
	return ( S -> top == S -> capacity - 1 );
}

void push( struct ArrayStack *S , int data ){
	if( !isFullStack(S) ){
		S -> array[++S -> top] = data ;
	}else{
		printf("\nStack is Full");
	}
}

int pop( struct ArrayStack *S ){
	if( !isEmptyStack(S) ){
		return S -> array[S -> top--];
	}else{
		printf("\nStack is Empty ");
	}
}

void display(struct ArrayStack *S){
	int i ;
	if( !isEmptyStack(S) ){
		for( i = S -> top ; i >= 0 ; i-- ){
			printf("%d ",S -> array[i]);
		}
	}else{
		printf("\nStack is Empty");
	}
}

void deleteStack(struct ArrayStack *S){
	if( S ){
		if ( S -> array )
			free(S -> array);
		free(S);
	}
}
