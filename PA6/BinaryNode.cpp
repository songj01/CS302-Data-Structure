#include "BinaryNode.h"

///Initialize the data and pointers.
BinaryNode::BinaryNode():data(0),lChildPtr(nullptr),rChildPtr(nullptr)
{

}

/// Set the data.
void BinaryNode::setData(const int& a){
  data = a;
}
/// Set the left pointer.
void BinaryNode::setLChildPtr(BinaryNode* lcp){
  lChildPtr = lcp;
}
/// Set the right pointer.
void BinaryNode::setRChildPtr(BinaryNode* rcp){
  rChildPtr = rcp;
}
/// Get the data.
int BinaryNode::getData() const{
  return data;
}
/// Get the left pointer.
BinaryNode* BinaryNode::getLChildPtr() const{
  return lChildPtr;
}
/// Get the right pointer.
BinaryNode* BinaryNode::getRChildPtr() const{
  return rChildPtr;
}
