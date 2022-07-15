#include <iostream>

 using namespace std;

class Node 
{

public:
int data;
  
Node * next;

 
};


 
class Linkedlist 
{

public:
Node * start;
  
Node * p_loc;
  
Node * loc;
  
 
 
 
bool isEmpty () 
  {
    
 
return start == NULL;
  
 
 
}
  
void InsertatFront (int value) 
  {
    
Node * newnode = new Node ();
    
newnode->data = value;
    
 
if (isEmpty ())
      
      {
	
start = newnode;
      
 
}
    
    else
      
      {
	
 
newnode->next = start;
	
start = newnode;
      
 
 
 
}
  
}
  
 
 
void Destroy () 
  {
    
if (!isEmpty ())
      
      {
	
Node * tempp = start;
	
while (start != NULL)
	  
	  {
	    
if (start->data % 2 != 0)
	      
	      {
		
 
 
start = start->next;
		
 
delete tempp;
		
tempp = start;
	      
 
 
}
	    
	    else
	      
	      {
		
start = start->next;
		
tempp = start;
	      
 
 
}
	  
}
      
 
}
  
 
 
}
  
 
void PrintList () 
  {
    
 
Node * temp = start;
    
if (!isEmpty ())
      
      {
	
 
while (temp != NULL)
	  
	  {
	    
 
 
 
cout << temp->data << " ";
	    
temp = temp->next;
	  
 
 
}
      
}
  
 
 
}

 
 
 
};


 
 
 
 
 
 
 
 
 
 
 
int 
main () 
{
  
 
Linkedlist * ll = new Linkedlist ();
  
ll->InsertatFront (10);
  
 
ll->InsertatFront (4);
  
 
ll->InsertatFront (9);
  
 
 
 
cout << " " << endl;
  
 
 
ll->PrintList ();
  
ll->Destroy ();
  
ll->PrintList ();
  
 
return 0;

}


