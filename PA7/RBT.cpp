#include "RBT.h"
#include "RandomData.h"
#include <iostream>
#include <fstream>


/// Initialize the rootPtr.
RBT::RBT(){
  rootPtr=nullptr;
  intcount= 0 ;
  Visited[rumbers]={0};
  sum =0;
}


/// Destroy the tree.
RBT::~RBT(){
  clear();
}

/// If the tree is emtry, it will return true, or return false.
bool RBT::isEmpty() const{
  return rootPtr == nullptr;
}


RBTNode* RBT::insertRBT(RBTNode* subTreePtr, RBTNode* newNode){
  /// If the tree is empty, insert the node as root.
  if(subTreePtr == nullptr) return newNode;
  /// If the data of node is less than root, go left to find it anfd then insert it.
  else if(subTreePtr->getData() > newNode->getData()){
      RBTNode* lPtr = insertRBT(subTreePtr->getLChildPtr(), newNode);
      subTreePtr->setLChildPtr(lPtr);
      lPtr->setParentPtr(subTreePtr);
  }
    /// If the data of node is greater than root, go right to find it anfd then insert it.
    else{
      RBTNode* rPtr = insertRBT(subTreePtr->getRChildPtr(), newNode);
      subTreePtr->setRChildPtr(rPtr);
      rPtr->setParentPtr(subTreePtr);
    }
   return subTreePtr;
}


/// Add a new node to the tree and fix it.
bool RBT::add(const int& newData){
  RBTNode* newNodePtr = new RBTNode(newData);
  rootPtr = insertRBT(rootPtr, newNodePtr);
  BRTFixup(rootPtr, newNodePtr);
  return true;
}


/// Add the all of nodes into the tree.
void RBT::createTree(){
  std::ofstream logfile("log.txt",std::ofstream::out |std::ofstream::app);
  RandomData aRandom;
  aRandom.generate1000();
  int* p = aRandom.getArr1();
  for(int i =0; i < rumbers;i++){
    int t = *(p+i);
    add(t);
    /// Log the the record of insertion and compare with output in preorder.
    logfile<<"inserted number: "<<t<<std::endl;
    preorder(rootPtr);
    logfile<<std::endl;
  }
  logfile.close();
}


/* If the left child of bNode is not NIL, assign it to the aNode
 * as right child, at same time, assign aNode as parent to it;
 * Assign the parent of aNode as the parent of bNode;
 * Assign aNode to the bNode as left child, bNode as the parent of aNode.*/
void RBT::leftRotation(RBTNode* subTreePtr, RBTNode* aNode){
  std::ofstream logfile("log.txt",std::ofstream::out |std::ofstream::app);
  logfile<<"the leftRotation function is called!"<<std::endl;

  RBTNode* bNode = aNode->getRChildPtr();
  aNode->setRChildPtr(bNode->getLChildPtr());
  bNode->setParentPtr(aNode->getParentPtr());
  if(bNode->getLChildPtr() != nullptr)
    bNode->getLChildPtr()->setParentPtr(aNode);
  if(aNode->getParentPtr() == nullptr) rootPtr = bNode;
  else if(aNode==aNode->getParentPtr()->getLChildPtr())
    aNode->getParentPtr()->setLChildPtr(bNode);
  else
    aNode->getParentPtr()->setRChildPtr(bNode);
  bNode->setLChildPtr(aNode);
  aNode->setParentPtr(bNode);
  logfile.close();
}

/* If the left child of bNode is not NIL, assign it to the aNode
 * as right child, at same time, assign aNode as parent to it;
 * Assign the parent of aNode as the parent of bNode;
 * Assign aNode to the bNode as right child, bNode as the parent of aNode.*/
void RBT::rightRotation(RBTNode* subTreePtr, RBTNode* aNode){
  std::ofstream logfile("log.txt",std::ofstream::out |std::ofstream::app);
  logfile<<"the rightRotation function is called!"<<std::endl;

  RBTNode* bNode = aNode->getLChildPtr();
  aNode->setLChildPtr(bNode->getRChildPtr());
  bNode->setParentPtr(aNode->getParentPtr());
  if(bNode->getRChildPtr() != nullptr)
    bNode->getRChildPtr()->setParentPtr(aNode);
  if(aNode->getParentPtr() == nullptr)
    rootPtr = bNode;
  else if(aNode==aNode->getParentPtr()->getLChildPtr())
    aNode->getParentPtr()->setLChildPtr(bNode);
  else
    aNode->getParentPtr()->setRChildPtr(bNode);
  bNode->setRChildPtr(aNode);
  aNode->setParentPtr(bNode);
  logfile.close();
}

/* There are 2 situations: parent is lfte child of grandprant and right child:
 * there are 2 stutas or 3 cases: uncle is red,
 * uncle is not red(balck or NIL): aNode is left or right child. */
