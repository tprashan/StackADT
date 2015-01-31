#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stackLibrary.h"
#include "expr_assert.h"

void test_create_an_empty_Stack_structure(){
	Stack result ;
	result = createStack();
	assertEqual(result.list->count,0);

};

void test_create_an_empty_Stack_structure_with_stackTop_NULL(){
	Stack result ;
	result = createStack();
	assert(*(result.stackTop)==NULL);
};

void test_Given_a_Stack_and_a_reference_to_some_data_this_reference_will_be_pushed_on_the_stack(){
	Stack new_stack = createStack();
	int data= 10,count;
	count = push(new_stack,&data);
	assertEqual(count, 1);
	assertEqual(*(int*)((*new_stack.stackTop)->data),data);
};

void test_push_puts_the_data_in_top_of_stack(){
	int data= 1,data1=10,count;
	Stack new_stack = createStack();
	count = push(new_stack,&data);
	count = push(new_stack,&data1);
	assertEqual(count, 2);
	assert((*new_stack.stackTop)->data==&data1);
}

void test_pop_remove_the_data_from_top_of_stack(){
	int data= 1,data1=10,count;
	Stack new_stack = createStack();
	push(new_stack,&data);
	push(new_stack,&data1);
	pop(new_stack);
	assertEqual(new_stack.list->count, 1);
	assertEqual(*(int*)((*new_stack.stackTop)->data),data);
};

void test_pop_remove_the_data_from_top_of_stack_and_gives_count_1(){
	int data= 1,data1=10;
	Stack new_stack = createStack();
	push(new_stack,&data);
	push(new_stack,&data1);
	pop(new_stack);
	assertEqual(new_stack.list->count, 1);
}

void test_stack_gives_data_15_at_index_2(){
	Stack stack = createStack();
	int data[] = {12,13,15,16},count,index,i;

	for(i=0;i<4;i++){
		count = push(stack,&data[i]);
	}
	
	index = indexOf(*stack.list,&data[2]);

	assertEqual(count,4);
	assertEqual(index,2);
	assertEqual(*(int*)(*stack.stackTop)->data,data[3]);
};