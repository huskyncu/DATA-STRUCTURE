#include<bits/stdc++.h>

using namespace std;

int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	a=4;
	int m[4][4];
		//int **m=new int*[a];
	//for(int i=0;i<a;i++) m[i]=new int [a];
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<a;j++)
		{
			cin>>m[i][j];
		}
	}
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<a;j++)
		{
			for(int k=0;k<a;k++)
			{
				if(m[i][k]+m[k][j]<m[i][j]) m[i][j]=m[i][k]+m[k][j];
			}
		}
	}
	cout<<m[b][c]<<endl;
}

