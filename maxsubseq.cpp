#include<bits/stdc++.h>
using namespace std;
int n, L1, L2;
int a[10000];
int t[10000];
void init(){
    for(int i=0;i<n;i++){
        t[i] = 0;
    }
}
int maxsub(int k){
    for(int i=0;i<k;i++){
        t[0] += a[i];
    }
    for (int i=0;i<n-k;i++){
        t[i+1] = t[i] - a[i] + a[i+k];
    }
    int maxx = t[0];
    for(int i=1;i<n-k+1;i++){
        if(maxx < t[i]){
            maxx = t[i];
        }
    }
    return maxx;
}

int main(){
    cin >> n >> L1 >> L2;
    int res[L2-L1+1];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=L1;i<=L2;i++){
        init();
        res[i-L1] = maxsub(i);
    }
    int maxx = res[0];
    for(int i=0;i<=L2-L1;i++){
            if(maxx < res[i]){
                maxx = res[i];
            }
    }
    cout << maxx;
    return 0;
}
