#include<bits/stdc++.h>
using namespace std;
void ckn(int k, int n){
    int a[n+1][n+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            a[i][j] = 0;
        }
    }
 for(int i=0;i<=n;i++){
    a[0][i] = 1 ;
    for(int j=1;j<=i;j++){
        a[j][i] = (a[j-1][i-1]+a[j][i-1])%(1000000000+7);
    }
 }
 cout << a[k][n];
}

int main(){
    int n, k;
    cin >> k >> n;
    ckn(k,n);
    return 0;
}
