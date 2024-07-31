#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *insertBST(TreeNode *root, int val) {
    if(root == NULL) {
        return new TreeNode(val);
    }

    if(val < root->val) {
        root->left = insertBST(root->left, val);
    } else {
        root->right = insertBST(root->right, val);
    }
    return root;
}

void printInorder(TreeNode *root) {
    if(root == NULL) {
        return;
    }

    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int32_t main() {
    TreeNode *root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);

    printInorder(root);

    return 0;
}
