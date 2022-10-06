# include <stdio.h>
# include <stdlib.h>
# include <string.h>

struct term
{
    int row;
    int col;
    int element;
};

struct term a[1000]= {};
struct term b[1000]= {};
struct term d[1000]= {};
int main(int argc, char *argv[])
{
    int row1,col1;
    int total_element1=0;
    scanf("%d %d",&row1,&col1);
    a[0].row=row1;
    a[0].col=col1;
    int matrix1[row1][col1];
    for(int i=0; i<row1; i++)
    {
        for(int j=0; j<col1; j++)
        {
            scanf("%d",&matrix1[i][j]);
        }
    }
    a[0].element=total_element1;
    int row2,col2;
    int total_element2=0;
    scanf("%d %d",&row2,&col2);
    b[0].row=row2;
    b[0].col=col2;
    int matrix2[row2][col2];
    for(int i=0; i<row2; i++)
    {
        for(int j=0; j<col2; j++)
        {
            scanf("%d",&matrix2[i][j]);
        }
    }
    b[0].element=total_element2;
    int sum=0;
    d[0].element=0;
    d[0].row=row1;
    d[0].col=col2;
    for(int i=0; i<row1; i++)
    {
        for(int j=0; j<col2; j++)
        {
            sum=0;
            for(int k=0; k<col1; k++)
            {
                sum+=(matrix1[i][k]*matrix2[k][j]);
            }
            if(sum!=0)
            {
                d[++d[0].element].row=i;
                d[d[0].element].col=j;
                d[d[0].element].element=sum;
            }

        }
    }

    for(int gg=0; gg<=d[0].element; gg++)
    {
        printf("%d %d %d\n",d[gg].row,d[gg].col,d[gg].element);
    }
}
