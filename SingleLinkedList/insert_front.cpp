#include <iostream>
using namespace std;
struct Node
{
    int data{};
    Node *next{};
    Node(int data) : data(data) {}
    ~Node()
    {
        cout << "Destroyed value is : " << data  << endl;
    }
};
class LinkedList
{
private:
    Node *head{};
    Node *tail{};
    int length = 0;
    public:
    void insert_front(int value)
    {// O(1)
        Node *newNode = new Node(value);
        // set the next pointer of the new node to the current head
        newNode->next = head;
        // update the head pointer to the point to the new node
        head = newNode;
        length++;
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
int main(){
    LinkedList list;
   list.insert_front(12);
   list.insert_front(1);
   list.insert_front(99);
   list.print();
}