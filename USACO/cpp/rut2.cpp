#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <functional>
#include <string>
#include <utility>
#include <unordered_set>

using namespace std;

#define ll long long
#define rep(n) for (int i = 0; i < n; i++)
#define F0R(i, n) for (int i = 0; i < n; i++)
#define vi vector<int>
#define vll vector<ll>

struct hash_pair
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

struct cow
{
    char d;
    ll x, y;
    int det;

    cow() {}
    cow(char a, ll b, ll c) : d(a), x(b), y(c)
    {
        switch (a)
        {
        case 'N':
            det = 0;
            break;

        case 'E':
            det = 1;
            break;

        case 'S':
            det = 2;
            break;

        case 'W':
            det = 3;
            break;
        }
    }
};

int n;
vector<cow> cows;
vll ans;
unordered_map<pair<ll,ll>, bool, hash_pair> coor;

ll maxx = 0;
ll maxy = 0;
ll minx = 1e9;
ll miny = 1e9;

int main()
{
    std::ios_base::sync_with_stdio(false);cin.tie(0);
    
    cin >> n;
    cows.resize(n);
    ans = vll(n, -2);

    char t1;
    ll t2, t3;

    // get input
    rep(n)
    {
        cin >> t1 >> t2 >> t3;

        cows[i] = cow(t1, t2, t3);

        maxx = max(maxx,t2);
        minx = min(minx, t2);
        maxy = max(maxy, t3);
        miny = min(miny, t3);
    }

    // do every step

    vector<ll> ans (n,0);

    unordered_set<int> rem;
    // simulate
    while (rem.size() != n){

        auto nextt = coor;

        for (int i=0; i<n; i++){

            if (rem.find(i) != rem.end()) continue;

            auto c = cows[i];
            auto cx = c.x;
            auto cy = c.y;

            if (cx+1 < minx || cx-1 > maxx || cy+1 < miny || cy-1 > maxy){
                rem.insert(i);
                ans[i] = -1;
                continue;
            }

            if (coor[{cx, cy}] == true){
                rem.insert(i);
                continue;
            }

            nextt[{cx,cy}] = true;
            ans[i]++;

            switch(c.d){
                case 'N':
                cows[i].y++;
                break;

                case 'S':
                cows[i].y--;
                break;

                case 'E':
                cows[i].x++;
                break;

                case 'W':
                cows[i].x--;
                break;
            }
        }

        coor = nextt;
    }

    for (auto a : ans){
        if (a == -1) cout << "Infinity";
        else cout << a;

        cout << endl;
    }

    return 0;
}