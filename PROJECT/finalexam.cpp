//final practical exam
#include "finalexam.h"

#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

static string id, nm, crs, yr, ag;
static int i = 0;

void
records::add (int x, string nm, string crs, string yr, string ag)	//pushes entries to list
{
  if (head == NULL)
    {
      tmp = new node;
      tmp->ID = x;
      tmp->Name = nm;
      tmp->Course = crs;
      tmp->Year = yr;
      tmp->Age = ag;
      tmp->next = NULL;
      tmp->prev = NULL;
      head = tmp;
      tail = head;

      cout << endl;
      cout << "ID:" << tmp->ID << endl;
      cout << "NAME: " << tmp->Name << endl;
      cout << "COURSE: " << tmp->Course << endl;
      cout << "YEAR: " << tmp->Year << endl;
      cout << "AGE: " << tmp->Age << endl;
      cout << endl;
    }
  else
    {
      tmp = new node;
      tmp->prev = head;
      head->next = tmp;
      tmp->next = NULL;
      tmp->ID = x;
      tmp->Name = nm;
      tmp->Course = crs;
      tmp->Year = yr;
      tmp->Age = ag;
      head = tmp;

      cout << endl;
      cout << "ID: " << tmp->ID << endl;
      cout << "NAME: " << tmp->Name << endl;
      cout << "COURSE: " << tmp->Course << endl;
      cout << "YEAR: " << tmp->Year << endl;
      cout << "AGE: " << tmp->Age << endl;
      cout << endl;
    }

}

void
records::srch (int x)		//initialize search for 'x' at tail
{
  srch_priv (tail, x);
}

bool records::srch_priv (node * tmp, int x)	//recursive search function
{
  if (tmp != NULL)
    {
      if (tmp->ID == x)
	{
	  cout << "Student number: '" << tmp->ID << "' found:\n";

	  cout << "ID: " << tmp->ID << endl;
	  cout << "NAME: " << tmp->Name << endl;
	  cout << "COURSE: " << tmp->Course << endl;
	  cout << "YEAR: " << tmp->Year << endl;
	  cout << "AGE: " << tmp->Age << endl;

	  cout << endl;
	  return true;
	}
      else
	{
	  srch_priv (tmp->next, x);
	}
    }
  else
    {
      cout << "Student number: '" << x << "' could not be found\n";
      return false;
    }
}

void
records::rem (int x)		//initializes delete student function at tail
{
  cout << "attempting to unregister student number: " << x << endl;
  if (head == NULL)
    {
      cout << "There's no one to remove\n";
    }
  else
    {
      rem_priv (tail, x);
    }
}

void
records::rem_priv (node * tmp, int x)	//recursive delete student member function
{
  node *acc = tmp;

  if (tmp != NULL)
    {
      if (tmp->ID == x)
	{
	  if ((tmp->next == NULL) && (tmp->prev == NULL))	//if node is in the middle of the list
	    {
	      delete (tmp);
	      cout << "Student successfully removed\n";
	    }
	  else if (tmp == tail)	//if node is at the tail of the list
	    {
	      acc = tmp->next;
	      acc->prev = NULL;
	      tail = acc;
	      delete (tmp);
	      cout << "Student successfully removed\n";
	    }
	  else if (tmp == head)	//if node is at the end of the list
	    {
	      acc = tmp->prev;
	      acc->next = NULL;
	      head = acc;
	      delete (tmp);
	      cout << "Student successfully removed\n";
	    }
	  else			//if node is the only element
	    {
	      acc = tmp->prev;
	      acc->next = tmp->next;
	      acc = tmp->next;
	      acc->prev = tmp->prev;
	      delete (tmp);
	      cout << "Student successfully removed\n";
	    }
	}
      else
	{
	  rem_priv (tmp->next, x);
	}
    }
  else
    {
      cout << "Student number: '" << x << "' was not registered to begin with"
	<< endl;
    }
}

void
records::sort_priv (node * p, node * r)	//recursive quick sort function
{
  if (p != NULL)
    {
      if (p->ID < r->ID)
	{
	  swap (r->ID, p->ID);
	  swap (r->Name, p->Name);
	  swap (r->Course, p->Course);
	  swap (r->Year, p->Year);
	  swap (r->Age, p->Age);
	}

      if (r == p)
	{
	  sort_priv (p->prev, tail);
	}
      else
	{
	  sort_priv (p, r->next);
	}
    }
}

void
records::sort ()		//initializes partition 'p' at head and comparative pointer 'r' at tail
{
  sort_priv (head, tail);
}

void
records::print ()		//prints out sorted record from stack
{
  node *tmp = head;
  sort ();
  while (tmp != NULL)		//from top 'head' to bottom 'tail'
    {
      cout << endl;
      cout << "ID: " << tmp->ID << endl;
      cout << "NAME: " << tmp->Name << endl;
      cout << "COURSE: " << tmp->Course << endl;
      cout << "YEAR: " << tmp->Year << endl;
      cout << "AGE: " << tmp->Age << endl;
      cout << endl;
      tmp = tmp->prev;
    }
  cout << endl;
}

bool records::exists (int x)	//checks if node->ID 'x' exists in list
{
  return (exists_priv (tail, x));

}

bool records::exists_priv (node * tmp, int x)	//returns true if 'x' is on the list
{
  while (tmp != NULL)
    {
      if (tmp->ID == x)
	{
	  return true;
	}
      tmp = tmp->next;
    }
  return false;

}


