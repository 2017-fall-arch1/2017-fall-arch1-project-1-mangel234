    #ifndef llist_included		/* prevent multiple inclusion */
    #define llist_included


    /* BST structure */
    typedef struct Branch {
    struct Branch *leftc, *rightc;
    char *str;
    }Branch;

    /* BST root */
    typedef struct {
    Branch *root;
    } BST;
        
    /* create a new list */
    Branch* addNode(Branch *root, Branch *node);
    
   /*Alocate memomry for the tree*/

    BST *BSTAlloc(); 
    /* free memory associated with a list */
    void BSTFree(BST *bst);

    /* insert new nodes to be inserted */
    void BSTInsert(BST *bst, char *s);

    /* print B-tree list  in ascending order*/
    void printBST(BST *bst);

    void BSTPrint(Branch *node);
    
    void makeFile(Branch *node, FILE *fp);
    
    void processPrint(BST *bst);
    
    void readFile();
    
    #endif	/* included */
