#include "Bubble.h"
#include <iostream>
#include <sys/time.h>


Bubble::Bubble()
{
    bubbleComparisons = 0; ///< Initilize the bubbleComparisons.
    bubbleComparisons_Sorted = 0; ///< Initilize the bubbleComparisons_Sorted.
    bubbleSwaps = 0; ///< Initilize the bubbleSwaps.
    bubbleSwaps_Sorted = 0; ///< Initilize the bubbleSwaps_Sorted.
}
/// Get the value of bubbleComparisons.
long Bubble::getBubbleComparisons(){
    return bubbleComparisons; ///< Return the value of bubbleComparisons.
}
/// Get the value of bubbleComparisons_Sorted.
long Bubble::getBubbleComparisons_Sorted(){
    return bubbleComparisons_Sorted;
    ///< Return the value of bubbleComparisons_Sorted.
}
/// Get the value of getBubbleSwaps.
long Bubble::getBubbleSwaps(){
    return bubbleSwaps; ///< Return the value of bubbleSwaps.
}
/// Get the value of getBubbleSwaps_Sorted.
long Bubble::getBubbleSwaps_Sorted(){
    return bubbleSwaps_Sorted;///< Return the value of bubbleSwaps_Sorted.
}

/// Define the swap funtion.
void Bubble::swap(int &a, int &b){
    int tmp;
    tmp = a;
    a = b;
    b =tmp;
}

void Bubble::bubbleSort(int arr[],int num)
{
  ///It will traverse the array from the second to the last.
  for( int i = 1; i < num; i++){
        int j;
    /// If the number is greater than the following ,they will switch.
    for(j =0;j<num-i;j++){
        if(arr[j]>arr[j+1]){
            swap(arr[j+1], arr[j]);
            bubbleSwaps++; ///< Count the numbers of swaps.
        }
    }
   bubbleComparisons += j; ///< Count the numbers of comparisons.
  }

}

/// If the number is greater than the following ,they will switch.
void Bubble::bubbleSort_Sorted(int arr[],int num)
{
  ///It will traverse the array from the second to the last.
  for(int i = 1; i < num; i++){
    int j;
    for(j =0;j<num-i;j++)
    if(arr[j]>arr[j+1]){
      swap(arr[j+1], arr[j]);
      bubbleSwaps_Sorted++; ///< Count the numbers of swaps.
    }
    bubbleComparisons_Sorted += j; ///< Count the numbers of comparisons.
  }
}


/// To get the running time of bubble sort.
double Bubble::bubbleTime(int arr[],int num){
    struct timeval t1,t2; ///< Define the t1, t2.
    double bubbleTimeuse; ///< Define the running time.
    gettimeofday(&t1,NULL); ///< Get the time before the sort.
    bubbleSort(arr,num); ///< Call the bubble sort method.
    gettimeofday(&t2,NULL);///< Get the time after the sort.
    bubbleTimeuse = t2.tv_sec - t1.tv_sec + (t2.tv_usec - t1.tv_usec)/1000000.0;
    ///< Get the running time by the difference of two times.
    return bubbleTimeuse;///< Return the running time.
}
/// To get the running time of bubble sort.
double Bubble::bubbleTimeSorted(int arr[],int num){
    struct timeval t1,t2; ///< Define the t1, t2.
    double bubbleTimeuse_Sorted;///< Define the running time.
    gettimeofday(&t1,NULL);///< Get the time before the sort.
    bubbleSort_Sorted(arr,num);///< Call the bubble sort method
    gettimeofday(&t2,NULL); ///< Get the time after the sort.
    bubbleTimeuse_Sorted = t2.tv_sec - t1.tv_sec + (t2.tv_usec - t1.tv_usec)/1000000.0;
    ///< Get the running time by the difference of two times.
    return bubbleTimeuse_Sorted;///< Return the running time.
}
