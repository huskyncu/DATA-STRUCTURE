#include <bits/stdc++.h>
using namespace std;

typedef struct term
{
    int row;
    int col;
    int value;
};
int mul[1000][1000];
int main()
{
    int row1, col1, row2, col2;
    int val;
    vector<term> spar_1;
    vector<term> spar_2;
    cin >> row1 >> col1;
    for(int i=0; i<row1; i++)
    {
        for(int j=0; j<col1; j++)
        {
            cin >> val;
            if(val != 0)
                spar_1.push_back({i, j, val});
        }
    }
    cin >> row2 >> col2;
    for(int i=0; i<row2; i++)
    {
        for(int j=0; j<col2; j++)
        {
            cin >> val;
            if(val != 0)
                spar_2.push_back({i, j, val});
        }
    }

    for(int i=0; i<row1; i++)
    {
        for(int j=0; j<col2; j++)
        {
            mul[i][j] = 0;
        }
    }
    int counts = 0;
    for(int i=0;i<spar_1.size();i++)
    {
        for(int j=0;j<spar_2.size();j++)
        {
            if(spar_1[i].col == spar_2[j].row)
            {
                if(mul[spar_1[i].row][spar_2[j].col] == 0)
                    counts++;
                mul[spar_1[i].row][spar_2[j].col] += (spar_1[i].value*spar_2[j].value);
            }
        }
    }

    cout << row1 << " " << col2 << " " << counts << endl;
    for(int i=0; i<row1; i++)
    {
        for(int j=0; j<col2; j++)
        {
            if(mul[i][j] != 0)
                cout << i << " " << j << " " << mul[i][j] << endl;
        }
    }

}
