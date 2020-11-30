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
    set<T> _members;
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

// to hash the stl's
// from geeksforgeeks
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
3
10 2
1 1 2 2 1 1 2 2 2 1
7 1
1 2 3 4 5 6 7
10 3
1 3 3 3 3 1 2 1 3 3
*/

int t;
int n,k;
vi arr;
uset<int> colors;

int myfind(int color, int st, int en){
    if (st >= en) return -1;
    for (int i=st; i<en; i++){
        if (arr[i] != color) return i;
    }

    return -1;
}

ll findmoves(int color){
    // i find the first disrecrptancy
    int needed = 0;
    int st = myfind(color, 0, n);
    // cout << st << endl;

    while (st != -1){
        needed++;
        
        st = myfind(color, st+k, n);
        // cout << st << endl;
    }

    return needed;
}

int main() {
	std::ios_base::sync_with_stdio(false);cin.tie(0);

	// setIO("repaintingstreet.cpp");

    cin >> t;
    while(t--){
        cin >> n >> k;
        colors.clear();
        arr.clear();

        int token;

        rep(n){
            cin >> token;
            arr.pb(token);
            colors.insert(token);
        }

        // i can try to find out how many it takes to paint something to one color, then i max it all
        ll maxx = 1e9;
        for (auto &c : colors){
            maxx = min(maxx, findmoves(c));
            // cout << findmoves(c) << sp << c << sp << t << aendl;
        }

        cout << maxx << endl;
    }


	return 0;
}
