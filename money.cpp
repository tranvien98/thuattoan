#include<bits/stdc++.h>

using namespace std;

int countMoney(int money){
    int countm = 0;
     int a[] = {1,5,10,50,100,500};
    int k = 0;
    int i=0;

    while(money > 0){
        for(int i=5;i>=0;i--){
            if(a[i] <= money)
            {
                k = a[i];
                break;
            }
        }
        if( k !=0){
            money = money - k;
            countm++;
        }
    }
    return countm;
}
int main(){
    int money;

    cin >> money;
    cout << countMoney(1000-money);
    return 0;
}
