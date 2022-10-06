#include <bits/stdc++.h>
using namespace std;
#define MAX_STACK_SIZE 1000

typedef struct
{
    short int row;
    short int col;
    short int dir;
} element;

element stack1[MAX_STACK_SIZE];

typedef struct
{
    short int vert;
    short int horiz;
} offsets;

offsets move1[4];

int main()
{
    int input_row,input_col;
    cin>>input_row>>input_col;
    int **maze=new int*[input_row];
    for(int i=0; i<input_row; i++) maze[i]=new int[input_col];

    int **mark=new int*[input_row];
    for(int i=0; i<input_row; i++) mark[i]=new int[input_col];

    for(int i=0; i<input_row; i++)
    {
        for(int j=0; j<input_col; j++)
        {
            cin>>maze[i][j];
            mark[i][j]=0;
        }
    }

    int row,col,next_col,next_row,dir,found=false;
    move1[0].vert=-1; //north
    move1[0].horiz=0;
    move1[2].vert=1; //south
    move1[2].horiz=0;
    move1[3].horiz=-1;  //west
    move1[3].vert=0;
    move1[1].horiz=1; //east
    move1[1].vert=0;
    element position;
    mark[0][0]=1;
    int top=0;
    stack1[0].row=0;
    stack1[0].col=0;
    stack1[0].dir=0;
    while(top>-1 && !found)
    {
        position=stack1[top--];
        row=position.row;
        col=position.col;
        dir=position.dir;
        while(dir<4 && !found)
        {
            next_row=row+move1[dir].vert;
            //cout<<next_row<<endl;
            next_col=col+move1[dir].horiz;
            // cout<<next_col<<endl;
            //cout<<"a"<<endl;
            if(next_col>=0 && next_row>=0 && next_col <input_col && next_row<input_row)
            {
                if(next_row==input_row-1 && next_col==input_col-1)
                {
                    found=true;
                    mark[next_row][next_col]=1;
                    position.row=row;
                    position.col=col;
                    position.dir=++dir;
                    stack1[++top]=position;
                }
                else if(!maze[next_row][next_col] && !mark[next_row][next_col])
                {
                    mark[next_row][next_col]=1;
                    position.row=row;
                    position.col=col;
                    position.dir=++dir;
                    stack1[++top]=position;
                    row=next_row;
                    col=next_col;
                    dir=0;
                }
                else ++dir;
            }
            else ++dir;
        }
    }
    if(found && maze[input_row-1][input_col-1] == 0)
    {
        for(int i=0; i<=top; i++)
        {
            cout<<"("<<stack1[i].row<<","<<stack1[i].col<<")"<<" ";
        }
        cout<<"("<<input_row-1<<","<<input_col-1<<")"<<endl;
    }
    else
    {
        cout<<"Can't reach the exit!"<<endl;
    }
}
