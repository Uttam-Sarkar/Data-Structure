#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *link;
};

struct node *start = (struct node*) malloc(sizeof(struct node));
struct node *last = start;
int counts=1;

void insertFornt(int value)
{
    struct node *ptr =(struct node*) malloc(sizeof(struct node));
    ptr->link = start;
    start = ptr;
    ptr->data = value;

}
void insertEnd(int n)
{
    struct node *ptr =(struct node*) malloc(sizeof(struct node));
    ptr->data =  n;
    last->link=ptr;
    last = ptr;
    ptr ->link=NULL;

}
void insert(int value,int loc)
{

    struct node *ptr =(struct node*) malloc(sizeof(struct node));
    struct node *aa = NULL;
    ptr->data = value;
    int c=1;
    aa = start;
    while(aa->link != NULL && c !=  loc-1)
        {
            c++;
            aa=aa->link;
        }
        ptr->link = aa->link;
        aa->link=ptr;
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
cout << "Enter Position and Value : " << endl;
cout << "1 ";
    int value,loc;
    cin >> value;
    start -> data = value;
    start->link=NULL;
    cout << "The all element is: ";
    Print();

 while(1)
 {
        cin >> loc ;

        if(loc > 0)
        {
            cin >> value;

        // last
        if(loc == counts+1)
        {
            counts++;
            insertEnd(value);
            cout << "The all element is: ";
            Print();
        }

        //front
        else if(loc == 1)
        {
            counts++;
            insertFornt(value);
            cout << "The all element is: ";
            Print();
        }

        //any
        else if(loc > 0 && loc <= counts)
        {
            insert(value, loc);
            counts++;
            cout << "The all element is: ";
            Print();
        }

        else
        {
            cout << "ERROR ! " << endl;
        }

        }
        else
        {
            break;
        }
    }
}
