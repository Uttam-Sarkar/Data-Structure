#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *link;
};

struct node *start = (struct node*) malloc(sizeof(struct node));

void Print(struct node* start)
{
    struct node *ptr = NULL;
    ptr = start;

    while(ptr != NULL)
    {
        cout << ptr-> data << " ";
        ptr = ptr -> link;
    }
}

int main()
{
    struct node *second = (struct node*) malloc(sizeof(struct node));
    struct node *third = (struct node*)malloc(sizeof(struct node));
    struct node *forth = (struct node*)malloc(sizeof(struct node));
    struct node *fifth = (struct node*)malloc(sizeof(struct node));
    struct node *sixth = (struct node*)malloc(sizeof(struct node));

    start->data = 5;
    start->link = second;

    second->data = 3;
    second->link = third;

    third->data = 9;
    third->link = forth;

    forth->data = 42;
    forth->link = fifth;

    fifth->data = 0;
    fifth->link = sixth;

    sixth->data = 10;
    sixth->link = NULL;

    Print(start);

    return 0;

}
