/*
 * Egzamin 1 termin, gr. B, 2012/2013
 * Zad.2
 */
/*
 * Pomysl:
 * 1) przechodze pierwsze drzewo postOrder i zapisuje jego wartosci do listy jednokierunkowej
 * 2) przechodze drugi drzewo postOrder i zapisuje jego wartosci do kolejnej listy jednokierunkowej
 * 3) tworze tablice o rozmiarze rownym rozmiarowi dwoch utworzonych list
 */

#include <iostream>

using namespace std;

struct BSTNode {
    int val;
    BSTNode *left, *right;
};

struct Node {
    int val;
    Node *prev;
    Node *next;
};

void printList(Node *first) {
    while (first != NULL) {
        cout << first->val << "\t";
        first = first->next;
    }
    cout << endl;
}

void printPostOrder(BSTNode *root) {
    if (root != NULL) {
        printPostOrder(root->right);
        cout << root->val << "\t";
        printPostOrder(root->left);
    }
}

void createList(BSTNode *root, Node *&head, int &noOfEls) {
    if (root != NULL) {
        createList(root->right, head, noOfEls);
        Node *node = new Node;
        noOfEls++;
        node->val = root->val;
        node->next = head;
        head = node;
        createList(root->left, head, noOfEls);
    }
}

void medianOrder(int A[], int M[], int &idx, int l, int r, int n) {
    if( l > r) return;
    int mid = (l+r)/2;
    M[idx] = A[mid];
    idx++;

    medianOrder(A, M, idx, l, mid-1, n);
    medianOrder(A, M, idx, mid+1, r, n);
}

BSTNode *insert(BSTNode *root, int data) {
    BSTNode *node = new BSTNode;
    node->val = data;
    if (root == NULL) return node;
    BSTNode *parent = NULL, *curr = root;
    while (curr != NULL) {
        parent = curr;
        if (curr->val <= data) {
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }

    if (parent->val <= data) {
        parent->right = node;
    } else {
        parent->left = node;
    }

    return root;
}

BSTNode* intersection(BSTNode *T1, BSTNode *T2) {
    Node *head1 = NULL;
    int noOfEls1 = 0;
    createList(T1, head1, noOfEls1);

    Node *head2 = NULL;
    int noOfEls2 = 0;
    createList(T2, head2, noOfEls2);

    if (head1 == NULL || head2 == NULL) return NULL;

    int *inter = new int [noOfEls1];
    int idx = 0;

    while(head1 != NULL && head2 != NULL) {
        Node *prev = head1;
        while(head1 != NULL && head1->val < head2->val) {
            prev = head1;
            head1 = head1->next;
        }
        head1 = prev;

        prev = head2;
        while(head2 != NULL && head1->val > head2->val) {
            prev = head2;
            head2 = head2->next;
        }
        head2 = prev;

        if(head1->val == head2->val) {
            inter[idx] = head2->val;
            idx++;
        }
        head1->val <= head2->val ? head1 = head1->next : head2 = head2->next;
    }

    int *medians = new int[idx];

    int index=0;
    medianOrder(inter, medians, index, 0, idx-1, idx);

    BSTNode *root = NULL;
    for(int i=0; i<idx; i++) {
        root = insert(root, medians[i]);
    }

    return root;
}


int main() {

    /*
     *                                               root=10
     *                    node1=3                                                node2=15
     *           node3=2              node4=6                               null        node5=30
     *      null      null      node6=5     node7=9                                  null       null
     *                        null  null   node8=8  null
     *                                    null  null
     */

    //implementacja pierwszego drzewa

    BSTNode *root = new BSTNode;
    BSTNode *node1 = new BSTNode;
    BSTNode *node2 = new BSTNode;
    BSTNode *node3 = new BSTNode;
    BSTNode *node4 = new BSTNode;
    BSTNode *node5 = new BSTNode;
    BSTNode *node6 = new BSTNode;
    BSTNode *node7 = new BSTNode;
    BSTNode *node8 = new BSTNode;

    root->val = 10;
    root->left = node1;
    root->right = node2;

    node1->val = 3;
    node1->left = node3;
    node1->right = node4;

    node2->val = 15;
    node2->left = NULL;
    node2->right = node5;
    node5->left = node5->right = NULL;

    node3->val = 2;
    node3->left = node3->right = NULL;

    node4->val = 6;
    node4->left = node6;
    node4->right = node7;

    node5->val = 30;
    node5->left = node5->right = NULL;

    node6->val = 5;
    node6->left = node6->right = NULL;

    node7->val = 9;
    node7->left = node8;
    node7->right = NULL;

    node8->val = 8;
    node8->left = node8->right = NULL;

    /*
   *                                               root2=30
   *                    node21=15                                                  null
   *              node22=8      null
   *         node27=6      node23=11
   *              node24=9    node25=13
   *            null  null  node26=12  null
   *                       null  null
   */

    //implementacja drugiego drzewa
    BSTNode *root2 = new BSTNode;
    BSTNode *node21 = new BSTNode;
    BSTNode *node22 = new BSTNode;
    BSTNode *node23 = new BSTNode;
    BSTNode *node24 = new BSTNode;
    BSTNode *node25 = new BSTNode;
    BSTNode *node26 = new BSTNode;
    BSTNode *node27 = new BSTNode;


    root2->val = 30;
    root2->left = node21;
    root2->right = NULL;

    node21->val = 15;
    node21->left = node22;
    node21->right = NULL;

    node22->val = 8;
    node22->left = node27;
    node22->right = node23;

    node23->val = 11;
    node23->left = node24;
    node23->right = node25;

    node24->val = 9;
    node24->left = node24->right = NULL;

    node25->val = 13;
    node25->left = node26;
    node25->right = NULL;

    node26->val = 12;
    node26->left = node26->right = NULL;

    node27->val = 6;
    node27->left = node27->right = NULL;

    printPostOrder(root);
    cout << endl;

    printPostOrder(root2);
    cout << endl;

    Node *head1 = NULL;
    int noOfEls1 = 0;
    createList(root, head1, noOfEls1);
    printList(head1);
    cout << noOfEls1 << endl;

    Node *head2 = NULL;
    int noOfEls2 = 0;
    createList(root2, head2, noOfEls2);
    printList(head2);
    cout << noOfEls2 << endl;

    BSTNode *result = intersection(root, root2);
    printPostOrder(result);

    return 0;
}