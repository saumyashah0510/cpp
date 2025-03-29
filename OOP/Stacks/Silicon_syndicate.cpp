#include <iostream>
using namespace std;

class node {
public:
    string name;
    int severity;
    node *next;

    node(string name, int severity) {
        this->name = name;
        this->severity = severity;
        this->next = NULL;
    }
};

void delete_first(node *&head) {
    if (head == NULL) return; // Check if ER is empty

    node *temp = head;
    head = temp->next;
    delete temp;
}

node *arrive(node *head, string name, int severity) {
    node *temp = new node(name, severity);

    // If the list is empty or the new patient has higher severity than head
    if (head == NULL || severity > head->severity) {
        temp->next = head;
        return temp; // New node becomes the head
    }

    // Find the correct position to insert
    node *curr = head;
    while (curr->next != NULL && curr->next->severity >= severity) {
        curr = curr->next;
    }

    // Insert the new node
    temp->next = curr->next;
    curr->next = temp;

    return head;
}

int main() {
    node *head = NULL;
    string name;
    int severity, type;

    do {
        cout << "1. Arrive" << endl
             << "2. Next" << endl
             << "3. Treat" << endl
             << "4. Exit" << endl;

        cin >> type;

        if (type == 1) {
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter severity: ";
            cin >> severity;
            head = arrive(head, name, severity);
        }
        else if (type == 2) {
            if (head == NULL)
                cout << "No patients in the ER" << endl;
            else
                cout << "Next patient: " << head->name << endl;
        }
        else if (type == 3) {
            if (head == NULL)
                cout << "No patients in the ER" << endl;
            else {
                cout << "Treating " << head->name << endl;
                delete_first(head);
            }
        }
    } while (type != 4);

    // Free all allocated memory before exiting
    while (head != NULL) {
        delete_first(head);
    }

    return 0;
}
