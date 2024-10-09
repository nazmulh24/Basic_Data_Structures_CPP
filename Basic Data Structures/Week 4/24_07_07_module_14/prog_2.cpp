//--> Using Doubly Linked-list

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class myQueue
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;

    void push(int v)
    {
        sz++;
        Node *newNode = new Node(v);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = tail->next;
    }

    void pop()
    {
        sz--;
        Node *dNode = head;

        head = head->next;
        if (head == NULL)
            tail = NULL;
        else
            head->prev = NULL;

        delete dNode;
    }

    int front()
    {
        return head->val;
    }

    int size()
    {
        return sz;
    }

    bool empty()
    {
        if (sz == 0)
            return true;
        else
            return false;
    }
};

int main()
{
    myQueue q;

    int n;
    cin >> n;
    while (n--)
    {
        int v;
        cin >> v;
        q.push(v);
    }

    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }

    return 0;
}
