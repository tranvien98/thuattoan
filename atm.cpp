#include<bits/stdc++.h>

using namespace std;
int to = 0;
int cach = 1;

long a[20] = {0};
void donvi(int n, int &to, int &cach){

  switch(n){
    case 1:
    case 3:
    case 2:
    case 5:
        to+=1;
        break;
    case 4:
    case 6:
        to+=2;
        cach*=2;
        break;
    case 7:
    case 8:
        to+=2;
        break;
    case 9:
        to+=3;
        cach*=3;
        break;
  }


}

void atm(long long money, int c){

    long long temp = money;
    int n = 1;
    int maxx = 0;
    if(n > c)
    {
        maxx = n;
    }
    else
        maxx = c;
    while(temp > 0){
        temp = temp /10;
        n++;
    }
    n--;

    for (int i=0;i<=maxx+1;i++){
        a[i] = 0;
    }
    int k = 1;
    temp = money;

    while(temp > 0){
        a[k] = temp%10;
        temp = temp / 10;
        k++;
    }

    for(int i=1; i<=c;i++){
        donvi(a[i],to,cach);
    }
    if(n==c+1){
        donvi(a[c+1],to,cach);
    }
    if(n > c+1 ){
        if(a[c+2] == 1 && a[c+1] == 1)
        {
            to+=3;
            cach*=2;
            int he = 1;
            int sum = 0;
            for(int i=c+3; i<=n;i++){
                sum += a[i]*he;
                he = he*10;
            }
            to+= sum*20;
        }
        else if(a[c+2] == 1 && a[c+1] == 4){
            to+=4;
            cach*=3;
            int he = 1;
            int sum = 0;
            for(int i=c+3; i<=n;i++){
                sum += a[i]*he;
                he = he*10;
            }
            to+= sum*20;
        }
        else {
            if(a[c+1] == 4){
                cach /=2;
                cach *= 3;
            }
            if(a[c+1] == 1)
            {
                cach *= 2;
            }
            donvi(a[c+1],to,cach);
            int he = 1;
            long sum = 0;
            for(int i=c+2; i<=n;i++){
                sum += a[i]*he;
                he = he*10;
            }
            to+= sum*2;
        }
    }
    cout << to << " " << cach << endl;
}
int main()
{

    int t;
    long long w;
    int c;
    int i=0;
    cin >> t;
    while(t>0)
    {
        cin >> w >> c;
          if(w %1000 == 0){
                long long y = (long long)(w/1000);
                 to = 0;
                cach =1;
                atm(y,c);
            }
            else {
                cout << 0 << endl;
            }
        t--;
    }




    return 0;
}
