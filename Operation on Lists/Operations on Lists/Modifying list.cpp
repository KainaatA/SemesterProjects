
#include <iostream>

using namespace std;

struct Node
{

    int data;

    struct Node *next;
};

void insertAtBeginning(struct Node **head, int dataToBeInserted)
{

    struct Node *current = new Node;

    current->data = dataToBeInserted;

    current->next = NULL;

    if (*head == NULL)

        *head = current;

    else

    {

        current->next = *head;

        *head = current;
    }
}

void display(struct Node **node)
{

    struct Node *temp = *node;

    while (temp != NULL)

    {

        if (temp->next != NULL)

            cout << temp->data << "->";

        else

            cout << temp->data;

        temp = temp->next;
    }

    cout << endl;
}

void Segregate(struct Node **head)
{

    struct Node *end = *head;

    struct Node *previous = NULL;

    struct Node *current = *head;

    while (end->next != NULL)

    {

        end = end->next;
    }

    struct Node *new_end = end;

    while (current->data % 2 != 0 && current != end)

    {

        new_end->next = current;

        current = current->next;

        new_end->next->next = NULL;

        new_end = new_end->next;
    }

    if (current->data % 2 == 0)

    {

        *head = current;

        while (current != end)

        {

            if ((current->data) % 2 == 0)

            {

                previous = current;

                current = current->next;
            }

            else

            {

                previous->next = current->next;

                current->next = NULL;

                new_end->next = current;

                new_end = current;

                current = previous->next;
            }
        }
    }

    else

        previous = current;

    if (new_end != end && (end->data) % 2 != 0)

    {

        previous->next = end->next;

        end->next = NULL;

        new_end->next = end;
    }

    return;
}

int main()
{

    struct Node *head = NULL;

    insertAtBeginning(&head, 50);

    insertAtBeginning(&head, 78);

    insertAtBeginning(&head, 98);

    insertAtBeginning(&head, 10);

    insertAtBeginning(&head, 9);

    insertAtBeginning(&head, 1);

    insertAtBeginning(&head, 2);

    cout << "Original:    ";

    display(&head);

    Segregate(&head);

    cout << "Modified: ";

    display(&head);

    return 0;
}
