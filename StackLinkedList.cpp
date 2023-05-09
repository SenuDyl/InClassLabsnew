//LinkedList implementation of a stack
#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

class Node{
public:
    int data;
    Node*link;
    Node(int x){
        this->data=x;
        this->link=NULL;
    }
};

class Stack{
    Node* top=NULL;
public:
    void push(int d){
        Node* ptr=new Node(d);
        ptr->data=d;
        ptr->link=NULL;
        ptr->link=top;
        top=ptr;
        
    }
    bool isEmpty(){
        if (top==NULL){
            return true;
        }else{
            return false;
        }
    }
    void pop(){
        Node* ptr2=top;
        if (isEmpty()==true){
            cout<<"Stack Underflow"<<endl;
        }
        
        int dlt=ptr2->data;
        top=top->link;
        delete ptr2;
        cout<< dlt<<endl;
    }
    void display(){
        Node*ptr3;
        if (top!=NULL){
            ptr3=top;
            while(ptr3!=NULL){
                cout<<ptr3->data<<" ";
                ptr3=ptr3->link;
            }
            cout<<endl;
        }
    }
    
};
int main(){
    auto start = high_resolution_clock::now();
    Stack newStack;
    newStack.push(8);
    newStack.push(10);
    newStack.push(5);
    newStack.push(11);
    newStack.push(15);
    newStack.push(23);
    newStack.push(6);
    newStack.push(18);
    newStack.push(20);
    newStack.push(17);
    newStack.display();
    newStack.pop();
    newStack.pop();
    newStack.pop();
    newStack.pop();
    newStack.pop();
    newStack.display();
    newStack.push(4);
    newStack.push(30);
    newStack.push(3);
    newStack.push(1);
    newStack.display();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "time taken is "
       << (duration.count())*0.000001<< " seconds" << endl;
    return 0;
}