#include <bits/stdc++.h>
using namespace std;
typedef struct list_node
{
    int data;
    list_node *next;
};
list_node *first =NULL;
int counts=0;


void addBack(int a)
{
    list_node *temp;
    temp=(list_node*)malloc(sizeof(list_node));
    list_node *current = first;//*
    if(first!=0)
    {
        while(current->next!=0)
        {
            current=current->next;
        }
        temp->data=a;
        temp->next=NULL;
        current->next=temp;

    }
    else
    {
        temp->data=a;
        temp->next=NULL;
        first=temp;
    }
    counts++;
}

void addFront(int *data)
{
    list_node *temp;
    temp=(list_node*)malloc(sizeof(list_node));
    temp->data=*data;
    temp->next=first;
    first=temp;
    counts++;
}

void addIndex(int *index,int *data)
{
    list_node *temp;
    list_node *current = first,*previous = 0;
    temp=(list_node*)malloc(sizeof(list_node));
    temp->data=*data;
    if(first!=0)
    {
        if(*index)
        {
            for(int i=0; i<*index; i++)
            {
                previous=current;
                current=current->next;
            }
            temp->next=current;
            previous->next=temp;
        }
        else
            addFront(data);
    }
    else
    {
        temp->next=0;
        first=temp;
    }
    counts++;
}

void deleteIndex(int *index)
{
    list_node *current = first,*previous = 0;
    if(first!=0)
    {
        if(*index!=0)
        {
            for(int i=0; i<*index; i++)
            {
                previous=current;
                current=current->next;
            }
            previous->next=current->next;
        }
        else
        {
            first = current->next;
        }
    }
    counts--;
}
int main()
{
    while(true)
    {
        string str;
        cin>>str;
        if(str=="exit")
            break;
        else if(str=="addBack")
        {
            int a;
            cin>>a;
            addBack(a);
        }
        else if(str=="addFront")
        {
            int b;
            cin>>b;
            addFront(&b);
        }
        else if(str=="addIndex")
        {
            int index,data;
            cin>>index>>data;
            if(index<=counts && index>=0)
                addIndex(&index,&data);
        }

        else if(str=="deleteIndex")
        {
            int index;
            cin>>index;
            if(index<counts && index>=0)
                deleteIndex(&index);
        }
    }
    //cout<<counts<<endl;
    if(first != NULL)
    {
        for(; first ; first=first->next)
        {
            cout<<first->data<<"-->";
        }
        cout<<"null"<<endl;
    }
    else cout<<"null"<<endl;
}