void FE()
{
	records students;
	int w=1;
  	while (w)
    {
      string
	u,
	p;			//Authentication login
      cout << "Username: ";
      getline (cin, u);
      cout << "Password: ";
      getline (cin, p);
      if ((u.compare ("final") != 0) || (p.compare ("exam") != 0))
	{
	  cout << "Please Re-Enter Username and Password\n";
	}

      else
	{
	  while (w)		//start of main while loop
	    {
	      string
		in;		// main menu
	      cout <<
		"\nStudent Record\n\n[1]Add Student\n[2]Delete Student\n[3]Search\n[4]Print\n[5]EXIT\nOption: ";
	      getline (cin, in);
	      if (in.length () == 1)	// main menu option input validity check
		{
		  char
		    o = in[0];
		  switch (o)
		    {
		    case '1':	//Add Student
		      {
			int
			  D;
			int
			  t = 1;
			while (t)
			  {
			    cout << "ID: ";
			    getline (cin, id);

			    for (int i = 0; i < id.length (); ++i)	//ID input validity check
			      {	//a valid input is defined as a positive integer of nine digits

				if (!isdigit (id[i]))
				  {
				    t = 1;
				    break;
				  }
				else
				  {
				    t = 0;
				  }
			      }
			    D = atoi (id.c_str ());
			    if (id.length () != 9)
			      {
				cout <<
				  "an ID number consists of nine digits\n";
				  t = 1;
			      }
			    if (students.exists (D))	//checks if ID is already on the list
			      {
				t = 1;
				cout << "\nID already exists\n";
			      }
			    if (t == 1)
			      {
				cout << "Please Enter a Valid ID\n";
			      }



			  }
			//input data associated with valid ID
			cout << "\nNAME: ";
			getline (cin, nm);
			cout << "\nCOURSE: ";
			getline (cin, crs);
			cout << "\nYEAR: ";
			getline (cin, yr);
			cout << "\nAGE: ";
			getline (cin, ag);
			students.add (D, nm, crs, yr, ag);
			cout <<
			  "\nYou have successfully registered student number: '"
			  << D << "'\n";

			i++;	//list item counter

			break;
		      }
		    case '2':	//Delete Student
		      {

			if (i == 0)	//if empty list
			  {
			    cout << "There's no one to remove\n";
			  }
			else
			  {
			    int
			      g = 1;

			    while (g)
			      {
				int
				  D;	//ID input validity check
				string
				  d;
				cout << "\nID: ";
				getline (cin, d);
				D = atoi (d.c_str ());

				for (int j = 0; j < d.length (); ++j)
				  {

				    if (!isdigit (d[j]))
				      {
					g = 1;
					break;
				      }
				    else
				      {
					g = 0;
				      }
				  }

				if (d.length () != 9)
				  {
				    cout <<
				      "an ID number consists of nine digits\n";
				    g = 1;
				  }
				if (g == 1)
				  {
				    cout << "Please Enter a Valid ID\n";
				  }
				else
				  {
				    if (students.exists (D))	//if student ID is on the list
				      {
					g = 0;
					int
					  e = 1;
					while (e)
					  {
					    string
					      in;
					    cout << "Are you sure you want student number: " << D << " removed from record? [y/n]: ";	//removal confirmation check
					    getline (cin, in);
					    if (in.length () == 1)
					      {
						char
						  t = in[0];

						switch (t)
						  {
						  case 'y':
						    {
						      students.rem (D);
						      i--;	//list item counter
						      e = 0;
						      break;
						    }
						  case 'Y':
						    {
						      students.rem (D);
						      i--;	//list item counter
						      e = 0;
						      break;
						    }
						  case 'n':
						    {
						      e = 0;
						      break;
						    }


						  case 'N':
						    {
						      e = 0;
						      break;
						    }
						  default:
						    {
						      cout <<
							"Invalid Input\n";
						      break;
						    }
						  }
					      }
					    else
					      {
						cout << "Invalid Input\n";
					      }

					  }
				      }
				    else if (!students.exists (D))	//if student is not found let member function rem confirm that
				      {
					students.rem (D);
				      }
				  }
			      }
			  }
			break;
		      }
		    case '3':	//Search
		      {
			if (i == 0)
			  {
			    cout << "There's no one to search for\n";
			  }
			else
			  {
			    int
			      g = 1;
			    while (g)
			      {
				int
				  D;	//ID input validity check
				string
				  d;
				cout << "\nID: ";
				getline (cin, d);
				D = atoi (d.c_str ());
				for (int j = 0; j < d.length (); ++j)
				  {

				    if (!isdigit (d[j]))
				      {
					g = 1;
					break;
				      }
				    else
				      {
					g = 0;
				      }
				  }

				if (d.length () != 9)
				  {
				    cout <<
				      "an ID number consists of nine digits\n";
				    g = 1;
				  }
				if (g == 1)
				  {
				    cout << "Please Enter a Valid ID\n";
				  }
				else	//search function call
				  {
				    students.srch (D);
				  }
			      }
			  }
			break;
		      }
		    case '4':	//print
		      {
			if (i == 0)	//if empty list
			  {
			    cout << "The list of student records is empty\n";
			  }
			else
			  {
			    cout << "\nList of student records:\n";	//print function call
			    students.print ();
			  }
			break;
		      }
		       case '5':// EXIT
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
		    default:	//if entered option is not valid
		      {
			cout << "\nInvalid Option Please Try again\n";
			break;
		      }

		    }
		}
	      else		// main menu option input validity check
		{
		  cout << "\nInvalid Option Please Try again\n";
		}
	    }
	}
    }
}
