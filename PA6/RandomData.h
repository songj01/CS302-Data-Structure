/**
@file RandomData.h
@author Song Jiang
@date April 21,2018
*/


#ifndef RANDOM_DATA_H
#define RANDOM_DATA_H

/** The class will generate the unique random datas which
  * contains 100 numbers of BST1, 10 numbers of BST2, 100000
	* numbers of bonus SBT1 and 10 numbers of bonus BST2.*/
class RandomData{

	public:
				RandomData(); ///< Constructor
				~RandomData();///< Destructor
		void generate100();///< Generate 100 unique numbers from 1 to 200 , then assign to arr1.
		void generate10(); ///< Generate 10 unique numbers from 1 to 200 and has overlap with BST1, then assign to arr2.
		void generate100s();///< Generate 100000 unique numbers from 1 to 10000 , then assign to arr3.
		void generate10s();///< Generate 10 unique numbers from 1 to 100000 and has overlap with bonus BST1, then assign to arr4.
		int* getArr1() const;///< Get the pointer of arr1
		int* getArr2() const;///< Get the pointer of arr2
		int* getArr3() const;///< Get the pointer of arr3
		int* getArr4() const;///< Get the pointer of arr4

	private:
		int* arr1; ///< Declare arr1
		int* arr2; ///< Declare arr2
		int* arr3; ///< Declare arr3
		int* arr4; ///< Declare arr4
};


#endif//RANDOM_DATA_H
