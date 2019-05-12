#include<bits/stdc++.h>
using namespace std;
int n, W;
int w[1001];
int v[1001];
int c[1001][1001];
void knapsac(){
    for(int i=0;i<=n;i++){
        c[i][0] = 0;
    }
    for(int i=0;i<=W;i++){
        c[0][i] = 0;
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(w[i] <= j)
                c[i][j] = max(c[i-1][j], v[i] + c[i-1][j-w[i]]);
            else{
                c[i][j] = c[i-1][j];
            }
        }
    }
    cout <<  c[n][W] << endl;;
}
int main(){
    cin >> n >> W;
    for(int i=0;i<n;i++){
        cin >> w[i] >> v[i];
    }
    knapsac();
    return 0;
}
