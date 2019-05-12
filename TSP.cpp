#include<bits/stdc++.h>
using namespace std;
#define MAXC 10000
int C[MAXC][MAXC];
int n,m;
int cmin = -999999;
int T = 0;
int visited[MAXC];
int best = MAXC;
int X[MAXC];
int ze;
int tim(int i){

    for(int j=2;j<=n;j++){

        if(visited[j] == 0){
            X[i] = j;
            T = T + C[X[i-1]][X[i]];
            visited[j] = 1;
            if(i == n){

                if(T + C[X[i]][1] < best){
                    best = T+ C[X[i]][1];
                }
            }
            else {
                ze = T + (n-i+1)*cmin;
                if(ze < best){
                    tim(i+1);
                }
            }
            T = T - C[X[i-1]][X[i]];
            visited[j] = 0;
        }
    }
}
int main(){
    int row,col;
    cin >> n >> m;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            C[i][j] = MAXC;
        }
    }
    for(int i=0;i<=n;i++){
        visited[i] = 0;

    }
    for(int i=0;i<=n;i++){
        C[i][i] = 0;
    }
    for(int i = 0; i < m ;i++){
        cin >> row >> col;
        cin >> C[row][col];
        if(cmin > C[row][col])
        {
            cmin = C[row][col];
        }
    }
    ze = n*cmin;
    X[1]=1;
    tim(2);
    cout << best;
return 0;}
