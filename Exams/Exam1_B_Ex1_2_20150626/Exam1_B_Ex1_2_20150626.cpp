//author: @kaspiotr (Piotr Kasprzyk)

/*
Egzamin, 1, 26.06.2015, gr. B
Zad.1.2 [4 pkt]
Drzewo BST jest opisane przez strukturę struct BST{BST *left, *right; int value};
Proszę zaimplementować funkcję double average(BST *T), która oblicza średnią wartość
elementów w drzewie T.
 */

#include <iostream>

using namespace std;

struct BST{
    int value;
    BST *left, *right;
};

int sumOfNodes(BST *root, int &noOfNodes){
    if(root == NULL) return 0;
    noOfNodes++;
    int sumLeft = sumOfNodes(root->left, noOfNodes);
    int sumRight = sumOfNodes(root->right, noOfNodes);

    return root->value + sumLeft + sumRight;
}

//time complexity: O(n), because we need to visit all BST tree nodes
double average(BST *T) {
    if(T == NULL) return 0.0;
    int noOfNodes = 0;
    int sum = sumOfNodes(T, noOfNodes);
    return (double)(sum)/(double)(noOfNodes);
}

int main() {

    /*
     *                        root
     *            rLeft                 rRight
     *        null     node1        node2     node3
     *               null null    null null  null null
     */


    //sample tree implementation
    BST *root = new BST;
    BST *rLeft = new BST;
    BST *rRight = new BST;
    BST *node1 = new BST;
    BST *node2 = new BST;
    BST *node3 = new BST;

    root->value = 10;
    root->left = rLeft;
    root->right = rRight;

    rLeft->value = 16;
    rLeft->left = NULL;
    rLeft->right = node1;

    node1->value = -3;
    node1->left = node1->right = NULL;

    rRight->value = 5;
    rRight->left = node2;
    rRight->right = node3;

    node2->value = 6;
    node2->left = node2->right = NULL;

    node3->value = 11;
    node3->left = node3->right = NULL;

    cout<<average(root)<<endl;

    return 0;
}