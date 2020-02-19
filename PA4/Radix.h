#ifndef RADIX_H
#define RADIX_H


/**
@file Radix.h
@author Song Jiang
@date March 31st, 2018
*/


class Radix
{
    public:
         ///constructor, initialize the varibles.
        Radix();
        /// declare the method which will find the max number.
        int maxVal(int arr[], int num);
        /// declare the method which will compute thr max digit of max number.
        int maxDigit(int arr[], int num);
        /// declare the method will sorting numbers with counting.
        void countSort(int arr[],int num, int exp);
        /** declare the radix sort method which will sort the numbers from
          * the least digit to the most digit with counting sort.
          */
        int* radixSort(int arr[], int num);
        /// declare radit sort method using sorted data.
        void radixSortSorted(int arr[], int num);
        /// declare radixTime method for computing the running time.
        double radixTime(int arr[],int num);
        /// declare radixTime method with sorted data.
        double radixTimeSorted(int arr[],int num);
        /// declare getRadixComparisons method for counting comparisons.
        long getRadixComparisons();
        /// declare getRadixComparisons method with sorted data.
        long getRadixComparisons_Sorted();
        /// declare getRadixSwaps method for counting swaps.
        long getRadixSwaps();
        /// declare getRadixSwaps method with sorted data.
        long getRadixSwaps_Sorted();

    private:
        ///declare the varibles of radixComparisons and radixComparisons_Sorted.
        long radixComparisons, radixComparisons_Sorted;
        ///declare the varibles of radixSwaps and radixSwaps_Sorted.
        long radixSwaps, radixSwaps_Sorted;
};

#endif // RADIX_H
