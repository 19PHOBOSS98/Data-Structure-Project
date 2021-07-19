//Queue Linked List
#include "queuell.h"

#include<iostream>
#include<string>
#include<cstdlib>


using namespace std;

static node *front=NULL,*rear=NULL,*tmp=NULL,*access=NULL;
void psh(int value){
	tmp=new node;
	tmp->data=value;
	tmp->next=NULL;
	
	if(front!=NULL)
	{
		rear->next=tmp;
		rear=tmp;
	}
	else
	{
		rear=tmp;
		front=tmp;
	}
	
}

void pp(){
	
	tmp = front;
   if (front == NULL) {
      cout<<"Underflow"<<endl;
   }
   else
   if (tmp->next != NULL) {
      front = front->next;
      delete tmp;
   } else {
      front = NULL;
      rear = NULL;
   }
}

void QL()
{	
	int option;
	int data;
	int w=1;
	while(w)
	{
		cout<<"\nSTACK MENU";
		cout<<"\n[1] enqueue";
		cout<<"\n[2] dequeue";
		cout<<"\n[3] print";
		cout<<"\n[4] EXIT";
		cout<<"\nOption:";
		
		cin>>option;
		cin.ignore();
		switch(option)
		{
			case 1: cout<<"\nData: ";
					cin>>data;
					cin.ignore();
					psh(data);
					break;
			case 2: cout<<" \nDequeued: ";
					pp();
					break;
					
					break;
			case 3: tmp = front;
					if ((front == NULL) && (rear == NULL)) 
					{
	      			cout<<"Queue is empty"<<endl;
	  				}
	  				else
	  				{
		   				cout<<"\nList of nodes: \n";
		   				while (tmp != NULL)
						{
			      			cout<<tmp->data<<" ";
			      			tmp = tmp->next;
		      			}
		      		}
	      			break;
	      	case 4:
	      		{
	      			int r = 1;
			        while (r)
			    	{
			    	    string input;
			    	    char c;
			    	    cout << "\nBack to main menu? [y/n]: ";
			    	    getline (cin, input);
			    	    if (!input.length () == 1)
			    	    {
			    	        cout << "Invalid Input\n";
			    	    }
			    	    else
			    	    {
			    	        c = input[0];
			    	        switch (c)
			    	        {
			    	            case 'y':
			        		    {
			        		        r = 0;
			        		        w = 0;
			        		        break;
			        		    }
			        		    case 'Y':
			        		    {
			        		        r = 0;
			        		        w = 0;
			        		        break;
			        		    }
			        		    case 'n':
			        		    {
			        		        r = 0;
			        	     	    break;
			        		    }
			        		    case 'N':
			        		    {
			        		        r = 0;
			        		        break;
			        		    }
			        		    default:
			        		    {
			        		        cout << "Invalid Input\n";
			        		        break;
			        		    }
			    		    }
			    	    }
			    	}
			    	break;
				}
	      	default: cout<<"\nInvalid choice"<<endl;
	      	break;
		}
		
		
	}
}
