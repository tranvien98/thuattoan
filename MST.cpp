#include<bits/stdc++.h>
using namespace std;
const int nmax = 100011;

struct DisjointSet{
    vector<int> lab;

    DisjointSet(int n){
        lab.resize(n+1, -1);
    }

    int root(int x){
        if (lab[x]==-1) return x;
        return lab[x] = root(lab[x]);
    }

    bool Union(int x,int y){
        x = root(x), y = root(y);
        if (x==y) return false;
        lab[x] = y;
        return true;
    }

};

main(){
    int n, m;
    cin>>n>>m;
    vector<pair<int,pair<int,int> > > E(m);
    for(auto &e:E){
        int x,y,k;
        cin>>x>>y>>k;
        if (x>y) swap(x,y);
        e = make_pair(k, make_pair(x,y));
    }
    sort(E.begin(), E.end());
    DisjointSet T(n);
    vector<pair<int,int>> ans;
    long long sum = 0;
    for(auto &e:E){
        int x = e.second.first;
        int y = e.second.second;
        if (T.Union(x,y)){
            ans.push_back({x,y});
            sum += e.first;
        }
    }
    sort(ans.begin(), ans.end());
    cout<<sum<<endl;
    for(auto &e:ans) cout<<e.first<<" "<<e.second<<" ";
}
