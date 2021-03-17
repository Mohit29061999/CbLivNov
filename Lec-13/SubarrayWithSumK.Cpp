//problem link: https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
       map<int,int>m;  
        int sum=0;
        int ans =0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==k)
                ans++;
            int y=sum-k;
            if(m.find(y)!=m.end())
                ans+=m[y];
            
            //insert this sum to map
            m[sum]++;
        }
        return ans;
    }
};