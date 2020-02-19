/**
@file BinaryNode.h
@author Song Jiang
@date April 21,2018
*/


#ifndef BINARY_NODE_H
#define BINARY_NODE_H



/** Declare the node of tree, which have data,
    left and right child pointers.*/
class BinaryNode{

  public:
    BinaryNode(); ///< Constuctor
    void setData(const int& a);///< Set the data.
    void setLChildPtr(BinaryNode* lcp);///< Set the left child pointer.
    void setRChildPtr(BinaryNode* rcp);///< Set the right child pointer.
    int getData() const; ///< Get the data.
    BinaryNode* getLChildPtr() const;///< Get the left child pointer.
    BinaryNode* getRChildPtr() const;///< Get the right child pointer.

  private:
    int data; ///< Declare the data.
    BinaryNode* lChildPtr; ///< Declare the left child pointer.
    BinaryNode* rChildPtr; ///< Declare the right child pointer.
};







#endif//BINARY_NODE_H
