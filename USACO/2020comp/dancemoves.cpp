#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

#define f first
#define s second
#define uset unordered_set

#define endl '\n'

#define FOR(i,a,b) for(int i=a;i<b;i++)

int n, k;
vector<pair<int,int> > swaps;

void naive(){

    vi ans (n+1);

    // for each cow traverse the graph until they get back where they started
    for (int c = 1; c <= n; c++){

        int pos = c;
        unordered_set<int> seen;
        unordered_set<int> traversed;

        seen.insert(pos);
        traversed.insert(pos);

        // traverse

        while (true){
            for (int i=0;i<k;i++){
                int a = swaps[i].f;
                int b = swaps[i].s;

                if (pos == a || pos == b){
                    pos = pos == a ? b : a;
                    traversed.insert(pos);
                }
            }

            if (seen.find(pos) != seen.end()){
                ans[c] = traversed.size();
                break;
            }
        }
    }

    for (int i=1;i<=n;i++){
        cout << ans[i] << endl;
    }
}

void better(){

    vi ans(n+1);

    // for each cow do a cycle
    uset<int> notseen;
    FOR(i,1,n+1) notseen.insert(i); // + 1e5

    // now try to ctcle
    while(!notseen.empty()){

        int start = *(notseen.begin());
        vi allencountered;
        unordered_map<int, uset<int> > alltraversed;

        // cout << start << " start\n";

        allencountered.push_back(start);

        // perform the cycles
        uset<int> seen;
        int pos = start;
        seen.insert(pos);

        uset<int> traversed;
        traversed.insert(pos);

        int past = pos;

        while(true){
            for (int i=0; i<k; i++){
                int a = swaps[i].f;
                int b = swaps[i].s;

                if (pos == a || pos == b){
                    pos = pos == a ? b : a;
                    traversed.insert(pos);
                    // cout << pos << ' ';
                }
            }

            // cout << pos << " pos\n";

            // append the traversed and the pos
            alltraversed[past] = traversed;
            traversed.clear();
            traversed.insert(pos);

            past = pos;

            if (seen.find(pos) == seen.end()) allencountered.push_back(pos);
            else break;

            seen.insert(pos);
        }

        // remove all the seen
        for (auto &i : seen) {
            notseen.erase(i);
        }
        
        vi cycle = allencountered;

        if (cycle.size() == 1){
            ans[cycle[0]] = alltraversed[cycle[0]].size();
            continue;
        }

        // for (auto &i : cycle){
        //     cout << i << ' ';
        // }
        // cout << endl;
        
        // evaluate the first term
        uset<int> cum;
        for (auto &i : cycle) for (auto &j : alltraversed[i])
            cum.insert(j);

        for (auto &i : cycle){
            ans[i] = cum.size();
        }


    }

    FOR(i,1,n+1) cout << ans[i] << endl;
}

int main(){
    cin >> n >> k;
    swaps.resize(k);

    FOR(i,0,k){
        cin >> swaps[i].f >> swaps[i].s;
    }

    // naive();
    better();
    
}