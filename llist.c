#include <stdio.h>		/* for puts,  */
#include <stdlib.h> 		/* for malloc */
#include <assert.h>		/* for assert */
#include "llist.h"		
#include <string.h>
/*int llDoCheck = 1;*/		/* set true for paranoid consistency checking*/

/*#define doCheck(_lp) (llDoCheck && llCheck(_lp))*/


    //* Allocate memory space for the Binary class 
BST *BSTAlloc(){
	BST *bst =(BST *)malloc(sizeof(BST));
	bst->root = 0;
	return bst;
}
 
void printBST(BST *bst){
    BSTPrint(bst->root); //Needed in order fo the recursion to work
     
}
void BSTPrint(Branch *node){
 //Prints the BST Recursively in Ascending order
    printf("%s\n" ,node->str);
    if(node != NULL){
    BSTPrint(node->leftc);
    printf("%s\n" ,node->str);
    BSTPrint(node->rightc);
   }
 }


/* create a new binary tree */
void BSTInsert(BST *bst, char *s)
{
	int length; 
	char *scopy;
	Branch *node;
    node = (Branch *)malloc(sizeof(Branch));
	for(length=0; s[length]; length++);

	scopy = (char *)malloc(length+1);
	for(length = 0; s[length]; length++)
	    scopy[length] = s[length];

	scopy[length] =0;

	node->str = scopy;
	node->leftc = NULL;
	node->rightc = NULL;
    
	bst->root = addNode(bst->root, node);

}
/* recycle a list, discarding all items it contains */
Branch* addNode(Branch *root, Branch *node){
    
    if(root == NULL){
        return node;
    }
    int compareVal = strcmp(node->str, root->str);
    //compare the root to the newly give item 
    if(0 > compareVal){
        root->leftc =addNode(root->leftc, node);
    }
    else{
        root->rightc =addNode(root->rightc,node);
    }
    return root;
}

/* Delete all elements off of the list */

  

/* print list membership.  Prints default mesage if message is NULL */
