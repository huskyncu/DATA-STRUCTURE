#include<bits/stdc++.h>
using namespace std;
typedef struct
{
    int col;
    int row;
    int value;
}term;
term matrix_a[1001];
term matrix_b[1001];
term matrix_d[1001];
vector<term> ans(1);
void mult()
{

    int row_a=matrix_a[0].row, col_a=matrix_a[0].col, value_a=matrix_a[0].value;
    int row_b=matrix_b[0].row, col_b=matrix_b[0].col, value_b=matrix_b[0].value;
    int totald=1;
    int row=matrix_a[1].row;
    int sum=0,time=0;
    int row_begin=1;
    int col;
    int c=1,check=0;
    int a=1;
    for(int i=1; i<value_a;i++)
    {
        row=matrix_a[i].row;


            for(int j=1;j<value_b+1;j++)
            {
                check=0;
                    if(matrix_a[i].col==matrix_b[j].row)
                    {

                        for(int a=0;a<c;a++)
                        {
                            if(matrix_d[a+1].row==matrix_a[i].row && matrix_d[a+1].col==matrix_b[j].col)
                            {
                                //cout<<"aa"<<endl;
                                matrix_d[a+1].value+=(matrix_a[i].value*matrix_b[j].value);
                                check=1;
                            }

                        }
                        if(check!=1)
                            {
                                //cout<<matrix_a[i].row<<" "<<matrix_b[j].col<<" "<<matrix_a[i].value*matrix_b[j].value<<endl;
                                matrix_d[c].row=matrix_a[i].row;
                                matrix_d[c].col=matrix_b[j].col;
                                matrix_d[c].value=(matrix_a[i].value*matrix_b[j].value);
                                /*cout<<a<<endl;
                                cout<<matrix_d[c].row<<" "<<matrix_d[c].col<<" "<<matrix_d[c].value<<endl;
                                cout<<endl;*/
                            }
                        c++;
                        //cout<<"c "<<c<<endl;
                    }
            }
    }
    matrix_d[0].row=row_a;
    matrix_d[0].col=col_b;
    matrix_d[0].value=c-1;
}

int main()
{
    int row_a,col_a;
    int row_b,col_b;
    cin>>row_a>>col_a;
    int avail_a=1,avail_b=1;
    matrix_a[0].row = row_a; matrix_a[0].col = col_a;
    for(int i=0;i<row_a;i++)
    {
        for(int j=0;j<col_a;j++)
        {
            int tmp1;
            cin >> tmp1;
            if(tmp1!=0){
                matrix_a[avail_a].row = i;
                matrix_a[avail_a].col = j;
                matrix_a[avail_a].value = tmp1;
                avail_a++;
            }
        }
    }

    matrix_a[0].value = avail_a-1;
    cin>>row_b>>col_b;
    matrix_b[0].row = row_b; matrix_b[0].col = col_b;
    for(long int p=0;p<row_b;p++)
    {
        for(long int q=0;q<col_b;q++)
        {
            long int tmp2;
            cin >> tmp2;
            if(tmp2!=0){
                matrix_b[avail_b].row = p;
                matrix_b[avail_b].col = q;
                matrix_b[avail_b].value = tmp2;
                avail_b++;
            }
        }
    }
    matrix_b[0].value = avail_b-1;
    mult();
    for(int s=0;s<=matrix_d[0].value;s++)
    {
        cout<<matrix_d[s].row<<" "<<matrix_d[s].col<<" "<<matrix_d[s].value;
        cout<<endl;
    }
    return 0;
}
