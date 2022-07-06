#include <bits/stdc++.h>
using namespace std;




int very_cool(int n,int k)  // funtion definition
{
    long long int a[1000000],i=0,j;
    int sum=0;
    while(n>0)
    {
        a[i]=n%2;
        n=n/2;
        i++;
    }  
    for( j=i-1;j>=2;j--)
    {
        if(a[j]==1&&a[j-1]==0&&a[j-2]==1)
            sum++;
    }
    if(sum>=k)
        return 1;
    else
        return 0;
}

int main()
{
    int t,r,k,s,total_no=0;
    cout<<"Enter t = ";
    cin>> t;
    
    for(int i=0; i<t; i++)
    {
        cout<<" Enter r and k ";

        scanf("%d%d",&r,&k);

        for(int j=5;j<=r;j++)
        {
            s=very_cool(j,k);  // function calling
            total_no=total_no+s;
        }
        printf("%d\n",total_no);
        total_no=0;
    }
    
    return 0;
}
