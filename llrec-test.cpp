#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------

struct Pred //bool operator for pred
{
	int num2; //check to see if number meets pred conditons
	Pred(int val) : num2(val){}
    bool operator()(int num1) {
        if (num1 <= num2)
        {
            return true;
        }
        else return false;
    }
};




int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }
    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
    Node* head = readList(argv[1]);
    cout << "Original list: ";
    print(head);

    // Test out your linked list code
    Node * list = new Node(3, new Node(6, new Node(4, new Node(9, NULL))));
    Node* small = NULL; 
	Node* large = NULL; 
    cout<<"Starting list: ";
    print(list);
    llpivot(list, small, large, 5);

    
    cout<<"small: ";
    print(small);
    cout<<endl<<"large: ";
    print(large);
    cout<<endl;
    cout<<"Original list: ";
    print(list);

    Node * list2 = new Node(2, new Node(4, new Node(6, new Node(8, NULL))));
    print(list2);
    Pred Pred(5);
    list2 = llfilter(list2, Pred);
    // Test out your linked list code
    cout<<"Filtered list: ";
    print(list2);
    
    return 0;

}
