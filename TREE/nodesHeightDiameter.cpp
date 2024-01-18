#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int countNodes(TreeNode *root) {
    if(!root) {
        return 0;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
}

int sumNodes(TreeNode  *root) {
    if(!root) {
        return 0;
    }

    return sumNodes(root->left) + sumNodes(root->right) + root->val;
}

int maximum_depth(TreeNode *root) {
    if(!root) {
        return 0;
    }
    int left_depth = maximum_depth(root->left);
    int right_depth = maximum_depth(root->right);

    return max(left_depth, right_depth) + 1;
}

int diameter(TreeNode *root) {
    if(!root) {
        return 0;
    }
    int left_depth = maximum_depth(root->left);
    int right_depth = maximum_depth(root->right);

    int currentDiameter = left_depth + right_depth + 1;

    int leftDiameter = diameter(root->left);
    int rightDiamter = diameter(root->right);

    return max(currentDiameter, max(leftDiameter, rightDiamter));
}

/*
     1
    / \
   2   3
  / \ / \ 
 4  5 6  7

*/

int main() {
    struct TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // total nodes
    cout << "Number of Nodes: " << countNodes(root) << endl;

    // sum of nodes
    cout << "Sum of all nodes: " << sumNodes(root) << endl;

    // height of tree
    cout << "The height of the tree is: " << maximum_depth(root) << endl;

    // diameter of tree
    cout << "Diameter is: " << diameter(root) << endl;
    
    return 0;
}
