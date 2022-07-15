
#include <iostream>

using namespace std;

class Node
{

public:
  int data;

  Node *next;
};

class LinkList
{

public:
  Node *start;

  Node *p_loc;

  Node *loc;

  bool isEmpty()
  {

    return start == NULL;
  }

  void InsertatFront(int value)
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

  void Reverse()
  {

    Node *loc;

    Node *p_loc;

    Node *s_loc;

    if (isEmpty())

      return;

    loc = start;

    p_loc = NULL;

    while (loc != NULL)

    {

      s_loc = loc->next;

      loc->next = p_loc;

      p_loc = loc;

      loc = s_loc;
    }

    start = p_loc;
  }

  void PrintList()
  {

    Node *temp = start;

    if (!isEmpty())

    {

      while (temp != NULL)

      {

        cout << temp->data << " ";

        temp = temp->next;
      }
    }
  }
};

int main()
{

  LinkList *ll = new LinkList();

  ll->InsertatFront(4);

  ll->InsertatFront(9);

  ll->InsertatFront(1);

  cout << "Original: ";

  ll->PrintList();

  cout << " " << endl;

  cout << "Reversed: ";

  ll->Reverse();

  ll->PrintList();

  return 0;
}
