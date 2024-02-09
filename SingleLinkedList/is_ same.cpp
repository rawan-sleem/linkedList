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
    void print()
    {
        for (Node *curr = head; curr; curr = curr->next)
        {
            cout << curr->data << "  ";
        }
        cout << endl;
    }
    int is_same(LinkedList list)
    {
        Node *first = head;
        Node *first_of_list = list.head;
        while (first_of_list && first)
        {
            if (first->data != first_of_list->data)
            {
                return 0;
            }
            first_of_list = first_of_list->next;
            first = first->next;
        }
        return !first_of_list && !first;
    }
    void insert_front(int value)
    { // O(1)
        Node *newNode = new Node(value);
        // set the next pointer of the new node to the current head
        newNode->next = head;
        // update the head pointer to the point to the new node
        head = newNode;
        length++;
    }
};
int main()
{
    LinkedList list1;
    LinkedList list2;
    cout << list1.is_same(list2);
    
}