#include "Radix.h"
#include <sys/time.h>
#include <cmath>
#include <iostream>

Radix::Radix()
{
    radixComparisons = 0; ///< Initilize the radixComparisons.
    radixComparisons_Sorted  = 0; ///< Initilize the radixComparisons_Sorted.
    radixSwaps = 0; ///< Initilize the radixSwaps.
    radixSwaps_Sorted = 0; ///< Initilize the radixSwaps_Sorted.
}
/// Get the value of radixComparisons.
long Radix::getRadixComparisons(){
    return radixComparisons; ///< Return the value of radixComparisons.
}
/// Get the value of radixComparisons_Sorted.
long Radix::getRadixComparisons_Sorted(){
    return radixComparisons_Sorted;
    ///< Return the value of radixComparisons_Sorted.
}
/// Get the value of radixSwaps.
long Radix::getRadixSwaps(){
    return radixSwaps; ///< Return the value of radixSwaps.
}

/// Get the value of radixSwaps_Sorted.
long Radix::getRadixSwaps_Sorted(){
    return radixSwaps_Sorted; ///< Return the value of radixSwaps_Sorted.
}


/// Get the max number of array.
int Radix::maxVal(int arr[], int num){
    int tmp = arr[0];
    for(int i = 1; i < num; i++){
        if(arr[i] > tmp)
            tmp = arr[i];
    }
    return tmp;
}
/// Get the maxdigit of max number.
int Radix::maxDigit(int arr[], int num){
    int p = maxVal(arr,num); ///< Call maxVal method and get the max number.
    int i = 0; ///< Define the variable i to record the max digit.
    while(p > 0){
        p = p/10;
        ///< The value decrease that means the digit decrease one once.
        i++;
    }
    return i; ///< Return the max digit.
}
/// Countingsort sorts the data by counting the numbers without comparisons.
void Radix::countSort(int arr[],int num, int exp){
    int counter[10]; ///< Setup an array to store 0~9;
    int *tmp = new int[num];///< Setup new temporary array.
    for(int i =0; i<10;i++){counter[i] = {0};}
    ///< Initialize the array of counter.
/** Scan the array which is combined by the value of each digit, and put the
  * value into the position which  is equal to the value.
  */
    for(int j =0; j< num; j++){
        int val = arr[j]/exp;
        int index = val%10;
        counter[index]++;
        }
    /// Count the numbers of data that is not greater than it self.
    for(int k =1; k <10; k++){
        counter[k] = counter[k] + counter[k-1];
    }
    /// Output the data into the temporary array.
    for(int i = num-1 ; i >= 0; i--){
        int val = arr[i]/exp;
        int index = val%10;
        tmp[counter[index]-1] = arr[i];
        counter[index]--;
    }
    /// Output the data from the tmporary array into the array.
    for(int j =0; j< num; j++){
        arr[j] = tmp[j];
    }
    delete[]tmp;  ///< Delete the tmp pointer.
    tmp = nullptr; ///< Assign null to tmp.
}

/// Radixsort sorts data by countingsort with each digit from unit digit.
int* Radix::radixSort(int arr[], int num){
    int exp =1, d = maxDigit(arr, num);
    for(int i = 1; i<= d; i++){
      countSort(arr,num,exp);
      exp = pow(10,i);
      }
    return arr;
}

/// Radixsort sorts data by countingsort with each digit from unit digit.
void Radix::radixSortSorted(int arr[], int num){
    int exp =1, d = maxDigit(arr, num);
    for(int i = 1; i<= d; i++){
      countSort(arr,num,exp);
      exp = pow(10,i);
      }
}


/// To get the running time of radix sort.
double Radix::radixTime(int arr[],int num){
    struct timeval t1,t2;///< Define the t1, t2.
    double radixTimeuse;///< Define the running time.
    gettimeofday(&t1,NULL);///< Get the time before the sort.
    radixSort(arr,num);///< Call the radix sort method
    gettimeofday(&t2,NULL);///< Get the time after the sort.
    radixTimeuse = t2.tv_sec - t1.tv_sec + (t2.tv_usec - t1.tv_usec)/1000000.0;
    ///< Get the running time by the difference of two times.
    return radixTimeuse;///< Return the running time.
}

/// To get the running time of radix sort.
double Radix::radixTimeSorted(int arr[],int num){
    struct timeval t1,t2; ///< Define the t1, t2.
    double radixTimeuse_Sorted;///< Define the running time.
    gettimeofday(&t1,NULL);///< Get the time before the sort.
    radixSortSorted(arr,num);///< Call the radix sort method
    gettimeofday(&t2,NULL);///< Get the time after the sort.
    radixTimeuse_Sorted=t2.tv_sec-t1.tv_sec + (t2.tv_usec-t1.tv_usec)/1000000.0;
    ///< Get the running time by the difference of two times.
    return radixTimeuse_Sorted;///< Return the running time.
}
