/**
@file KSmall.h
@author Song Jiang
@date Feb. 13th,2018
*/


#ifndef KSMALL _H
#define KSMALL _H

#include <iostream>
#include <fstream>
#include <vector>


using namespace std;



class KSmall{

public:
    /** This method will create a new vector and read the data from the
      * text file and write them to the vector.*/
    vector<int> *readDataFromFileInputData();
    /** This method will do the following things:
      * first, sorting the data into two parts, the left of pivot is smaller than pivot;
      * the right is larger than pivot; second, search the kth data using  the idea of
      * recursion. */
    int partitiondata(vector<int> data, int k, int first, int last);
    void writeDataToFile(int a);  /**< This method will write the result
    * to the file named searchResult.txt, it will create this file if the
    * file does not exist in the directory. */


private:


};

#endif // KSMALL _H

