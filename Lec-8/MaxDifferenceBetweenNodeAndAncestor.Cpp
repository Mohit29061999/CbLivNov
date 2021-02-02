/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int abs(int a,int b){
    if(b>=a)
        return b-a;
    return a-b;
}
void max_diff(TreeNode* root,int min_1,int max_1,int *res){
    if(root==NULL)
        return;
   
    *res = max(*res,(abs(max_1,root->val)));
    
     *res = max(*res,(abs(min_1,root->val)));
   
    max_diff(root->left,min(min_1,root->val),max(root->val,max_1),res);
       max_diff(root->right,min(min_1,root->val),max(max_1,root->val),res);
}
class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        int ans =0;
        int max_1 = root->val;
        int min_1 = root->val;
        max_diff(root,min_1,max_1,&ans);
            return ans;
    }
};