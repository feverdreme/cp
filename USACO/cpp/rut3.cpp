#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(n) for (int i = 0; i < n; i++)
#define F0R(i, n) for (int i = 0; i < n; i++)
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define f first
#define s second

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
    int ind;

    cow() {}
    cow(char a, ll b, ll c, int ind) : d(a), x(b), y(c), ind(ind)
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

    bool operator==(cow c1) const {
        return (c1.x == x && c1.y == y && c1.d == d);
    }
};

struct hash_cow{
    size_t operator()(const cow &c) const {
        auto hash1 = hash<char>{}(c.d);
        auto hash2 = hash<ll>{}(c.x);
        auto hash3 = hash<ll>{}(c.y);
        return hash1 ^ hash2 ^ hash3;
    }
};

int n;
vector<cow> cows, candidates, vers, hors, ds, de, dn, dw;

int main(){

    cin >> n;
    cows.resize(n);
    candidates.resize(n);

    char t1;int t2,t3;
    rep(n){
        cin >> t1 >> t2 >> t3;
        cows[i] = cow(t1,t2,t3,i);

        if (cows[i].det % 2) vers.pb(cows[i]);
        else hors.pb(cows[i]);

        switch(cows[i].d){
            case 'N':dn.pb(cows[i]);break;
            case 'W':dw.pb(cows[i]);break;
            case 'S':ds.pb(cows[i]);break;
            case 'E':dw.pb(cows[i]);break;
        }
    }
    
    // look at all -> and sort by ns x<
    sort(vers.begin(), vers.end(), [](cow a, cow b){return a.x < b.x;});
    for (cow &sel : de){
        for (cow &comp : vers){

            if (comp.x < sel.x) continue;
            if ((comp.y < sel.y && comp.d == 'S') || (sel.y < comp.y && comp.d == 'N')) continue;

            ll dx = comp.x - sel.x;
            ll dy = comp.y - sel.y;

            if (comp.d == 'N') dy *= -1;

            if (dx == dy) continue;

            candidates[sel.ind] = comp;
            goto found;
        }

        candidates[sel.ind] = cow('I',-1,-1,-1);

        found:
        continue;
    }

    // do the ones by west
    reverse(vers.begin(), vers.end());
    for (cow &sel : dw){
        for (cow &comp : vers){

            if (comp.x > sel.x) continue;
        }
    }
    
}