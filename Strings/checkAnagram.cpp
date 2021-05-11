#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> frequencyWords(string s)
{
    int n = s.size();
    unordered_map<char, int> charFreq;

    for (int i=0; i<n; i++) {
        charFreq[s[i]]++;
    }

    return charFreq;
}

bool isAnagram(string s, string t)
{
    unordered_map<char, int> map1 = frequencyWords(s);
    unordered_map<char, int> map2 = frequencyWords(t);

    // for (auto it: freq_S) {
    //     cout<<it.first<<" : "<< it.second<<endl;
    // }
    bool tag = true;

    // check for keys from 1st to 2nd.
    for (auto it1 : map1) {
        if (map2.find(it1.first) == map2.end()) {
            tag  = false;
            break;
        }
        else
            continue;
    }

    // check for keys from 2nd to 1st.
    for (auto it2 : map2) {
        if (map1.find(it2.first) == map1.end()) {
            tag  = false;
            break;
        }
        else
            continue;
    }


    // If Keys are matched then check for frequencies of word.
    if (tag==true) {
        for (auto it1 : map1) {
            if (map2[it1.first] != it1.second) {
                tag = false;
                break;
            }
            else 
                continue;
        }
    }
    else 
        tag = false;


    return tag;
}


int main ()
{
    string s = "silent", t = "listen";
    bool val = isAnagram(s, t);
    cout<< val<<'\n';
}

