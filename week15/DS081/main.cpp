#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

TreeNode* buildTree(vector<int>& nums) {
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

void inorderTraversal(TreeNode* root, vector<int>& result) {
    if (!root) return;
    inorderTraversal(root->left, result);
    result.push_back(root->val);
    inorderTraversal(root->right, result);
}

int main() {
    int size;
    cout << "Enter the number of nodes: ";
    cin >> size;

    vector<int> nums(size);
    cout << "Enter the node values in order: ";
    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }

    TreeNode* root = buildTree(nums);
    vector<int> inorderResult;
    inorderTraversal(root, inorderResult);

    cout << "Inorder traversal: ";
    for (vector<int>::iterator it = inorderResult.begin(); it != inorderResult.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << " Inorder traversal:";
    for(vector<int>::iterator it )

    return 0;
}
