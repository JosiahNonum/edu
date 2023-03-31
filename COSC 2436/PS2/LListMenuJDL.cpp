// Josiah Larimer
// COSC 2436
// programming set 2
//
// I drew heavily from the textbook


#include<iostream>

using namespace std;


// the most basic of linked list structures
struct Node {
    int key;
    Node* next;
};


// instantiation of the head node of the linked list
Node* head = new Node{ 4, new Node{2, new Node{3, new Node{1, NULL}}} }; // a debug intialization is commented out


// inserts a node
Node* insertNode() {

    // getting input f
    int data;
    cout << "Enter the value that you want to insert: ";
    cin >> data;

    // Create a new node with the given data
    Node* newNode = new Node;
    newNode->key = data;        // the integer value to be stored in the new node
    newNode->next = nullptr;    

    // If the linked list is empty, make the new node the head and return
    if (head == nullptr) {
        head = newNode;
        return head;
    }

    // Traverse the linked list to find the appropriate position for the new node
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr && current->key < data) {
        prev = current;
        current = current->next;
    }

    // If a node with the same key already exists, delete the new node and return the original head
    if (current != nullptr && current->key == data) {
        cout << "Duplicate key found, cannot insert node" << endl;
        delete newNode;
        return head;
    }

    // If the new node needs to be inserted at the beginning of the linked list, update the head
    if (prev == nullptr) {
        newNode->next = head;
        head = newNode;
    }
    // Otherwise, insert the new node between the previous and current nodes
    else {
        prev->next = newNode;
        newNode->next = current;
    }

    // returns the updated head of the linked list
    return head; 
}


// deletes a node
void deleteNode() {

    int value;
    cout << "Enter the key which you want to be removed from the list: ";
    cin >> value;

    Node* temp = head;
    Node* prev = NULL;

    // If the head node has the specified key, delete it and set the new head to the next node
    if (temp != NULL && temp->key == value) {
        head = temp->next;
        cout << endl << "Node with key " << value << " was deleted." << endl;
        delete temp;
        return;
    }

    // Traverse the linked list to find the node with the specified key
    while (temp != NULL && temp->key != value) {
        prev = temp;
        temp = temp->next;
    }

    // If the node with the specified key was not found, print an error message and return
    if (temp == NULL) {
        cout << endl << "Node with key " << value << " not found." << endl;
        return;
    }

    // Otherwise, set the previous node's next pointer to the current node's next pointer
    prev->next = temp->next;

    // Delete the node and free its memory
    delete temp;
    cout << "Node with key " << value << " was deleted." << endl;
}


// Searches for a given value in the linked list
// Returns true if the value is found, false otherwise
bool searchLinkedList() {

    int value;
    cout << "Enter the key you wish to search for: ";
    cin >> value;

    // Start at the head of the linked list
    Node* current = head; 

    // Loop until the end of the linked list is reached
    while (current != NULL) {
        if (current->key == value) { // Check if the current node contains the value
            cout << "Key " << value << " found in the linked list" << endl;
            return true;            // Return true if the value is found
        }
        current = current->next;    // Move to the next node in the linked list
    }

    cout << "Key " << value << " not found in the linked list" << endl;
    return false;// Return false if the value is not found in the linked list
}


// This function counts the number of nodes in the linked list and prints the result.
void size() {
    int count = 0;
    Node* current = head;
    while (current != NULL) { // While there are still nodes in the linked list
        count++;
        current = current->next; // Move to the next node in the linked list
    }
    cout << "The size of the linked list is " << count << " nodes.";
}


// same as the above function, but returns count as an int instead of printing it
// used by printAscii function
int sizeInt()
{
    int count = 0;
    Node* current = head;
    while (current != NULL) {// While there are still nodes in the linked list
        count++;
        current = current->next;// Move to the next node in the linked list
    }
    return count;
}


