//practice
#include "practice.h"

#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

string s, t;
int i, r, n = 0, a[5] = { };

bool
Notdigit (string input)
{
  for (int j = 0; j < input.length (); j++)
    {
      if ((!isdigit (input[j])) && (input[j] != ' ') && (input[j] != ','))
return true;
    }
  return false;
}

void
practice ()
{
  int w = 1;
  while (w)
    {

      cout << "\nEnter Grades: ";
      getline (cin, s);
      if (Notdigit (s))
        {
         cout << "Invalid Input\n";
        }
      else if ((!isdigit (s[0])) || (!isdigit (s[s.length () - 1])))
        {
         cout << "Please don't start or end with non numerical characters\n";
        }
      else
        {
          for (int i = 0; i < s.length (); i++)
            {
              if ((s[i] != ' ') && (s[i] != ','))
                {
                  t.push_back (s[i]);
                }
              else
                {
                  a[n] = atoi (t.c_str());
                  t.clear ();
                  n++;
                }
            }

          a[n] = atoi (t.c_str());
          t.clear ();
          if (n > 4)
            {
              cout << "too many entries\n";
            }
          else if (n < 4)
            {
              cout << "not enough entries\n";
            }

          else
           {
             for (int j = 0; j < 5; j++)
              {
                r = 1;
                if ((a[j] < 0) || (a[j] > 100))
                  {
                    cout << "\nEach entry must be between 0-100";
                    r = 0;
                    break;
                  }
              }
             if (r)
              {
               cout << "Passing Grades: ";
               for (int j = 0; j < 5; j++)
                 {
                    if (a[j] >= 70)
                      {
                        cout << a[j] << " ";
                      }
                 }
               cout << "\nFailing Grades: ";
               for (int j = 0; j < 5; j++)
                 {
                    if (a[j] < 70)
                      {
                        cout << a[j] << " ";
                      }
                 }
              }
            }
          n = 0;
        }
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
                 cout << "Invalid Input\n";
                 break;
                }
             }
        }

    }
}

