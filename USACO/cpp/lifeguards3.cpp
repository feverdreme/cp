#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define sp ' '

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

struct point {
    ll x;
    bool on;
    int ind;

    point(ll a, bool b, int c): x(a), on(b), ind(c){}
};

int n;
vector<point> points;
unordered_map<ll, ll> alone;

int main(){
    ifstream cin("lifeguards.in");
    ofstream cout("lifeguards.out");

    cin >> n;

    ll a, b;
    
    for (int i=0; i<n; i++){
        cin >> a >> b;

        points.push_back(point(a, true, i));
        points.push_back(point(b, false, i));

        alone[i] = 0;
    }

    sort(points.begin(), points.end(), [](point a, point b){
        return a.x < b.x;
    });

    point past = points[0];
    unordered_set<ll> seen;
    seen.insert(past.ind);

    ll sum = 0;

    for (int i=1; i < 2*n; i++){
        point p = points[i];

        ll diff = p.x - past.x;

        if (!seen.empty()){
            sum += diff;
        }

        if (seen.size() == 1){
            ll curr = *(seen.begin());
            alone[curr] += diff;
        }

        if (p.on) seen.insert(p.ind);
        else seen.erase(p.ind);

        past = p;
    }

    ll minalone = 1e10;

    for (auto &i : alone){
        // cout << i.first << sp << i.second << endl;

        minalone = min(minalone, i.second);
    }

    cout << sum - minalone;

    return 0;
}