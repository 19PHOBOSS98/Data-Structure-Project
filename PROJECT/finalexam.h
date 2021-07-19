//final practical exam header
#ifndef FINALEXAM_H
#define FINALEXAM_H
#include<string>
class records			//object class records
{
private:
  struct node			//Node structure of Doubly Linked List / Undirected Graph
  {
    int ID;
    std::string Name;
    std::string Course;
    std::string Year;
    std::string Age;
    node *next;
    node *prev;
  };

  node *head = NULL, *tail = NULL, *tmp, *acc;	//Node pointers

  bool srch_priv (node *, int);	//private recursive member functions
  void rem_priv (node *, int);
  void sort_priv (node *, node *);
  bool exists_priv (node *, int);

public:
  void add (int, std::string,std::string,std::string,std::string);	//Public member funtions to call private member functions
  void srch (int);
  void rem (int);
  void sort ();
  void print ();
  bool exists (int);
};

void FE();

#endif
