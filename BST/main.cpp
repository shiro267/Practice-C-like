#include "BST.h"


void print(vector<int>&);

int main()
{
    string input;
    BST myTree;
    vector<int> TraverseData;

    vector<int> defau = {5,3,6,2,4,7,1,10,0,8,9};

    for(auto&c : defau)
    {
        myTree.insertNode(c);
    }

    while(cin>>input)
    {

        transform(input.begin(),input.end(),input.begin(),::tolower);

        if(input=="insert" || input=="i")
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
        else if(input=="delete" || input=="d")
        {
            int x;
            cin >> x;
            myTree.deleteNode(x);
        }
        else if(input=="showall")
        {
           cout << "preorder �� " << endl;
           TraverseData = myTree.preorderTraverse();
           print(TraverseData);
           cout << "inorder �� " << endl;
           TraverseData = myTree.inorderTraverse();
           print(TraverseData);
           cout << "postorder �� " << endl;
           TraverseData = myTree.postorderTraverse();
           print(TraverseData);
           cout << "levelorder �� " << endl;
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
