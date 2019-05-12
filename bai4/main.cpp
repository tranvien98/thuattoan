#include<bits/stdc++.h>
// sap xep 
using namespace std;
const long N = 1000000 + 10;

int n;
double a[N];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a+1,a+n+1);

    for (int i = 1; i <= n; i++)
        printf("%0.2f ",a[i]);
}
