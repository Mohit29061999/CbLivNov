//problem link:https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1#

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

vector <int> verticalOrder(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
          
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;
        
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}


int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        // string c;
        // getline(cin,c);
    	Node* root = buildTree(s);
    	
    	vector <int> res = verticalOrder(root);
    	for (int i : res) cout << i << " ";
        cout << endl;
    }
	return 0;
}


// } Driver Code Ends


/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// root: root node of the tree
vector<int> verticalOrder(Node *root)
{   map<int,vector<int>>m;  //to store horizontal dist and node for that hd
    queue<pair<Node*,int>>q;  //to store node and horizontal distance
    
    //do level order traversal
    q.push({root,0});
    
    while(!q.empty()){
        pair<Node*,int>p=q.front();
        q.pop();
         int hd =p.second;
         Node* n = p.first;
        //add this hd and node in map
        if(m.find(hd)==m.end()){
            vector<int>v;
            m[hd]=v;
        }
        m[hd].push_back(n->data);
        
        //insert left
        if(n->left){
            q.push({n->left,hd-1});
        }
        
         //insert left
        if(n->right){
            q.push({n->right,hd+1});
        }
    }
    
    vector<int>ans;
    
    for(auto it=m.begin();it!=m.end();it++){
        //print nodes in this hd
        vector<int>v;
        v=it->second;
        for(int i=0;i<v.size();i++)
        ans.push_back(v[i]);
    }
    
    return ans;
    
    
    
}

