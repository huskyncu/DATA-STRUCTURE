#include<bits/stdc++.h>
#include<algorithm>

using namespace std;
struct things{
    string name;
    int pr;
};
things t;

void MaxHeapify(vector<things> &array, int root, int length){

    int left = 2*root,      // 取得left child
    right = 2*root + 1,     // 取得right child
    largest;                // largest用來記錄包含root與child, 三者之中Key最大的node
    if (left <= length && array[left].pr > array[root].pr) largest = left;
    else largest = root;
    if (right <= length && array[right].pr > array[largest].pr) largest = right;
    if (largest != root) {                         // 如果目前root的Key不是三者中的最大
        swap(array[largest], array[root]);         // 就調換root與三者中Key最大的node之位置
        MaxHeapify(array, largest, length);        // 調整新的subtree成Max Heap
    }
}

void BuildMaxHeap(vector<things> &array){
    for (int i = (int)array.size()/2; i >= 1 ; i--)
        MaxHeapify(array, i, array.size() - 1);    // length要減一, 因為heap從1開始存放資料
}

void Heap(vector<things> &array){
    things tt;
    tt.name="0",tt.pr=0;
    array.insert(array.begin(),tt);                     // 將index(0)閒置
    BuildMaxHeap(array);                                // 將array調整成Max Heap
    if(array[1].pr!=array[2].pr)
         if(array[2].pr<array[3].pr) swap(array[2],array[3]);
    array.erase(array.begin());                         // 將index(0)刪除
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
