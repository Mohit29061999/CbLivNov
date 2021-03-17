//problem link : https://leetcode.com/problems/course-schedule/


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>v; //2-d vector for adjacency list
        for(int i=0;i<numCourses;i++){
            vector<int>temp;
            v.push_back(temp);
        }
        int z=prerequisites.size();
        for(int i=0;i<z;i++){
            int x=prerequisites[i][0];
            int y=prerequisites[i][1];
            v[x].push_back(y);
        }
        int n=numCourses;
        
        int indeg[n]; //indegree[i]=number of edges so that ith node is at end of edge
        for(int i=0;i<n;i++)
            indeg[i]=0;
        for(int i=0;i<z;i++){
         //   int x=prerequisites[i][0];
            int y=prerequisites[i][1];
            indeg[y]++; 
        }
        int c=0;
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                c++;
                q.push(i); //indegree[i]=0 means i can be done without any prequesties
            }
        }
        
        while(!q.empty()){
            int x=q.front();
            q.pop();
            //we have done x
            int z=v[x].size();
            for(int j=0;j<z;j++){
                int y=v[x][j];
                indeg[y]--; //to do y x is neccessary and we have done x
                if(indeg[y]==0){
                    //then this course can be done
                    q.push(y);
                    c++;
                }
            }
        }
        
        if(c==n)
            return true;
        else
            return false;
        
        
        
        
        
        
        
        
        
        
    }
};