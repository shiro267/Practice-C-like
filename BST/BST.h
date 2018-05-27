#ifndef LIBRARY_
#define LIBRARY_

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

#endif // LIBRARY_




#ifndef BST_H_
#define BST_H_

class TreeNode{

friend class BST;
public:
    TreeNode(int x): val(x),left(nullptr),right(nullptr){}
private:
    int val;
    TreeNode* left;
    TreeNode* right;
};

class BST{

public:
    BST():root(nullptr){};
    //---traversal---///
   vector<int> preorderTraverse();
   vector<int> postorderTraverse();
   vector<int> inorderTraverse();
   vector<int> levelorderTraverse();
    //---input---//
   void insertNode(TreeNode* x); // limited the node cannot have any child!
                                 // if the same value is already inserted in the BST, then do nothing.
   void insertNode(int& x);
   void deleteNode(int& x);

    //---output---///

private:
        //---traversal---///
   void preorder(TreeNode* root,vector<int> &ans);
   void postorder(TreeNode* root,vector<int> &ans);
   void inorder(TreeNode* root,vector<int> &ans);
   void levelorder(TreeNode* root,vector<int> &ans);

    TreeNode* root;
};

#endif // BST_H_
