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
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        
        stack<TreeNode*>s1,s2;
        //s1=min stack s2=max stack;
        TreeNode* c=root;
        
        //pushing value in min stack
        while(c!=NULL){
            s1.push(c);
            c=c->left;
        }
        
         c=root;
        
        //pushing value in min stack
        while(c!=NULL){
            s2.push(c);
            c=c->right;
        }
        
        while(!s1.empty() && s1.top()!=s2.top()){
            int val= (s1.top())->val + (s2.top())->val;
            if(val==k)
                return true;
            if(val>k){
                //change right pointer
                c=s2.top();
                s2.pop();
                 c=c->left;
                
                //insert next max;
                 while(c!=NULL){
            s2.push(c);
            c=c->right;
        }
            }
            else{
                  //change left pointer
                c=s1.top();
                s1.pop();
                 c=c->right;
                
                //insert next max;
                 while(c!=NULL){
            s1.push(c);
            c=c->left;
            }
                
                
                
                
                
                
            }
        }
        
        return  false;
    }
};