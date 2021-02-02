/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<int>v;
void printAsRoot(TreeNode* root,int k){
    if(root==NULL || k<0)
        return;
    if(k==0){
        v.push_back(root->val);
      //  return;
    }
    
    printAsRoot(root->left,k-1);
     printAsRoot(root->right,k-1);
    
}

int printAll(TreeNode* root,int k,TreeNode* t){
    //base case
    if(root==NULL)
        return -1;
    
    if(root==t){
        printAsRoot(root,k);
        return 0;
    }
    
    //target node se root->left ka distance
    int l=printAll(root->left,k,t);
    //l==-1 means left me exist nhi karta target node
    if(l!=-1){
        if(l+1==k){
            v.push_back(root->val);
            return l+1;
        }
        //call right
        printAsRoot(root->right,k-l-1-1);
        return l+1;
        
    }
    //else check if node  lie in right
    int r=printAll(root->right,k,t);
    if(r!=-1){
             if(r+1==k){
            v.push_back(root->val);
            return r+1;
        }
        //call right
        printAsRoot(root->left,k-r-2);
        return r+1;
    }
    return -1;
}

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        v.clear();
        printAll(root,K,target);
        return v;
    }
};