/***************************************************************************
 * 	FILE_NAME   :   bst_fun.c
 * 	DESCRIPTION :   This file contains BST functions
 *      Revision History:
 *      ----------------
 *
 *      DATE             NAME            REFERENCE               REASON
 *      09-03-2022      Shankar Karn     Function Definition     BST Implementation
 * 
 *      Copyrights 2022 Capgemini All rights reserved
 *
 * ************************************************************************/

#include "bst.h"

/***************************************************************************
 * 			FUNCTION_PROTOTYPES 
 **************************************************************************/
static bst_node *create_node(int);
static void find(bst_node *, bst_node **, bst_node **, int);
static void delete_01child(bst_node**,bst_node*,bst_node*);
static void delete_2child(bst_node**,bst_node*,bst_node*);

/***************************************************************************
 *	FUNCTION_NAME  :  create_node()
 * 	DESCRIPTION    :  creating a new node
 * 	RETURN_TYPE    :  returns the new_node
 * **********************************************************************/
static bst_node *create_node(int element)
{
   /* declaring a new node */
	bst_node *new;
   /* allocating memory to new node */
	new=(bst_node*)malloc(sizeof(bst_node));

	if(NULL != new)
	{
		new->data=element;
		new->left=NULL;
		new->right=NULL;
	}
   else
   {
      printf("Memory allocation failure in creating new node\n");
   }
	return new;
}

/***************************************************************************
 * 	FUNCTION_NAME  :  find()
 * 	DESCRIPTION    :  Searches the node the user wants
 *                        and gives the node's parent node and child nodes
 *	   RETURN_TYPE    :  returns void 
 **************************************************************************/

static void find(bst_node *root, bst_node **loc, bst_node **par, int item)
{
   /* declaring a new node */
	bst_node *ptr;
   /* If Tree is Empty  */
	if(NULL == root) 
	{
      *loc = NULL;
      *par = NULL;
      return;
	}
        
   /* If item at root */
   if (item == root->data)
   {
      *loc = root;
      *par = NULL;
      return;
   }
        
   /* Initialize Pointers */
   *par = root;
   if (item < root->data)
   {
      ptr = root->left;
   }
   else
   {
      ptr = root->right;
   }

	while(NULL != ptr)
	{
		if(item == ptr->data)
		{
         *loc = ptr;
		   return;
		}
		*par = ptr;
		if(item < ptr->data)
		{
		   ptr = ptr->left;
		}
		else 
		{
		   ptr = ptr->right;
		}
	}
   *loc = NULL;
	return ;
}

/***************************************************************************
 * 	FUNCTION_NAME  :  insert
 * 	DESCRIPTION    :  inserts the elements at the appropriate location
 *                        if element already present return failure as
 *                        duplicate entry
 * 	RETURN_TYPE    :  returns SUCCESS or FAIL
 * ************************************************************************/
int insert(bst_node **root, int item)
{
   bst_node *loc, *par, *new_node;

   loc = NULL;
   par = NULL;

   /* check if item is present in the tree */
   find(*root, &loc, &par, item);

	if(NULL != loc)
	{
      printf("item already present. Duplicate Entry, Can't insert\n");
      return FAILURE;
	}
	else
	{
		new_node = create_node(item); 
      if (NULL == par)
      {
         *root = new_node;
      }
		else
		{
		   if(item < par->data)
         {
			   par->left = new_node;
         }
         else
         {
		      par->right = new_node;
         }

	   }
	}
   return SUCCESS;
}

/****************************************************************************
 *	FUNCTION_NAME   :   inorder()
 * 	DESCRIPTION     :   displays the elements in inorder
 ***************************************************************************/
void inorder(bst_node *root)
{
	if(NULL == root) {
		return;
   }
	inorder(root->left);
	printf("%4d->",root->data);
	inorder(root->right);
}

/***************************************************************************
 * 	FUNCTION_NAME   :   preorder()
 * 	DESCRIPTION     :   displays the elements in preorder
 **************************************************************************/
void preorder(bst_node *root)
{
	if(NULL == root) {
		return;
   }

	printf("%4d->",root->data);
	preorder(root->left);
	preorder(root->right);
}

/***************************************************************************
 * 	FUNCTION_NAME   :   postorder()
 * 	DESCRIPTION     :   displays the elements in postorder
 **************************************************************************/
void postorder(bst_node *root)
{
	if(NULL == root) {
	   return;
   }

	postorder(root->left);
	postorder(root->right);
	printf("%4d->",root->data);
}

/************************************************************************
 * 		FUNCTION_NAME  :   free_bst()
 * 		DESCRIPTION    :   frees the allocated memory
 **************************************************************************/
