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

template<class T>
bool in_set (uset<T> &s, const T &k){
    return (s.find(k) != s.end());
}
template<class T>
bool in_set (uset<T> &s, const T k){
    return (s.find(k) != s.end());
}
template<class T>
bool in_set(set<T> &s, const T &k){
    return (s.find(k) != s.end());
}
template <class T>
bool in_set(set<T> &s, const T k){
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
##....
....#.
.#..#.
.#####
...###
....##
*/

bool in_set (uset<pii, hash_pair> &s, const pii k){
    return s.find(k) != s.end();
}

int n;
int n2;
char arr[1000][1000];

uset<pii, hash_pair> notseen;
uset<pii, hash_pair> seen;
vec< uset<pii, hash_pair> > blobs;

void flood_fill(pii cell){
    stack<pii> stk;
    stk.push(cell);
    unordered_set<pii, hash_pair> visited;

    pii curr;
    while (!stk.empty()){ // while not empty
        curr = stk.top();
        visited.insert(curr);
        seen.insert(curr);
        notseen.erase(curr);
        stk.pop();
        
        int x = curr.f;
        int y = curr.s;

        bool b1 = x > 0 && arr[x-1][y] == '#' && !in_set(seen, {x-1, y});
        bool b2 = x < n-1 && arr[x+1][y] == '#' && !in_set(seen, {x+1, y});
        bool b3 = y > 0 && arr[x][y-1] == '#' && !in_set(seen, {x, y-1});
        bool b4 = y < n-1 && arr[x][y+1] == '#' && !in_set(seen, {x, y+1});

        if (b1) stk.push({x-1, y});
        if (b2) stk.push({x+1, y});
        if (b3) stk.push({x, y-1});
        if (b4) stk.push({x, y+1});
    }
    
    blobs.pb(visited);
}

pii blobify(uset<pii, hash_pair> blob){
    // get area
    int area = blob.size();

    int perim = 0;
    // get all whitespace

    for (auto &cell : blob){
        int x = cell.f;
        int y = cell.s;

        bool b1 = x > 0 && arr[x - 1][y] == '.';
        bool b2 = x < n - 1 && arr[x + 1][y] == '.';
        bool b3 = y > 0 && arr[x][y - 1] == '.';
        bool b4 = y < n - 1 && arr[x][y + 1] == '.';

        bool b5 = x == 0;
        bool b6 = y == 0;
        bool b7 = x == n-1;
        bool b8 = y == n-1;

        perim += b1 + b2 + b3 + b4 + b5 + b6 + b7 + b8;
        // printf("%d %d %d %d\n", b5, b6, b7, b8);
    }

    return mp(area, perim);
}

int main()
{
    std::ios_base::sync_with_stdio(false);cin.tie(0);

	setIO("perimeter");

    cin >> n;
    n2 = n*n;

    char token;
    F0R(i,n) F0R(j,n) {
        cin >> token;
        arr[i][j] = token;

        if (token == '#'){
            notseen.insert({i,j});
            // creams.insert({i,j});
        }
    }

    while(!notseen.empty()){
        flood_fill(*notseen.begin());
        // break;
    }

    pii maxblob = {-1,-1};

    // iterate through every blob
    for (auto &blob : blobs){
        pii curr = blobify(blob);
        // cout << curr.f << sp << curr.s << endl;

        if (curr.f > maxblob.f) maxblob = curr;
        else if (curr.f == maxblob.f && curr.s < maxblob.s) maxblob = curr;
    }

    cout << maxblob.f << sp << maxblob.s;
    // cout << 13 << sp << 22;

	return 0;
}
