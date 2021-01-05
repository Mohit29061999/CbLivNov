bool mycomp(int a1[],int a2[]){
    if(a1[0]==a2[0]){
        return a1[1] <=a2[1];
    }
    
    return a1[0] <=a2[0];
}


int Solution::maximumGap(const vector<int> &A) {
    int n=A.size();
   // int arr[n][2];
   // for(int i=0;i<n;i++){
   //     arr[i][0]=A[i];
   //     arr[i][1]=i;
   // }
   
   vector<vector<int>>v;
   for(int i=0;i<n;i++){
       vector<int>temp;
       v.push_back(temp);
   }
       for(int i=0;i<n;i++){
       v[i].push_back(A[i]);
       v[i].push_back(i);
    }
    
    sort(v.begin(),v.end());
  
    
    int max_i=v[n-1][1];
    int ans =0;
    for(int i=n-2;i>=0;i--){
        //treat current index as i
        //greater value to its right
       // cout << max_i << endl;
        ans =max(ans,max_i-v[i][1]);
        max_i=max(max_i,v[i][1]);
    }
    
    return ans;
    
    
}
