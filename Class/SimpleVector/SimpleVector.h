// SimpleVector class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
using namespace std;

template <class T>
class SimpleVector
{
private:
   T *aptr;          // To point to the allocated array
   int arraySize;    // Number of elements in the array
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range

public:
   // Default constructor
   SimpleVector()
      { aptr = 0; arraySize = 0;}
      
   // Constructor declaration
   SimpleVector(int);
   
   // Copy constructor declaration
   SimpleVector(const SimpleVector &);
   
   // Destructor declaration
   ~SimpleVector();
   
   // Accessor to return the array size
   int size() const
      { return arraySize; }

   // Accessor to return a specific element
   T getElementAt(int position);
   
   //Push a value to the top of the array, add 1
   void push(T value);
   
   //Pull a value from the top of the array, minus 1
   void pull();

   // Overloaded [] operator declaration
   T &operator[](const int &);
};

int main()
{
    int para = 5;
    SimpleVector<float> simVec(para);
    cout << "============================" << endl;
    cout << "Creating array of size (" 
            << para << ")" << endl;
    cout << "The size of the array is: " << simVec.size() << endl;
    for(int i = 0; i < simVec.size(); i++)
        {
            cout << simVec.getElementAt(i) << " "; 
        }
    
    cout << endl << endl << "============================" << endl;
    cout << "Push a num" << endl;
    simVec.push(3);
    cout << "The size of the array is: " << simVec.size() << endl;
    for(int i = 0; i < simVec.size(); i++)
        {
            cout << simVec.getElementAt(i) << " "; 
        }
        
    cout << endl << endl <<  "============================" << endl;
    cout << "Push a num" << endl;
    simVec.push(5);
    cout << "The size of the array is: " << simVec.size() << endl;
    for(int i = 0; i < simVec.size(); i++)
        {
            cout << simVec.getElementAt(i) << " "; 
        }
    
    cout << endl << endl <<  "============================" << endl;
    cout << "Pull a num" << endl;
    simVec.pull();
    cout << "The size of the array is: " << simVec.size() << endl;
    for(int i = 0; i < simVec.size(); i++)
        {
            cout << simVec.getElementAt(i) << " "; 
        }
    
    cout << endl << endl <<  "============================" << endl;
    cout << "Pull a num" << endl;
    simVec.pull();
    cout << "The size of the array is: " << simVec.size() << endl;
    for(int i = 0; i < simVec.size(); i++)
        {
            cout << simVec.getElementAt(i) << " "; 
        }
    
    return 0;
}

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
SimpleVector<T>::SimpleVector(int s)
{
   arraySize = s;
   // Allocate memory for the array.
   try
   {
      aptr = new T [s];
   }
   catch (bad_alloc)
   {
      memError();
   }

   // Initialize the array.
   for (int count = 0; count < arraySize; count++)
      *(aptr + count) = 0;
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
   // Copy the array size.
   arraySize = obj.arraySize;
   
   // Allocate memory for the array.
   aptr = new T [arraySize];
   if (aptr == 0)
      memError();
      
   // Copy the elements of obj's array.
   for(int count = 0; count < arraySize; count++)
      *(aptr + count) = *(obj.aptr + count);
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector()
{
   if (arraySize > 0)
      delete [] aptr;
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVector<T>::memError()
{
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVector<T>::subError()
{
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************

template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}

//*******************************************************
// push function. Augment the array by 1 at the top    *
// to hold the new value pushed *
//*******************************************************

template <class T>
void SimpleVector<T>::push(T value)
{
    if(arraySize == 0)
    memError();
    else {
    T * tmpArryPtr = new T[arraySize + 1];
    arraySize++;
    tmpArryPtr[0] = value;
    for(int i = 1; i < arraySize; i++)
        {
            tmpArryPtr[i] = aptr[i-1];
        }
    delete[] aptr;
    aptr = new T[arraySize];
    for(int i = 0; i < arraySize; i++)
    {
        aptr[i] = tmpArryPtr[i];
    }
    delete[] tmpArryPtr;
    }
}

//*******************************************************
// pull function. Takes one value off the top of the    *
// array and decreases the size by 1. *
//*******************************************************

template <class T>
void SimpleVector<T>::pull()
{
    if(arraySize == 0)
    memError();
    else {
    T * tmpArryPtr = new T[arraySize - 1];
    arraySize--;
    for(int i = 0; i < arraySize; i++)
        {
            tmpArryPtr[i] = aptr[i + 1];
        }
    delete[] aptr;
    aptr = new T[arraySize];
    for(int i = 0; i < arraySize; i++)
    {
        aptr[i] = tmpArryPtr[i];
    }
    delete[] tmpArryPtr;
    }
}

#endif