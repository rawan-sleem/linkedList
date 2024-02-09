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
    void delete_front()
    {
        if (!head)
        {
            cout << "List is empty!" << endl;
            return;
        }
        Node *temp = head; // store the pointer to the end to be deleted
        head = head->next; // move the head to the next node
        delete temp;
        length--;
    }
    void print()
    {
        for (Node *cur = head; cur; cur = cur->next)
        {
            cout << cur->data << "  ";
        }
        cout << endl;
    }
    void insert_front(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        length++;
    }
    void insert_end(int value)
    {
        Node *newNode = new Node(value);
        if (!head)
        {
            head = tail = newNode; // Update both head and tail for the first node
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }
};
int main()
{
    LinkedList list;
    list.insert_front(1212);
    list.insert_end(23);
    list.insert_front(999);
    list.insert_end(12);
    list.print();
    list.delete_front();
    list.print();
    return 0;
}