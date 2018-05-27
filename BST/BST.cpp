
//#define DEBUG
#include "BST.h"


vector<int> BST::preorderTraverse()
{
    vector<int> ans;
    preorder(root,ans);
    return ans;
}

void BST::preorder(TreeNode* root,vector<int>& ans)
{
    if(root==nullptr) return;
    ans.push_back(root->val);
    preorder(root->left,ans);
    preorder(root->right,ans);
}


vector<int> BST::postorderTraverse()
{
    vector<int> ans;
    postorder(root,ans);
    return ans;
}

void BST::postorder(TreeNode* root,vector<int>& ans)
{
    if(root==nullptr) return;
    postorder(root->left,ans);
    postorder(root->right,ans);
    ans.push_back(root->val);
}


vector<int> BST::inorderTraverse()
{
    vector<int> ans;
    inorder(root,ans);
    return ans;
}

void BST::inorder(TreeNode* root,vector<int>& ans)
{
    if(root==nullptr) return;
    inorder(root->left,ans);
    ans.push_back(root->val);
    inorder(root->right,ans);
}



vector<int> BST::levelorderTraverse()
{
    if(root==nullptr) return vector<int>();
    auto traverseNode = root;
    vector<int> ans;#ifdef DEBUG
    cout << "enter left subtree" << endl;
#endif // DEBUG
        cur_node = cur_node->left;
        while(cur_node->right!=nullptr)
        {
            searchedNode_parent = cur_node;
            cur_node = cur_node->right;
        }

#ifdef DEBUG
    cout << cur_node->val << " = LeftMax Node" << endl;
    cout << searchedNode_parent->val << " = searched parent Node" << endl;
#endif // DEBUG

        if(parent==nullptr)
        {
#ifdef DEBUG
    cout << "into parent==nullptr" << endl;
#endif // DEBUG
            if(searchedNode_parent!=d_Node)
            {
                searchedNode_parent->right = cur_node->left;
                cur_node->left = d_Node->left;
                cur_node->right = d_Node->right;
            }
            else
            {
                cur_node->right = d_Node->right;
            }
            root = cur_node;
        }
        else
        {
#ifdef DEBUG
    cout << "into parent!=nullptr" << endl;
#endif // DEBUG
            if(parent->val > cur_node->val){parent->left = cur_node;}
            else{parent->right = cur_node;}

            if(searchedNode_parent!=d_Node)
            {
                searchedNode_parent->right = cur_node->left;
                cur_node->left = d_Node->left;
                cur_node->right = d_Node->right;
            }
            else
            {
                cur_node->right = d_Node->right;
            }
        }
    queue<TreeNode*> cur_level;

    cur_level.push(traverseNode);

    while(!cur_level.empty())
    {
        queue<TreeNode*> next_level;
        while(!cur_level.empty())
        {
            auto cur_node = cur_level.front();
            ans.push_back(cur_node->val);
            if(cur_node->left!=nullptr) next_level.push(cur_node->left);
            if(cur_node->right!=nullptr) next_level.push(cur_node->right);
            cur_level.pop();
        }
        cur_level = next_level;
    }
    return ans;
}




    //---input---//
void BST::insertNode(TreeNode* x)
{

    if(x->left || x->right){cout << "Parent node cannot be inserted." << endl;  return;}
    if(root==nullptr){ root = x; return;}
    TreeNode* check_node = root;

    while(check_node)
    {
        if(x->val > check_node->val)
        {
            if(check_node->right!=nullptr)check_node = check_node->right;
            else
            {
                check_node->right = x;
                cout << "inserted " << x->val << endl;
                return;
            }
        }
        else if(x->val < check_node->val)
        {
            if(check_node->left!=nullptr)check_node = check_node->left;
            else
            {
                check_node->left = x;
                cout << "inserted " << x->val << endl;
                return;
            }
        }
        else
        {
            cout << "value " << x->val << " is already inserted." << endl;
            return;
        }
    }

}


