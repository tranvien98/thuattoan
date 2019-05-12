#include <bits/stdc++.h>

using namespace std;

int n, m, i, j;
vector <int> adj[100001];
vector <int> adj1[100001];
vector<bool> visited(100001, false);

vector <int> component(100001, -1);
vector <int> parent(100001, -1);
vector <int> d(100001, 0); // độ sâu


void init(){

    for ( int x = 1; x <= n; x++){
        visited[x] = false;
        parent[x] = -1;
        d[x] = 0;
    }


}

int components = 0;
queue <int> Q;

void BFS(int start){

    Q.push(start);
    visited[start] = true;

    while(!Q.empty()){

        int u = Q.front();
        Q.pop();

        for ( int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i];

            if(!visited[u]){
                Q.push(v);
                visited[v] = true;
            }
        }
    }
}

void dfs(int u){

    // if u đã được duyệt : dừng lại

    if( visited[u]){
        return;
    }

    // Nếu u chưa được duyệt
    visited[u] = true;

    // Xét tất cả các đỉnh kề với u
    for ( int i = 0; i < adj1[u].size(); i++){
        int v = adj1[u][i];
        dfs(v);
    }

}

int min_path( int i, int j){

    init();
    //cout << "khoi tao " << endl;

    Q.push(i);
    visited[i] = true;
    //cout << i << endl;


    while(!Q.empty()){

        int u = Q.front();
        Q.pop();
        //cout << u << endl;

        for ( int i = 0; i < adj[u].size(); i++){

            int v = adj[u][i];

            if(!visited[v]){

                d[v] = d[u] + 1;
                parent[v] = u;
                visited[v] = true;
                Q.push(v);
            }
            if( v == j)
                break;
        }
    }

    if(visited[j] == false){
        return 0;
    }else{
        return d[j] + 1;
    }

}

void tudien( int u){

    if( visited[u]){
        return;
    }
    else{
        visited[u] = true;
        //cout << visited[u] << endl;

        // Xét tất cả các đỉnh kề với u
        for ( int x = 0; x < adj[u].size(); x++){
            int v = adj[u][x];
            if(visited[v])
                continue;

            d[v] = d[u] + 1;
            parent[v] = u;

            tudien(v);
        }
    }
}

void induongdi(){
    init();
    tudien(i);
    if (d[j] == 0){
        cout << 0;
        return;
    }

    cout << d[j] + 1 << endl;

    stack<int> S;
    int x = j;
    while(x != i){
        S.push(x);
        x = parent[x];
    }

    cout << i << " ";
    while(!S.empty()){
        x = S.top(); S.pop();
        cout << x << " ";
    }

}

void countComponents(){

    init();
    for ( int u = 1; u <= n; u++){

        if(visited[u] == false){
            dfs(u);
            components++;
        }
    }
}





int main(){
    freopen("test.txt","r",stdin);
    cin >> n  >> m;

    for (int x = 1; x <= m; x++){
        int u1, v1;
        cin >> u1 >> v1;
        adj[u1].push_back(v1);
        adj1[u1].push_back(v1);
        adj1[v1].push_back(u1);
    }

    cin >> i >> j;

    countComponents();

    cout << components << endl;

    cout << min_path(i, j) << endl;

    for ( int  x = 1; x <= n; x++){
        sort(adj[x].begin(), adj[x].end());
    }

    induongdi();

    return 0;
}
