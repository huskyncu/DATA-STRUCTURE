#include<bits/stdc++.h>

using namespace std;

typedef struct bst_node{
    float value;
    bst_node *left,*right;
};

int re(float s,bst_node *n,float g){
    if(!n) return 0;
    s+=n->value;
    if(s==g) return 1;
    else if(s<g)
    {
        if(re(s,n->left,g)) return 1;
        else if(re(s,n->right,g)) return 1;
        else return 0;
    }
}
bst_node *first=NULL;
int main(){
    int n,nn;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>nn;
        if(!first)
        {
            bst_node *temp = (bst_node *)malloc(sizeof(bst_node));
            temp->value=nn;
            temp->left=temp->right=NULL;
            first=temp;
        }
        else{
            bst_node *temp = (bst_node *)malloc(sizeof(bst_node));
            bst_node *current=first;
            while(true){
                if(nn>current->value && current->right) current=current->right;
                else if(nn<current->value && current->left) current=current->left;
                if(nn>current->value && !current->right)
                {
                    temp->value=nn;
                    temp->right=temp->left=NULL;
                    current->right=temp;
                    break;
                }
                else if(nn<current->value && !current->left){
                    temp->value=nn;
                    temp->right=temp->left=NULL;
                    current->left=temp;
                    break;
                }
            }
        }
    }
    float goal=0;
    cin>>goal;
    float sum=0;
    bst_node *current=first;
    if(re(sum,current,goal)) cout<<"There exit at least one path in binary search tree."<<endl;
    else cout<<"There have no path in binary search tree."<<endl;
}
