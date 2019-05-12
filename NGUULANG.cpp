#include<bits/stdc++.h>
#include<stack>
using namespace std;
#define MAX 100
#define MAXINT 999999
int A[MAX][MAX];
int parent[MAX];
int d[MAX];
int n,m;
int q[MAX];
stack <int> T;
void init(){
    d[0] = 0;
    parent[0] = 0;
    q[0] = 0;
    T.push(0);
    for(int i=1;i<n;i++){
        if(A[0][i] > 0){
            d[i] = A[0][i];
        }
        else {
            d[i] = MAXINT;
        }
        parent[i] = 0;
        q[i] = 1;
    }
}
int emty(){
    for(int i=0;i<n;i++){
        if(q[i] > 0){
            return false;
      }
    }
    return true;
}
int minn;
int index;
int timduong(){
    while(!emty()){

        int u = T.top();
        minn = MAXINT;
        for(int i=0;i<n;i++){
            if(A[u][i] > 0 && i!=u && A[u][i] < minn){
                minn = A[u][i];
                index = i;
            }

        }
        q[index] = 0;
        T.push(index);
        for(int i=0;i<n;i++){
            if(q[i]!=0){
                if(d[i] > d[u] + A[u][i]){
                    d[i] = d[u] + A[u][i];
                    parent[i] = u;
                    if(i==n-1){
                        cout <<d[n-1];
                        retu;
                    }
                }
            }
        }

    }

}
int main(){



    freopen("test.txt","r",stdin);
    cin >> n >>m;
    int a,b,t;
        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            A[i][j] = MAXINT;
        }
    }
    for(int i=0;i<m;i++){
        cin >> a >> b;
        a--;
        b--;
        cin >> t;
        A[a][b] = t;
        A[b][a] = t;
    }
    init();
    timduong();
    return 0;
}