void RBT::BRTFixup(RBTNode* subTreePtr, RBTNode* aNode){
  std::ofstream logfile("log.txt",std::ofstream::out |std::ofstream::app);
  logfile<<"the BRTFixup function is called!"<<std::endl;

  RBTNode* grandParentPtr = nullptr;
  RBTNode* parentsPtr = nullptr;
  while((aNode!=subTreePtr)&&(aNode->getNodeColor()!=BLACK)
              &&(aNode->getParentPtr()->getNodeColor()==RED)){
    grandParentPtr = aNode->getParentPtr()->getParentPtr();
    parentsPtr = aNode->getParentPtr();
    /// Situation 1: parent is the left node of grandparent.
    if(parentsPtr==grandParentPtr->getLChildPtr()){
      RBTNode* unclePtr = grandParentPtr->getRChildPtr();
      /* Case 1: Uncle is red, just set parent and uncle as black node,
       * grandparent as red node, and set grandparent as aNode
       * then return into while loop again.*/
      if(unclePtr!=nullptr&&unclePtr->getNodeColor()==RED){
        grandParentPtr->setNodeColor(RED);
        unclePtr->setNodeColor(BLACK);
        parentsPtr->setNodeColor(BLACK);
        aNode = grandParentPtr;
        }
        /* Case 2: Uncle is balck and aNode is left child,
         * set parent as black node, and grandparent as red node;
         * then right rotation. At last,  set the prarent as aNode,
         * return into while loop. */
      else if(aNode==parentsPtr->getLChildPtr()){
        parentsPtr->setNodeColor(BLACK);
        grandParentPtr->setNodeColor(RED);
        rightRotation(subTreePtr, grandParentPtr);
        aNode = parentsPtr;
        }
        /* Case 3: Uncle is balck and aNode is right child,
         * left rotation and set parent as aNode and then
         * return into while loop. */
      else{
        leftRotation(subTreePtr, parentsPtr);
        aNode = parentsPtr;
        }
   }
     /// Situation 2: parent is the right node of grandparent.
   else{
      RBTNode* unclePtr = grandParentPtr->getLChildPtr();
      /* Case 1: Uncle is red, just set parent and uncle as black node,
       * grandparent as red node, and set grandparent as aNode
       * then return into while loop again.*/
      if(unclePtr!=nullptr&&unclePtr->getNodeColor()==RED){
        grandParentPtr->setNodeColor(RED);
        unclePtr->setNodeColor(BLACK);
        parentsPtr->setNodeColor(BLACK);
        aNode = grandParentPtr;
        }
        /* Case 2: Uncle is balck and aNode is right child,
         * set parent as black node, and grandparent as red node;
         * then left rotation. At last,  set the prarent as aNode,
         * return into while loop. */
      else if(aNode==parentsPtr->getRChildPtr()){
        parentsPtr->setNodeColor(BLACK);
        grandParentPtr->setNodeColor(RED);
        leftRotation(subTreePtr, grandParentPtr);
        aNode = parentsPtr;
        }
        /* Case 3: Uncle is balck and aNode is left child,
         * right rotation and set parent as aNode and then
         * return into while loop. */
      else{
        rightRotation(subTreePtr, parentsPtr);
        aNode = parentsPtr;
        }
   }
  }
  /// Set root as black as root is always black.
  rootPtr->setNodeColor(BLACK);
}


/** If the tree is empty, the height of tree is 0, or recursively calculate the height of
  * left subtree and right subtree. compare the value of left height and right
  * height, finllay greater value plus 1(root).*/
int RBT::getHeightHelper(RBTNode* subTreePtr) const{
  if(subTreePtr == nullptr) return 0;
  else{
    int l = getHeightHelper(subTreePtr->getLChildPtr());
    int r = getHeightHelper(subTreePtr->getRChildPtr());
    return (l > r)? l+1:r+1;
  }
}

/// Get the height of rootPtr tree.
int RBT::getHeight() const{
  return getHeightHelper(rootPtr);
}


/// Traverse R&B tree in the preorder.
void RBT::preorder(RBTNode* treePtr){
 std::ofstream logfile("log.txt",std::ofstream::out |std::ofstream::app);
 if(treePtr != nullptr){
   logfile<<"preoder: "<<treePtr->getData()<<","<<treePtr->getNodeColor()<<std::endl; ///< Fisrtly, traverse the root.
   preorder(treePtr->getLChildPtr()); ///< Secondly, traverse the left child.
   preorder(treePtr->getRChildPtr()); ///< Finally, traverse the right child.
 }
 logfile.close();
}

/// Traverse R&B tree in the inorder.
void RBT::inorder(RBTNode* treePtr){
  if(treePtr != nullptr){
    inorder(treePtr->getLChildPtr()); ///< Fisrtly, traverse the left child.
    visited(treePtr->getData());///< Secondly, traverse the root.
    inorder(treePtr->getRChildPtr()); ///< Finally, traverse the right child.
 }
}

/// If the is not empty, recursively delete the left sub tree, then right subtree and finally root.
void RBT::deleteTree(RBTNode* subTreePtr){
  if(subTreePtr != nullptr){
      deleteTree(subTreePtr->getLChildPtr());
      deleteTree(subTreePtr->getRChildPtr());
      delete subTreePtr;
    }
}

/// Clear the data of rootPtr tree.
void RBT::clear(){
  deleteTree(rootPtr);
}

void RBT::visited(const int  &data){
    Visited[intcount]=data;
    intcount++;
}
/// Print the result.
void RBT::RBTPrint(){
  std::ofstream  ofile("PA7result.txt");
  createTree();
  inorder(rootPtr);
  for(int i  = 0; i < rumbers; i++){
     sum = sum+Visited[i];
  }

  ofile<<"1. sum of all values of red black tree is: "<<sum<<std::endl;
  ofile<<"2. the height of red black tree is: "<<getHeight()<<std::endl;
  ofile<<"3. the isEmpty status of red black tree before clear is: "<<isEmpty()<<std::endl;
  clear();
  ofile<<"4. the isEmpty status of red black tree after clear is: "<<isEmpty()<<std::endl;
  ofile.close();
}
