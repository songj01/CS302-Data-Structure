/**
@file RandomData.h
@author Song Jiang
@date April 30,2018
*/


#ifndef RANDOM_DATA_H
#define RANDOM_DATA_H


const int rumbers = 1000;
/** The class will generate the unique random datas which
  * contains 1000 numbers */
class RandomData{

	public:
		RandomData(); ///< Constructor
		~RandomData();///< Destructor
		void generate1000();///< Generate 1000 unique numbers from 1 to 10000 , then assign to arr1.
		int* getArr1() const;///< Get the pointer of arr1

	private:
		int* arr1; ///< Declare arr1
};


#endif//RANDOM_DATA_H
