#ifndef MERGE_H
#define MERGE_H

/**
@file Merge.h
@author Song Jiang
@date March 31st, 2018
*/


class Merge
{
    public:
        ///constructor, initialize the varibles.
        Merge();
        /// declare merge method with unsorted data.
        void mergeAlg(int arr[], int first, int last);
        /// declare merge method with sorted data.
        void mergeAlgSorted(int arr[], int first, int last);
         /** declare merge sort with unsorted data. merge sort
           * will merge the data that have been devided with
           * comparisons and store into temporary data structure.
           */
	      void mergeSort(int arr[], int first, int last);
        /// declare merge sort method with sorted data.
	      void mergeSort_Sorted(int arr[], int first, int last);
        /// declare mergetime method for computing the running time.
        double mergeTime(int arr[], int first, int last);
        /// declare mergetime method with sorted data.
        double mergeTimeSorted(int arr[], int first, int last);
        /// declare getMergeComparisons method for counting comparisons.
        long getMergeComparisons();
        /// declare getMergeComparisons method with sorted data.
        long getMergeComparisons_Sorted();
        /// declare getMergeSwaps method for counting swaps.
        long getMergeSwaps();
        /// declare getMergeSwaps method with sorted data.
        long getMergeSwaps_Sorted();

    private:
        ///declare the varibles of mergeComparisons and mergeComparisons_Sorted.
        int mergeComparisons, mergeComparisons_Sorted;
        ///declare the varibles of mergeSwaps and mergeSwaps_Sorted.
        int mergeSwaps, mergeSwaps_Sorted;
};


#endif // MERGE_H
