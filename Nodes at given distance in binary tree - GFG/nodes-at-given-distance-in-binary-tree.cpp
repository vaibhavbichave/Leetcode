//{ Driver Code Starts
#include<bits/stdc++.h>
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


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:

public:

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        vector<int> ans;
        unordered_map<Node*, int> nodeToDist;  // {node: distance to target}
    
        getDists(root, target, nodeToDist);
        dfs(root, k, 0, nodeToDist, ans);
        sort(begin(ans),end(ans));
        return ans;
    }

 private:
  void getDists(Node* root, int target,
                unordered_map<Node*, int>& nodeToDist) {
    if (root == nullptr) return;
    if (root->data == target) {
        nodeToDist[root] = 0;
        return;
    }
    
    getDists(root->left, target, nodeToDist);
    if ( nodeToDist.find(root->left) != nodeToDist.cend()) {
        // The target is in the left subtree
        nodeToDist[root] = nodeToDist[root->left] + 1;
        return;
    }
    
    getDists(root->right, target, nodeToDist);
    
    if (nodeToDist.find(root->right) != nodeToDist.cend())
        // The target is in the right subtree
        nodeToDist[root] = nodeToDist[root->right] + 1;
  }

  void dfs(Node* root, int k, int dist,
           unordered_map<Node*, int>& nodeToDist, vector<int>& ans) {
        if (root == nullptr) return;
        if (nodeToDist.find(root) != nodeToDist.cend()) dist = nodeToDist[root];
        if (dist == k) ans.push_back(root->data);
        dfs(root->left, k, dist + 1, nodeToDist, ans);
        dfs(root->right, k, dist + 1, nodeToDist, ans);
  }

};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends