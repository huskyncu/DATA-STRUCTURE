#include <iostream>
#include<vector>


using namespace std;

typedef struct matrix_data
{
    int row;
    int col;
    int element;
};

void fast_transpose(vector <matrix_data>  m1,vector <matrix_data> m2)
{
    int row_terms[100],staring_pos[100];
    int i,j;
    int num_cols=m1.at(0)->col;
    int num_terms=m1.at(0)->element;
    m2.at(0)->row=num_cols;
    m2.at(0)->col=m1[0].row;
    m2.at(0)->element=num_terms;
    if(num_terms>0)
    {
        for(i=0; i<num_cols; i++)
            row_terms[i]=0;
        for(i=1; i<=num_terms; i++)
            row_terms[m1.at(i)->col]++;
        staring_pos[0]=1;
        for(i=1; i<=num_terms; i++)
            staring_pos[i]=staring_pos[i-1]+row_terms[i-1];
        for(i=1; i<num_terms; i++)
        {
            j=staring_pos[m1.at(i)->col]++;
            m2.at(j)->row=m1.at(i)->col;
            m2.at(j)->col=m1.at(i)->row;
            m2.at(j)->element=m1.at(i)->element;
        }

    }
}

void store_sum(vector <matrix_data> d,int *totald, int row, int column,int *sum)
{
    if(*sum)
    {
        d.at(++*totald)->row=row;
        d.at(*totald)->column=column;
        d.at(*totald)->value=*sum;
        *sum=0;
    }
}

void mmult (vector <matrix_data> *a,vector <matrix_data> *b,vector <matrix_data> *d)
{
    int i,j,column,totalb=b.at(0)->element;
    int totald=0;
    int rows_a=a.at(i)->row,cols_a=a.at(0)->col,totala=a.at(0)->element;
    int cols_b=b.at(0)->col;
    int row_begin=1,row=a.at(1)->row,sum=0;
    vector<matrix_data> new_b;
    fast_transpose(&b,&new_b);
    a.at(totala+1)->row=row_a;
    new_b.at(totalb+1])->row=cols_b;
    new_b.at(totalb+1])->col=0;
    for(i=1; i<totala;)
    {
        column=new_b.at(1)->row;
        for(j=1; j<totalb+1;)
        {
            if(a.at(i)->row!=row)
            {
                storesum(d,&totald,row,column,&sum);
                i=row_begin;
                for(; new_b.at(j)->row==column; j++)
                    ;
                column=new_b.at(j)->row;
            }
            else if(new_b.at(j)->row!=column)
            {
                storesum(d,&totald,row,column,&sum);
                i=row_begin;
                column=new_b.at(j)->row;
            }
            else switch(compare(a.at(i)->col,new_b.at(j)->col))
                {
                case -1:
                    i++;
                    break;
                case 0:
                    sum+=(a.at(i++)->element * new_b.at(j++)->element);
                    break;
                case 1:
                    j++;
                }
        }
        for(; a.at(i)->row==row; i++)
            ;
        row_begin=i;
        row=a.at(i)->row;
    }
    d.at(i)->row=rows_a;
    d.at(i)->col=cols_b;
    d.at(i)->element=totald;
}

int main()
{
    int row1,col1;
    int sum_element1=0;
    matrix_data m_d;
    vector<matrix_data> m_d_g_1;
    cin>>row1>>col1;
    int matrix1[row1][col1];
    for(int i=0; i<row1; i++)
    {
        for(int j=0; j<col1; j++)
        {
            cin>>matrix1[i][j];
            if(matrix1[i][j]>0)
            {
                m_d.row=i;
                m_d.col=j;
                m_d.element=matrix1[i][j];
                m_d_g_1.push_back(m_d);
                sum_element1++;
            }
        }
    }
    int row2,col2;
    int sum_element2=0;
    cin>>row2>>col2;
    vector<matrix_data> m_d_g_2,m_d_g_3;
    int matrix2[row2][col2];
    for(int i=0; i<row2; i++)
    {
        for(int j=0; j<col2; j++)
        {
            cin>>matrix2[i][j];
            if(matrix2[i][j]>0)
            {
                m_d.row=i;
                m_d.col=j;
                m_d.element=matrix1[i][j];
                m_d_g_2.push_back(m_d);
                sum_element2++;
            }
        }
    }
    m_d.row=row1;
    m_d.col=col1;
    m_d.element=sum_element1;
    m_d_g_1.insert(m_d_g_1.begin(),m_d);
    m_d.row=row2;
    m_d.col=col2;
    m_d.element=sum_element2;
    m_d_g_2.insert(m_d_g_2.begin(),m_d);
    mmult(&m_d_g_1,&m_d_g_2,&m_d_g_3);
    cout<<endl;
    for(int i=0;i<m_d_g_3.size();i++)
        cout<<m_d_g_3[i].row<<" "<<m_d_g_3[i].col<<" "<<m_d_g_3[i].element<<endl;
}
