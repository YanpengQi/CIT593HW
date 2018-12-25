/************************************************************************/
/* File Name : lc4_memory.c		 										*/
/* Purpose   : This file implements the linked_list helper functions	*/
/* 			   to manage the LC4 memory									*/
/*             															*/
/* Author(s) : tjf and you												*/
/************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lc4_memory.h"


/*
 * adds a new node to the end of a linked list pointed to by head
 */
int add_to_list (row_of_memory** head,
		 short unsigned int address,
		 short unsigned int contents)
{

	/* allocate memory for a single node */

	/* populate fields in newly allocated node w/ address&contents */

	/* if head==NULL, node created is the new head of the list! */

	/* otherwise, traverse linked list until we reach the end */

	/* add node to the end of list */

	/* return 0 for success, -1 if malloc fails */

	row_of_memory* newNode = malloc(sizeof(row_of_memory));

	if (newNode == NULL) {
		return -1;
	}

	newNode->address = address;
	newNode->label = NULL;
	newNode->contents = contents;	
	newNode->assembly = NULL;
	newNode->next = NULL;

	if(*head == NULL) {
		// new node as the start node
		*head = newNode;
		return 0;
	}

	// pointer to the end
	row_of_memory* cur = *head;
	while (cur->next != NULL) {
		if (cur->next->next != NULL && cur->next->address < address) {
			cur = cur->next;
		} else {
			break;
		}
	}

	// consider the address
	if (cur->address <= address) {
		// at the end
		if (cur->next == NULL) {
			cur->next = newNode;
			return 0;
		}

		// in the middle
		if (cur->next->address > address) {
			// inset node
			row_of_memory* tmp = cur->next;
			cur->next = newNode;
			newNode->next = tmp;
			return 0;
		}

		row_of_memory* tmp = cur->next;
		tmp->next = newNode;
		return 0;
		
	}

	// append at the end
	newNode->next = cur;
	*head = newNode;
	return 0;
}


/*
 * search linked list by address field, returns node if found
 */
row_of_memory* search_address (row_of_memory* head,
			       short unsigned int address )
{
	/* traverse linked list, searching each node for "address"  */

	/* return pointer to node in the list if item is found */

	/* return NULL if list is empty or if "address" isn't found */

	row_of_memory* cur = head;
	while (cur != NULL) {
		if (cur->address == address) {
			break;
		}
		cur = cur->next;
	}

	return (cur == NULL)? NULL: cur; 
}

/*
 * search linked list by opcode field, returns node if found
 */
row_of_memory* search_opcode  (row_of_memory* head,
				      short unsigned int opcode  )
{
	/* traverse linked list until node is found with matching opcode
	   AND "assembly" field of node is empty */

	/* return pointer to node in the list if item is found */

	/* return NULL if list is empty or if no matching nodes */

	row_of_memory* cur = head;

	while (cur != NULL) {
		if ((cur->contents/0x1000) == opcode && cur->assembly == NULL) {
			break;
		}

		cur = cur->next;
	}

	return (cur == NULL)? NULL: cur;
}


void print_list (row_of_memory* head )
{
	/* make sure head isn't NULL */

	/* print out a header */

	/* traverse linked list, print contents of each node */

	if (head == NULL) {
		printf("The head is NULL");
		return;
	}

	row_of_memory* cur = head;

	printf("<label>\t\t<address>\t<contents>\t<assembly>\n");
	while (cur != NULL) {
		printf("%s\t\t%04x\t\t%04x\t\t%s\n", cur->label, cur->address, cur->contents, cur->assembly);
		cur = cur->next;
	}

	return;
}

/*
 * delete entire linked list
 */
int delete_list    (row_of_memory** head )
{
	/* delete entire list node by node */
	/* if no errors, set head = NULL upon deletion */

	/* return 0 if no error, -1 for any errors that may arise */
	row_of_memory* cur = *head;

	while (cur != NULL) {
		row_of_memory* tmp = cur->next;
		free(cur->label);
		free(cur->assembly);
		free(cur);
		cur = tmp;
	}
	if (cur == NULL) {
		*head = NULL;
		return 0;
	}
	return -1;
}
