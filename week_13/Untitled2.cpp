#include<bits/stdc++.h>
#include<algorithm>

using namespace std;
struct things{
    string name;
    int pr;
};
things t;

void MaxHeapify(vector<things> &array, int root, int length){

    int left = 2*root,      // ���oleft child
    right = 2*root + 1,     // ���oright child
    largest;                // largest�ΨӰO���]�troot�Pchild, �T�̤���Key�̤j��node
    if (left <= length && array[left].pr > array[root].pr) largest = left;
    else largest = root;
    if (right <= length && array[right].pr > array[largest].pr) largest = right;
    if (largest != root) {                         // �p�G�ثeroot��Key���O�T�̤����̤j
        swap(array[largest], array[root]);         // �N�մ�root�P�T�̤�Key�̤j��node����m
        MaxHeapify(array, largest, length);        // �վ�s��subtree��Max Heap
    }
}

void BuildMaxHeap(vector<things> &array){
    for (int i = (int)array.size()/2; i >= 1 ; i--)
        MaxHeapify(array, i, array.size() - 1);    // length�n��@, �]��heap�q1�}�l�s����
}

void Heap(vector<things> &array){
    things tt;
    tt.name="0",tt.pr=0;
    array.insert(array.begin(),tt);                     // �Nindex(0)���m
    BuildMaxHeap(array);                                // �Narray�վ㦨Max Heap
    if(array[1].pr!=array[2].pr)
         if(array[2].pr<array[3].pr) swap(array[2],array[3]);
    array.erase(array.begin());                         // �Nindex(0)�R��
}

void Print(vector<things> &array){
    cout<<"First three things to do:"<<endl;
    for (int i = 0; i<2; i++)
        cout << array[i].name <<endl;
    cout << array[2].name ;
}

int main() {
    int num,arr;
    cin>>num;
    vector<things> array;
    for(int i=0;i<num;i++)
    {
        cin>>t.name>>t.pr;
        array.push_back(t);
    }
    Heap(array);
    Print(array);
    return 0;
}
