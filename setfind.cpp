#include <bits/stdc++.h>

template <class T>
class setfind {
private:
    long long _size = 0;
    unordered_map<T,bool> _set;

public:
    // constructors
    setfind(){}
    // initialize from some iterable
    template<class InputIterator>
    setfind(InputIterator beg, InputIterator en){

        _size = en-beg;
        while (beg != en){
            _set[*beg] = true;
            beg++;
        }
    }
    //initliaze from antother findset
    setfind(setfind &cpy) : _set(cpy.getset()){}

    // getters
    unordered_map<T,bool> getset(){
        return _set;
    }

    long long size(){
        return _size;
    }

    // member funcs
    auto begin() -> decltype(_set.begin())
    {
        return _set.begin();
    }
    
    auto end() -> decltype(_set.end()){
        return _set.end();
    }

    auto find(const T &val) -> decltype(_set.begin()){
        return _set.find(val);
    }
    auto find(const T &&val) -> decltype(_set.begin())
    {
        return _set.find(val);
    }

    bool contains(const T &val){
        return _set[val];
    }
    bool contains(const T &&val){
        return _set[val];
    }

    void insert(const T &val){
        _set[val] = true;
        _size++;
    }
    void insert(const T &&val){
        _set[val] = true;
        _size++;
    }

    void erase(const T &val){
        _set[val] = false;
        _size--;
    }
    void erase(const T &&val){
        _set[val] = false;
        _size--;
    }
    

};

int main(){
    setfind<int> test;
    unordered_set<int> t2;

    for (long long i=0;i<1000000;i++){
        test.insert(i);
        // t2.insert(i);
    }

    for (long long i=0;i<1000000;i++){
        test.find(i);
        // t2.find(i);
    }
}

ll dfs(ll node){
    stack<ll> stk;
    stk.push(node);
    unordered_set<ll> visited;

    ll curr;
    while (stk.size()){ // while not empty
        curr = stk.top();
        visited.insert(curr);
        stk.pop();
        
        for (auto &e : edges[curr]){
            if (visited.find(e) == visited.end()) stk.push(e);
        }
    }

}
