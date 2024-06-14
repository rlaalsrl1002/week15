#include <iostream>
#include <queue>
#include <vector>
#include <sstream>

using namespace std;

class TreeNode {
public:    
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(const vector<int>& nums) {
    if (nums.empty() || nums[0] == 0) return NULL;

    TreeNode* root = new TreeNode(nums[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (i < nums.size()) {
        TreeNode* curr = q.front();
        q.pop();
        if (i < nums.size() && nums[i] != 0) {
            curr->left = new TreeNode(nums[i]);
            q.push(curr->left);
        }
        i++;
        if (i < nums.size() && nums[i] != 0) {
            curr->right = new TreeNode(nums[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

void preorderTraversal(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(TreeNode* root) {
    if (!root) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->val << " ";
}

int main() {
    while (true) {
        string input;
        getline(cin, input);
        
        stringstream ss(input);
        int nodeCount, traversalType;
        ss >> nodeCount;
        if (nodeCount == q) break;
        
        ss >> traversalType;
        
        vector<int> nodes(nodeCount);
        for (int i = 0; i < nodeCount; ++i) {
            cin >> nodes[i];
        }
        cin.ignore();
        
        TreeNode* root = buildTree(nodes);
        
        if (traversalType == 1) {
            preorderTraversal(root);
        } else if (traversalType == 2) {
            postorderTraversal(root);
        }
        
        cout << endl;
    }
    
    return 0;
}
