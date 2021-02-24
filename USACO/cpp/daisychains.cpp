#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define ll long long

int n;
vector<double> arr;
vector<double> prefix;

int main(){

    cin >> n;

    arr.resize(n);
    prefix.resize(n);

    int ccount = 0;
    rep(i,n){
        cin >> arr[i];

        ccount += arr[i];
        prefix[i] = ccount;
    }

    ll ret = 0;
    // brute force everythinh
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (j < i) continue;

            double token = prefix[j] - prefix[i] + arr[i];
            double tavg = token / (j-i+1);

            for (int k=i; k<=j; k++){
                if (arr[k] == tavg){
                    ret++;
                    break;
                }
            }
        }
    }

    cout << ret;

    return 0;
}