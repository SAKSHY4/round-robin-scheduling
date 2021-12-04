#include <iostream>
using namespace std;

struct node
{
    struct node* next;
    struct node* prev;
    int time_req;
    char process[10];
};

void enqueue(node** start)
{
    node* p = * start;
    node* x = new node;
    x->next = NULL;
    x->prev = NULL;
    getchar();
    cout << "\nEnter name of process (Max 10 characters): ";
    cin.getline(x->process, 10);
    cout << "Enter time required to complete process: ";
    cin >> x->time_req;
    cout << "\n";
    if (*start == NULL)
    {
        *start = x;
    }
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = x;
        x->prev = p;
    }
}

void enqueue(node** start, node* x)
{
    x->next = NULL;
    node* p = * start;
    if (*start == NULL)
    {
        *start = x;
    }
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = x;
        x->prev = p;
    }
}

node* dequeue(node** start)
{
    node* p = *start;
    if (p->next == NULL)
    {
        *start == NULL;
        node* temp = p;
        delete temp;
        return p;
    }
    node* x = p->next;
    *start = x;
    x->prev = p->prev;
    node* temp = p;
    delete temp;
    return p;
}

void display(node** start)
{
    node* p = *start;
    while (p != NULL)
    {
        cout << "\n\nProcess: " << p->process << "\tTime requirement: " << p->time_req;
        p = p->next;
    }
}

void run(node** start, int qtime)
{
    node* p = *start;
    while (p != NULL)
    {
        node* hold = p->next;
        cout << "\n\nProcess: " << p->process << "\tTime requirement: " << p->time_req;
        p->time_req = p->time_req-qtime;
        cout << "\tRemaining time: ";
        {
            if (p->time_req > 0)
                cout << p->time_req;
            else
                cout << "0";
        }
        if (p->time_req > 0)
        {
            node* temp = dequeue(start);
            enqueue(start, temp);
            cout << "\nProcess " << temp->process << " enqueued\n";
        }
        else
        {
            node* temp = dequeue(start);
            cout << "\nProcess " << temp->process << " completed\n";
        }
        p = hold;
    }
}

int main()
{
    node* start = NULL;
    cout << "\n\nEnter number of processes: ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        enqueue(&start);
    }
    cout << "\nEnter quantum time: ";
    int qtime;
    cin >> qtime;
    display(&start);
    cout << "\n\n";
    run(&start, qtime);
    cout << "\n\n";
}