/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

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

            Node *loc, *ploc, *nextloc;

            loc = start;

            ploc = NULL;

            if (isEmpty())

            {

                  return;
            }

            while (loc != NULL)

            {

                  nextloc = loc->next;

                  loc->next = ploc;

                  ploc = loc;

                  loc = nextloc;
            }

            start = ploc;
      }

      Node *rearrangeEvenOdd()
      {

            Node *head;

            // Corner case
            if (head == NULL)

            {

                  return NULL;
            }

            // Initialize first nodes of even and
            // odd lists
            Node *odd = head;

            Node *even = head->next;

            // Remember the first node of even list so
            // that we can connect the even list at the
            // end of odd list.
            Node *evenFirst = even;

            while (1)

            {

                  // If there are no more nodes, then connect
                  // first node of even list to the last node
                  // of odd list
                  if (!odd || !even || !(even->next))

                  {

                        odd->next = evenFirst;

                        break;
                  }

                  // Connecting odd nodes
                  odd->next = even->next;

                  odd = even->next;

                  // If there are NO more even nodes after
                  // current odd.
                  if (odd->next == NULL)

                  {

                        even->next = NULL;

                        odd->next = evenFirst;

                        break;
                  }

                  // Connecting even nodes
                  even->next = odd->next;

                  even = odd->next;
            }

            return head;
      };
};

int main()
{

      LinkedList *x = new LinkedList();

      x->InsertFront(2);

      x->InsertFront(27);

      x->InsertFront(87);

      x->InsertFront(100);

      cout << "\nThe original list is: \n";

      x->printlist();

      x->reverse();

      cout << "\nThe reversed list is: \n";

      x->printlist();

      x->rearrangeEvenOdd();

      cout << "\n The list with odd before even is: \n"
           << endl;

      x->printlist();

      return 0;
}
