#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k;
    int a,b;
    cin >> n >> m >> k;
    int arr[k];
    vector<int> adj[n];
    vector<int> index[n];
    for(int i=0;i<m;i++){
        cin >> a >> b;

        adj[a-1].push_back(b-1);
        index[b-1].push_back(a-1);

    }
    for(int i=0;i<k;i++){
        cin >> arr[i];
    }
    cout << n << " " << m << endl ;
    for(int i=0;i<n;i++){
        sort(adj[i].begin(), adj[i].end());
    }
     for(int i=0;i<n;i++){
        if(index[i].size()!=0){
             sort(index[i].begin(), index[i].end());
        }

    }
    int head[n];
    head[0] = 1;
    for(int i=1;i<n;i++){
        head[i] = head[i-1] + adj[i-1].size();
    }
    for(int i=0;i<n;i++){
        cout << head[i] << " ";
    }
    cout << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<adj[i].size();j++){
            cout << adj[i][j]+1 << " ";
        }
    }
    cout << endl;
      for(int i=0;i<k;i++){
      if(index[arr[i]-1].size() != 0)
      {
        for(int j=0;j<index[arr[i]-1].size() ;j++){

            cout << index[arr[i]-1][j]+1<< " ";
        }
        cout << endl;
      }
      else {
        cout << endl;
      }
      }



    return 0;
}
