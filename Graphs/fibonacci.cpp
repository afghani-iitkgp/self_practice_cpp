#include <bits/stdc++.h>
#define N 100

using namespace std;

const int NIL = -1;
int lookup_table[N];


void init() {
    for (int i = 0; i < N; i++) {
        lookup_table[i] = NIL;
    }
}

int fib_mem(int n) {
    if (lookup_table[n] == NIL)
        cout<<endl;
}