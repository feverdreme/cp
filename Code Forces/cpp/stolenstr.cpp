#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
// #pragma GCC optimize ("O3")
// #pragma GCC target("sse4")

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
#define s second

//iterators
#define rep(a) for(int i=0; i<a;i++)
#define range(i,a,b) for(int i=a;a<b;i++)
#define fori(i,iter) for(auto i:iter)

#define F0R(i,a) for(int i = 0;i<a;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define R0F(i,a) for(int i=a;i>=0;i--)

#define ff(n,m) for (ll i=0;i<n;i++) for (ll j=0;j<n;j++)

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

vi factors(ll n){
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
bool in_set(uset<T> &s, const T &k)
{
    return (s.find(k) != s.end());
}
template <class T>
bool in_set(uset<T> &s, const T k)
{
    return (s.find(k) != s.end());
}
template <class T>
bool in_set(set<T> &s, const T &k)
{
    return (s.find(k) != s.end());
}
template <class T>
bool in_set(set<T> &s, const T k)
{
    return (s.find(k) != s.end());
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

const char sp = ' ';
const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const string ualphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
const umap<int, char> charcode = {
    //lowercase
    {'a', 0},
    {'b', 1},
    {'c', 2},
    {'d', 3},
    {'e', 4},
    {'f', 5},
    {'g', 6},
    {'h', 7},
    {'i', 8},
    {'j', 9},
    {'k', 10},
    {'l', 11},
    {'m', 12},
    {'n', 13},
    {'o', 14},
    {'p', 15},
    {'q', 16},
    {'r', 17},
    {'s', 18},
    {'t', 19},
    {'u', 20},
    {'v', 21},
    {'w', 22},
    {'x', 23},
    {'y', 24},
    {'z', 25},
    // uppercase
    {'A', 26},
    {'B', 27},
    {'C', 28},
    {'D', 29},
    {'E', 30},
    {'F', 31},
    {'G', 32},
    {'H', 33},
    {'I', 34},
    {'J', 35},
    {'K', 36},
    {'L', 37},
    {'M', 38},
    {'N', 39},
    {'O', 40},
    {'P', 41},
    {'Q', 42},
    {'R', 43},
    {'S', 44},
    {'T', 45},
    {'U', 46},
    {'V', 47},
    {'W', 48},
    {'X', 49},
    {'Y', 50},
    {'Z', 51}
};

// static 2d-array
template<class T>
struct arr2 {
    int n, m;
    T** _arr;

    // no init value
    arr2(int n, int m) :
    n(n), 
    m(m){
        _arr = new T*[n];

        for (int i=0; i<n; i++){
            _arr[i] = new T[m];
        }
    }

    arr2(int n, int m, T val) : 
    n(n),
    m(m){
        _arr = new T* [n];

        for (int i = 0; i < n; i++)
        {
            _arr[i] = new T[m];

            fill(_arr[i], _arr[i] + m, val);
        }
    }

    T& operator[](const size_t& ind) {
        return _arr[ind];
    }

    const T& operator[](const size_t& ind) const {
        return _arr[ind];
    }

    void show(){
        F0R(i,n){
            F0R(j,m) cout << _arr[i][j] << ' ';
            cout << endl;
        }
    }

    ~arr2(){
        F0R(i,n) delete[] _arr[i];
        delete[] _arr;
    }
};

// dynamic 2d-array
// template <class T>
// struct vec2d {
//     int n, m;
//     vector<vector<T> > _arr;

//     vec2d(int n, int m):
//     n(n),
//     m(m) {
//         _arr.resize(n);
//         for (auto& i: _arr){
//             i.resize(m);
//         }
//     }

//     vec2d(int n, int m, T val) :
//     n(n),
//     m(m)
//     {
//         _arr.resize(n);
//         for (auto &i : _arr)
//         {
//             i.resize(m);
//             fill(i.begin(), i.end(), val);
//         }
//     }

//     vector<T>& operator[](const size_t& ind){
//         return _arr[ind];
//     }

//     const vector<T>& operator[](const size_t& ind) const {
//         return _arr[ind];
//     }

//     auto begin(){
//         return _arr.begin();
//     }
//     auto end(){
//         return _arr.end();
//     }
// };

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
3 5
aaaaa
bbbbb
ccccc
aaaaa
bbbbb
3 4
aaaa
bbbb
cccc
aabb
bbaa
5 6
abcdef
uuuuuu
kekeke
ekekek
xyzklm
xbcklf
eueueu
ayzdem
ukukuk
*/

int t;
int n, m;

int main()
{
    std::ios_base::sync_with_stdio(false);cin.tie(0);

	// setIO("stolenstr");
    cin >> t;
    while(t--){
        cin >> n >> m;

        vs orig(n);
        vs chg(n-1);

        rep(n) cin >> orig[i];
        rep(n-1) cin >> chg[i];

        // look at all the scrambled strings [0]
        // see which letter does not exist in the original
        // keep going until you are left with only one candidate
        uset<string> cando (orig.begin(), orig.end());
        // multiset<string> candc (chg.begin(), chg.end());

        // goes through each letter index
        string ans = "";
        for (int i = 0; i<m; i++){
            umap<char, int> counts;
            
            for (auto j : orig){
                counts[j[i]]++;
            }
            for (auto j : chg){
                counts[j[i]]--;
                if (counts[j[i]] == 0) counts.erase(j[i]);
            }

            // cout << "here\n";

            // get the reminaing key
            // try {
            //     auto discrept = (*(counts.begin())).f;
            // } catch (exception& e){
            //     cout << "except\n";
            //     for (auto h : counts){
            //         cout << h.f << sp << h.s << endl;
            //     }
            //     return 0;
            // }

            auto discrept = (*(counts.begin())).f;
            
            auto itcando = cando;
            for (auto j : itcando){
                if (j[i] != discrept) cando.erase(j);
            }

            if (cando.size() == 1){
                ans = *(cando.begin());
                break;
            }
        }

        cout << ans << endl;
        cout.flush();
    }

	return 0;
}
