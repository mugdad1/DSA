#include <iostream>
using namespace std;
struct Node{
    int info;
    Node *link;
};
Node *temp=NULL, *cur=NULL, *head=NULL, *tail=NULL;
void InsertFront()
{
    temp = new Node;
    cout<<"Enter Integer Data:\n";
    cin>>temp->info;
    temp->link=NULL;

    if (head==NULL)
    {
        head=temp;
        tail=temp;
    }
    else
    {
        temp->link=head;
        head=temp;
    }
}
void InsertRear()
{
    temp=new Node;
    cout<<"Enter Integer Data:\n";
    cin>> temp->info;
    temp->link=NULL;
    if (head==NULL)
    {
        head=temp;
        tail=temp;
    }
    else
    {
        tail->link=temp;
        tail=temp;
    }
}
void DeleteFront()
{
    temp = head;
    if(head==NULL)
    {
      cout<<"List is Empty!!\n";
    }
    else
    {
        if(temp->link==NULL)
        {
            head=NULL;
            tail=NULL;
        }
        else
        {
            head = head->link;
        }
        cout<<"Deleted:"<<temp->info <<"\n";
        delete temp;
    }
    cout<<endl;
}

void DeleteRear()
{
    cur=head;
    temp=tail;

    if(head==NULL)
    {
       cout<< "List is Empty!!\n";
    }

    else
    {
        if(cur->link==NULL)
        {
            head=NULL;
            tail=NULL;
        }
        else
        {
            while(cur->link!=tail)
            {
                cur=cur->link;
            }
                tail=cur;
                cur->link=NULL;
        }
           cout<<"Deleted: "<<temp->info << "\n";
           delete temp;
    }
    cout<<endl;
}
void PrintForward()
{
    cur=head;

    if(head==NULL)
    {
        cout<<"List is Empty!!\n";
    }
    else
    {
        cout<<"List display: \n";
        while(cur!=NULL)
        {
            cout<< cur->info<<"\t";
            cur=cur->link;
        }
        cout<<endl;
    }
}

int main(){

    int choice;

    do{
        cout << "1: Insert item at front\n";
        cout << "2: Insert item at rear\n";
        cout << "3: Delete item from front\n";
        cout << "4: Delete item from rear\n";
        cout << "5: Print List in forward direction\n";
        cout << "6: Exit\n";
        cout << "Enter your choice: \n";
        cin>>choice;

        switch (choice){
        case 1:
               InsertFront();
               break;
        case 2:
               InsertRear();
               break;
        case 3:
               DeleteFront();
               break;
        case 4:
               DeleteRear();
               break;
        case 5:
               PrintForward();
               break;
        case 6:
               cout<<"Exiting Program\n";
               break;
               default:
                   cout<<"Error! wrong choice\n";
              }
           }while (choice!=6);
       
           return 0;
       }