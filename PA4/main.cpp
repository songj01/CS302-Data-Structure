#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "Radix.h"
#include "Merge.h"
#include "Bubble.h"
#include <cmath>
#include <fstream>

int main()
{
  int num, fac;
  const int inexp = 4;///< Define the number of getting array.
  const int total = 10; ///< Define the number of random running.
  const int maxnum = 1000000; ///< Define maxnum.
  std::ofstream ofile("outputPA04.cvs"); ///< Define the output file.
  /// Output the information of sort that I selected.
  ofile<<std::endl<<"Section 1: Algorithms selected and their complexity"<<std::endl<<std::endl;
  ofile<< "Algorithm Name"<<","<<"Complexity"<<std::endl;
  ofile<< "Radix Sort"<<","<<"O(n)"<<std::endl;
  ofile<< "Merge Sort"<<","<<"O(nlogn)"<<std::endl;
  ofile<< "Bubble Sort"<<","<<"O(n^2)"<<std::endl;
  /// Define and initilize the array of average running time, swaps and comparisons of radix, merge and bubble with unsorted datas.
  double radixAveCPUTime[inexp] = {0}, mergeAveCPUTime[inexp] = {0},bubbleAveCPUTime[inexp] = {0};
  long radixAveSwaps[inexp] = {0}, mergeAveSwaps[inexp] = {0}, bubbleAveSwaps[inexp] = {0};
  long radixAveComparisons[inexp] = {0}, mergeAveComparisons[inexp] = {0}, bubbleAveComparisons[inexp] = {0};
  /// Define and initilize the array of total running time, swaps and comparisons of radix, merge and bubble with unsorted datas.
  double sumt1[inexp] = {0}, sumt2[inexp] = {0}, sumt3[inexp] = {0};
  long sumbc1[inexp] = {0}, sumbc2[inexp] = {0}, sumbc3[inexp] = {0};
  long sumbs1[inexp] = {0}, sumbs2[inexp] = {0}, sumbs3[inexp] = {0};
  /// Define and initilize the array of average running time, swaps and comparisons of radix, merge and bubble with sorted datas.
  double radixAveCPUTimeSorted[inexp] = {0}, mergeAveCPUTimeSorted[inexp] = {0}, bubbleAveCPUTimeSorted[inexp] = {0};
  long radixAveSwapsSorted[inexp] = {0}, mergeAveSwapsSorted[inexp] = {0}, bubbleAveSwapsSorted[inexp] = {0};
  long radixAveComparisonsSorted[inexp] = {0}, mergeAveComparisonsSorted[inexp] = {0}, bubbleAveComparisonsSorted[inexp] = {0};
  /// Define and initilize the array of total running time, swaps and comparisons of radix, merge and bubble with sorted datas.
  double sumt1Sorted[inexp] = {0}, sumt2Sorted[inexp] = {0}, sumt3Sorted[inexp] = {0};
  long  sumbc1Sorted[inexp] = {0}, sumbc2Sorted[inexp] = {0}, sumbc3Sorted[inexp] = {0};
  long sumbs1Sorted[inexp] = {0}, sumbs2Sorted[inexp] = {0}, sumbs3Sorted[inexp] = {0};


  /// Produce 1000, 10000, 100000 seprately.
  for(fac = 0; fac <inexp-1; fac++){
    num = 1000*pow(10,fac); ///< Compute the value of num by pow function.
    int *arr = new int[num];
    int *arrcopy1 = new int[num];
    int *arrcopy2 = new int[num];
    /// Create 10 times of 1000, 10000 and 100000 datas once seprately.
    for(int j =1; j <=total; j++){
      srand(time(NULL));
      for(int i =0; i < num; i++){
        arr[i] = rand()%1000000;
        arrcopy1[i] = arr[i];
        arrcopy2[i] = arrcopy1[i];
        }

  	Radix aRadix; ///< Create new Object of Radix class.
  	Merge aMerge; ///< Create new Object of Merge class.
    Bubble aBubble; ///< Create new Object of Bubble class.
      /** Get the data of total cpu running time, swaps and comparisons of
        * radix when running 1000, 10000,1000000 datas.*/
      double t1 = aRadix.radixTime(arr,num);
      sumt1[fac] += t1;
      long bc1 = aRadix.getRadixComparisons();
      sumbc1[fac] += bc1;
      long bs1 = aRadix.getRadixSwaps();
      sumbs1[fac] += bs1;
      /** Get the data of total cpu running time, swaps and comparisons of
        * radix when running 1000, 10000,1000000 sorted datas.*/
      double t1Sorted = aRadix.radixTimeSorted(arr,num);
      sumt1Sorted[fac] += t1Sorted;
      long bc1Sorted = aRadix.getRadixComparisons_Sorted();
      sumbc1Sorted[fac] += bc1Sorted;
      long bs1Sorted = aRadix.getRadixSwaps_Sorted();
      sumbs1Sorted[fac] += bs1Sorted;
      /** Get the data of total cpu running time, swaps and comparisons of
        * merge when running 1000, 10000,1000000 datas.*/
      double t2 = aMerge.mergeTime(arrcopy1,0, num-1);
      sumt2[fac] += t2;
      long bc2 =aMerge.getMergeComparisons();
      sumbc2[fac] += bc2;
      long bs2 =aMerge.getMergeSwaps();
      sumbs2[fac] += bs2;
      /** Get the data of total cpu running time, swaps and comparisons of
        * merge when running 1000, 10000,1000000 sorted datas.*/
      double t2Sorted = aMerge.mergeTimeSorted(arrcopy1,0, num-1);
      sumt2Sorted[fac] += t2Sorted;
      long bc2Sorted =aMerge.getMergeComparisons_Sorted();
      sumbc2Sorted[fac] += bc2Sorted;
      long bs2Sorted =aMerge.getMergeSwaps_Sorted();
      sumbs2Sorted[fac] += bs2Sorted;
      /** Get the data of total cpu running time, swaps and comparisons of
        * bubble when running 1000, 10000,1000000 datas.*/
      double t3 = aBubble.bubbleTime(arrcopy2,num);
      sumt3[fac] += t3;
      long bc3 = aBubble.getBubbleComparisons();
      sumbc3[fac] += bc3;
      long bs3 = aBubble.getBubbleSwaps();
      sumbs3[fac] += bs3;
      /** Get the data of total cpu running time, swaps and comparisons of
        * bubble when running 1000, 10000,1000000 sorted datas.*/
      double t3Sorted = aBubble.bubbleTimeSorted(arrcopy2,num);
      sumt3Sorted[fac] += t3Sorted;
      long bc3Sorted = aBubble.getBubbleComparisons_Sorted();
      sumbc3Sorted[fac] += bc3Sorted;
      long bs3Sorted = aBubble.getBubbleSwaps_Sorted();
      sumbs3Sorted[fac] += bs3Sorted;
      }
    /** Get the data of average cpu running time of radix, merge and bubble
      * when running 1000, 10000,1000000 datas.*/
    radixAveCPUTime[fac] = sumt1[fac]/total;
    mergeAveCPUTime[fac] = sumt2[fac]/total;
    bubbleAveCPUTime[fac] = sumt3[fac]/total;
    /** Get the data of average swaps of radix, merge and bubble
      * when running 1000, 10000,1000000 datas.*/
    radixAveSwaps[fac] = sumbs1[fac]/total;
    mergeAveSwaps[fac] = sumbs2[fac]/total;
    bubbleAveSwaps[fac] = sumbs3[fac]/total;
    /** Get the data of average comparisons of radix, merge and bubble
      * when running 1000, 10000,1000000 datas.*/
    radixAveComparisons[fac] = sumbc1[fac]/total;
    mergeAveComparisons[fac] = sumbc2[fac]/total;
    bubbleAveComparisons[fac] = sumbc3[fac]/total;
    /** Get the data of average cpu running time of radix, merge and bubble
      * when running 1000, 10000,1000000 sorted datas.*/
    radixAveCPUTimeSorted[fac] = sumt1Sorted[fac]/total;
    mergeAveCPUTimeSorted[fac] = sumt2Sorted[fac]/total;
    bubbleAveCPUTimeSorted[fac] = sumt3Sorted[fac]/total;
    /** Get the data of average swaps of radix, merge and bubble
      * when running 1000, 10000,1000000 sorted datas.*/
    radixAveSwapsSorted[fac] = sumbs1Sorted[fac]/total;
    mergeAveSwapsSorted[fac] = sumbs2Sorted[fac]/total;
    bubbleAveSwapsSorted[fac] = sumbs3Sorted[fac]/total;
    /** Get the data of average comparisons of radix, merge and bubble
      * when running 1000, 10000,1000000 sorted datas.*/
    radixAveComparisonsSorted[fac] = sumbc1Sorted[fac]/total;
    mergeAveComparisonsSorted[fac] = sumbc2Sorted[fac]/total;
    bubbleAveComparisonsSorted[fac] = sumbc3Sorted[fac]/total;

    delete[]arr; ///< Delete arr pointer.
    arr = nullptr; ///< Assign nullptr to arrcopy2.
    delete[]arrcopy1; ///< Delete arrcopy1 pointer.
    arrcopy1 = nullptr; ///< Assign nullptr to arrcopy2.
    delete[]arrcopy2; ///< Delete arrcopy2 pointer.
    arrcopy2 = nullptr; ///< Assign nullptr to arrcopy2.
    }

    int *arrb = new int[maxnum]; ///< Create new arrb[1000000]
    int *arrbcopy1 = new int[maxnum]; ///< Create new arrbcopy1[1000000]
    int *arrbcopy2 = new int[maxnum]; ///< Create new arrbcopy2[1000000]

    /**Create 1000000 datas and store then into the arrb[],
      *arrbcopy1[],and arrbcopy2[].*/
      srand(time(NULL));
      for(int i =0; i < maxnum; i++){
        arrb[i] = rand()%1000000;
        arrbcopy1[i] = arrb[i];
        arrbcopy2[i] = arrbcopy1[i];
        }

    Radix abRadix; ///< Create new Object of Radix class.
    Merge abMerge; ///< Create new Object of Merge class.
    Bubble abBubble; ///< Create new Object of Bubble class.

    /** Get the data of cpu running time of radix, merge and bubble
      * when running 10000000 datas.*/
    radixAveCPUTime[3] = abRadix.radixTime(arrb,maxnum);
    mergeAveCPUTime[3] = abMerge.mergeTime(arrbcopy1,0, maxnum-1);
    bubbleAveCPUTime[3] = abBubble.bubbleTime(arrbcopy2,maxnum);

    /** Get the data of swaps of radix, merge and bubble
      * when running 10000000 datas.*/
    radixAveSwaps[3] = abRadix.getRadixSwaps();
    mergeAveSwaps[3] = abMerge.getMergeSwaps();
    bubbleAveSwaps[3] = abBubble.getBubbleSwaps();
    /** Get the data of comparisons of radix, merge and bubble
      * when running 10000000 datas.*/
    radixAveComparisons[3] = abRadix.getRadixComparisons();
    mergeAveComparisons[3] = abMerge.getMergeComparisons();
    bubbleAveComparisons[3] = abBubble.getBubbleComparisons();
    /** Get the data of cpu running time of radix, merge and bubble
      * when running 10000000 sorted datas.*/
    radixAveCPUTimeSorted[3] = abRadix.radixTimeSorted(arrb,maxnum);
    mergeAveCPUTimeSorted[3] = abMerge.mergeTimeSorted(arrbcopy1,0, maxnum-1);
    bubbleAveCPUTimeSorted[3]= abBubble.bubbleTimeSorted(arrbcopy2,maxnum);
    /** Get the data of swaps of radix, merge and bubble
      * when running 10000000 sorted datas.*/
    radixAveSwapsSorted[3] = abRadix.getRadixSwaps_Sorted();
    mergeAveSwapsSorted[3] = abMerge.getMergeSwaps_Sorted();
    bubbleAveSwapsSorted[3] = abBubble.getBubbleSwaps_Sorted();
    /** Get the data of comparisons of radix, merge and bubble
      * when running 10000000 sorted datas.*/
    radixAveComparisonsSorted[3] = abRadix.getRadixComparisons_Sorted();
    mergeAveComparisonsSorted[3] = abMerge.getMergeComparisons_Sorted();
    bubbleAveComparisonsSorted[3] = abBubble.getBubbleComparisons_Sorted();



  /// Output the results to the file.
  ofile<<std::endl<<"Section 2: Timings and Swaps"<<std::endl<<std::endl;
  ofile<<"2.1 Times (Unit: second): "<<std::endl<<std::endl;
  ofile<<"Size/Algorithm(Unsorted)"<<","<<"Radix"<<","<<"Merge"<<","<<"Bubble"<<std::endl;
  for(int i =0; i<inexp; i++){
    ofile<<1000*pow(10,i)<<","<<radixAveCPUTime[i]<<","<<mergeAveCPUTime[i]<<","<<bubbleAveCPUTime[i]<<std::endl;
    }
  ofile<<std::endl<<"Size/Algorithm(Sorted)"<<","<<"Radix"<<","<<"Merge"<<","<<"Bubble"<<std::endl;
  for(int i =0; i<inexp; i++){
    ofile<<1000*pow(10,i)<<","<<radixAveCPUTimeSorted[i]<<","<<mergeAveCPUTimeSorted[i]<<","<<bubbleAveCPUTimeSorted[i]<<std::endl;
    }
  ofile<<std::endl<<"2.2 Comparisons/Swaps:"<<std::endl<<std::endl;
  ofile<<"Size/Algorithm(Unsorted)"<<","<<"Radix"<<","<<"Merge"<<","<<"Bubble"<<std::endl;
  for(int j =0; j<inexp; j++){
    ofile<<1000*pow(10,j)<<","<<radixAveComparisons[j]<<"/"<<radixAveSwaps[j]<<","<<mergeAveComparisons[j]<<"/"<<mergeAveSwaps[j]<<","<<bubbleAveComparisons[j]<<"/"<<bubbleAveSwaps[j]<<std::endl;
    }
  ofile<<std::endl<<"Size/Algorithm(Sorted)"<<","<<"Radix"<<","<<"Merge"<<","<<"Bubble"<<std::endl;
  for(int j =0; j<inexp; j++){
    ofile<<1000*pow(10,j)<<","<<radixAveComparisonsSorted[j]<<"/"<<radixAveSwapsSorted[j]<<","<<mergeAveComparisonsSorted[j]<<"/"<<mergeAveSwapsSorted[j]<<","<<bubbleAveComparisonsSorted[j]<<"/"<<bubbleAveSwapsSorted[j]<<std::endl;
    }
  ofile<<std::endl<<"Section 3:Timing Curve"<<std::endl;
}