void BST::insertNode(int& x)
{
    if(root==nullptr){  root = new TreeNode(x); cout << "inserted " << x << endl; return;}
    TreeNode* check_node = root;
    while(check_node)
    {
        if(x > check_node->val)
        {
            if(check_node->right!=nullptr)check_node = check_node->right;
            else
            {
                check_node->right = new TreeNode(x);
                cout << "inserted " << x << endl;
                return;
            }
        }
        else if(x < check_node->val)
        {
            if(check_node->left!=nullptr)check_node = check_node->left;
            else
            {
                check_node->left = new TreeNode(x);
                cout << "inserted " << x << endl;
                return;
            }
        }
        else
        {
            cout << "value " << x << " is already inserted." << endl;
            return;
        }
    }
}




void BST::deleteNode(int& x)
{
    TreeNode* parent = nullptr;
    TreeNode* cur_node = root;
    while(cur_node!=nullptr && x!=cur_node->val)
    {
        parent = cur_node;
        if(x>cur_node->val)
        {
            cur_node = cur_node->right;
        }
        else
        {
            cur_node = cur_node->left;
        }
    }

    if(cur_node==nullptr)return;

#ifdef DEBUG
    cout << cur_node->val << " = cur_node->val" << endl;
    if(parent!=nullptr) cout << parent->val << " = parent->val" << endl;
#endif // DEBUG

    TreeNode* d_Node = cur_node;
    TreeNode* searchedNode_parent = cur_node;

    if(cur_node->left!=nullptr) //找左邊最大的
    {
#ifdef DEBUG
    cout << "enter left subtree" << endl;
#endif // DEBUG
        cur_node = cur_node->left;
        while(cur_node->right!=nullptr)
        {
            searchedNode_parent = cur_node;
            cur_node = cur_node->right;
        }

#ifdef DEBUG
    cout << cur_node->val << " = LeftMax Node" << endl;
    cout << searchedNode_parent->val << " = searched parent Node" << endl;
#endif // DEBUG

        if(parent==nullptr)
        {
#ifdef DEBUG
    cout << "into parent==nullptr" << endl;
#endif // DEBUG
            if(searchedNode_parent!=d_Node)
            {
                searchedNode_parent->right = cur_node->left;
                cur_node->left = d_Node->left;
                cur_node->right = d_Node->right;
            }
            else
            {
                cur_node->right = d_Node->right;
            }
            root = cur_node;
        }
        else
        {
#ifdef DEBUG
    cout << "into parent!=nullptr" << endl;
#endif // DEBUG
            if(parent->val > cur_node->val){parent->left = cur_node;}
            else{parent->right = cur_node;}

            if(searchedNode_parent!=d_Node)
            {
                searchedNode_parent->right = cur_node->left;
                cur_node->left = d_Node->left;
                cur_node->right = d_Node->right;
            }
            else
            {
                cur_node->right = d_Node->right;
            }
        }

    }
    else if(cur_node->right!=nullptr)//左邊空 - >找右邊最小的
    {
#ifdef DEBUG
    cout << "enter right subtree" << endl;
#endif // DEBUG
        cur_node = cur_node->right;
        while(cur_node->left!=nullptr)
        {
            searchedNode_parent = cur_node;
            cur_node = cur_node->left;
        }

#ifdef DEBUG
    cout << cur_node->val << " = LeftMax Node" << endl;
    cout << searchedNode_parent->val << " = searched parent Node" << endl;
#endif // DEBUG

        if(parent==nullptr)
        {
#ifdef DEBUG
    cout << "into parent==nullptr" << endl;
#endif // DEBUG
            if(searchedNode_parent!=d_Node)
            {
                searchedNode_parent->left = cur_node->right;
                cur_node->right = d_Node->right;
            }
            root = cur_node;
        }
        else
        {
#ifdef DEBUG
    cout << "into parent!=nullptr" << endl;
#endif // DEBUG
            if(parent->val > cur_node->val){parent->left = cur_node;}
            else{parent->right = cur_node;}

            if(searchedNode_parent!=d_Node)
            {
                searchedNode_parent->left = cur_node->right;
                cur_node->right = d_Node->right;
            }
        }
    }
    else //都空(leaf) 直接刪掉這點
    {
        if(parent==nullptr)
        {
            root = nullptr;
        }
        else if(parent->val > cur_node->val)
        {
            parent->left = nullptr;
        }
        else
        {
            parent->right = nullptr;
        }

        delete cur_node;
        return;
    }


    delete d_Node;
    return;
}
