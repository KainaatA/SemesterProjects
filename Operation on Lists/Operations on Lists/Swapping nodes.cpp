
#include <iostream>

using namespace std;

using namespace std;

class Node
{

public:
      int data;

      Node *next;
};

class LinkedList
{

public:
      Node *start;

      bool isEmpty()
      {

            return start == NULL;
      }

      void InsertFront(int value)
      {

            Node *newnode = new Node();

            newnode->data = value;

            if (isEmpty())

            {

                  start = newnode;
            }

            else

            {

                  newnode->next = start;

                  start = newnode;
            }
      }

      void printlist()
      {

            if (!isEmpty())

            {

                  Node *temp = start;

                  while (temp != NULL)

                  {

                        cout << temp->data << " ";

                        temp = temp->next;
                  }
            }
      }

      // Reverse
      void reverse()
      {

            Node *loc, *pred_loc, *nextloc;

            loc = start;

            pred_loc = NULL;

            if (isEmpty())

            {

                  return;
            }

            while (loc != NULL)

            {

                  nextloc = loc->next;

                  loc->next = pred_loc;

                  pred_loc = loc;

                  loc = nextloc;
            }

            start = pred_loc;
      }

      void swapping(int a, int b)
      {

            if (a == b)

                  return;

            Node *pred_loca = NULL;

            Node *loca = start;

            while (loca && loca->data != a)

            {

                  pred_loca = loca;

                  loca = loca->next;
            }

            Node *pred_locb = NULL;

            Node *locb = start;

            while (locb && locb->data != b)

            {

                  pred_locb = locb;

                  locb = locb->next;
            }

            if (loca == NULL && locb == NULL)

                  return;

            if (pred_loca != NULL)

                  pred_loca->next = locb;

            else

                  start = locb;

            if (pred_locb != NULL)

                  pred_locb->next = loca;

            else

                  start = loca;

            Node *temp = locb->next;

            locb->next = loca->next;

            loca->next = temp;
      }
};

int main()
{

      LinkedList *x = new LinkedList();

      x->InsertFront(2);

      x->InsertFront(4);

      x->InsertFront(13);

      x->InsertFront(7);

      cout << "\n Original List: \n"
           << endl;

      x->printlist();

      x->reverse();

      cout << "\n Reversed list\n " << endl;

      x->printlist();

      x->swapping(2, 13);

      cout << "\n List after swapping the nodes \n"
           << endl;

      x->printlist();

      return 0;
}
