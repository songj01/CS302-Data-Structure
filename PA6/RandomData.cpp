
#include "RandomData.h"
#include <ctime>
#include <iostream>
#include <stdlib.h>

/// Generate and initilize the dynamical arrays.
RandomData::RandomData(){
  arr1 = new int[100];
  arr2 = new int[10];
  arr3 = new int[100000];
  arr4 = new int[10];
}
/// Delete the dynamical arrays.
RandomData::~RandomData(){
  delete[]arr1;
  delete[]arr2;
  delete[]arr3;
  delete[]arr4;
}

/** This method will generate 100 numbers,
  * if the value has existed, then it will be regenerated,
  * finally save the data in the arr1.*/
void RandomData::generate100(){
  int a, i;
  srand(time(NULL));
  arr1[0] = rand()%200+1;
  /// Generate 100 numbers, and the value of each nunber is from 1 to 200.
  for(i = 0;  i< 100; i++){
    a = rand()%200+1;
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

/// Generate 10 numbers which is subset of arr1.
void RandomData::generate10(){
  RandomData::generate100();
  for(int i =0; i<10;i++){ arr2[i] = arr1[i];}
  }



void RandomData::generate100s(){
  int a, i;
  srand(time(NULL));
  arr3[0] = rand()%100000+1;
  /// Generate 100000 numbers, and the value of each nunber is from 1 to 100000.
  for(i = 0;  i< 100000; i++){
    a = rand()%100000+1;
    /**Compare the new value with the values which have
      *existed in the array, if the new value has existed,
      *then it will be regenerated, or save it in the array.*/
      for(int j = 0; j < i; j++){
        if(a == arr3[j]){ i--; break;}
        else
          arr3[i] = a;
      }
  }
}
/// Generate 10 numbers which is subset of arr3.
void RandomData::generate10s(){
  RandomData::generate100s();
  for(int i =0; i<10;i++){ arr4[i] = arr3[i];}
  }

/// Get the arr1 pointer.
int* RandomData::getArr1() const{
  return arr1;
}

/// Get the arr2 pointer.
int* RandomData::getArr2() const{
  return arr2;
}

/// Get the arr3 pointer.
int* RandomData::getArr3() const{
  return arr3;
}
/// Get the arr4 pointer.
int* RandomData::getArr4() const{
  return arr4;
}
