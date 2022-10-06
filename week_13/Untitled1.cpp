#include<bits/stdc++.h>

using namespace std;

struct things{
    string name;
    int pri_num;
};
things t;
int main()
{

    int num;
    cin>>num;
    things *a;
    a =new things [num];
    for(int i=0;i<num;i++)
    {
        cin>>t.name>>t.pri_num;
        a[i]=t;
    }

    for(int i=0;i<num;i++) cout<<a[i].name<<endl;
}
