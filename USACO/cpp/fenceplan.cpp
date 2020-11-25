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
#define pb push_back
#define pub push_back
#define pob pop_back
#define tup tuple
#define mp make_pair
#define mt make_tuple
#define get(i,x) get<i>(x)
#define f first
#define s second

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
// #define cout cout<<
#define cint(n) int n;cin>>n;
#define dispbr(n) for(auto& i:n) cout<<i<<endl;
#define disp(n) for(auto& i:n) cout<<i<<space

template<class T>
class dsu{
private:
    map<T,T> _dsu;
    unordered_set<T> _members;
    pair<T,long long> _find_set(T a){
        stack<int> stk;
        T head = a;
        while(head != _dsu[head]){
            head = _dsu[head];
            stk.push(head);
        }
        //compression
        long long stksize = 0;
        T temp;
        while(stk.size() != 0){
            temp = stk.top();
            stk.pop();
            _dsu[temp] = head;
            stksize++;
        }
        return {head, stksize};
    }
public:
    dsu(){}
    dsu(T val){
        _dsu[val] = val;
        _members.insert(val);
    }
    bool union_find(T a, T b){
        pair<T, long long> h1 = _find_set(a), h2 = _find_set(b);
        //union them
        if (h1.second > h2.second){
            _dsu[h2.first] = h1.first;
        } else {
            _dsu[h1.first] = h2.first;
        }
        return h1.first == h2.first;
    }
    T find_set(T a){
        return _find_set(a).first;
    }
    void add_child(T parent, T child){
        if (_members.find(parent) == _members.end()){
            _dsu[parent] = parent;
        }
        _dsu[child] = parent;
    }
    void add_member(T a){
        _members.insert(a);
        _dsu[a] = a;
    } 
};

vi factors(int n){
	vi factors;
	double sqrtofn=sqrt(n);
	int count=1;
	while(count<=sqrtofn){
		if(n%count==0){
			factors.pub(count);
			if(count*count!=n)factors.pub(n/count);
		}
		count++;
	}
	return factors;
}

template<class T>
vec<T> filter(vec<T> iter, T delim){
	vec<T> ret;
	fori (i,iter) if (i != delim) ret.pub(i);
	return ret;
}

vs ssplit(string s, char delim){
	stringstream ss(s);
	string token;
	vs ret;
	while(getline(ss,token,delim)) ret.pub(token);
	ret = filter<string>(ret,"");
	return ret;
}

template<class InputIterator>
ll arr_sum(InputIterator first, InputIterator last){
	ll sum = 0;
	while(first != last){
		sum += *first;
		first++;
	}
	return sum;
}

template<class InputIterator, class T>
InputIterator arr_remove(InputIterator first, InputIterator last, const T& val){
	while (first != last){
		if (*first == val) return first;
	}
	throw "Element does not exist\n";
}

template<class InputIterator, class T>
vec<T> find_all(InputIterator first, InputIterator last, const T& val){
	vec<T> inds;

	InputIterator ptr = first;

	while(ptr != last){
		if (*ptr == val) inds.pb(ptr - first);
		ptr++;
	}

	return inds;
}

template <class T>
void Max(T &a, const T &b)
{
	T *ptr = &a;
	*ptr = max(a,b);
}
template <class T>
void Max(T &a, const T &&b){
    T *ptr = &a;
    *ptr = max(a,b);
}

template <class T>
void Min(T &a, const T &b)
{
	T *ptr = &a;
	*ptr = min(a, b);
}
template <class T>
void Min(T &a, const T &&b){
    T *ptr = &a;
    *ptr = min(a,b);
}

void setIO(string filename){
	freopen((filename + ".in").c_str(), "r" , stdin);
	freopen((filename + ".out").c_str(), "w" , stdout);
}

char sp = ' ';

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
7 5
0 5
10 5
5 0
5 10
6 7
8 6
8 4
1 2
2 3
3 4
5 6
7 6
*/

int n, m;
pz cows[100001];
map<int,vi> edges;

uset<int> visited;

ll dfs(int node){
    stack<int> stk;
    stk.push(node);

    ll minx = cows[node].f;
    ll maxx = cows[node].f;
    ll miny = cows[node].s;
    ll maxy = cows[node].s;

    int curr;
    while(stk.size() != 0){
        curr = stk.top();
        stk.pop();
        visited.insert(curr);

        // Min(minx, cows[curr].f);
        minx = min(minx, cows[curr].f);
        // Min(miny, cows[curr].s);
        miny = min(miny, cows[curr].s);
        // Max(maxx, cows[curr].f);
        maxx = max(maxx, cows[curr].f);
        // Max(maxy, cows[curr].s);
        maxy = max(maxy, cows[curr].s);

        for (auto &e : edges[curr]){
            if (visited.find(e) == visited.end()) stk.push(e);
        }
    }

    return (2*(maxx - minx + maxy - miny));
}

int main() {
	std::ios_base::sync_with_stdio(false);cin.tie(0);

	setIO("fenceplan");

    cin >> n >> m;
    rep(n) cin >> cows[i+1].f >> cows[i+1].s;

    int token1, token2;
    rep(m){
        cin >> token1 >> token2;
        edges[token1].pb(token2);
        edges[token2].pb(token1);
    }

    // time to find all the groups
    ll minperimeter = 1e9;

    int minfind = 1;
    while (visited.size() != n){
        for(int i=minfind;i<=n;i++)
            if (visited.find(i) == visited.end()){
                minperimeter = min(minperimeter, dfs(i));
                minfind = i;
                break;
            }
    }

    cout << minperimeter << endl;

	return 0;
}
