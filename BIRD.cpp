#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n;
    int index;
    m = n;
    int a[n+1];
    a[n] = -1;
    int solon = -1;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i] < 0){
            return 0;
        }
    }
    int sum = 0;

    while(m>=0){
        solon = -1;

        for(int i=m-1;i>=0;i--)
        {
            if(solon <= a[i]){
            solon = a[i];
            index = i;
            }
        }

        if(m == 1){
            sum += a[0];
            cout << sum;
            return 0;
        }
        if(index == 0){
            sum = sum + a[0] + a[1];
            for(int j=0;j<m;j++){
                a[j] = a[j+1];
            }
        }
        if(index == m-1){
            sum = sum + a[m-1] + a[m-2];
        }
        if(index != 0 && index != m-1){
            sum = sum + a[index] + a[index-1] + a[index+1] ;
             for(int j=index;j<m;j++){
                a[j] = a[j+1];
            }
        }
        m = m-1;
    }
    return 0;

}
