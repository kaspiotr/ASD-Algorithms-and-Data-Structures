//author: @kaspiotr (Piotr Kasprzyk)

/*
 * There is given a binary tree (not binary search tree) and a sum. Write a function to check if there is a path
 * in that tree from root to leaf, that sum of nodes on this path is equal to the given sum.
 */

#include <iostream>
#include <vector>

using namespace std;

struct BTNode {
    int val;
    BTNode *left, *right;
};

void inOrder(BTNode *root) {
    if(root != NULL) {
        inOrder(root->left);
        cout<<root->val<<"\t";
        inOrder(root->right);
    }
}



bool rootToLeafSum(BTNode *root, int sum, vector <int> &result) {
    if(root == NULL) return false;

    if(root->left == NULL && root->right == NULL){
        if(root->val == sum) {
            result.push_back(root->val);
            return true;
        } else {
            return false;
        }
    }

    if(rootToLeafSum(root->left, sum-root->val, result)) {
        result.push_back(root->val);
        return true;
    }

    if(rootToLeafSum(root->right, sum -root->val, result)) {
        result.push_back(root->val);
        return true;
    }

    return false;
}

int main() {

    /*
     *                        root
     *            rLeft                 rRight
     *        null     node1        node2     node3
     *               null null    null null  null null
     */


    //sample tree implementation
    BTNode *root = new BTNode;
    BTNode *rLeft = new BTNode;
    BTNode *rRight = new BTNode;
    BTNode *node1 = new BTNode;
    BTNode *node2 = new BTNode;
    BTNode *node3 = new BTNode;

    root->val = 10;
    root->left = rLeft;
    root->right = rRight;

    rLeft->val = 16;
    rLeft->left = NULL;
    rLeft->right = node1;

    node1->val = -3;
    node1->left = node1->right = NULL;

    rRight->val = 5;
    rRight->left = node2;
    rRight->right = node3;

    node2->val = 6;
    node2->left = node2->right = NULL;

    node3->val = 11;
    node3->left = node3->right = NULL;

    inOrder(root);

    vector <int> result;

    rootToLeafSum(root, 26, result);
    cout<<endl;

    for(int i=0; i<result.size(); i++) cout<<result[i]<<"\t";
    cout<<endl;
    return 0;
}