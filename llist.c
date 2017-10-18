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
	bst->root = NULL;
	return bst;
}
 
void printBST(BST *bst){
    BSTPrint(bst->root); //Needed in order fo the recursion to work
     
}
void BSTPrint(Branch *node){
 //Prints the BST Recursively in Ascending order
  
    if(node != NULL){
    BSTPrint(node->leftc);
    printf("%s\n" ,node->str);
    BSTPrint(node->rightc);
   }
 }
//Read a file from same directory
void readFile(){
    FILE *fileReader;
    char filename[15];
    char ch;
 
    printf("Enter the filename \n");
    scanf("%s", filename);
    //  open the file for reading 
    fileReader = fopen(filename, "r");
    if (fileReader == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }
    ch = fgetc(fileReader); //Grabs the characters and checks if all of the chars have been read
    while (ch != EOF)
    {
        printf ("%c", ch); 
        ch = fgetc(fileReader);
    }
    printf("\n");
    fclose(fileReader);
}
 
void processPrint(BST *bst)
{
    FILE *fp; 
    fp = fopen("bst.txt", "w"); //Tells u to read and write to file
   makeFile(bst->root, fp);
}


void makeFile(Branch *node, FILE *fp)
{
        //Inorder printing
        if( node != NULL ){
        makeFile(node-> leftc, fp);
        printf("%s\n", node-> str); //Print the file
        fprintf(fp, "%s\n", node-> str); //Write to file
        makeFile(node-> rightc, fp);
    }
}
/* create a new binary tree and allocates space for a emty Btree*/
void BSTInsert(BST *bst, char *s)
{
	int length; 
	char *scopy;
	Branch *node;
    //allocate 
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
