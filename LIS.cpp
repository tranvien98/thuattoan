#include<bits/stdc++.h>
using namespace std;
int a[100000+9];
int b[100000+9];
int n;
void LIS(){
    int res = 1;
    for(int i=0;i<=n;i++){
        b[i] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            if(a[j-1] <= a[i-1]){
                b[i] = max(b[i],b[j]+1);
            }
        }
        res = max(res,b[i]);
    }
    cout << res << endl;
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    LIS();
    return 0;
}
