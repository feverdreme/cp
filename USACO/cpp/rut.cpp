#include <bits/stdc++.h>

#define ll long long
#define rep(n) for(int i=0;i<n;i++)
#define F0R(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define f first
#define s second

/*
6
E 3 5
N 5 3
E 4 6
E 10 4
N 11 2
N 8 1
*/
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
struct cow {
    char d;
    ll x,y;
    int det;

    cow(){}
    cow(char a, ll b, ll c): d(a), x(b), y(c){
        switch(a){
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
vector<cow> cn, ce, cs, cw;
int sn, se, ss, sw;
vll ans;

int main(){

    cin >> n;
    cows.resize(n);
    ans = vll(n,-2);

    char t1;
    ll t2, t3;

    rep(n){
        cin >> t1 >> t2 >> t3;
        cows[i] = cow(t1,t2,t3);

        switch(t1){
            case 'N':
            cn.pb(cows[i]); break;

            case 'S':
            cs.pb(cows[i]); break;

            case 'E':
            ce.pb(cows[i]); break;

            case 'W':
            cw.pb(cows[i]); break;
        }
    }

    set<pair<ll,ll>, hash_pair> inters;
    map<ll, vector<pair<cow, cow> > > interx, intery;

    // calcualte all possible interesections
    F0R(i,n){
        F0R(j,n){
            if (i == j) continue;
            
            auto c1 = cows[i];
            auto c2 = cows[j];

            if (c1.det % 2 == c2.det % 2) continue;

            ll dx = c1.x - c2.x;
            ll dy = c1.y - c2.y;
            if (dx == dy) continue;

            if (c1.det % 2 == 0){
                interx[c1.x].pb({c1,c2});
                intery[c2.y].pb({c1,c2});
            } else {
                interx[c2.x].pb({c2,c1});
                intery[c1.y].pb({c2,c1});
            }
        }
    }

    // look through every cow and see if it properly intersects

    // look through every vertical interseciton
    for (auto &vertsect : interx){
        auto vertsectx = vertsect.f;
        auto vertsects = vertsect.s;

        sort(vertsects.begin(), vertsects.end(), [](pair<cow,cow> a, pair<cow, cow> b){
            return (a.s.y > b.s.y);
        });

        for (auto &points : vertsects){

            // i want to know if they will actually intersect
            auto gver = points.f;
            auto ghor = points.s;

            auto dx = vertsectx - ghor.x;
            if (ghor.d == 'W') dx *= -1;

            if (dx < 0) continue;

            auto dy = gver.y - ghor.y;
            if (ghor.d == ' '){}
        }
    }

    return 0;
}