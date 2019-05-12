#include<bits/stdc++.h>
using namespace std;
int n;
int coun = 0;
int K1,K2;
void nurse(int k,int dem, char str[]){

    if(k == n )
    {
        str[k] = '\0';
        if(dem == 0 || dem >= K1){

        coun++;
        }
        return;
    }
    if(dem<=K1){

        str[k] = '1';
        dem ++;
        nurse(k+1,dem,str);
    }
     if(dem>K1 && dem < K2){

        str[k] = '1';
        dem ++;
        nurse(k+1,dem,str);
        str[k] = '0';
        nurse(k+1,0,str);
    }

    if(dem==K2){

        str[k] = '0';
          nurse(k+1,0,str);
    }
}
int main(){

    cin >> n >> K1 >> K2;
    if(n < K1){
        cout << "1";
        return 0;
    }
    char str[n+1];
    str[0] = '0';
    nurse(1,0,str);
    str[0] = '1';
    nurse(1,1,str);
    cout << coun;
    return 0;
}
