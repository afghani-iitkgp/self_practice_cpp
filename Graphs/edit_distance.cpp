#include <bits/stdc++.h>
using namespace std;
int mem[1000];


int Minimum(int x, int y, int z) {
    return min(min(x, y), z);
}

int editDist(string s1, string s2, int len_str1, int len_str2) {
    // Base case 
    if (len_str1 == 0)
        return len_str2;
    if (len_str2 == 0)
        return len_str1;
    
    int del, ins, sub;

    if (s1[len_str1 - 1] == s2[len_str2 - 1] ) {

        return editDist(s1, s2,  len_str1 - 1, len_str2 - 1);
    }
    else {
        // Delete, Insert, Substitute...
        del = editDist(s1, s2, len_str1-1, len_str2);
        ins = editDist(s1, s2, len_str1, len_str2-1);
        sub = editDist(s1, s2, len_str1-1, len_str2-1);
    }


    return (1 + Minimum(del, ins, sub) );
}

int editDist_DP(string s1, string s2, int len1, int len2) {

    
}

int main() {
    string s2 = "AGGCTATCACCTGACCTCCAGGCCGATGCCC";
    string s1 = "TAGCTATCACGACCGCGGTCGATTTGCCCGAC";

    int x = editDist(s1, s2, s1.length(), s2.length());

    cout<<"the result = "<<x;

    return 0;
}