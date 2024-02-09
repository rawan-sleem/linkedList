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
            tail->next = item;
            tail = item;
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

    void delete_even_positions()
    {
        Node *prev = nullptr;
        Node *current = head;
        int position = 1; // Start with position 1 (1-based index)

        // Traverse the list and delete nodes at even positions
        while (current != nullptr)
        {
            if (position % 2 == 0)
            {
                // Even position, delete the node
                prev->next = current->next;
                delete current;
                current = prev->next;
            }
            else
            {
                // Odd position, move to the next node
                prev = current;
                current = current->next;
            }
            position++;
        }
    }
};

int main()
{
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(10);
    cout << "Original List: ";
    list.print();
    list.delete_even_positions();
    cout << "List after deleting even positions: ";
    list.print();


    return 0;
}
