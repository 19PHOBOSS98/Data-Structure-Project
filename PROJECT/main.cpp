//main body

#include <iostream>
#include <string>
#include<cstdlib>

#include "practice.h"
#include "magicsqr.h"
#include "stackarray.h"
#include "queuell.h"
#include "queuearr.h"
#include "recursion.h"
#include "graph.h"
#include "midterms.h"
#include "finalexam.h"
using namespace std;

int
main ()
{
  string op;
  int o;
  int w=1;
  while (w)
    {
      cout << endl << "FINAL PROJECT COMPILATION:" << endl << endl;
      cout << "[1]  Lab Activity 1 (Practice)" << endl;
      cout << "[2]  Lab Activity 1 (Magic Square)" << endl;
      cout << "[3]  Lab Activity 3 (Stack Array)" << endl;
      cout << "[4]  Lab Activity 4 (Queue Linked List)" << endl;
      cout << "[5]  Lab Activity 4 (Queue Array)" << endl;
      cout << "[6]  Lab Activity 5 (Recursion)" << endl;
      cout << "[7]  Lab Activity 7 (Graphs)" << endl;
      cout << "[8]  Midterm Practical Exam" << endl;
      cout << "[9]  Final Practical Exam" << endl;
      cout << "[10] Close Program" << endl;
      cout << "Option: ";
      getline (cin, op);
      if (op.length () > 2)
{
 cout << "Invalid Input\n";
}
      else
{
 o=atoi(op.c_str());
 switch (o)
   {
   case 1:
     {
         cout<<"\nLab Activity 1 (Practice)\n";
         practice();
     break;
     }
   case 2:
     {
         cout<<"\nLab Activity 1 (Magic Square)\n";
         magicSqr();
     break;
     }
   case 3:
     {
         cout<<"\nLab Activity 3 (Stack Array)\n";
         stackAry();
		 break;
     }
   case 4:
     {
         cout<<"\nLab Activity 4 (Queue Linked List)\n";
         QL();
break;
     }
   case 5:
     {
         cout<<"\nLab Activity 4 (Queue Array)\n";
         QA();
break;
     }
   case 6:
     {
         cout<<"\nLab Activity 5 (Recursion)\n";
         rec();
break;
     }
   case 7:
     {
         cout<<"\nLab Activity 7 (Graphs)\n";
         graph();
		 break;
     }
   case 8:
     {
         cout<<"\nMidterm Practical Exam\n";
         ME();
break;
     }
   case 9:
     {
         cout<<"\nFinal Practical Exam\n";
         FE();
		 break;
     }
   case 10:
   	 {
   	 	 int r = 1;
        while (r)
    	{
    	    string input;
    	    char c;
    	    cout << "\nDo you wish to terminate the program? [y/n]: ";
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
   default:
     {
cout << "Invalid Input\n";
break;
     }


   }
}
    }
    
}

