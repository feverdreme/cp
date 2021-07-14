/*
By Jeffrey Huang
See README for more details at https://github.com/JeffreyHuang06/cp
*/

#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
// #pragma GCC optimize ("O3")
#pragma GCC target("sse4")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
typedef pair<ll,ll> pz;

#define vec vector
#define uset unordered_set
#define umap unordered_map
#define usetpii unordered_set<pair<int, int> , hash_pair>
#define pb push_back
#define pub push_back
#define pob pop_back
#define tup tuple
#define mp make_pair
#define mt make_tuple
#define get(i,x) get<i>(x)
#define f first

//iterators
#define rep(a) for(int i=0; i<a;i++)
#define range(i,a,b) for(int i=a;a<b;i++)
#define fori(i,iter) for(auto i:iter)

#define F0R(i,a) for(int i = 0;i<a;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define R0F(i,a) for(int i=a;i>=0;i--)

#define OE <<endl
#define aendl "<-\n"
#define space ' '
#define elif else if

#define MAXINT 100007
#define MAXLL 1000000007

// #define cout cout<<
#define cint(n) int n;cin>>n;
#define dispbr(n) for(auto& i:n) cout<<i<<endl;
#define disp(n) for(auto& i:n) cout<<i<<space


/*
Time complexities

O(n) = 10^8
O(n^2) = 10^4
O(n^3) = 200
O(logn) = Very big number, fucking massive 10^(4 * 10^8)
O(nlogn) = 10^7
O(2^n) = 24
*/

/*
6
6
1 9 17 6 14 3
3
4 2 2
3
7 3 4
3
2 2 4
5
0 1000000000 0 1000000000 0
2
1 1
*/

int t;
int n;
vll arr;


int main()
{
    std::ios_base::sync_with_stdio(false);cin.tie(0);

	// setIO("restoremodulo");

    cin >> t;

    while (t--){
        cin >> n;
        arr.resize(n);
        uset<ll> diffs;
        ll maxnum = 0;

        rep(n){
            cin >> arr[i];
            maxnum = max(maxnum, arr[i]);

            if (i != 0) diffs.insert(arr[i] - arr[i-1]);
        }

        if (n <= 2){
            cout << 0 << endl;
            continue;
        }

        // see how many distinct in there
        if (diffs.size() == 1) cout << 0;
        elif (diffs.size() > 2) cout << -1;
        else {
            // get the two numbers
            ll first = *diffs.begin();
            diffs.erase(diffs.begin());
            ll second = *diffs.begin();

            ll ma = max(first, second);
            ll mi = min(first, second);

            ll m = ma - mi;
            ll c = ma;

            if (maxnum < m){
                cout << m << space << c;
            } else cout << -1;
        }

        cout << endl;
    }


	return 0;
}
