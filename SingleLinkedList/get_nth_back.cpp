#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList
{
private:
    Node *head;
    Node *tail;

public:
    LinkedList() : head(nullptr) {}

    // Function to insert a node at the beginning of the linked list
    void insert(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Function to get the nth node from the beginning of the linked list
    Node *get_nth(int n)
    {
        Node *current = head;
        for (int i = 1; i < n && current != nullptr; ++i)
        {
            current = current->next;
        }
        return current;
    }

    // Function to get the nth node from the end of the linked list
    Node *get_nth_back(int n)
    {
        int length = 0;
        Node *current = head;

        // Count the total number of nodes
        while (current != nullptr)
        {
            length++;
            current = current->next;
        }

        // Calculate the position from the beginning
        int position_from_beginning = length - n + 1;

        // Get the node at the calculated position from the beginning
        return get_nth(position_from_beginning);
    }
};

int main()
{
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.insert(6);

    // Get the node at the 1st position from the back
    Node *nth_back_node = list.get_nth_back(1);

    // Print the value of the node at the 1st position from the back
    if (nth_back_node != nullptr)
    {
        cout << "Value of the node at the 1st position from the back: " << nth_back_node->data <<endl;
    }
    else
    {
        cerr << "Invalid position" << endl;
    }

    return 0;
}
