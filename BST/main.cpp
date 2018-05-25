#include "BST.h"


void print(vector<int>&);

int main()
{
    string input;
    BST myTree;
    vector<int> TraverseData;
    while(cin>>input)
    {

        transform(input.begin(),input.end(),input.begin(),::tolower);

        if(input=="insert")
        {
            int x;
            cin >> x;
            myTree.insertNode(x);

        }
        else if(input=="preorder")
        {
           TraverseData = myTree.preorderTraverse();
           print(TraverseData);
        }
        else if(input=="inorder")
        {
            TraverseData = myTree.inorderTraverse();
            print(TraverseData);
        }
        else if(input=="postorder")
        {
            TraverseData = myTree.postorderTraverse();
            print(TraverseData);
        }
        else if(input=="levelorder")
        {
            TraverseData = myTree.levelorderTraverse();
            print(TraverseData);
        }
        else if(input=="delete")
        {

        }
        else if(input=="showall")
        {
           cout << "preorder ¡õ " << endl;
           TraverseData = myTree.preorderTraverse();
           print(TraverseData);
           cout << "inorder ¡õ " << endl;
           TraverseData = myTree.inorderTraverse();
           print(TraverseData);
           cout << "postorder ¡õ " << endl;
           TraverseData = myTree.postorderTraverse();
           print(TraverseData);
           cout << "levelorder ¡õ " << endl;
           TraverseData = myTree.levelorderTraverse();
           print(TraverseData);
        }
        else
        {
            cout << "wrong input." << endl;
        }
    }
}

void print(vector<int>& data)
{
    cout << "Traverse Result: ";
    for(auto&c : data)
    {
        cout << c << " ";
    }
    cout << endl;
}
