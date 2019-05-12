#include<bits/stdc++.h>
/*4 6
2 1 3
2 3 1
3 1 10
4 1 5
3 4 5
4 2 6*/

#define maxx 1000+1
using namespace std;
// cau truc mot canh cua cay
struct Edge{
    int u,v,c;
};
struct Node{
    int u,v;
};
Edge edge[maxx];

int n,m;
int parent[maxx];
int rankk[maxx];
int W = 0;
int dem = 0;
Node node[maxx];
// ham tim nut cha
void make_set(int x){
    parent[x] = x;
    rankk[x] = 0;
}
int find_set(int x){
    if(x!=parent[x]){
        parent[x] = find_set(parent[x]);
    }
    return parent[x];
}
// ham noi 2 dinh
void link(int x, int y){
    if(rankk[x] == rankk[y]){
        rankk[x] = rankk[x] + 1;
    }
    if(rankk[x] > rankk[y])
    {
        parent[y] = x;
    }
    else
    {
        parent[x] = y;
    }

}

void Union(int u, int v){
   link(find_set(u), find_set(v));
}
void Sort(){
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(edge[i].c > edge[j].c){
                Edge tmp = edge[i];
                edge[i] = edge[j];
                edge[j] = tmp;
            }
        }
    }
}
void Sort_node(){
    for(int i=0;i<dem;i++){
        for(int j=i;j<dem;j++){
            if(node[i].u > node[j].u){
                Node tmp = node[i];
                node[i] = node[j];
                node[j] = tmp;
            }
            if(node[i].u == node[j].u){
                if(node[i].v > node[j].v){
                    Node tmp = node[i];
                    node[i] = node[j];
                    node[j] = tmp;
                }
            }
        }
    }
}
void xuat(){
        for(int i=0;i<m;i++){
            cout << edge[i].u << " "<< edge[i].v <<" "<< edge[i].c << endl;
        }
    }
void find_MST(){
    // cac dinh cha
    for(int i=0;i<n;i++){
        make_set(i);
    }
    Sort();

    for(int i=0;i<m;i++){

        int a = find_set(edge[i].u);
        int b = find_set(edge[i].v);

        if(a!=b){
            int x = edge[i].u;
            int y = edge[i].v;
            W+=edge[i].c;
            if(edge[i].u > edge[i].v){
                node[dem].u = edge[i].v;
                node[dem].v = edge[i].u;
                dem++;
            }
            else
            {
                node[dem].u = edge[i].u;
                node[dem].v = edge[i].v;
                dem++;
            }
            Union(edge[i].u,edge[i].v);
        }

    }
    cout << W << endl;
}
int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> edge[i].u >> edge[i].v >> edge[i].c;
    }
    find_MST();
    Sort_node();
    for(int i=0;i<dem;i++){
        cout << node[i].u << " " << node[i].v << " ";
    }

    return 0;

}


