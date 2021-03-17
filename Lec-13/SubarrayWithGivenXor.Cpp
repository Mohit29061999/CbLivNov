//problem link: https://www.interviewbit.com/problems/subarray-with-given-xor/

int Solution::solve(vector<int> &A, int B) {
    int ans =0;
    int n=A.size();
    map<int,int>m;  //freq of a particular
    int x=0;   //cumulative xor
    for(int i=0;i<n;i++){
        x=x^A[i];
        if(x==B)
        ans++;
        int z=x^B;
        if(m.find(z)!=m.end())
        ans+=(m[z]);
        m[x]++;
    }
    return ans;
}
