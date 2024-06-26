#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void sumReplacement(TreeNode *root) {
    if(root == NULL) {
        return;
    }
    
    sumReplacement(root->left);
    sumReplacement(root->right);

    if(root->left != NULL) {
        root->val += root->left->val;
    }

    if(root->right != NULL) {
        root->val += root->right->val;
    }

}


void Printpreorder(TreeNode *root) {
    if(root == NULL) {
        return;
    }

    cout << root->val << " ";

    Printpreorder(root->left);
    Printpreorder(root->right);
}


/*
     1
    / \
   2   3
  / \ / \ 
 4  5 6  7

*/

// after replacement it should be

/*
     28
    / \
   11   16
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

    Printpreorder(root);
    cout << endl;
    sumReplacement(root); // time complexity O(n)
    Printpreorder(root);
    
    return 0;
}
