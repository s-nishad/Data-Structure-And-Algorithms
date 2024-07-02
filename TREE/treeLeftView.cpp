#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void printLeftView(TreeNode *root) {
    if(root == NULL) {
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        int n = q.size();

        for(int i = 1; i <= n; i++) {
            TreeNode* current = q.front();
            q.pop();

            if(i == 1) {
                cout << current->val << '\t';
            }

            if(current->left != NULL) {
                q.push(current->left);
            }
            if(root->right != NULL) {
                q.push(current->right);
            }
        }
    }


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

    printLeftView(root);   // time complexity O(n)
    
    return 0;
}
