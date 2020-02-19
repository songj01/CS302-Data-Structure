#include "RandomData.h"
#include <fstream>
#include <stdlib.h>
#include <ctime>
#include <iostream>
#include <cmath>

RandomData::RandomData(){
  for(int i = 0; i < max; i++){
    arrStartTime[i] =0;///< Inilitialize the arrival time.
    arrDuration[i] =0;///< Inilitialize the duration time.
  }
}
/// Generate 99,999 arrival time bewteen 0 and 99999.
void RandomData::randomEvent(){
  srand(time(NULL));
  for(int i = 0; i < max; i++)
    arrStartTime[i] = rand()%1000000;///< Generate the data from 0 to 99999, and save it.
}

/// Generate 99,999 transction time bewteen 1 and 100.
void RandomData::randomDuration(){
  srand(time(NULL));
  for(int i = 0; i < max; i++)
    arrDuration[i] = rand()%100+1;///< Generate the data from 1 to 100, and save it.
}

int RandomData::maxDigit(int arr[], int num){
  int digit = 0, tmp = arr[0];
  /// Find the max data.
  for(int i = 1; i < num; i++){
      if(arr[i] > tmp)
          tmp = arr[i];
        }
  /// Compute the digit of max data.
  while(tmp>0){
    tmp = tmp /10;
    digit++;
          }
return digit;
}


void RandomData::countSort(int arr[],int num, int exp){
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
  /// Save the data into the temporary array.
  for(int i = num-1 ; i >= 0; i--){
      int val = arr[i]/exp;
      int index = val%10;
      tmp[counter[index]-1] = arr[i];
      counter[index]--;
  }
  /// Output the data from the tmporary array into the array.
  for(int j =0; j< num; j++){arr[j] = tmp[j];}
  delete[]tmp;  ///< Delete the tmp pointer.
  tmp = nullptr; ///< Assign null to tmp.
}

/// Sort from unitdigit to the max digit.
void  RandomData::radixSort(int arr[], int num){
  int exp =1, d = maxDigit(arr, num);
  /// traversal from the unitdigt to the max digit
  for(int i = 1; i<= d; i++){
    countSort(arr,num,exp);
    /// exp will increasem from 1 to 100, 1000 or 10000.
    exp = pow(10,i);
    }
}

/// Output the data to the file of eventdata.txt.
void RandomData::printToFile(){
std::ofstream ofile("eventdata.txt");
randomEvent();
randomDuration();
radixSort(arrStartTime, max);
for(int i = 0; i < max; i++){
  ofile<<arrStartTime[i]<<" "<<arrDuration[i]<<std::endl;
}
ofile.close();
}
