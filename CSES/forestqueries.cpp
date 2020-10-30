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
#define pb push_back
#define pub push_back
#define pob pop_back
#define tup tuple
#define mp make_pair
#define mt make_tuple
#define get(i,x) get<i>(x)
#define fir first
#define sec second

//iterators
#define rep(a) for(int i=0; i<a;i++)
#define range(i,a,b) for(int i=a;a<b;i++)
#define fori(i,iter) for(auto i:iter)

#define F0R(i,a) for(int i = 0;i<a;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define R0F(i,a) for(int i=a;i>=0;i--)

#define OE <<endl
#define space ' '
#define elif else if
// #define cout cout<<
#define cint(n) int n;cin>>n;
#define dispbr(n) for(auto& i:n) cout<<i<<endl;
#define disp(n) for(auto& i:n) cout<<i<<space

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
vll find_all(InputIterator first, InputIterator last, const T& val){
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
	*ptr = max(a, b);
}

template <class T>
void Min(T &a, const T &b)
{
	T *ptr = &a;
	ptr = min(a, b);
}

void setIO(string filename){
	freopen((filename + ".in").c_str(), "r" , stdin);
	freopen((filename + ".out").c_str(), "w" , stdout);
}

/*
4 3
.*..
*.**
**..
****
2 2 3 4
3 1 3 1
1 1 2 2
*/

int n,q;
int prefix[1001][1001];

struct Rect {
	int y1,x1,y2,x2;

	Rect(int a, int b, int c, int d){
		y1 = a;
		x1 = b;
		y2 = c;
		x2 = d;
	}

	int getArea(){
		return prefix[y2][x2] - prefix[y2][x1 - 1] - prefix[y1-1][x2] + prefix[y1-1][x1-1];
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);cin.tie(0);

	cin >> n >> q;
	char token;

	int rowsum = 0;

	// oh god a 2d prefix sum is incredibly stupid
	rep(n+1){
		prefix[i][0] = 0;
		prefix[0][i] = 0;
	}

	for(int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){

			cin >> token;

			if (j==1) rowsum = 0;
			if(token == '*') rowsum++;

			prefix[i][j] = prefix[i-1][j] + rowsum;

		}
	}

	int a,b,c,d;
	vec<Rect> queries;

	rep(q){
		cin >> a >> b >> c >> d;
		queries.pb(Rect(a,b,c,d));
	}

	for (auto &i : queries){
		cout << i.getArea() << endl;
	}

	return 0;
}
