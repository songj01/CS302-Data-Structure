#include "kSmall .h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;




vector<int>* KSmall::readDataFromFileInputData()
{
    int num; ///< Declare the number which will be written from file.
    vector<int> *datavec = new vector<int>; ///< Create new integer type's vector named datavec.
    /// Declare the object of ifstream class named songfile and open the file named data.txt.
    ifstream songfile("data.txt");
    /**Input the numbers from the file
      * and add them to the vector.*/
    while(songfile>> num){
        datavec->push_back(num);
  }
    songfile.close(); ///< Close the file.
    return datavec; ///< Return the vector.
}



int KSmall::partitiondata(vector<int> data, int k, int first, int last)
{
    int piv = data[first];///< Declare the value of the first position as pivot(piv).
    int i=first+1; ///< Declare i which locates at the second position.

    /** When j moves from the second to the last, if the value j points is
      * smaller than pivot, then exchanging them, at the same time, i will move
      * the next. */
    for(int j=first+1;j<=last;j++){
        if(data[j]<=piv){
        swap(data[i],data[j]);
        i++;}
        }

        /** At last, after exchanging the value of first and i-1,
          * the final position of pivot will be i-1.*/
        swap(data[first],data[i-1]);

    /** After sorting, the real position of pivot will be i-1,
      * if k just equals (i-1+1), then return data[i-1] which is same as piv.
      * if k is smaller than i, it will sort again between first and i-1, or it
      * will sort again form i to last until finding the kth value's element.*/
    if(first < last){
        if(k==i)
        return piv;
        else if(k>i)
            return partitiondata(data, k, i, last);
        else
            return partitiondata(data, k, first, i-1);
    }

}




void KSmall::writeDataToFile(int a)
{
   ofstream outputfile("searchResult.txt"); ///< Declare the object of ofstream class and open the file.
   /// Output the result.
   outputfile<<a<<endl;
   /// Close the file.
   outputfile.close();
}


