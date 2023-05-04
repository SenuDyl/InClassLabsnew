#include <iostream>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   // obtain the index of the left child and the right child
   int Left=2*root+1;
   int Right=2*root+2;
   int Largest=root;
   // Exchange the indexes if the left child is greater
   if (Left<n && arr[Left]>arr[Largest]){
      Largest=Left;
   }else{
      Largest=root;
   }
   //Check if the right child is greater
   if (Right<n && arr[Right]>arr[Largest]){
      Largest=Right;
   }
   // Swap the values such that the maximum value is in the parent node
   if (Largest!=root){
      int temp=arr[root];
      arr[root]=arr[Largest];
      arr[Largest]=temp;
      // Invoke the heapify function to heapify the next sub tree
      heapify(arr,n,Largest);
   }
}

// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for (int j = n / 2 - 1; j >= 0; j--)
   {   
      heapify(arr, n, j);
   }
   // extracting elements from heap one by one  
   for (int i = n - 1; i >= 0; i--) {
      //Swap the highest value with the last value in the array
      int temp=arr[0];
      arr[0]=arr[i];
      arr[i]=temp;
      // Invoke heapify function to get the maximum number at the root again
      heapify(arr, i, 0);
   }
   
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   int heap_arr[] = {4,17,3,12,9,6};
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
   int newArr[8];
   int x=8;
   for(int j=0;j<8;j++){
      int x;
      cin>>x;
      newArr[j]=x;
   }
   cout<<"Input array"<<endl;
   displayArray(newArr,x);
  
   heapSort(newArr, x);
  
   cout << "Sorted array"<<endl;
   displayArray(newArr, x);

}