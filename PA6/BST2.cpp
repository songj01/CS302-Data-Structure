#include "BST2.h"
#include "BinaryNode.h"
#include "RandomData.h"
#include <iostream>
#include <fstream>

/// Initialize the rootPtr2.
BST2::BST2():rootPtr2(nullptr){

}

/// Destroy the tree.
BST2::~BST2(){
  clear();
}


BinaryNode* BST2::insertInorder(BinaryNode* subTreePtr, BinaryNode* newNode){
  /// If the tree is empty, insert the node as root.
  if(subTreePtr == nullptr) return newNode;
  /// If the data of node is less than root, go left to find it anfd then insert it.
  else if(subTreePtr->getData() > newNode->getData()){
      BinaryNode* lPtr = insertInorder(subTreePtr->getLChildPtr(), newNode);
      subTreePtr->setLChildPtr(lPtr);
  }
  /// If the data of node is greater than root, go right to find it anfd then insert it.
    else{
      BinaryNode* rPtr = insertInorder(subTreePtr->getRChildPtr(), newNode);
      subTreePtr->setRChildPtr(rPtr);
    }
    return subTreePtr;
}

/// Add a new node to the tree.
bool BST2::add(const int& newData){
  BinaryNode* newNodePtr = new BinaryNode();
  newNodePtr->setData(newData);
  newNodePtr->setLChildPtr(nullptr);
  newNodePtr->setRChildPtr(nullptr);
  rootPtr2 = insertInorder(rootPtr2, newNodePtr);
  return true;
}

/// Add the all of nodes into the tree.
bool BST2::createTree(){
 RandomData aRandom;
 aRandom.generate10();
  int* p = aRandom.getArr2();
  for(int i =0; i<10;i++){
    int t = *(p+i);
    add(t);
  }
  return true;
}

/// Add the all of nodes into the bonus tree.
bool BST2::createTreeBonus(){
 RandomData aRandom;
 aRandom.generate10s();
  int* p = aRandom.getArr4();
  for(int i =0; i<10;i++){
    int t = *(p+i);
    add(t);
  }
  return true;
}


void BST2::preorder(BinaryNode* treePtr) const{
  std::ofstream ofile("PA06Result.txt",std::ofstream::out |std::ofstream::app);
  if(treePtr != nullptr){
    ofile<<"preorder: "<<treePtr->getData()<<std::endl; ///< Fisrtly, traverse the root.
    preorder(treePtr->getLChildPtr()); ///< Secondly, traverse the left child.
    preorder(treePtr->getRChildPtr()); ///< Finally, traverse the right child.
  ofile.close();
  }
}

void BST2::inorder(BinaryNode* treePtr) const{
  std::ofstream ofile("PA06Result.txt",std::ofstream::out |std::ofstream::app);
  if(treePtr != nullptr){
    inorder(treePtr->getLChildPtr()); ///< Fisrtly, traverse the left child.
    ofile<<"inorder: "<<treePtr->getData()<<std::endl;///< Secondly, traverse the root.
    inorder(treePtr->getRChildPtr());  ///< Finally, traverse the right child.
  ofile.close();
  }
}

void BST2::postorder(BinaryNode* treePtr) const{
  std::ofstream ofile("PA06Result.txt",std::ofstream::out |std::ofstream::app);
  if(treePtr != nullptr){
    postorder(treePtr->getLChildPtr()); ///< Fisrtly, traverse the left child.
    postorder(treePtr->getRChildPtr()); ///< Secondly, traverse the right child.
    ofile<<"postorder: "<<treePtr->getData()<<std::endl; ///< Finally, traverse the root.
  ofile.close();
  }
}

void BST2::preorderBonus(BinaryNode* treePtr) const{
  std::ofstream bonusofile("PA06Bonus.txt",std::ofstream::out |std::ofstream::app);
  if(treePtr != nullptr){
    bonusofile<<"preorderBonus: "<<treePtr->getData()<<std::endl;///< Fisrtly, traverse the root.
    preorderBonus(treePtr->getLChildPtr()); ///< Secondly, traverse the left child.
    preorderBonus(treePtr->getRChildPtr()); ///< Finally, traverse the right child.
  bonusofile.close();
  }
}

void BST2::inorderBonus(BinaryNode* treePtr) const{
  std::ofstream bonusofile("PA06Bonus.txt",std::ofstream::out |std::ofstream::app);
  if(treePtr != nullptr){
    inorderBonus(treePtr->getLChildPtr()); ///< Fisrtly, traverse the left child.
    bonusofile<<"inorderBonus: "<<treePtr->getData()<<std::endl; ///< Secondly, traverse the root.
    inorderBonus(treePtr->getRChildPtr()); ///< Finally, traverse the right child.
  bonusofile.close();
  }
}

void BST2::postorderBonus(BinaryNode* treePtr) const{
  std::ofstream bonusofile("PA06Bonus.txt",std::ofstream::out |std::ofstream::app);
  if(treePtr != nullptr){
    postorderBonus(treePtr->getLChildPtr()); ///< Fisrtly, traverse the left child.
    postorderBonus(treePtr->getRChildPtr()); ///< Secondly, traverse the right child.
    bonusofile<<"postorderBonus: "<<treePtr->getData()<<std::endl; ///< Finally, traverse the root.
  bonusofile.close();
  }
}

/// If the is not empty, recursively delete the left sub tree, then right subtree and finally root.
void BST2::deleteTree(BinaryNode* subTreePtr){
  if(subTreePtr != nullptr){
      deleteTree(subTreePtr->getLChildPtr());
      deleteTree(subTreePtr->getRChildPtr());
      delete subTreePtr;
    }
}

/// Clear the data of rootPtr2 tree.
void BST2::clear(){
  deleteTree(rootPtr2);
}


void BST2::BST2Display(){
  createTree();
  preorder(rootPtr2); ///< Print the tree in the preorder.
  inorder(rootPtr2); ///< Print the tree in the inorder.
  postorder(rootPtr2); ///< Print the tree in the postorder.
}

void BST2::BST2DisplayBonus(){
  createTreeBonus();
  preorderBonus(rootPtr2); ///< Print the bonus tree in the preorder.
  inorderBonus(rootPtr2); ///< Print the bonus tree in the inorder.
  postorderBonus(rootPtr2); ///< Print the bonus tree in the postorder.
}
