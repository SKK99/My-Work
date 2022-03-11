/***************************************************************************
 * 	FUNCTION_NAME   :    bst.h
 * 	DESCRIPTION     :    contains the node structure definition ,
 *                           header files and the funcvtion prototypes
 * 		DATE             NAME            REFERENCE               REASON
 *      09-03-2022      Shankar Karn     Header File        BST Implementation
 *      
 *		Copyrights 2022 Capgemini All rights reserved
 **************************************************************************/

#include<stdio.h>
#include<stdlib.h>

/****************************************************************************
 *		MACRO_DEFINITIONS
 ************************************************************************/
#define SUCCESS 1
#define FAILURE 0

/***************************************************************************
 *		STRUCTURE_DEFINITION
 * *************************************************************************/
typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}bst_node;

/*******************************************************************
 * FUNCTION_PROTOTYPES
 ***********************************************************************/

int insert(bst_node**,int);
int delete(bst_node**,int);
void free_bst(bst_node *root);
void inorder(bst_node*);
void preorder(bst_node*);
void postorder(bst_node*);
