#include "../TCP_reuse.h"

#define LARGESTWORD 100
#define ENDINGCHAR  '~'

// Our tree struct
struct binaryTreeNode
{
    char* word;
    int count;
    struct binaryTreeNode* left; 
    struct binaryTreeNode* right;
};
// Our tree functions
struct binaryTreeNode* addToTree(struct binaryTreeNode*, char*);
void printTree(struct binaryTreeNode*);

void main()
{
    // To maximize efficiency, we will not get the input first and then operate. We will do these
    // operations at the same time

    // We need a binary tree to hold the words. The struct and corresponding functions are defined below.
    struct binaryTreeNode* root = NULL;

    // Time to read!
    int  i;
    char c;
    char* word = malloc(sizeof(char) * LARGESTWORD);
    for(i = 0; (c = getchar()) != EOF; i++)
    { 
        if(c == ' ' || c == '\n' || c == ENDINGCHAR)
        {
            *(word+i) = '\0';            // Capping off word
            root = addToTree(root,word); // Adding word to tree
            i = 0;                       // Resetting iterator

            if(c == ENDINGCHAR) {break;}

            continue;
        }
        
        *(word + i) = c;
    }

    // The tree is filled! Now to print:
    printTree(root);
}


// Function that adds node to the tree.
struct binaryTreeNode* addToTree(struct binaryTreeNode* treeNode, char* word)
{
    int comparison;

    // If the pointer is null, we have not found the word.
    // We can safely create a new node
    if(treeNode = NULL)    
    {
        treeNode = malloc(sizeof(struct binaryTreeNode));
        treeNode->word = word;
        treeNode->count = 1;
        treeNode->left = NULL;
        treeNode->right = NULL;
    }
    // If the comparison between the current node and the incoming word is 0,
    // then we have found the node the word is saved in. We simply increment the counter.
    else if((comparison = strcmp(word,treeNode->word)) == 0)
    {
        treeNode->count++;
    }
    else if(comparison < 0)
    {
        treeNode->left = addToTree(treeNode->left,word);
    }
    else
    {
        treeNode->right = addToTree(treeNode->right,word);
    }
    
    // Returning the treenode. The only way this changes is in the case where a new node
    // is created, at which point this new node replaces a NULL pointer.
    // In all other cases, nothing changes :)
    return treeNode;
}

void printTree(struct binaryTreeNode* treeNode)
{
    if(treeNode == NULL)
    {
        return;
    }

    printTree(treeNode->left);
    printf("\n%10s | Count : %d",treeNode->word,treeNode->count);
    printTree(treeNode->right);
}
