#include<iostream>

using namespace std;

typedef struct Data{
	int id;
  	int score;
};

void Selection_sort(vector<Data> student_group,int num){
  	int i,j,min;
  	for(i=0;i<num-1;i++){
      	min=i;
      	for(j=i+1;j<num;j++){
          	if(student_group[j].score<student_group[min].score){
          		min=j;
          		cout<<student_group[min].score<<endl;
          		//cout<<j<<endl;
        	}
        }
      	//swap(student_group[i],student_group[min]);
      	//cout<<"S"<<endl;
      	Data temp = student_group[i];
        student_group[i] = student_group[min];
        student_group[min] = temp;
        for(int i=0;i<num;i++){
      	cout<<student_group[i].id<<" ";
    	}
    	cout<<endl;
    }
}

int main(){
  	Data student;
  	int num;
	cin>>num;
  	vector<Data> student_group;
  	for(int i=0;i<num;i++){
      	int tmp_id;
      	int tmp_score;
    	cin>>tmp_id>>tmp_score;
        student.id=tmp_id;
      	student.score=tmp_score;
      	student_group.push_back(student);
    }
  	Selection_sort(student_group,num);
  	for(int i=0;i<num;i++){
      	cout<<student_group[i].id<<endl;
    }

}
