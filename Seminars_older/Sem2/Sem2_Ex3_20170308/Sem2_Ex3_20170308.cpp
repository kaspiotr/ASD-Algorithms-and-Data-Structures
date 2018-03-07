
struct Node{
    int value;
    Node *next;
};



void print_l(Node* l){
    while(l){
        cout << l->value << " ";
        l=l->next;
    }
    cout << endl;
}
Node *mergeTwoLists(Node* &l1, Node* &l2) {
    Node *head = new Node;
    Node *p = head;

    Node *p1=l1;
    Node *p2=l2;
    while(p1!=NULL && p2!=NULL){
        if(p1->value < p2->value){
            p->next = p1;
            p1 = p1->next;
        }else{
            p->next = p2;
            p2 = p2->next;
        }
        p=p->next;
    }

    if(p1!=NULL){ //wersja bez wartownika, bo tutaj sie nie da
        p->next = p1;
    }

    if(p2!=NULL){
        p->next = p2;
    }

    return head;

}

Node *mergeTwoLists2(Node * &p,Node* &l1, Node* &l2) {
    Node *head = new Node;
    p = head;

    Node *p1=l1;
    Node *p2=l2;
    while(p1!=NULL && p2!=NULL){
        if(p1->value < p2->value){
            p->next = p1;
            p1 = p1->next;
        }else{
            p->next = p2;
            p2 = p2->next;
        }
        p=p->next;

    }

    if(p1!=NULL){ //wersja bez wartownika, bo tutaj sie nie da
        p->next = p1;
    }
    if(p2!=NULL){
        p->next = p2;
    }
    while(p->next!=NULL) p=p->next; //aby móc zwrócić koniec listy, bo jeżeli przepinamy końcówkę jednej listy to nie przechodzimy wskaźnikiem do końca
    return head->next;
}
