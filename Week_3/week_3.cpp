#include<iostream>
# include<vector>

using namespace std;
typedef struct polynomial
{
    long double coef;
    long long int exp;
};

int compare(int a,int b)
{
    if(a>b)
        return 1;
    else if(a==b)
        return 0;
    else
        return -1;
}

int main()
{
    polynomial poly;
    vector<polynomial> poly_group;
    int starta=0;
    int finisha;
    cin>>finisha;
    for(int i=0; i<finisha; i++)
    {
        cin>>poly.coef>>poly.exp;
        poly_group.push_back(poly);
    }
    int startb=finisha;
    int finishb;
    cin>>finishb;
    for(int j=startb; j<finishb+finisha; j++)
    {
        cin>>poly.coef>>poly.exp;
        poly_group.push_back(poly);
    }
    finishb+=finisha;
    int startd,finishd;
    int avail=finishb;
    long double coef_sum;
    startd=avail;
    //printf("%d %d %d %d\n", starta, finisha, startb, finishb);
    while(starta<finisha && startb<finishb)
    {
        switch(compare(poly_group[starta].exp,poly_group[startb].exp))
        {
        case -1://a<b
            poly_group[avail].coef=poly_group[startb].coef;
            poly_group[avail++].exp=poly_group[startb].exp;
            startb++;
            break;
        case 0:
            coef_sum=poly_group[startb].coef+poly_group[starta].coef;
            poly_group[avail].coef=coef_sum;
            poly_group[avail++].exp=poly_group[starta].exp;
            starta++;
            startb++;
            break;
        case 1:
            poly_group[avail].coef=poly_group[starta].coef;
            poly_group[avail++].exp=poly_group[starta].exp;
            starta++;
        }
    }
    for(; starta<finisha; starta++)
    {
        poly_group[avail].coef=poly_group[starta].coef;
        poly_group[avail++].exp=poly_group[starta].exp;
    }

    for(; startb<finishb; startb++)
    {
        poly_group[avail].coef=poly_group[startb].coef;
        poly_group[avail++].exp=poly_group[startb].exp;
    }
    finishd=avail-1;
    for(int y=0;y<poly_group.size();y++)
        cout<<poly_group[y].coef<<" "<<poly_group[y].exp<<" ";
    cout<<endl;
    for(int g=startd; g<=finishd; g++)
    {
        if(poly_group[g].coef)
           cout<<poly_group[g].coef<<" "<<poly_group[g].exp<<" ";
    }
}
