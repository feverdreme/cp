#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

/*
9
0 1
1 0
1 1
1 2
2 1
2 2
3 1
3 2
4 1
*/

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define f first
#define s second

int n;
vector<pair<int,int> > cows;

int main(){
    std::ios_base::sync_with_stdio(false);cin.tie(0);

    cin >> n;
    cows.resize(n);

    FOR(i,0,n){
        cin >> cows[i].f >> cows[i].s;
    }

    
}