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
#define aendl "<-\n"
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

template<class T>
void Max(T &a, const T &b){
	T *ptr = &a;
	*ptr = max(a,b);
}

template<class T>
void Min(T &a, const T &b){
	T *ptr = &a;
	ptr = min(a,b);
}

void setIO(string filename){
	freopen((filename + ".in").c_str(), "r" , stdin);
	freopen((filename + ".out").c_str(), "w" , stdout);
}

/*
5
P
P
H
P
S
*/

int H = 0, P = 0, S = 0;

struct Cont {
	int h,p,s;
	char inflection;
	Cont(int a, int b, int c, char switched){
		h = a;
		p = b;
		s = c;
		inflection = switched;
	}

	int maxnum(){
		return max({h,p,s});
	}

	int getAfterMax(){
		return max({
			H - h,
			P - p,
			S - s
		});
	}

	void repr(){
		printf("H: %d P: %d S: %d\n", h,p,s);
	}
};

int n;

int main() {
	std::ios_base::sync_with_stdio(false);cin.tie(0);

	setIO("hps");

	cin >> n;
	vec<char> moves (n);
	map<int, Cont> prefix;

	char lastchar = ' ';
	int lastseen = 0;
	int h = 0;
	int p = 0;
	int s = 0;

	rep(n){
		cin >> moves[i];

		switch (moves[i]){
			case 'H':
				H++;
				break;
			case 'P':
				P++;
				break;
			case 'S':
				S++;
				break;
		}

		if (i == 0) lastchar = moves[0];

		if (lastchar != moves[i]){
			switch(moves[i-1]){
				case 'H':
					h += i - lastseen;
					break;
				case 'P':
					p += i - lastseen;
					break;
				case 'S':
					s += i - lastseen;
					break;
			}

			prefix.insert({i, Cont(h,p,s, moves[i])});
			lastseen = i;
			lastchar = moves[i];
		}
	}

	switch (moves[n - 1])
	{
	case 'H':
		h += n - lastseen;
		break;
	case 'P':
		p += n - lastseen;
		break;
	case 'S':
		s += n - lastseen;
		break;
	}

	prefix.insert({n, Cont(h,p,s, moves[n-1])});

	//solve the damn thing
	//loop through every prefix sum, then get mins maxes and find answer
	int maxans = 0;

	for (auto &i : prefix){
		int ind = i.fir;
		Cont pre = i.sec;

		int curr = pre.maxnum();
		curr += pre.getAfterMax();

		maxans = max(maxans, curr);
	}

	cout << maxans << endl;

	return 0;
}
