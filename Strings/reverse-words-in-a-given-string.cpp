#include <bits/stdc++.h>
using namespace std;

int main()
{
std::string s = "scott>=tiger";
std::string del = ">=";
std::string token =  s.substr(0, s.find(del));

cout<<token;
}
