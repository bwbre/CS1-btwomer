/*

*/


#include <iostream>
#include <string>

using namespace std;

struct Node {
    int data;
    Node *next;

};


int main(int argc, char* argv[]) {
    int listsize = 0;
    Node *first = new Node({0, NULL});

    cout << "How long you want linked list?: ";
    cin >> listsize;

    Node *currnode = first;
    for (int i = 0; i < listsize; i++) {
        Node *nextnode = new Node();
        currnode->next = nextnode;

        cout << "\nenter number: ";
        cin >> nextnode->data;
        nextnode->next = NULL;

        currnode = nextnode;
    }

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


    Node *currnode;
    currnode = first;

    /*NOTE: use curnode, not curnode->next... next goes to final and checks next which returns null, thus wont print.*/
    while(currnode->next != NULL) {
        cout << "curnode->data: " << currnode->data << endl;
        currnode = currnode->next;

    }

    // cout << "curnode->data: " << curnode->data << endl;


    /*TO DELETE THE SELF GENERATED LINKED LIST*/
    Node *curnode;
    curnode = first;
    while (curnode != NULL){
        cout << "DEBUG: inside delete loop for currnode: " << endl;
        Node *tmpnode = curnode;
        curnode = curnode->next;
        delete tmpnode;
    }

    delete first;
    // delete second;
    // delete third;

    return 0;
}