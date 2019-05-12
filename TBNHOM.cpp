// bai tbnhom kiem tra
#include<bits/stdc++.h>
#define MAX 10000
using namespace std;
long n;
float B;
long s[MAX];
long a[MAX];
int dem = 0;
void init(){
    for(int i=0;i<=n;i++){
        s[i] = 0;
    }
}
int dodai(int k){
    for(int i=1;i<=k;i++){
        s[1] += a[i];
    }
    if((float)(2*s[1])/(k*k+k) == B)
        return k;
    for(int i=1;i<=n-k;i++){
        s[i+1] = s[i] - a[i] + a[i+k];
        if((float)(2*s[i+1])/(k*k+2*i*k+k)== B){
            return k;
        }
    }
    return 0;
}
int main(){
   // freopen("test.txt","r",stdin);
    cin  >> n >> B;
    init();
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    for(int j=n;j>=1;j--){
         //   cout << k;
            init();
            if(dodai(j)!= 0){
                cout << j;
                dem = 1;
                break;
            }


    }
    if(dem == 0){
         cout << -1;
    }

    return 0;
}

