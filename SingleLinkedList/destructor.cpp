#include <iostream>
using namespace std;
struct Node
{
    int data{};
    Node *next{};
    // Constructor
    Node(int data) : data(data) {}
    // constructor to delete the node
    ~Node()
    {
        cout << "Destroyed value : " << data << endl;
    }
};
class LinkedList
{
private:
    Node *head{};
    Node *tail{};
    int length = 0;

public:
    void print()
    { // O(n)
        for (Node *cur = head; cur; cur = cur->next)
        {
            cout << cur->data << " ";
        }
        cout << endl;
    }
    void insert_end(int value)
    { // O(1)
        Node *item = new Node(value);
        if (!head)
        {
            head = tail = item;
        }
        else
        {
            tail->next = item;
            tail = item;
        }
        length++;
    }
    ~LinkedList()
    {
        while (head)
        {
            Node *current = head->next;
            delete head;
            head = current;
        }
    }
};
int main()
{
    LinkedList list;
    list.insert_end(12);
    list.insert_end(7);
    list.insert_end(99);
    list.insert_end(333);
    list.insert_end(1);
    list.insert_end(9);
    list.print();
    return 0;
}
