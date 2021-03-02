#include <bits/stdc++.h>
#include <iostream>
// #pragma GCC optimize("Ofast")
using namespace std;
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define f first
#define s second
#define ll long long
#define pb push_back
#define uset unordered_set

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

int n;
int arr[500][500];

// prefix will have (the max number < 100, how many 100s it has come across)
pair<uset<pair<int,int>,hash_pair >,int> prefix[500][500];

ll solve(){
    uset<pair<int, int>, hash_pair> p00;

    if (arr[0][0] < 100)
        p00.insert({0, 0});

    prefix[0][0] = {
        p00,
        arr[0][0] == 100};

    // level
    FOR(j, 1, n)
    {
        auto past = prefix[0][j - 1];
        auto curr = arr[0][j];

        if (curr < 100)
            past.f.insert({0, j});
        prefix[0][j] = {
            past.f,
            past.s + (curr == 100)};
    }

    FOR(i, 1, n)
    {
        auto past = prefix[i - 1][0];
        auto curr = arr[i][0];

        if (curr < 100)
            past.f.insert({i, 0});
        prefix[i][0] = {
            past.f,
            past.s + (curr == 100)};
    }

    // all
    FOR(i, 1, n)
    {
        auto curow = prefix[i][0];

        FOR(j, 1, n)
        {
            auto curr = arr[i][j];
            auto below = prefix[i - 1][j];

            // update curopw
            if (curr < 100)
                curow.f.insert({i, j});
            else if (curr == 100)
                curow.s++;
            below.f.insert(curow.f.begin(), curow.f.end());

            prefix[i][j] = {
                below.f,
                below.s + curow.s};
        }
    }

    ll ans = 0;

    // now brute force every possible thing
    FOR(x1, 0, n)
    {
        FOR(z1, 0, n)
        {
            FOR(x2, 0, x1 + 1)
            {
                FOR(z2, 0, z1 + 1)
                {

                    // get the number
                    ll num100 = prefix[x1][z1].s - prefix[x1][z2 - 1].s - prefix[x2 - 1][z1].s + prefix[x2 - 1][z2 - 1].s;
                    // check the min
                    auto curr = prefix[x1][z1].f;

                    if (z2 != 0)
                        for (auto &k : prefix[x1][z2 - 1].f)
                            curr.erase(k);

                    if (x2 != 0)
                        for (auto &k : prefix[x2 - 1][z1].f)
                            curr.erase(k);

                    if (num100 > 0 && curr.size() == 0)
                    {
                        ans++;
                    }
                }
            }
        }
    }

    return ans;
}

int main(){
    std::ios_base::sync_with_stdio(false);cin.tie(0);

    cin >> n;

    FOR(i,0,n){
        FOR(j,0,n){
            cin >> arr[i][j];
        }
    }

    cout << solve() << endl; 

    // cout << __cplusplus;

    // return 0;
}