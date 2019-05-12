#include<bits/stdc++.h>
using namespace std;
void nextStringChild(int k,int d,char str[],int n,int i,int &count,int dem){

	if(k+1==n ){
		count++;

		if(count==dem){
		str[n] = '\0';
		for(int t=0;t<n-1;t++){
            cout<< str[t] << " ";
		}
		 cout<< str[n-1]<<"\n";
		}
		return ;
	}
	// neu d so khong lien tiep nho hon i-1
	if(d<i-1){

		str[k+1] = '0';
		nextStringChild(k+1,d+1,str,n,i,count,dem);
		str[k+1] = '1';
			nextStringChild(k+1,0,str,n,i,count,dem);
	}
	// neu d so khong lien tiep bang i-1
	if(d==i-1){
		if(str[k]=='0'){
			str[k+1]='1';
				nextStringChild(k+1,0,str,n,i,count,dem);
		}
		if(str[k]=='1'){
			str[k+1] = '0';
			nextStringChild(k+1,1,str,n,i,count,dem);
			str[k+1] = '1';
			nextStringChild(k+1,0,str,n,i,count,dem);
		}

	}

	}
void binaryList(int n,int i,int k){
	if(n<0)
	return;
	if(i<2){

	cout << -1;
	return;
	}
	int count = 0;
	char str[n];
	str[0] = '0';
	nextStringChild(0,1,str,n,i,count,k);
	str[0] = '1';
	nextStringChild(0,0,str,n,i,count,k);
	if(count < k)
	{
		cout << -1;
		return ;
	}
}
int main(){
	int n,k,i;
	cin >> n >> k >> i;
	binaryList(n,i,k);
	return 0;

}

