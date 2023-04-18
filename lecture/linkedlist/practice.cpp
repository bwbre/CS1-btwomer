/*
Brendan Womer
practice and experimentation with linked list and double pointers
*/

#include <iostream>
#include <string>

using namespace std;

struct Node {
    Node *prev;
    int data;
    Node *next;
};

void debug(Node*, Node*, string);

int main(int argc, char* argv[]) {
    int listsize = 0;
    Node *first = new Node({NULL, 1, NULL});
    cout << "how many nodes in your linked list?: ";
    cin >> listsize;
    cout << endl;

    Node *currnode;
    currnode = first;
    // cout << "currnode->data: " << nextnode->data << endl;
    // cout << "nextnode->next: " << nextnode->next << endl;

    for (int i = 0; i < listsize; i++) {
        Node *nextnode = new Node();
        //start from 1
        int loopcount = 0; 
        cout << "*******Loop count: " << loopcount << "**********" << endl;
        debug(currnode, nextnode, "beginning of loop- ");

        nextnode->prev = currnode;
        currnode->next = nextnode;
        currnode->next = nextnode->next;
        currnode->prev = nextnode->prev;

        debug(currnode, nextnode, "before input, after nodes shuffle- ");

        cout << "enter number ";
        cin >> nextnode->data;
        currnode->data = nextnode->data;
        
        debug(currnode, nextnode, "end of loop, after input- ");

        nextnode->next = NULL;
        loopcount+= 1;

    }

    cin.ignore(1000, '\n');
    // while (currnode->prev != NULL) {
    //     currnode = currnode->prev;
    //     cout << "======AFTER ALL LISTS CRREATED, LETS TRY TO ITERATE CAND PRINT IN REVERSE=====" << endl;
    //     cout << "currnode->prev: " << currnode->prev << endl;
    //     cout << "currnode->data: " << currnode->data << endl;
    //     cout << "currnode->next: " << currnode->next << endl;
    // }

    /*Confusing iterations with next node*/
    // for (int i=0; i < listsize; i++) {
    //     Node *nextnode = new Node();
    //     while (nextnode != NULL) {
    //     // cout << "current node->prev : " << nextnode->prev << endl;
    //     cout << "current node address : " << nextnode << endl;
    //     cout << "current node->data : " << nextnode->data << endl;
    //     cout << "current node->next : " << nextnode->next << endl << endl;
    //     // if (first->next == NULL) {
    //     //     first->next = nextnode;
    //     // }
    //     cout << "enter number: ";
    //     cin >> nextnode->data;
    //     nextnode->next = NULL;
    //     }


    delete first;

    return 0;
}

void debug(Node *currnode, Node *nextnode, string prefix) {
    cout << "\n----\n";
        cout << prefix << " currnode->prev: " << currnode->prev << endl;
        cout << prefix << " currnode->data: " << currnode->data << endl;
        cout << prefix << " currnode->next: " << currnode->next << endl;
        cout << prefix << " nextnode->data: " << nextnode->prev << endl;
        cout << prefix << " nextnode->data: " << nextnode->data << endl;
        cout << prefix << " nextnode->next: " << nextnode->next << endl << endl;

}














// struct Node {
//     Node *prev;
//     int data;
//     Node *next;
// };
// int main(int argc, char* argv[]) {
//     Node *first = new Node();
//     Node *second = new Node();
//     Node *third = new Node();
//     first->prev = NULL;
//     first->data = 1;
//     first->next = second;
//     second->prev = first;
//     second->data = 2;
//     second->next = third;
//     third->prev = second;
//     third->data = 3;
//     third->next = NULL;
//     Node *currnode;
//     currnode = first;
//     int sum = 0;
//     //NODES CAN BE == NULL
//     while (currnode != NULL) {
//         cout << "current node->prev : " << currnode->prev << endl;
//         cout << "current node address : " << currnode << endl;
//         cout << "current node->data : " << currnode->data << endl;
//         cout << "current node->next : " << currnode->next << endl << endl;
//         sum += currnode->data;
//         currnode = currnode->next;
//     }
//     cout << "sum: " << sum << endl;
//     cout << "first->data " << first->data << endl;
//     cout << "second->data " << second->data << endl;
//     cout << "third->data " << third->data << endl;
//     delete first;
//     delete second;
//     delete third;
//     return 0;
// }