#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define f first
#define s second
#define ll long long
#define pb push_back

/*
5 3
101
85
100
46
95

4 3
101
85
100
95
*/

int n, k;
vector<ll> years;

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    years.resize(n);

    FOR(i,0,n){
        cin >> years[i];
    }
    sort(years.rbegin(), years.rend());
    years.pb(0);
    n++;
    k--;

    // find endpoints
    vector<ll> endpoints;

    for (auto &i : years){
        endpoints.pb((int)(ceil(i / 12.0)));
    }

    // get split into non consecutive
    vector<pair<int,int> > groups;

    int lastind = 0;
    FOR(i,1,n){
        if (endpoints[i-1] - endpoints[i] > 1){
            groups.pb({lastind, i-1});
            lastind = i;
        }
    }

    groups.pb({lastind, n-1});

    // find real vals
    vector<pair<int,int> > vals;
    for (auto &i : groups){

        vals.pb({
            endpoints[i.f] * 12,
            (endpoints[i.s] - 1 ) * 12
        });
    }

    // get the diffs
    vector<ll> diffs;
    FOR(i,1,vals.size()){
        // cout << vals[i-1].s << ' ' << vals[i].f << endl;
        diffs.pb(vals[i-1].s - vals[i].f);
    }

    // sort the diffs
    ll diffsum = 0;

    if (k >= diffs.size()){
        for (ll &d : diffs)
            diffsum += d;
    } else {
        // sum all the way up to diffsize - k
        sort(diffs.rbegin(), diffs.rend());
        FOR(i,0, k){
            diffsum += diffs[i];
        }
    }

    // get max opf the endpoints
    

    cout << 12 * (int)ceil(years[0] / 12.0) - diffsum;
}