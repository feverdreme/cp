#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

struct store {
    int q, p;

    store(){}
};

int n, m, r;

vi cows;
vector<store> stores;
vi neighbors;
vll prefix;

bool check(int nneigh){
    ll sum = 0;

    sum += prefix[nneigh - 1];

    ll Ni = n - i;

    // get the gallons of the current cow, and the topmost store and keep reducing until Niis 0
    while (Ni != 0){
        
    }
}

int main(){
    cin >> n >> m >> r;

    cows.resize(n);
    stores.resize(m);
    neighbors.resize(r);
    prefix.resize(r);

    for (int i=0; i<n; i++){
        cin >> cows[i];
    }
    for (int i=0; i<m; i++){
        cin >> stores[i].q >> stores[i].p;
    }
    for (int i=0; i<r; i++){
        cin >> neighbors[i];
    }

    // sort the cows by milk
    sort(cows.begin(), cows.end());

    // sort the stores by price
    sort(stores.begin(), stores.end(), [](store a, store b){
        return a.p < b.p;
    });

    sort(neighbors.rbegin(), neighbors.rend());

    //prefix sum neighbors
    ll sum = 0;
    for (int i=0; i<r; i++){
        sum += neighbors[i];
        prefix[i] = sum;
    }

    // we separate i in neighbors and N-i into store
}