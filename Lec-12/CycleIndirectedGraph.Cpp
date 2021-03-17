//problem link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1#


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    bool dfs(int i,vector<int> v[],bool vis[],bool callStack[]){
        vis[i]=true;  //it is visited now
        callStack[i]=true; //it is in dfs call
        
        //call all its adjacent node
        int z=v[i].size();
        for(int j=0;j<z;j++){
            int x=v[i][j]; //x is value of its current adjacent node
            if(vis[x]==false){
                if(dfs(x,v,vis,callStack)==true)
                return true;
            }
            else if(callStack[x]==true){
                return true;  //if x is already visited and it is in callstack
                //then there is cycle
            }
        }
        callStack[i]=false;  //ith node is no longer in call stack
        return false;
    }
public:
	bool isCyclic(int V, vector<int> adj[]) {
	   	// code here
	   	bool vis[V]={false};
	   	bool callStack[V]={false};
	   	
	   	for(int i=0;i<V;i++){
	   	    if(vis[i]==false){
	   	        if(dfs(i,adj,vis,callStack)==true)
	   	        return true;
	   	    }
	   	}
	   	
	   	return false;
	   	
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends



