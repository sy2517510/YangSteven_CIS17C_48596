/*
 * File:   main.cpp
 * Author: Steven Yang
 * Created on August 27, 2014, 8:05 PM
 * Purpose:  First Data Structure Triangular Array
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

//Class
template<class T>
class TriArray{
public:
T* fillArray(int);
T** fillArray(int,int);
T** fillArray(int,T*);
void printArray(T*,int,int);
void printArray(T**,int,int);
void printArray(T**,int,T *);
void destroy(T *);
void destroy(T **,int);

};

//Execution Begins Here
int main(int argc, char** argv) {

    //float array
    cout << "This is float" << endl;
    cout << "-------------" << endl;

    TriArray<float> triArray;

    //Initialize the random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Declare the 2-D Array
    int rows=5,cols=10;
    int cls=rows,perLine=10;
    float **array= triArray.fillArray(rows,cols);
    float *colAry=triArray.fillArray(cls);
    float **triAry=triArray.fillArray(rows,colAry);
    //Print the array
    triArray. printArray(array,rows,cols);
    triArray.printArray(colAry,cls,perLine);
    triArray.printArray(triAry,rows,colAry);
    //Delete the array
    triArray.destroy(array,rows);
    triArray.destroy(triAry,rows);
    triArray.destroy(colAry);

    //int array
    cout << "This is int" << endl;
    cout << "-------------" << endl;

    TriArray<int> triArray2;

    int **array2= triArray2.fillArray(rows,cols);
    int *colAry2=triArray2.fillArray(cls);
    int **triAry2=triArray2.fillArray(rows,colAry2);
    //Print the array
    triArray2.printArray(array2,rows,cols);
    triArray2.printArray(colAry2,cls,perLine);
    triArray2.printArray(triAry2,rows,colAry2);

    //Delete the array
    triArray2.destroy(array2,rows);
    triArray2.destroy(triAry2,rows);
    triArray2.destroy(colAry2);

    //Exit stage right
    char c;
	  cin >> c;
    return 0;
}

template<class T>
void TriArray<T>::destroy(T *array){
    //Destroy row pointers
    delete []array;
}

template<class T>
void TriArray<T>::destroy(T **array,int rows){
    //Destroy cols
    for(int row=0;row<rows;row++){
        delete []array[row];
    }
    //Destroy row pointers
    delete []array;
}

template<class T>
void TriArray<T>::printArray(T*array,int cols,int perLine){
    //Print the Array
    cout<<endl;
    for(int col=0;col<cols;col++){
       cout<<fixed << setprecision(2)<< array[col]<<" ";
       if(col%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

template<class T>
void TriArray<T>::printArray(T**array,int rows,T *colAry){
    //Print the Array
    cout<<endl;
    for(int row=0;row<rows;row++){
        for(int col=0;col<colAry[row];col++){
            cout<<fixed << setprecision(2)<< array[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

template<class T>
void TriArray<T>::printArray(T**array,int rows,int cols){
    //Print the Array
    cout<<endl;
    for(int row=0;row<rows;row++){
        for(int col=0;col<cols;col++){
            cout<< fixed << setprecision(2)<< array[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

template<class T>
T* TriArray<T>::fillArray(int cols){
    //Declare the 1-D Array
    T * array=new T[cols];
    //Fill the array with random 2 digit numbers
    for(int col=0;col<cols;col++){
        array[col]=rand()%9+2;
    }
    return array;
}

template<class T>
T** TriArray<T>::fillArray(int rows,T *colAry){
    //Declare the 2-D Array
    T ** array=new T*[rows];
    for(int row=0;row<rows;row++){
        //cout<<"Number of Cols = "<<colAry[row]<<endl;
        array[row]=new T[(int)colAry[row]];
    }
    //Fill the array with random 2 digit numbers
    for(int row=0;row<rows;row++){
        for(int col=0;col<colAry[row];col++){
            array[row][col]=rand()%90+10;
            //cout<<"Row Col"<<row<<" "<<col<<endl;
        }
    }
    return array;
}

template<class T>
T** TriArray<T>::fillArray(int rows,int cols){
    //Declare the 2-D Array
    T ** array=new T*[rows];
    for(int row=0;row<rows;row++){
        array[row]=new T[cols];
    }
    //Fill the array with random 2 digit numbers
    for(int row=0;row<rows;row++){
        for(int col=0;col<cols;col++){
            array[row][col]=rand()%90+10;
        }
    }
    return array;
}