void free_bst(bst_node *root)
{
	if(NULL == root) {
	   return;
   }
	free_bst(root->left);
	free_bst(root->right);
	free(root);
}

/***************************************************************************
*           FUNCTION_NAME  :   delete_01child
*           DESCRIPTION    :   deleting the node with one child
***************************************************************************/
static void delete_01child(bst_node **root, bst_node *par, bst_node *loc)
{
   bst_node *child;

   child=NULL;

   /* initialize child to correct location */
    
   if(NULL != loc->right)
   {
      child=loc->right;
   }

   if(NULL != loc->left)
   {
      child=loc->left;
   }
     
   if(NULL == par)
   {
      *root=child;
   }
   else
   {
      if (loc == par->left)
      {
         par->left = child;
      }
      else
      {
         par->right = child;
      }
   }
}

/***************************************************************************
*           FUNCTION_NAME  :   delete_2child()
*           DESCRIPTION    :   deleting the node with two children 
***************************************************************************/
static void delete_2child(bst_node **root, bst_node *par, bst_node *loc)
{
   bst_node *ptr, *parsuc, *suc;
 
   /* find inorder successor */

   ptr = loc->right;    /* Right child of the node */
   parsuc = loc;        /* parent successor */
    
   while(NULL != ptr->left)
   {
      parsuc = ptr;
      ptr = ptr->left;
   }
     
   suc = ptr;
   delete_01child(root, parsuc, suc);
   if (NULL != par)
   {
      if (loc == par->left)
      {
         par->left = suc;
      }
      else
      {
         par->right = suc;
      }
   }
   else
   {
      *root = suc;
   }

   suc->left = loc->left;
   suc->right = loc->right;
}

/****************************************************************************
 * 	FUNCTION_NAME  :   delete
 * 	DESCRIPTION    :   deleting the node from BST if present
 *                         else returns failure 
 * 	RETURN_TYPE    :   
 **************************************************************************/
int delete(bst_node **root, int item)
{
   bst_node *loc, *par;

   /* find if item is present else report the same */

   find(*root, &loc, &par, item);
    
   if (NULL == loc)
   {
      printf("\nItem not present, can't delete\n");
      return FAILURE;
   }

   /* Check no of children and call appropriate procedure */

   if ((NULL != loc->left) && (NULL != loc->right))
   {
      delete_2child(root, par, loc);
   }
   else
   {
      delete_01child(root, par, loc);
   }
    
   free(loc);
   loc = NULL;
 
   return SUCCESS;
}
/* Returns the height of the bst */
int height(bst_node* node)
{
    if (node == NULL)
        return -1;
    else {
        /* compute the height of each subtree */
        int lHeight = height(node->left);
        int rHeight = height(node->right);
 
        /* use the larger one */
        if (lHeight > rHeight)
            return (lHeight + 1);
        else
            return (rHeight + 1);
    }
}

/* Returns minimum value in a given Binary Tree */
int findMin(bst_node* root)
{
   if(root == NULL)
      return -1;
   bst_node* current = root;
 
   /* loop down to find the leftmost leaf */
   while (current->left != NULL) {
      current = current->left;
   }
   return(current->data);
}
/* Returns Maximum value in a given Binary Tree */
int findMax(bst_node* root)
{
    /* Base case */
    if (root == NULL)
      return -1;
 
    /* Return maximum of 3 values:
    * 1) Root's data 2) Max in Left Subtree 3) Max in right subtree */
    int res = root->data;
    int lres = findMax(root->left);
    int rres = findMax(root->right);
    if (lres > res)
      res = lres;
    if (rres > res)
      res = rres;
    return res;
}

/* The functions prints all the keys which in
the given range [k1..k2]. The function assumes than k1 < k2 */
void printInRange(bst_node *root, int k1, int k2)
{
   /* base case */
   if (NULL == root )
      return;
 
   /* Since the desired o/p is sorted, recurse for left subtree first
      If root->data is greater than k1, then only we can get o/p keys
      in left subtree */
   if ( k1 < root->data )
     printInRange(root->left, k1, k2);
 
   /* if root's data lies in range, then prints root's data */
   if ( k1 <= root->data && k2 >= root->data )
     printf("%d ", root->data );
 
   /* recursively call the right subtree */
   printInRange(root->right, k1, k2);
}

/* C function to search a given key in a given BST */
bst_node* search(bst_node* root, int key)
{
   /* Base Cases: root is null or key is present at root */
   if (root == NULL || root->data == key)
      return root;
    
   /*  Key is greater than root's key */
   if (root->data < key)
      return search(root->right, key);
 
   /* Key is smaller than root's key */
   return search(root->left, key);
}