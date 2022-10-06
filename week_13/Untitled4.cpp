#include<bits/stdc++.h>

using namespace std;

typedef struct things{
    string name;
    int pr;
};
things t,*arr;

void insert_maxheap(things t,int n)
{
    int i;
    i=++n;
    while(i!=1 && t.pr>arr[i/2-1].pr)
    {
        arr[i-1]=arr[i/2-1];
        i/=2;
    }
    arr[i-1]=t;
}

things delete_maxheap(int n)
{
    int parent=0,child=1;
    things item=arr[0],temp=arr[n--];
    while(child<=n)
    {
        if(child<n && arr[child].pr<arr[child+1].pr)
            child++;
        if(temp.pr>=arr[child].pr) break;
        arr[parent]=arr[child];
        parent=child;
        child*=2;
    }
    arr[parent]=temp;
    return item;
}
int main(){
    int num,times=0;
    cin>>num;
    arr= new things [num];
    for(int i=0;i<num;i++)
    {
        cin>>t.name>>t.pr;
        insert_maxheap(t,i);
        times++;
    }
    for(int i=0;i<num;i++) cout<<arr[i].pr<<" ";
	cout<<endl;
    cout<<"First three things to do:"<<endl;
    for (int i = 0; i<3; i++)
    {
        things th=delete_maxheap(times-1);
        cout << th.name <<endl;
    }
	for(int i=0;i<num;i++) cout<<arr[i].pr<<" ";
}
