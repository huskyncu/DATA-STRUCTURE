#include<bits/stdc++.h>

using namespace std;

typedef struct node{
    int value;
    node *left,*right;
};
node *first;

int re(float s,node *n,float g)
{
    if(!n) return 0;
    s+=n->value;
    if(s==g) return 1;
    if(s<g)
    {
        if(re(s,n->left,g)) return 1;
        else if(re(s,n->right,g)) return 1;
        else return 0;
    }
}
int main()
{
    int t,tt,goal,sum=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>tt;
        if(!first)
        {
            node *temp=(node*)malloc(sizeof(node));
            temp->value=tt;
            temp->right=temp->left=NULL;
            first=temp;
        }
        else{
            node *temp=(node*)malloc(sizeof(node));
            node *current=first;
            while(true)
            {
                if(tt>current->value && current->right) current=current->right;
                else if(tt<current->value && current->left) current=current->left;
                if(tt>current->value && !current->right)
                {
                    temp->value=tt;
                    temp->right=temp->left=NULL;
                    current->right=temp;
                    break;
                }
                else if(tt<current->value && !current->left)
                {
                    temp->value=tt;
                    temp->right=temp->left=NULL;
                    current->left=temp;
                    break;
                }
            }
        }

    }
    cin>>goal;
    if(re(sum,first,goal)) cout<<"there exit at least one path in binary search tree"<<endl;
    else cout<<"there have no path in binary search tree"<<endl;
}

