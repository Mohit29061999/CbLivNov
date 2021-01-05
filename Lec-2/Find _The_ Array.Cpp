#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long 




void solve(){
   int n;
    cin>>n;
    

   
    
   int a[n];
    for(int i=0;i<n;i++){
    cin>>a[i]; 
    
    }
    
 
 
    int e=0;
    int o=0;
  for(int i=0;i<n;i++){
      if(i%2==0)
      e+=a[i];
      else
      o+=a[i];
            
  }
  
  if(e>o){
     for(int i=0;i<n;i++){
        if(i%2==0)
        cout << a[i] << " ";
        else
        cout << 1 << " ";
     }
  }
  else{
       for(int i=0;i<n;i++){
        if(i%2==1)
        cout << a[i] << " ";
        else
        cout << 1 << " ";
     }
  }
   cout << endl;
    
    
    
        
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    while(t){
        t--;
     solve();
     
    }
    
    
}