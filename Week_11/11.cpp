#include<bits/stdc++.h>

using namespace std;
#define Max 1000

typedef struct node
{
    int data;
    node *left_child, *right_child;
};

node* newNode(int k)
{
    node *Node = (node *)malloc(sizeof(node));
    Node->data = k;
    Node->right_child = Node->left_child = NULL;
    return Node;
};

node* vectoCBT(vector<int> nums,node *root,int index)
{
    if(index<nums.size())
    {
        root=newNode(nums[index]);
        root->left_child=vectoCBT(nums,root->left_child,2*index+1);
        root->right_child=vectoCBT(nums,root->right_child,2*index+2);
        return root;
    }
    else return NULL;
}


void inorder(node *ptr)
{
    if(ptr)
    {
        inorder(ptr->left_child);
        cout<<ptr->data<<" ";
        inorder(ptr->right_child);
    }
    //else return NULL;
}

int main()
{
    vector<int> nums;
    int n;
    while(cin>>n)
    {
    	//if(cin.get() == '\n') break;
        nums.push_back(n);
    }
    node *root=vectoCBT(nums,root,0);
    inorder(root);
}
