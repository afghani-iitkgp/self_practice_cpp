#include<bits/stdc++.h>
using namespace std;
/*
Input: arr = [1,4,2,5,3]
Output: 58
Explanation: The odd-length subarrays of arr and their sums are:
[1] = 1
[4] = 4
[2] = 2
[5] = 5
[3] = 3
[1,4,2] = 7
[4,2,5] = 11
[2,5,3] = 10
[1,4,2,5,3] = 15
If we add all these together we get 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58
*/

int sumOddLengthSubarrays(vector<int>& arr) 
{
    int n = arr.size();
    int Sum = 0;

    int i;
    int k = 1;

    while (k<=n){

        int temp = 0;


        for (i=0; i<k; i++) {
            temp += arr[i];
            cout<<"temp  "<<temp<<"\n";
        }

        Sum += temp;

        for (i=0; i<n-k; i++) {
            temp += arr[i+k] - arr[i];
            Sum += temp;
        }

        cout<<k<<endl;

        k += 2;
    }



    return Sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int t;
    // cin>>t;
    // cout<<t;

    vector<int> arr = {1,4,2,5,3};
    arr = {10,11,12};
    arr = {};

    int res = sumOddLengthSubarrays(arr);

    cout<<"Result = "<<res<<endl;

}