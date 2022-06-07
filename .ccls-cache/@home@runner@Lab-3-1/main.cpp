#include <stdio.h>
#include <iostream>
using namespace std;
class A {
public:
  A();         //it creates a default constructor 
  A(int);      //it creates a constructor that has an intiger 
  A(const A&); //it creates a constructor that has a constant call by reference
               //Space 
  ~A();        // it creates a default destructor
public:
  void operator=(const A& rhs); // it creates a function called operator that calls a constant by reference
  void Print();        //it prints x
  void PrintC() const; //it prints x as a const
                       //                       
  int x;       // declare x as an integer
public:
  // 
  int& X() { return x; }
};
A::A()
  : x(0)
{ 
  cout << "Hello from A::A() Default constructor" << endl;
}
A::A(int i)
    : x(i)
{
  cout << "Hello from A::A(int) constructor" << endl;
}
A::A(const A& a)
    : x(a.x)
{
  cout << "Hello from A::A(const A&) constructor" << endl;
}
A::~A()
{
  cout << "Hello from A::A destructor" << endl;
}
void A::operator=(const A& rhs)
{
  x = rhs.x;
  cout << "Hello from A::operator=" << endl;
}
void A::Print()
{
  cout << "A::Print(), x " << x << endl;
}
void A::PrintC() const
{
  cout << "A::PrintC(), x " << x << endl;
}
void PassAByValue(A a)
{
  cout << "PassAByValue, a.x " << a.x << endl;
  a.x++;  //it adds one to x and pass a to x by value, not by reference
  a.Print();
  a.PrintC();
}
void PassAByReference(A& a)
{
  cout << "PassAByReference, a.x " << a.x << endl;
  a.x++;  // it adds one to x and pass a to x by reference
  a.Print();
  a.PrintC();
}
void PassAByConstReference(const A& a)
{
  cout << "PassAByReference, a.x " << a.x << endl;
a. PrintC();  // it prints x
//a.Print(); // Call to "non-const" print function fails!
  // Compiler error from above line.  Why?
}
void PassAByPointer(A* a)
{
  cout << "PassAByPointer, a->x " << a->x << endl;
  a->x++; //it adds one to x and pass a to x by pointer
  a->Print(); 
  a->PrintC();
}
int main()
{
  cout << "Creating a0"<<endl; getchar();
  A a0;    // it creates a0 that is initialized in A() with 0 value
  cout << "Creating a1"<<endl; getchar();
  A a1(1); // creates a1 that has a 1 value
  cout << "Creating a2"<<endl; getchar();
  A a2(a0); //  it creates a2 that has 0 value and it is called by valu
  cout << "Creating a3"<<endl; getchar();
  A a3 = a0; // it creates a3 and assing to it 0 value
  cout << "Assigning a3 = a1"<<endl; getchar();
  a3 = a1; // it assigns a3 a1 value
  // Call some of the "A" subroutines
  cout << "PassAByValue(a1)"<<endl; getchar();
  PassAByValue(a1); // it pass by value a1
  cout << "After PassAByValue(a1)" << endl;
  a1.Print();
  
  cout << "PassAByReference(a1)"<<endl; getchar();
  PassAByReference(a1); // it pass by reference a1
  cout << "After PassAByReference(a1)" << endl;
  a1.Print();
  
  cout << "PassAByConst(a1)"<<endl; getchar();
  PassAByConstReference(a1); // it pass by a constant reference wich means it value can not be changed
  cout << "After PassAByConstReference(a1)" << endl;
  a1.Print();
  
  cout << "PassAByPointer(&a1)"<<endl; getchar();
  PassAByPointer(&a1); // it pass by a pointer, pointing the memory space where x is 
  cout << "After PassAByPointer(a1)" << endl;
  a1.Print();
  // 
  cout << "a1.X() = 10"<<endl; getchar();
  a1.X() = 10;
  a1.Print();
  cout << "PassAByConstReference"<<endl; getchar();
  PassAByConstReference(20);
  // Why does the above compile?  What does it do?
  return 0;
  }