#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* buildTreeHelper(vector<int>& preorder, int& preIndex, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& inorderMap) {
        if (preIndex >= preorder.size() || inStart > inEnd) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preIndex]);
        int inIndex = inorderMap[root->val];

        preIndex++;

        root->left = buildTreeHelper(preorder, preIndex, inorder, inStart, inIndex - 1, inorderMap);
        root->right = buildTreeHelper(preorder, preIndex, inorder, inIndex + 1, inEnd, inorderMap);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty() || preorder.size() != inorder.size()) {
            return nullptr;
        }

        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderMap[inorder[i]] = i;
        }

        int preIndex = 0;
        return buildTreeHelper(preorder, preIndex, inorder, 0, inorder.size() - 1, inorderMap);
    }

    void preorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        cout << root->val << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }

    void inorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        inorderTraversal(root->left);
        cout << root->val << " ";
        inorderTraversal(root->right);
    }

    void postorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->val << " ";
    }
};

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    BinaryTree tree;
    TreeNode* root = tree.buildTree(preorder, inorder);

    cout << "Preorder traversal: ";
    tree.preorderTraversal(root);
    cout << endl;

    cout << "Inorder traversal: ";
    tree.inorderTraversal(root);
    cout << endl;

    cout << "Postorder traversal: ";
    tree.postorderTraversal(root);
    cout << endl;

    return 0;
}
