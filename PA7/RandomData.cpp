
#include "RandomData.h"
#include <ctime>
#include <iostream>
#include <stdlib.h>

/// Generate and initilize the dynamical arrays.
RandomData::RandomData(){
  arr1 = new int[rumbers];
}
/// Delete the dynamical arrays.
RandomData::~RandomData(){
  delete[]arr1;
}

/** This method will generate 1000 numbers,
  * if the value has existed, then it will be regenerated,
  * finally save the data in the arr1.*/
void RandomData::generate1000(){
  int a, i;
  srand(time(NULL));
  arr1[0] = rand()%10000+1;
  /// Generate 1000 numbers, and the value of each nunber is from 1 to 10000.
  for(i = 0;  i< rumbers; i++){
    a = rand()%10000+1;
    /**Compare the new value with the values which have
      *existed in the array, if the new value has existed,
      *then it will be regenerated, or save it in the array.*/
      for(int j = 0; j < i; j++){
        if(a== arr1[j]){ i--; break;}
        else
          arr1[i] = a;
      }
  }
}


/// Get the arr1 pointer.
int* RandomData::getArr1() const{
  return arr1;
}
