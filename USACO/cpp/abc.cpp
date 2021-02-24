#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vll vector<ll>
#define rep(n) for(int i=0;i <n; i++)

// 7 numbers

vll arr(7);

int main(){

    rep(7) cin >> arr[i];

    // brute force this
    // the sum has to be the greatest
    sort(arr.begin(), arr.end());

    ll abc = arr[6];

    // the min has to be one
    ll minn = arr[0];

    // bf this
    for (int i=1; i<6; i++){
        ll guess = arr[i];

        for (int j=1; j<6; j++){
            if (j == i) continue;

            ll guess2 = arr[j];

            if (guess + guess2 + minn == abc){
                printf("%d %d %d", minn, guess, guess2);
                goto en;
            }
        }
    }

    en:

    return 0;
}