#include <stdio.h>
#include <stdlib.h>
#include "function.h"


void inorder(Node *root)
{
    if(root==nullptr)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}





void postorder(Node *root)
{
    if(root==nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

