/*
   Author : Shivam Chauhan
   Date   : Feb 26 , 2019
   Implementation of Stack Using Linked List
*/
#include <stdio.h>
#include <stdlib.h>

struct stack{
	int data ;
	struct stack *next ;
};

struct stack *createStack();
int isEmptyStack(struct stack **top );
void push( struct stack **top , int data );
int pop( struct stack **top);
void display( struct stack **top);
void deleteStack( struct stack **top);

int main(){
	struct stack *top = createStack();
	push(&top,1);
	push(&top,2);
	push(&top,3);
	display(&top);
	while(top){
		printf("%d ",pop(&top));
	}
	display(&top);
	deleteStack(&top);
	
	return 0 ;
}

struct stack *createStack(){
	return NULL ;
}

int isEmptyStack( struct stack **top){
	return (top == NULL);
}

void push( struct stack **top , int data ){
	struct stack *tmp = (struct stack *)malloc(sizeof(struct stack));
	if(!tmp){
		printf("\nMemory not available");
		return ;
	}
	tmp -> data = data ;
	tmp -> next = *top ;
	*top = tmp ;
}

int pop( struct stack **top ){
	struct stack *tmp = *top ;
	int data = tmp -> data ;
	*top = (*top) -> next ;
	free(tmp);
	return data ;
}


void display(struct stack **top){
	struct stack *tmp = *top ;
	if(tmp){
		while(tmp){
			printf("%d ",tmp -> data );
			tmp = tmp -> next ;
		}
	}else{
		printf("\nStack is Empty");
	}
	printf("\n");
}

void deleteStack(struct stack **top){
	struct stack *tmp = *top; 
	while(*top){
		*top = (*top) -> next ;
		free(tmp);
	}
}