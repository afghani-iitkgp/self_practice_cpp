// Summation of Summations

#include <bits/stdc++.h>
using namespace std;


int sumOfSummation(int n, vector<int> v)
{

    for (int i : v) {
        cout<<i;
    }

}


int main()
{
    int n;
    cout<<"Enter the number = ";
    cin>>n;
    
    vector<int> v;
    for (int i=0; i<n; i++)
        v.push_back(1);


    int s = sumOfSummation(n, v);
    cout<<s;


    

    return 0;
}
