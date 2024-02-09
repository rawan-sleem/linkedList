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

public:
    void print()
    {
        for (Node *cur = head; cur; cur = cur->next)
        {
            cout << cur->data << " ";
        }
        cout << endl;
    }
    void add_element(int value)
    {
        Node *item = new Node(value);
        item->next = head;
        head = item;
    }
    Node *get_tail()
    {
        if (!head)
            return nullptr;
        Node *current = head;
        for (; current->next; current = current->next)
            ;
        return current;
    }
};
int main()
{
    LinkedList list;

    list.add_element(10);
    list.add_element(20);
    list.add_element(30);
    list.add_element(40);
    list.add_element(50);
    list.add_element(60);

    list.print();                  // 60 50 40 30 20 10
    cout << list.get_tail()->data; // 10
}