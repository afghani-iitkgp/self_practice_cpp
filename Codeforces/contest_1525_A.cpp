/*
A. Potion-making

You have an initially empty cauldron, and you want to brew a potion in it. The potion consists of two ingredients: magic essence and water. The potion you want to brew should contain exactly k % magic essence and (100−k) % water.

In one step, you can pour either one liter of magic essence or one liter of water into the cauldron. What is the minimum number of steps to brew a potion? You don't care about the total volume of the potion, only about the ratio between magic essence and water in it.

A small reminder: if you pour e liters of essence and w liters of water (e+w>0) into the cauldron, then it contains ee+w⋅100 % (without rounding) magic essence and we+w⋅100 % water.


*/

// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>
using namespace std;


int gcd(int a, int b)
{
    if (a==0 && b==0)
        return 0;
    if (a==0)
        return b;
    if (b==0)
        return a;
    
    // base case
    if (a==b)
        return a;
    
    // 'a' is greater
    if (a > b)
        return gcd(a-b, b);
    
    else
        return gcd(a, b-a);

}

int min_steps_for_good_potion(int k)
{
    // Calculate GCD.
    int den = gcd(k, 100-k);
    return ((100-k)/den) + (k/den);

}

int main()
{   
    // int T;
    // vector<int> magic_percentage_list;

    // cout<<"Enter the number of test cases = ";
    // cin>>T;
    // cout<<'\n';
    

    // while (T>0) {
    //     int k;
    //     cout<<"ENTER the %age value of k = ";
    //     cin>>k;
    //     cout<<'\n';
    //     magic_percentage_list.push_back(k);

    //     T--;
    // }


    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);

    int t;
    cin >> t;


    while (t--) {

        vector<int> res;
        int k;
        cin>> k;
    

        // cout<<"Value = "<<magic_percentage_list[i]<<'\n';
        int min_steps = min_steps_for_good_potion(k);
        // cout<<"Output = "<<min_steps<<'\n';

        cout<<min_steps<<'\n';
        
    }


    return 0;    

        
}
