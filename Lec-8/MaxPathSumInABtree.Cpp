/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


int maxSumPathNode2Node(TreeNode* root,int &res){
    if(root==NULL){
        return 0;
    }
    int left=maxSumPathNode2Node(root->left,res);
    int right=maxSumPathNode2Node(root->right,res);
    int case1=root->val;
    int case2=root->val+left;
    int case3=root->val+right;
    int case4=root->val+left+right;
    res=max(case1,max(case2,max(case3,max(case4,res))));
    return max(left,max(right,0))+root->val;
}
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        maxSumPathNode2Node(root,res);
        return res;
        
    }
};