#include <bits/stdc++.h>
using namespace std;

int LongestSubstring(string s) 
{
    unordered_map<char, int> umap;
    int count;



    while (!s.empty()) {
        umap.clear();
        count = 0;

        for (int i=0; i<s.size(); ++i) {
            
            if (umap[s[i]] >  0) {
                s = s.substr(i, string::npos);
                break;
            }

            else {
                umap[s[i]]++;
                count++;
            }
        }
    }

    return count;
}

void PrintFreq(string s)
{
    unordered_map<char, int> mp_freq;

    for (int i=0; i<s.size(); ++i) {
        mp_freq[s[i]]++;
    }

    for (auto itr=mp_freq.begin(); itr != mp_freq.end(); itr++)
        cout << itr->first<< " - " << itr->second<< '\n';


}

int main() 
{
    string s1 = "pwwkew";

    string res = "Amit Parashar";

    cout<< res.length() << endl;

    cout<< int(res[1]) << endl; 

    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);

    cout<< LongestSubstring(s1);

    // PrintFreq(s1);

    return 0;

}

