class cord{
    public:
    int x;
    int y;
 
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
         queue<pair<int,int>> q;
        //to store count of fresh orange
        int count = 0;
        
        //to get rotten orange on day 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i,j});
                }
                else if(grid[i][j] == 1)
                {
                    ++count;
                }
            }
        }
        //if there are no fresh orange;
        if(count == 0)
            return 0;
        
        //grid.size() means row
        int n = grid.size();
       // grid[0].size() means col
        int m = grid[0].size();
        //ans will store day
        int ans = 0;
        //queue is not empty then there is a rotten orange
        while(!q.empty())
        {   //to get to know about day
            int ssize = q.size();
            ++ans;
            for(int i=0;i<ssize;i++)
            {
                pair<int,int> top = q.front();
                q.pop();
                int x = top.first;
                int y = top.second;
                //lower neighbour
                if(x+1 < grid.size() && grid[x+1][y] == 1)
                {   //ek fresh orange rotten ho gya h
                    --count;
                    
                    //to not include
                    grid[x+1][y] = 2;
                    q.push({x+1,y});
                }
                
                //upper
                if(x-1>=0 && grid[x-1][y] == 1)
                {
                    --count;
                    grid[x-1][y] = 2;
                    q.push({x-1,y});
                }
                
                //right
                if(y+1< grid[0].size() && grid[x][y+1] == 1)
                {
                    --count;
                    grid[x][y+1] = 2;
                    q.push({x,y+1});
                }
                
                //left
                if(y-1>=0 && grid[x][y-1] == 1)
                {
                    --count;
                    grid[x][y-1] = 2;
                    q.push({x,y-1});
                }
            }
            
            if(count == 0)
                return ans;
        }
        
        
        
        return -1;
    }
};