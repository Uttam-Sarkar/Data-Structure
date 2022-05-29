#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *link;
};

struct node *start = (struct node*) malloc(sizeof(struct node));
struct node *last = start;

void insertFornt(struct node* start)
{

}
void insertLast(int n)
{
    struct node *ptr =(struct node*) malloc(sizeof(struct node));
    ptr->data =  n;
    last->link=ptr;
    last = ptr;
    ptr ->link=NULL;

}
void insert(struct node* start)
{

}
void Print()
{
        struct node *ptr =(struct node*) malloc(sizeof(struct node));

        ptr = start;
        while(ptr->link != NULL)
        {
            cout << ptr->data << " ";
            ptr=ptr->link;
        }
        cout << ptr->data << " ";

        cout << endl;
}
int main()
{

    int n;
    cout << "Enter the first number of the array: " << endl;
    cin >> n;
    start -> data = n;
    start->link=NULL;

    while(n != -1)
    {
        cout << "Enter a number to insert Last: " << endl;
        cin >> n;
        if(n != -1)
        {insertLast(n);
        cout << "The all element is: ";
        Print();

        }

    }
}
