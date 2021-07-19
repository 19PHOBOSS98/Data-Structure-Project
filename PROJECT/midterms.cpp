//midterms  practical exam
#include "midterms.h"

#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

static nde *tmp,*tp=NULL;
static string zi,y,x;
static int i=0;

void psh(char a)
{
    tmp=new nde;
    tmp->data=a;
    tmp->next=tp;
    tp=tmp;
}

void pp()
{
    tmp=tp;
    if(tp==NULL) 
    {
        return;
    }
    else
    {
        tp=tp->next;
        delete (tmp);

    }
            
}


void InfixToPostfix(string z)
{
    y="";
    x="";
    cout<<"Infix"<<setw(35)<<"Stack"<<setw(35)<<"Postfix"<<endl;
    for(int j=0;j<z.size();j++)
       {
           
            if(isop(z[j]))
            {
                if (z[j] =='(') 
                {
                    psh(z[j]);
                  x+=tp->data;
                }
            
                else if(z[j]==')')
                {
                    while((tp!=NULL) && tp->data !=  '(') 
                    {
                    y += tp->data;
                    x.erase(x.end()-1);
                    pp();
                    }
                    x.erase(x.end()-1);
                    pp();
                }
                
                else
                {
                  while((tp!=NULL)&&(tp->data!= '(')&&(isH(tp->data,z[j])))
                  {
                      y+=tp->data;
                        x.erase(x.end()-1);
                      pp();
                  }
                  psh(z[j]);
                  x+=tp->data;
                }
                  
                
            }
            
            
            else if(isalp(z[j]))
            {
               y+=z[j];
            }
            cout<<z[j]<<setw(35)<<x<<setw(39)<<y<<endl;
       }
       
        while(tp!=NULL)
        {
            y+=tp->data;
            x.erase(x.end()-1);
            pp();
        }
            cout<<"Postfix: "<<y<<endl;
}


bool isalp(char b)
{
    if(isalpha(b))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isop(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='('||c==')')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int weight(char d)
{
    switch (d)
    {
        case '+': 
        {
            return 1;
            break;
        }
        case '-': 
        {
            return 1;
            break;
        }
        case '*': 
        {
            return 2;
            break;
        }
        case '/': 
        {
            return 2;
            break;
        }
        default:
        {
            return 0;
            break;
        }
    }
}

bool isH(char e,char f)
{
    if(weight(e)>=weight(f))
    {
        return true;
    }
    else
    {
        return false;
    }
}




void ME()
{
	cout<<"Midterm Practical Exam\nName: Obordo, Kim Nickho A.     Date: May 20, 2019\nSubject/Section:CCS0015L N04    Prof. Aki Anthony Aquino\nTotal Lines: 193\n------------------------------------\n";
	
	int w=1;
	while(w)
   {
       cout<<"Input Infix here: \n";
       cin>>zi;
       cin.ignore();
		cout<<"\nPostfix: \n";
       InfixToPostfix(zi);
	 
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
	        
   }
}
