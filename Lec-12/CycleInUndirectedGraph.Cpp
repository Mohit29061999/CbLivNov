// Question link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    //true means there is cycle else not
    bool dfs(int i,vector<int> v[],int par,bool vis[]){ //i is node where we are currently
        vis[i]=true; //current node is visited
        
        //visit its adjacent node
        int z=v[i].size();
        for(int j=0;j<z;j++){
            if(vis[v[i][j]]==false){
                //visit that adjacent node
                if(dfs(v[i][j],v,i,vis)==true){
                    return true;
                }
            }
            else{
                //it is already visited
                if(par!=v[i][j]){
                    return true; //there is a cycle
                }
            }
        }
        
        return false; //no cycle
    }
public:
	bool isCycle(int V, vector<int> adj[]){
	   bool vis[V]={false}; //to keep track which nodes are visited
	   
	   for(int i=0;i<V;i++){
	       if(vis[i]==false){
	           if(dfs(i,adj,-1,vis)==true)
	           return true;
	       }
	   }
	   
	   return false;
	   
	   
	   
	   
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends