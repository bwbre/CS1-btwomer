/*

*/


#include <iostream>
#include <string>

using namespace std;
struct Node {
    int data;
    Node *next;

};

void lisize(int*);
Node* buildlist(int*, Node* );
void printlist(int&);
void deletelist(Node*);


int main(int argc, char* argv[]) {
    int *listsize = 0;
    //*head needs to be initialized.
    Node currnode;
    Node *head;
    Node **first;
    head = &currnode;
    first = &head;

    lisize(listsize);

    //pass the & because thats the value of 
    buildlist(listsize, head);
    
    deletelist(head);

//DOUBLE POINTER PTR** IS PASS BY REFERENCE FOR POINTERS.
    // Node *second = new Node();
    // Node *third = new Node();
    // first->data = 42;
    // first->next = second;
    // second->data = 15;
    // second->next = third;
    // third->data = 23;
    // third->next = NULL;
    // cout << "first->data: " << first->data << endl;
    // cout << "second->data: " << second->data << endl;
    // cout << "third->data: " << third->data << endl;
    // Node *currnode;
    // currnode = first;

    /*NOTE: use curnode, not curnode->next... next goes to final and checks next which returns null, thus wont print.*/
    while(currnode != NULL) {
        cout << "curnode->data: " << currnode->data << endl;
        currnode = currnode->next;

    }
    /*TO DELETE THE SELF GENERATED LINKED LIST*/
    delete first;
    // delete second;
    // delete third;

    return 0;
}

void printlist(Node *head) {
    while (head != NULL) {
        cout << "head->data: " << head->data << endl;
        head = head->next;
    }

}

Node* buildlist(int listsize, Node *head) {
    //
    Node *currnode = new (Node());
    head = currnode;
    for (int i = 0; i < listsize; i++) {
        Node *nextnode = new Node();
        currnode->next = nextnode;

        cout << "\nenter number: ";
        cin >> nextnode->data;
        nextnode->next = NULL;

        currnode = nextnode;
    }
}

void lisize(int& listsize) {
    cout << "How long you want linked list?: ";
    cin >> listsize;

}

void deletelist(Node *head) { 
    while (head != NULL){
        cout << "DEBUG: inside delete loop for currnode: " << endl;
        Node *tmpnode = head;
        head = curnode->next;
        delete tmpnode;
    }

}

