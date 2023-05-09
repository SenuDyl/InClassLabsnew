//Array implementation of a stack
#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace std::chrono;
//Declare global array and a global variable top because there are used in multiple functions
int top=-1;
int arr[10];
//Increment the value of top using a function having a reference as an argument
void increment(int *v){
    (*v)++;
}
//Define a function to check if the array is empty or not
bool IsEmpty(){
    if (top>=0){
        return false;
    }else{
        return true;
    }
}
//Define a function to see if the array is full
bool isFull(){
    if (top+1==10){
        return true;
    }else{
        return false;
    }
}
//Define a function to see the element at the top of the array
void stackTop(){
    cout<<arr[top];
}
//Add value at the end of the array--Insertion
void push(int value){
    if(isFull()==false){
        increment(&top);
        arr[top]=value;
    }else{
        //Check if the array is full
        cout<<"Stack Overflow"<<endl;
    }
}
//Delete value at the end of the array--Deletion
void pop(){
    if (IsEmpty()!=true){
        top--;
        cout<<arr[top+1]<<endl;
    }else{
        cout<<"Stack Underflow"<<endl;
    }
}
//Function to display all the elements in the array
void display(){
    for(int i=0;i<top+1;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    auto start = high_resolution_clock::now();
    push(8);
    push(10);
    push(5);
    push(11);
    push(15);
    push(23);
    push(6);
    push(18);
    push(20);
    push(17);
    display();
    pop();
    pop();
    pop();
    pop();
    pop();
    display();
    push(4);
    push(30);
    push(3);
    push(1);
    display();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "time taken is "
       << (duration.count())*0.000001<< " seconds" << endl;
    return 0;

}