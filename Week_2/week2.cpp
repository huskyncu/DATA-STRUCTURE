#include<iostream>
#include <vector>
using namespace std;

typedef struct Data
{
    int id;
    float score;
    int first_order;
};

void Selection_sort(vector<Data> student_group,int num)
{
    int i,j,max,min;
    for(i=0; i<num-1; i++)
    {
        max=i;
        for(j=i+1; j<num; j++)
        {
            if(student_group[j].score>student_group[max].score)
            {
                max=j;
            }
            else if(student_group[j].score==student_group[max].score && student_group[j].first_order<student_group[max].first_order)
            {
            	max=j;
			}
        }
        swap(student_group[i],student_group[max]);
    }
    for(int i=0; i<num; i++)
    {
        cout<<student_group[i].id<<endl;
    }

}
int main()
{
    Data student;
    int num;
    cin>>num;
    vector<Data> student_group;
    for(int i=0; i<num; i++)
    {
        int tmp_id;
        float tmp_score;
        cin>>tmp_id>>tmp_score;
        student.id=tmp_id;
        student.score=tmp_score;
        student.first_order=i;
        student_group.push_back(student);
    }
    Selection_sort(student_group,num);
}
