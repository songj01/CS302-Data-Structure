#ifndef BUBBLE_H
#define BUBBLE_H


/**
@file Bubble.h
@author Song Jiang
@date March 31st, 2018
*/

class Bubble
{
    public:
         ///constructor, initialize the varibles.
        Bubble();
        ///declare swap method.
        void swap(int &a, int &b);
        /** declare bubble sort method which will sort the data with comparing
          * the adjacent data and swaping if needed.
          */
        void bubbleSort(int arr[],int num);
        ///declare the method with sorted data.
        void bubbleSort_Sorted(int arr[],int num);
         /// declare bubbleTime method for computing the running time.
        double bubbleTime(int arr[],int num);
        /// declare bubbleTime method with sorted data.
        double bubbleTimeSorted(int arr[],int num);
        /// declare getBubbleComparisons method for counting comparisons.
        long getBubbleComparisons();
        /// declare getBubbleComparisons method with sorted data.
        long getBubbleComparisons_Sorted();
       /// declare getBubbleSwaps method for counting swaps.
        long getBubbleSwaps();
        /// declare getBubbleSwaps method with sorted data.
        long getBubbleSwaps_Sorted();

    private:
       /** declare the varibles of bubbleComparisons and
         * bubbleComparisons_Sorted. */
        long bubbleComparisons, bubbleComparisons_Sorted;
        ///declare the varibles of bubbleSwaps and bubbleSwaps_Sorted.
        long bubbleSwaps, bubbleSwaps_Sorted;
};

#endif // BUBBLE_H
