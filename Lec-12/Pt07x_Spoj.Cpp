//problem link: https://www.spoj.com/problems/PT07X/

#include <bits/stdc++.h>
using namespace std;


int dp[100001][2];

void dfs(int i,vector<vector<int>>&v,int par){
	dp[i][0]=1;  //ith node included
	dp[i][1]=0;  //ith not included
	int z=v[i].size();
	for(int j=0;j<z;j++){
		 if(v[i][j]!=par){
		 	int y=v[i][j];
		 	dfs(y,v,i);
		 	dp[i][0]+=min(dp[y][0],dp[y][1]);
		 	dp[i][1]+=dp[y][0];
		 }
	}

}


int main(){
int n;
cin>>n;
vector<vector<int>>v;
for(int i=0;i<n;i++){
    vector<int>temp;
v.push_back(temp);
}

for(int i=0;i<n-1;i++){
	int x,y;
	cin>>x>>y;
	x--;
	y--;
	v[x].push_back(y);
	v[y].push_back(x);
}

dfs(0,v,-1);
cout << min(dp[0][0],dp[0][1]) << endl;

}
