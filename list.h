#ifndef LIST_H_
#define LIST_H_
#include<stdio.h>

typedef struct Node{
	double value;
	int count;
	struct Node *next;
}Node;

typedef Node* List;
List init_list(void );
int is_empty(List L);
Node* create_node(double val);
void display_list(List L);
int count_element(List L);
int is_in(List L, double x);
List add_element(List L, double y);
List remove_element(List L, double z);
#endif