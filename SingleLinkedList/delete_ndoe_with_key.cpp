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

    void insert(int value)
    {
        Node *item = new Node(value);
        if (head == nullptr)
        {
            head = tail = item;
        }
        else
        {
            item->next = head;
            head = item;
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

    void delete_node_with_key(int value)
    {
        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
            return;
        }

        // Handle case where head node has the key
        if (head->data == value)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node *current = head;
        Node *prev = nullptr;

        // Traverse the list to find the node with the key value
        while (current != nullptr && current->data != value)
        {
            prev = current;
            current = current->next;
        }

        // If node with key value is found, delete it
        if (current != nullptr)
        {
            prev->next = current->next;
            delete current;
        }
        else
        {
            cout << "Key not found in the list! 😢" << endl;
        }
    }
};

int main()
{
    LinkedList list;
    list.insert(12);
    list.insert(34);
    list.insert(78);
    list.insert(11);
    list.insert(99);
    list.print();
    list.delete_node_with_key(78);
    list.print();
    list.delete_node_with_key(1);
    return 0;
}