// a simplified print function with easy to read and not perpetually broken output
void printSimplified() {
    // check if the linked list is empty
    if (head == NULL) {
        cout << "Nothing to print" << endl;
        return;
    }

    // traverses the list and prints the nodes
    Node* current = head;
    while (current != NULL) {
        cout << current->key << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}


// called by the printAscii function below
// built so that it can handle negative numbers and multidigit numbers
void printKey(int key)
{
    if (key < 10 && key > 0)
        cout << "  " << key << ' ';
    else if ((key >= 10 && key < 100) || (key > -10 && key <= 0))
        cout<< key << "  ";
    else if ((key >= 100 && key < 1000) || (key > -100 && key <= -10))
        cout<< ' ' << key;
    else if ((key >= 1000 && key < 10000) || (key > -1000 && key <= -100))
        cout << key;
}


// prints the linked list in the little ascii boxes
// prints 5 nodes on each "line"
void printAscii(Node* head) {

    int size = sizeInt();
    int printCount = size;

    // check if the linked list is empty
    if (head == NULL) {
        cout << "Nothing to print" << endl;
        return;
    }

    // prints five nodes at a time
    do {

        // first line
        for (int j = 0; j < 5 && j < size; j++)
        {
                cout << "------------" << "\t\t";
        }
        cout << endl;

        // second line
        for (int j = 0; j < 5 && j < size; j++)
        {            
            if (printCount == 1)
                cout << "|      | \\ | ";
            else
                cout << "|      |" << "   |  -----> " << "\t";

            printCount--;
        }  
        cout << endl;

        // third line
        for (int j = 0; j < 5 && j < size; j++)
        {            
            cout << "| ";
            printKey(head->key);

            if (head->next == nullptr)
            {
                cout << " | " << " \\|";
            }
            else
            {
                cout << " |   |" << "\t\t";
                head = head->next;
            }
        }
        cout << endl;

        // fourth line
        for (int j = 0; j < 5 && j < size; j++)
        {
                cout << "------------" << "\t\t";
        }
        cout << endl;

        size -= 5;  // keeps track of how many nodes there are remaining
    } while (size > 0);
}


// uses a bubble sort to sort the keys in ascending order
void sort() {    
    Node* current = head;   // pointer to traverse the linked list
    Node* index = NULL;     // pointer to compare current node with the rest of the nodes
    int temp;

    // check if the linked list is empty
    if (head == NULL) {
        return;
    }

    else {
        while (current != NULL) {// traverse the linked list

            index = current->next;
            while (index != NULL) {// compare current node with the rest of the nodes  
                if (current->key > index->key) {// swap node values if current node's key is greater than the next node's key           
                    temp = current->key;
                    current->key = index->key;
                    index->key = temp;
                }
                index = index->next;

            }
            current = current->next;
        }
    }    
}


// reverses the linked list
Node* reverseLinkedList() {
    if (head == nullptr || head->next == nullptr) { // If the linked list is empty or has only one node, there is no need to reverse it
        return head;
    }

    Node* prev = nullptr; // Initialize the previous, current, and next nodes to nullptr, the head node, and the second node, respectively
    Node* curr = head;
    Node* next = nullptr;

    while (curr != nullptr) {// Traverse the list and reverse the direction of the pointers
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}


// Moves the key at the front of the list to the end of the list
void rotate() {
    if (!head || !head->next) return; // Check if list is empty or only has 1 element

    Node* curr = head;
    while (curr->next) {
        curr = curr->next;
    }
    curr->next = head; // Connect end to head
    head = head->next; // Move head to the next node
    curr->next->next = NULL; // Set the new end's next to NULL
}


// Note that I started my even-odd count from 0
// so: 0, 1, 2, 3, 4, 5, ...
// It links all the odd and even nodes together, and then puts the odd nodes at the end of the list
void shift() {
    if (!head || !head->next) return; // Check if list is empty or only has 1 element

    Node* even = head;
    Node* odd = head->next;
    Node* oddHead = odd; // Keep track of the head of the odd list

    while (odd && odd->next) {
        even->next = odd->next; // Link even nodes together
        even = even->next;
        odd->next = even->next; // Link odd nodes together
        odd = odd->next;
    }

    even->next = oddHead; // Link the end of even to the head of odd
}


// traverses the list and deletes the nodes one by one
void clear() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
        cout << "Empty List";
}


int main() {

	bool quit = false;

	do
	{
        int menu;

        cout << endl << "1:insert  2:delete  3:search  4:print  5:size  6:sort  7:reverse  8:rotate  9:shift  10:clear  11:quit " << endl;
        cin >> menu;

        switch (menu) {
        case 1:
            insertNode();
            break;
        case 2:
            deleteNode();
            break;
        case 3:
            searchLinkedList();
            break;
        case 4:
            printAscii(head);
            //printSimplified();        // a simplified print function that is easier to read and usually not broken
            break;
        case 5:
            size();
            break;
        case 6:
            sort();
            break;
        case 7:
            head = reverseLinkedList();
            break;
        case 8:
            rotate();
            break;
        case 9:
            shift();
            break;
        case 10:
            clear();
            break;
        case 11:
            quit = true;
            break;
        default:
            cout << "Sir, this is a Wendy's. Please place an order or leave." << endl << "(Choose an option from the menu.)" << endl;
        }

	} while (quit == false);		// tests whether to continue outer do while loop
}