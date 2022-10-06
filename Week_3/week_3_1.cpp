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
    vector<polynomial> poly_group1;
    vector<polynomial> poly_group2;
    vector<polynomial> poly_final;
    int starta=0;
    int finisha;
    cin>>finisha;
    for(int i=0; i<finisha; i++)
    {
        cin>>poly.coef>>poly.exp;
        poly_group1.push_back(poly);
    }
    int startb=0;
    int finishb;
    cin>>finishb;
    for(int j=0; j<finishb; j++)
    {
        cin>>poly.coef>>poly.exp;
        poly_group2.push_back(poly);
    }
    //int startd,finishd;
    int avail=0;
    //long double coef_sum;
    //startd=avail;
    while(starta<finisha && startb<finishb)
    {
        switch(compare(poly_group1[starta].exp,poly_group2[startb].exp))
        {
        case -1://a<b
            poly.coef=poly_group2[startb].coef;
            poly.exp=poly_group2[startb].exp;
            poly_final.push_back(poly);
            startb++;
            avail++;
            break;
        case 0:
            poly.coef=poly_group2[startb].coef+poly_group1[starta].coef;
            poly.exp=poly_group1[starta].exp;
            starta++;
            startb++;
            avail++;
            poly_final.push_back(poly);
            break;
        case 1:
            poly.coef=poly_group1[starta].coef;
            poly.exp=poly_group1[starta].exp;
            poly_final.push_back(poly);
            starta++;
            avail++;

        }
    }
    for(starta; starta<finisha; starta++)
    {
        poly.coef=poly_group1[starta].coef;
        poly.exp=poly_group1[starta].exp;
        poly_final.push_back(poly);
        avail++;
    }

    for(startb; startb<finishb; startb++)
    {
        poly.coef=poly_group2[startb].coef;
        poly.exp=poly_group2[startb].exp;
        poly_final.push_back(poly);
        avail++;
    }
    for(int g=0; g<avail; g++)
    {
        if(poly_final[g].coef!=0)
            cout<<poly_final[g].coef<<" "<<poly_final[g].exp<<" ";
    }
}
