#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList
{
private:
    Node *head;
    Node *tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    void insert_sorted(int value)
    {
        Node *newNode = new Node(value);

        // If the list is empty or the value is less than the head's data,
        // insert the new node at the beginning
        if (head == nullptr || value < head->data)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        // Find the correct position to insert the new node
        Node *prev = nullptr;
        Node *current = head;
        while (current != nullptr && current->data < value)
        {
            prev = current;
            current = current->next;
        }

        // Insert the new node at the correct position
        newNode->next = current;
        prev->next = newNode;

        // Update the tail if the new node is inserted at the end
        if (current == nullptr)
        {
            tail = newNode;
        }
    }

    void print()
    {
        Node *curr = head;
        while (curr != nullptr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList list;
    list.insert_sorted(10);
    list.insert_sorted(2);
    list.insert_sorted(30);
    list.insert_sorted(4);
    list.insert_sorted(1);
    list.print();

    return 0;
}
