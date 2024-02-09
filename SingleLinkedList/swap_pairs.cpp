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
    void insert(int value)
    {
        Node *item = new Node(value);
        item->next = head;
        head = item;
    }
    void swap_pairs()
    {
        Node *prev = nullptr;
        Node *current = head;

        // Swap pairs of nodes
        while (current != nullptr && current->next != nullptr)
        {
            // Swap data of current and next nodes
            int temp = current->data;
            current->data = current->next->data;
            current->next->data = temp;

            // Move current pointer two steps forward
            current = current->next->next;
        }
    }
    void print()
    {
        for (Node *node = head; node != NULL; node = node->next)
        {
            cout << node->data << " ";
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
    list.print();
    list.swap_pairs();
    list.print();
    return 0;
}
