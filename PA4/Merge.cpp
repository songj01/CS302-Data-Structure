#include "Merge.h"
#include <sys/time.h>
#include <iostream>

Merge::Merge()
{
    mergeComparisons = 0;///< Initilize the mergeComparisons.
    mergeComparisons_Sorted = 0; ///< Initilize the mergeComparisons_Sorted.
    mergeSwaps = 0; ///< Initilize the mergeSwaps.
    mergeSwaps_Sorted = 0; ///< Initilize the mergeSwaps_Sorted.
}
/// Get the value of mergeComparisons.
long Merge::getMergeComparisons(){
    return mergeComparisons; ///< Return the value of mergeComparisons.
}

/// Get the value of mergeComparisons_Sorted.
long Merge::getMergeComparisons_Sorted(){
    return mergeComparisons_Sorted;
    ///< Return the value of mergeComparisons_Sorted.
}
/// Get the value of mergeSwaps.
long Merge::getMergeSwaps(){
    return mergeSwaps;///< Return the value of mergeSwaps.
}
/// Get the value of mergeSwaps_Sorted.
long Merge::getMergeSwaps_Sorted(){
    return mergeSwaps_Sorted;///< Return the value of mergeSwaps_Sorted.
}

/// Devided the arary into two parts and merge recursively. 
void Merge::mergeSort(int arr[], int first, int last){
    if(last>first){
    int mid = (first+last)/2;
        mergeSort(arr,first,mid);
        mergeSort(arr,mid+1,last);
        mergeAlg(arr,first,last);
    }
}
/// It is the same as the method of mergeSort.
void Merge::mergeSort_Sorted(int arr[], int first, int last){
    if(last>first){
    int mid = (first+last)/2;
        mergeSort_Sorted(arr,first,mid);
        mergeSort_Sorted(arr,mid+1,last);
        mergeAlgSorted(arr,first,last);
    }
}

/// The merhod is to merge the data with two arrays in the order.
void Merge::mergeAlg(int arr[], int first, int last){
    int *tmp = new int[last+1];///< Setup the new temporary array.
    int mid = (first + last)/2;///< Define and compute the middle of array.
    int first1 =first;
    int last1 = mid;
    int first2 = mid+1;
    int last2 = last;
    int index = first1;
    /** Compare the data from beginning and store the less data in the order.
      * If the data in the first array is less, then store it in the temporary,
      * or store the other data into the temporary.
      */
    while((last1>=first1)&&(last2>=first2)){
      if(arr[first1]<=arr[first2])
        tmp[index++]=arr[first1++];
      else
        tmp[index++]=arr[first2++];
        mergeComparisons++; ///< Count the numbers of comparison.
      }
    /** If the first array has more data after the first step, then store them
      * into the temporary; If the secend array has more data after the first
      * step, then store them into the temporary.
      */
    while(last1>=first1){
      tmp[index++]=arr[first1++];
      }
    while(last2>=first2){
      tmp[index++]=arr[first2++];
      }
    /// Output the data from the tmporary array into the array.
    for(int i=first; i< index;i++)
    arr[i] = tmp[i];
    delete[]tmp; ///< Delete the tmp pointer.
    tmp = nullptr; ///< Assign null to tmp.
}

/// It is the same as the method of mergeAlg.
void Merge::mergeAlgSorted(int arr[], int first, int last)
{
    int *tmp = new int[last+1];
    int mid = (first + last)/2;
    int first1 =first;
    int last1 = mid;
    int first2 = mid+1;
    int last2 = last;
    int index = first1;
    while((last1>=first1)&&(last2>=first2)){
      if(arr[first1]<=arr[first2])
        tmp[index++]=arr[first1++];
      else
        tmp[index++]=arr[first2++];
        mergeComparisons_Sorted++;
      }
    while(last1>=first1){
      tmp[index++]=arr[first1++];
      }
    while(last2>=first2){
      tmp[index++]=arr[first2++];
      }
    for(int i=first; i< index;i++)
    arr[i] = tmp[i];
    delete[]tmp;
    tmp = nullptr;
}

/// To get the running time of merge sort.
double Merge::mergeTime(int arr[], int first, int last){
    struct timeval t1,t2; ///< Define the t1, t2.
    double mergeTimeuse; ///< Define the running time.
    gettimeofday(&t1,NULL); ///< Get the time before the sort.
    mergeSort(arr,first, last); ///< Call the merge sort method
    gettimeofday(&t2,NULL); ///< Get the time after the sort.
    mergeTimeuse = t2.tv_sec - t1.tv_sec + (t2.tv_usec - t1.tv_usec)/1000000.0;
   ///< Get the running time by the difference of two times.
    return mergeTimeuse; ///< Return the running time.
}

/// It is the same as the method of mergeTime.
double Merge::mergeTimeSorted(int arr[], int first, int last){
    struct timeval t1,t2;
    double mergeTimeuse_Sorted;
    gettimeofday(&t1,NULL);
    mergeSort_Sorted(arr,first, last);
    gettimeofday(&t2,NULL);
    mergeTimeuse_Sorted = t2.tv_sec - t1.tv_sec + (t2.tv_usec - t1.tv_usec)/1000000.0;
    return mergeTimeuse_Sorted;
}
