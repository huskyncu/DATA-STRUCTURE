#include <iostream>
#include<vector>


using namespace std;

typedef struct term
{
    int row;
    int col;
    int element;
};
term a[100000];
term b[100000];
term d[100000];

int compare(int a,int b)
{
    if(a>b)
        return 1;
    else if(a==b)
        return 0;
    else
        return -1;
}

void fast_transpose(term m1[],term m2[])
{
    int row_terms[100000],staring_pos[100000];
    int i,j;
    int num_cols=m1[0].col;
    int num_terms=m1[0].element;
    m2[0].row=num_cols;
    m2[0].col=m1[0].row;
    m2[0].element=num_terms;
    if(num_terms>0)
    {
        for(i=0; i<num_cols; i++)
            row_terms[i]=0;
        for(i=1; i<=num_terms; i++)
            row_terms[m1[i].col]++;
        staring_pos[0]=1;
        for(i=1; i<num_cols; i++)
            staring_pos[i]=staring_pos[i-1]+row_terms[i-1];
        for(i=1; i<=num_terms; i++)
        {
            j=staring_pos[m1[i].col]++;
            m2[j].row=m1[i].col;
            m2[j].col=m1[i].row;
            m2[j].element=m1[i].element;
        }

    }
}

void store_sum(int *totald, int row, int column,int *sum)
{
    if(*sum!=0)
    {
        d[++*totald].row=row;
        d[*totald].col=column;
        d[*totald].element=*sum;
        *sum=0;
    }
}

void mmult ()
{
    int i,j,column,totalb=b[0].element;
    int totald=0;
    int rows_a=a[0].row,cols_a=a[0].col,totala=a[0].element;
    int cols_b=b[0].col;
    int row_begin=1,row=a[1].row,sum=0;
    term new_b[100000]={};
    fast_transpose(b,new_b);
    a[totala+1].row=rows_a;
    new_b[totalb+1].row=cols_b;
    new_b[totalb+1].col=0;
    for(i=1; i<=totala;)
    {
        column=new_b[1].row;
        for(j=1; j<=totalb+1;)
        {
            if(a[i].row!=row)
            {
                store_sum(&totald,row,column,&sum);
                i=row_begin;
                for(; new_b[j].row==column; j++)
                    ;
                column=new_b[j].row;
            }
            else if(new_b[j].row!=column)
            {
                store_sum(&totald,row,column,&sum);
                i=row_begin;
                column=new_b[j].row;
            }
            else switch(compare(a[i].col,new_b[j].col))
                {
                case -1:
                    i++;
                    break;
                case 0:
                    sum+=(a[i++].element * new_b[j++].element);
                    break;
                case 1:
                    j++;
                }
        }
        for(; a[i].row==row; i++)
            ;
        row_begin=i;
        row=a[i].row;
    }
    d[0].row=rows_a;
    d[0].col=cols_b;
    d[0].element=totald;
}

int main()
{
    int row1,col1;
    int total_element1=0;
    cin>>row1>>col1;
    a[0].row=row1;
    a[0].col=col1;
    int matrix1[row1][col1];
    for(int i=0; i<row1; i++)
    {
        for(int j=0; j<col1; j++)
        {
            cin>>matrix1[i][j];
            if(matrix1[i][j]!=0)
            {
                a[++total_element1].row=i;
                a[total_element1].col=j;
                a[total_element1].element=matrix1[i][j];
            }
        }
    }
    a[0].element=total_element1;
    int row2,col2;
    int total_element2=0;
    cin>>row2>>col2;
    b[0].row=row2;
    b[0].col=col2;
    int matrix2[row2][col2];
    for(int i=0; i<row2; i++)
    {
        for(int j=0; j<col2; j++)
        {
            cin>>matrix2[i][j];
            if(matrix2[i][j]!=0)
            {
                b[++total_element2].row=i;
                b[total_element2].col=j;
                b[total_element2].element=matrix2[i][j];
            }
        }
    }
    b[0].element=total_element2;
    mmult();
    for(int gg=0; gg<=d[0].element; gg++)
    {
        cout<<d[gg].row<<" "<<d[gg].col<<" "<<d[gg].element<<endl;
    }
}
