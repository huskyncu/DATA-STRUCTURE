#include<bits/stdc++.h>

using namespace std;

typedef struct node
{
    int data;
    node *left,*right;
};

node *newNode(int k)
{
    node *Node=(node*)malloc(sizeof(node));
    Node->data=k;
    Node->right=Node->left=NULL;
    return Node;

}
node *vectoCBT(vector<int> nodes, node *root,int index)
{
    if(index<nodes.size())
    {
        root=newNode(nodes[index]);
        root->left=vectoCBT(nodes,root->left,2*index+1);
        root->right=vectoCBT(nodes,root->right,2*index+2);
        return root;
    }
    else return NULL;
}

void printinorder(node *root)
{
    if(root)
    {
        printinorder(root->left);
        cout<<root->data<<" ";
        printinorder(root->right);
    }
}
int main()
{
    vector<int> nodes;
    int num;
    while(cin>>num)
    {

        nodes.push_back(num);
    }

    node *root=vectoCBT(nodes,root,0);
    printinorder(root);

}
