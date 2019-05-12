#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000000];
int gold(int L1, int L2){
    int maxx = 0;
    int s[n+1];
    int m = L2 - L1 + 1;
    int tmp[m];
    for(int i=0;i<=n;i++){
        s[i] = 0;
    }
    for(int i=0;i<n;i++){
    if(i < L1){
        s[i] = a[i];

    }
    else {
    s[i] = s[i-L1] + a[i];
    for(int k = L1+1;k<=L2; k++){
            if(i-k>0){
                s[i] = max(s[i],s[i-k] + a[i]);
                }
            }
        }
    }
    for(int i=0;i<=n;i++){

        maxx = max(maxx,s[i]);
    }
    return maxx;
}
int main(){

    cin >> n;
    int L1,L2;
    cin >> L1 >> L2;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    cout << gold(L1,L2);
    return 0;
}
