#include <stdio.h>
#include <stdlib.h>

#include<stdio.h>
#include "list.h"

int main (){
	List L=init_list();
	int choice;
	double value;
	
	do{
		printf("1.add element\n2.remove element\n3.check if value exists\n4.count total element\n5.display list\n0.Exit\n=======================\nEnter your choice: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1 :
				printf("enter the value to add ");
				scanf("%lf", &value);
				L= add_element(L, value);
				break;
			case 2 :
				printf("enter the value to remove ");
				scanf("%lf", &value);
				L= remove_element(L,value);
				break ;
			case 3 :
				printf("enter the value to check ");
				scanf("%lf",&value);
				printf("occurence of %.2f=%d\n",value,is_in(L, value));
				break;
			case 4 :
				printf("total element with repetition : %d\n",count_element(L));
				break;
			case 5 :
				display_list(L);
				break;
			case 0 :
				printf("Exiting..");
				return 0;
			default:
				printf("invalid Choice\n ");
			}}while(choice=!0);
			return 0 ; }
				