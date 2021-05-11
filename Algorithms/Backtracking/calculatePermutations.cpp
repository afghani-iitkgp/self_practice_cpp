#include <bits/stdc++.h>
using namespace std; 


void print_permutations(string s)
{
    for (int i=0; i<s.length(); i++)
        cout<<s[i];
    
}



int main()
{
    string s;
    cout<<"Enter the string = ";
    
    cin>>s; 
    print_permutations(s);
    cout<<s;
       
    return 0;
}

