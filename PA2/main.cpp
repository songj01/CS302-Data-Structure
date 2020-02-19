
#include <iostream>
#include <fstream>
#include "kSmall .h"

using namespace std;





int main()

{
	//Declerations (insert as needed)
	int kSmall_pos;
	int kSmall_val;
	int pivot=0;
	vector<int> *dataset; ///< Declare the pointer of integer vector.

    //User Input DO NOT MODIFY
	std::cout<<"Please enter required kth smallest value: ";
	std::cin>>kSmall_pos;

	//File Read code (insert) - This code should be able to parse the data in a text file similar to the provided one and store values in an array for processing.
    KSmall kth;
    kth.readDataFromFileInputData();

    //kmsall algorithm implementation or function call (insert) - implement using recursion as indicated
    dataset=kth.readDataFromFileInputData(); ///< Get the pointer value.
    kSmall_val=kth.partitiondata((*dataset), kSmall_pos,pivot, ((*dataset).size()-1));

    //Log file output (insert) - preferred in .txt format acoording to instructions posted on assignment page
    kth.writeDataToFile(kSmall_val);

	//Output DO NOT MODIFY
	std::cout<<"kth smallest value = "<<kSmall_val<<std::endl;

}



