#include <stdlib.h>
#include <stdio.h>
#include "bst.h"


/* This class provides an implementation of the Binary Search Tree, with functions add, inOrder, removeLargest, and removeSmallest
 * For added functionality and modularity, the functions compareTo and insertNewNode are used.
 * Author: Ananditha Raghunath
 * NetID: ar4460
 * Class: CSO Section 3
 * Date: 2/15/17
 */ 

int compareTo(int a, int b);
bst_node* insertNewNode(int a);
/******************************************************************************
//add num to the BST rooted at *root 
******************************************************************************/
void add ( bst_node ** root, int  num ) {
	// create new node and give it num
	if (*root == NULL) {
	*root = (bst_node*) insertNewNode(num);
	} else {
		int is_left  = 0;
		int compareTo = 0;
		bst_node* current = *root;
		bst_node* previous = NULL;

		while(current != NULL)
		{
			compareTo = compareTo(num, current->data);
			previous = current;
			if(compareTo < 0)
			{
				is_left = 1;
				current = current->left;
			}
			else if(compareTo > 0)
			{
				is_left = 0;
				current = current->right;
			}

		}
		if(is_left)
			previous ->left = insertNewNode(num);
		else
			previous ->right = insertNewNode(num);
	}
}

/******************************************************************************
   compare two integers
   returns 1, -1 or 0 depending which integer is bigger.
******************************************************************************/
int compareTo(int left, int right)
{
	if(left > right)
		return 1;
	if(left < right)
		return -1;
	return 0;
}
/******************************************************************************
   create a new node
   returns the new bst_node
******************************************************************************/
bst_node* insertNewNode(int num)
{
	bst_node *newNode = (bst_node*)malloc(sizeof(bst_node));
	if(newNode == NULL)
	{
		printf ("Malloc Problem!\n");
		exit(1);
	}
	newNode->data = num;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}


/******************************************************************************
   inorder traversal
   returns void
   function prints recursive inorder traversal of a tree
******************************************************************************/
void inorder(bst_node* root)
{
    if(root != NULL){
        inorder(root -> left);
        printf("%d, ", root->data);
        inorder(root -> right);
    }
}


/*****************************************************************************
removes the smallest value stored in 
the BST rooted at *root
if the BST is empty, the function returns zero 
Else the funtion returns the value stored in the deleted node
******************************************************************************/
int removeSmallest ( bst_node ** root ) {
	int retVal = 0;  
	if (root == NULL) {
		return 0;
	} else {
		bst_node *current = *root;
		bst_node *curParent = NULL;
	//handling root node (last node in tree)
        if ( current->left == NULL ) {
              retVal= current->data;
              *root = NULL;              
        } else {
		while (current->left != NULL) {
			curParent = current;
			current = (current->left);
		} 
		retVal = current->data ;
		if ( current->right != NULL ) {
		curParent->left = current->right; 
		} else {
		curParent->left = NULL; 
		}
        }
        //memory management
        if ( current != NULL ) 
           free(current) ;
        current = NULL;
        return retVal;
    }
}

/*************************************************************
removes the largest value stored in 
the BST rooted at *root
if the BST is empty, the function returns zero 
Else the funtion returns the value stored in the deleted node
*************************************************************/
int removeLargest ( bst_node ** root ) {
        int retVal = 0 ;
	if (root == NULL) {
		return retVal;
	} else {
		bst_node *current = *root;
		bst_node *curParent = NULL;
		//handling root node (last node in tree)
        if ( current->right == NULL ) {
              retVal= current->data;
              *root = NULL;              
        } else {
	        while (current->right != NULL) {
                curParent = current;
	            current = (current->right);
	        } 
            retVal = current->data ;
            if ( current->left != NULL ) {
                curParent->right = current->left; 
            } else {
                curParent->right = NULL; 
            }
        }
		//memory management
        if ( current != NULL ) 
              free(current) ;
         current = NULL;
         return retVal;
    }
}
