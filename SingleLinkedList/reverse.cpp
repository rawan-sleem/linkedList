#include <iostream>
using namespace std;
struct Node
{
    int data{};
    Node *next{};
    Node(int data) : data(data) {}
};
class LinkedList
{
private:
    Node *head{};
    Node *tail{};
    int length = 0;

public:
    void reverse()
    {
        Node *prev = nullptr;
        Node *current = head;
        Node *next = nullptr;

        // Reverse the list by adjusting pointers
        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        // Update head to point to the last node
        head = prev;
    }
    void insert(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
    void print()
    {
        for (Node *cur = head; cur; cur = cur->next)
        {
            cout << cur->data << "  ";
        }
        cout << endl;
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
    list.print();
    list.reverse();
    list.print();
    return 0;
}