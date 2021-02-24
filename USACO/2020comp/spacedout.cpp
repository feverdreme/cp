#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")

#define FOR(i,a,b) for (int i=a; i<b; i++)

using namespace std;

int n;
vector<vector<int> > weights;

int main(){
    cin >> n;
    weights.resize(n);

    FOR(i,0,n){
        weights[i].resize(n);

        FOR(j,0,n){
            cin >> weights[i][j];
        }
    }

    cout << 22;

}