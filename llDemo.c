#include <stdio.h>		/* for printf */
#include <stdlib.h>		/* for free() */
#include <string.h> 		/* for strlen */
#include "llist.h"		/* for list operations */
/* This is the Arch 1 Assignment 1!
 * Author: Miguel NUnez
 * Professor: Dr. Fredthental
 * Disclaimer: This code would not be possible without the collaboration between Brian Briveron and Julie Hinojosa that helped me learn about the structure of the Structs 
 * and how reading FILE in C is similar to Java. Being able to look back to the Binary Class in Java helped me solve it in C

/* read no more than limit chars into s, return #chars read.  Doesn't include trailing \n */
int gets_n(char *s, int limit)	
{
  char *p = s;			/* for indexing into s */
  char c;
  if (fgets(s, limit, stdin)) {
    while ((c = *p) && c != '\n') /* scan p through s until 0 or \n */
      p++;
    if (c == '\n')		/* erase \n */
      *p = 0;
  }
  return (p - s);		/* #chars read (not including terminator or \n*/
}

int main()

{

    printf("Starting Arch 1 demo, hold onto your seats..");

    char buf[100];
    /* make empty list */
    BST *bst = BSTAlloc();
  
    printf("Welcome to the Binary Search tree\n");

  while (!(strcmp(buf,"exit") == 0)){	/* build list */
    
    printf("Enter names or 'exit'\n");
    gets_n(buf, 100);
    
        if(strcmp(buf,"exit") == 0){
            break;
        }
      
      BSTInsert(bst,buf); //Inserting new node from user
    }
    //Work in progress

      printf("\n");
      printf("Printing Whole list..\n");
      printBST(bst); //Print the binary tree we have created
      printf("\n");
      printf("\n");
      printf("Writing Binary Tree to file..\n");
      processPrint(bst); //Make a file with bst
      printf("\n");
      printf("\n");
      readFile();
      printf("\n");
      printf("Exiting program sad face :(...\n");

  return 0;
} 
  
