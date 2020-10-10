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
#define R0F(i,a) for(int i=a;i>=0;i--)

#define OE <<endl
#define space ' '
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

void setIO(string filename){
	freopen((filename + ".in").c_str(), "r" , stdin);
	freopen((filename + ".out").c_str(), "w" , stdout);
}

int t, R, C;
int temp;
//set of visited and unvisited nodes
char token;
char board[1000][1000];
set<pii> visited, unvisited;
map<pii,int> weights;

int main()
{
	// std::ios_base::sync_with_stdio(false);cin.tie(0);
	
	cin >> t;
	cout << "\nnee";
	while (t--){
		cout << "\nhere";
		cin >> R >> C;
		range(i,0,R){
			range(j,0,C){
				cin >> token;
				board[i][j] = token;
				unvisited.insert(mp(i,j));
				weights.insert({mp(i,j), -1});
			}
		}

		unvisited.erase(mp(0,0));
		visited.insert(mp(0,0));

		while(unvisited.size()){
			pii minpoint;
			int minscore = 1e9;
			for (auto i : visited){
				if (unvisited.find({i.fir+1, i.sec}) != unvisited.end()){
					if (board[i.fir+1][i.sec] == board[i.fir][i.sec]){
						
						if (weights[{i.fir,i.sec}] < minscore){
							minpoint = {i.fir + 1, i.sec};
							minscore = weights[{i.fir, i.sec}] + weights[{i.fir + 1, i.sec}];
						}

					} else {
						if (weights[{i.fir, i.sec}] + 1 < minscore)
						{
							minpoint = {i.fir + 1, i.sec};
							minscore = weights[{i.fir, i.sec}] + weights[{i.fir + 1, i.sec}] + 1;
						}
					}
				}
				if (unvisited.find({i.fir, i.sec + 1}) != unvisited.end()){
					if (board[i.fir][i.sec + 1] == board[i.fir][i.sec]){
						
						if (weights[{i.fir,i.sec}] < minscore){
							minpoint = {i.fir , i.sec + 1};
							minscore = weights[{i.fir, i.sec}] + weights[{i.fir , i.sec + 1}];
						}

					} else {
						if (weights[{i.fir, i.sec}] + 1 < minscore)
						{
							minpoint = {i.fir , i.sec + 1};
							minscore = weights[{i.fir, i.sec}] + weights[{i.fir, i.sec + 1}] + 1;
						}
					}
				}
				if (unvisited.find({i.fir - 1, i.sec}) != unvisited.end())
				{
					if (board[i.fir - 1][i.sec] == board[i.fir][i.sec])
					{

						if (weights[{i.fir, i.sec}] < minscore)
						{
							minpoint = {i.fir - 1, i.sec};
							minscore = weights[{i.fir, i.sec}] + weights[{i.fir - 1, i.sec}];
						}
					}
					else
					{
						if (weights[{i.fir, i.sec}] + 1 < minscore)
						{
							minpoint = {i.fir - 1, i.sec};
							minscore = weights[{i.fir, i.sec}] + weights[{i.fir - 1, i.sec}] + 1;
						}
					}
				}
				if (unvisited.find({i.fir, i.sec - 1}) != unvisited.end())
				{
					if (board[i.fir][i.sec - 1] == board[i.fir][i.sec])
					{

						if (weights[{i.fir, i.sec}] < minscore)
						{
							minpoint = {i.fir, i.sec - 1};
							minscore = weights[{i.fir, i.sec}] + weights[{i.fir, i.sec - 1}];
						}
					}
					else
					{
						if (weights[{i.fir, i.sec}] + 1 < minscore)
						{
							minpoint = {i.fir, i.sec - 1};
							minscore = weights[{i.fir, i.sec}] + weights[{i.fir, i.sec - 1}] + 1;
						}
					}
				}
			}

			cout << minpoint.fir << ' ' << minpoint.sec << endl;
			visited.insert(minpoint);
			unvisited.erase(minpoint);
			weights[minpoint] = minscore;
		}

		
	}
	
	return 0;
}
