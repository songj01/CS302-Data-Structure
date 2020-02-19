#include "RBTNode.h"

///Initialize the data and pointers.
RBTNode::RBTNode(){
  data = 0 ;
  lChildPtr = rChildPtr = parentPtr = nullptr;
  nodeColor = RED;
}
///Initialize the data with parameter.
RBTNode::RBTNode(const int& newData){
  data = newData ;
  lChildPtr = rChildPtr = parentPtr = nullptr;
  nodeColor = RED;
}

/// Set the data.
void RBTNode::setData(const int& a){
  data = a;
}
/// Set the left pointer.
void RBTNode::setLChildPtr(RBTNode* lcp){
  lChildPtr = lcp;
}
/// Set the right pointer.
void RBTNode::setRChildPtr(RBTNode* rcp){
  rChildPtr = rcp;
}
/// Set the parent pointer.
void RBTNode::setParentPtr(RBTNode* parent){
  parentPtr = parent;
}
/// Set the color of node.
void RBTNode::setNodeColor(const Color &color){
  nodeColor = color;
}

/// Get the data.
int RBTNode::getData() const{
  return data;
}
/// Get the left pointer.
RBTNode* RBTNode::getLChildPtr() const{
  return lChildPtr;
}
/// Get the right pointer.
RBTNode* RBTNode::getRChildPtr() const{
  return rChildPtr;
}
/// Get the parent pointer.
RBTNode* RBTNode::getParentPtr() const{
  return parentPtr;
}
/// Get the color of node.
Color RBTNode::getNodeColor() const{
  return nodeColor;
}
