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
    std::vector<int> leafs;
    int sumNumbers(TreeNode* root) {
        string rootVal = to_string(root->val);
        if (root->right != nullptr){
            string rightChild = to_string(root->right->val);
            root->right->val = stoi(rootVal+rightChild);
            traverseTree(root->right);
        }
        if (root->left != nullptr){
            string leftChild = to_string(root->left->val);
        
            root->left->val = stoi(rootVal+leftChild);
        
            traverseTree(root->left);
        }
        // traverseLefttree(root->left);
        if (root->right == nullptr && root->left ==nullptr){
            return root->val;
        }
        int sum = 0;
        for (int i = 0; i < leafs.size(); i++){
            cout << leafs[i] << endl;
            sum += leafs[i];
        }
        return sum;
    }
    void traverseTree(TreeNode* childNode){
        string root = to_string(childNode->val);
        if (childNode->right != nullptr){
            string rightChild = to_string(childNode->right->val);
            string newVal = root+rightChild;
            childNode->right->val = stoi(newVal);
        
            traverseTree(childNode->right);
        }
        if(childNode->left != nullptr){
            string leftChild = to_string(childNode->left->val);
            string newLeftval = root+leftChild;
            childNode->left->val = stoi(newLeftval);
        
            traverseTree(childNode->left);
        }
        if (childNode->left == nullptr && childNode->right == nullptr){
            leafs.push_back(childNode->val);
        }
    }
};