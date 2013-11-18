/*
Ρ§Ιϊ£ΊΌ§Οι
Ρ§ΊΕ£Ί2012060090026
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int MI(int x,int y)
{
        if(y==0)
                return 1;
        return x*MI(x,y-1);
}

int main()
{
        int x,y;
        cin>>x>>y;
        cout<<MI(x,y)<<endl;
        return 0;
}