#include <bits/stdc++.h>

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
#define R0F(i,a,b) for(int i=a;i>=0;i--)

#define OE <<endl
#define space ' '
// #define cout cout<<
#define cint(n) int n;cin>>n;
#define dvec(v) fori(i,v){cout << i OE;}

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

int t,N;
vi arr;

bool removeAdj(vi &arr){
    //check if there's non duplicates
    unordered_set<int> nums (arr.begin(), arr.end());
    
    if (nums.size() == 1) return false;
	vi erind;
    int prev = arr[0];
    FOR(i,1,N){
        if (prev != arr[i]){
            arr[i] += prev;
            prev = arr[i];
            erind.pub(i-1);
        }
    }
    int numerased = 0;
    fori(i,erind){
    	arr.erase(arr.begin() + i - numerased);
    	numerased++;
	}
	return true;

}

int main() {
    cin >> t;
    while(t--){
    	arr.clear();
        cin >> N;
        rep(N){
			int j;
			cin >> j;
			arr.pub(j);
		}

        while (removeAdj(arr)){}
        cout << arr.size() << endl;
    }
    

	return 0;
}
