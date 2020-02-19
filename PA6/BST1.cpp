#include "BST1.h"
#include "BinaryNode.h"
#include "RandomData.h"
#include <iostream>
#include <fstream>
#include "BST2.h"

/// Initialize the rootPtr1.
BST1::BST1():rootPtr1(nullptr){

}
/// Destroy the tree.
BST1::~BST1(){
  clear();
}

/// If the tree is emtry, it will return true, or return false.
bool BST1::isEmpty() const{
    return rootPtr1 == nullptr;
}


BinaryNode* BST1::insertInorder(BinaryNode* subTreePtr, BinaryNode* newNode){
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
bool BST1::add(const int& newData){
  BinaryNode* newNodePtr = new BinaryNode();
  newNodePtr->setData(newData);
  newNodePtr->setLChildPtr(nullptr);
  newNodePtr->setRChildPtr(nullptr);
  rootPtr1 = insertInorder(rootPtr1, newNodePtr);
  return true;
}


/// Add the all of nodes into the tree.
void BST1::createTree(){
  RandomData aRandom;
  aRandom.generate100();
  int* p = aRandom.getArr1();
  for(int i =0; i<100;i++){
    int t = *(p+i);
    add(t);
  }
}

/// Add the all of nodes into the bonus tree.
void BST1::createTreeBonus(){
  RandomData cRandom;
  cRandom.generate100s();
  int* p = cRandom.getArr3();
  for(int i =0; i<100000;i++){
    int t = *(p+i);
    add(t);
  }
}


/** If the tree is empty, the height of tree is 0, or recursively calculate the height of
  * left subtree and right subtree. compare the value of left height and right
  * height, finllay greater value plus 1(root).*/
int BST1::getHeightHelper(BinaryNode* subTreePtr) const{
  if(subTreePtr == nullptr) return 0;
  else{
    int l = getHeightHelper(subTreePtr->getLChildPtr());
    int r = getHeightHelper(subTreePtr->getRChildPtr());
    return (l > r)? l+1:r+1;
  }
}

/// Get the height of rootPtr1 tree.
int BST1::getHeight() const{
  return getHeightHelper(rootPtr1);
}


/** If the tree is empty, the node of tree is 0, or recursively calculate the
  * numbers of nodes of left subtree and right subtree, finllay add
  * both of them and 1(root).*/
int BST1::getNumberOfNodesHelper(BinaryNode* subTreePtr) const{
  if(subTreePtr == nullptr) return 0;
  else{
    int a = getNumberOfNodesHelper(subTreePtr->getLChildPtr());
    int b = getNumberOfNodesHelper(subTreePtr->getRChildPtr());
    return (a+b+1);
  }
}

/// Get the nunbers of nodes of rootPtr1 tree.
int BST1::getNumberOfNodes() const{
    return getNumberOfNodesHelper(rootPtr1);
}


void BST1::inorder(BinaryNode* treePtr) const{
  std::ofstream ofile("PA06Result.txt",std::ofstream::out |std::ofstream::app);
  if(treePtr != nullptr){
    inorder(treePtr->getLChildPtr()); ///< Fisrtly, traverse the left child.
    ofile<<"inorder: "<<treePtr->getData()<<std::endl; ///< Secondly, traverse the root.
    inorder(treePtr->getRChildPtr()); ///< Finally, traverse the right child.
  ofile.close();
}
}

void BST1::inorderBonus(BinaryNode* treePtr) const{
  std::ofstream bonusofile("PA06Bonus.txt",std::ofstream::out |std::ofstream::app);
  if(treePtr != nullptr){
    inorderBonus(treePtr->getLChildPtr()); ///< Fisrtly, traverse the left child.
    bonusofile<<"inorderBonus: "<<treePtr->getData()<<std::endl; ///< Secondly, traverse the root.
    inorderBonus(treePtr->getRChildPtr()); ///< Finally, traverse the right child.
  bonusofile.close();
 }
}

/** Find the most left node. If the left child is null of this node,
  * then return this node, or recursovely find left node.*/
BinaryNode* BST1::leftmostNode(BinaryNode* nodePtr){
  if(nodePtr->getLChildPtr() == nullptr) return nodePtr;
  else
    return leftmostNode(nodePtr->getLChildPtr());
}

/** In order to delte the some node, we have to find it firstly:
  * If the target equals the data of root, we find it.
  * If the target is less than root, we will search left subtree,
  * or search right subtree.*/
BinaryNode* BST1::deleteNode(BinaryNode *subTreePtr, const int& target){
  if(subTreePtr == nullptr) return subTreePtr;
  else if(target< subTreePtr->getData())
    subTreePtr->setLChildPtr(deleteNode(subTreePtr->getLChildPtr(),target));
  else if(target> subTreePtr->getData())
    subTreePtr->setRChildPtr(deleteNode(subTreePtr->getRChildPtr(),target));
  /** After find the target, we will delete it:
    * If the node is leaf, we can delete it directly;
    * If the node has a child, the parents'pointer of will point at the child of this node;
    * If the node has two children, we will find the inordersucessor firstly, then replace
    * the target with inordersucessor,finally delete the inordersucessor.*/
  else{
    if(!subTreePtr->getLChildPtr()&& !subTreePtr->getRChildPtr()){
      delete subTreePtr;
      subTreePtr = nullptr;
      return subTreePtr;
  }
    else if(!subTreePtr->getLChildPtr()){
      BinaryNode * temp = subTreePtr;
      subTreePtr = subTreePtr->getRChildPtr();
      delete temp;
      return subTreePtr;
    }
    else if(!subTreePtr->getRChildPtr()){
      BinaryNode * temp = subTreePtr;
      subTreePtr = subTreePtr->getLChildPtr();
      delete temp;
      return subTreePtr;
  }
    else{
      BinaryNode *temp = leftmostNode(subTreePtr->getRChildPtr());
      subTreePtr->setData(temp->getData());
      subTreePtr->setRChildPtr(deleteNode(subTreePtr->getRChildPtr(), subTreePtr->getData()));
    }
  }
  return subTreePtr;
}


/// If the is not empty, recursively delete the left sub tree, then right subtree and finally root.
void BST1::deleteTree(BinaryNode* subTreePtr){
  if(subTreePtr != nullptr){
      deleteTree(subTreePtr->getLChildPtr());
      deleteTree(subTreePtr->getRChildPtr());
      delete subTreePtr;
    }
}

/// Clear the data of rootPtr1 tree.
void BST1::clear(){
  deleteTree(rootPtr1);
}


/// Print the result.
void BST1::BST1Print(){
  std::ofstream ofile("PA06Result.txt",std::ofstream::out |std::ofstream::app);
  RandomData aRandom;
  aRandom.generate10();
  createTree();
  ofile<<"---------Output information of BST1-------- "<<std::endl;
  ofile<<"the height of BST1 is: "<<getHeight()<<std::endl;
  ofile<<"the nodes of BST1 is: "<<getNumberOfNodes()<<std::endl;
  inorder(rootPtr1);
  ofile<<"---------Output information of BST2-------- "<<std::endl;
  BST2 bst2;
  bst2.BST2Display();
  ofile<<"---------Output information of modified BST1-------- "<<std::endl;
  int *p = aRandom.getArr2();
  for(int i = 0; i<10;i++) {deleteNode(rootPtr1,*(p+i));}
  ofile<<"the height of modified BST1 is: "<<getHeight()<<std::endl;
  ofile<<"the nodes of modified BST1 is: "<<getNumberOfNodes()<<std::endl;
  inorder(rootPtr1);
  ofile<<"the result of isEmpty method before clear operation is: "<<isEmpty()<<std::endl;
  clear();
  ofile<<"the result of isEmpty method after clear operation is: "<<isEmpty()<<std::endl;
  ofile.close();
}
/// Print the result.
void BST1::BST1PrintBonus(){
  std::ofstream bonusofile("PA06Bonus.txt",std::ofstream::out |std::ofstream::app);
  RandomData aRandom;
  aRandom.generate10s();
  createTreeBonus();
  bonusofile<<"---------Output information of BST1-------- "<<std::endl;
  bonusofile<<"the height of BonusBST1 is: "<<getHeight()<<std::endl;
  bonusofile<<"the nodes of BonusBST1 is: "<<getNumberOfNodes()<<std::endl;
  inorderBonus(rootPtr1);
  bonusofile<<"---------Output information of BonusBST2-------- "<<std::endl;
  BST2 bst2;
  bst2.BST2DisplayBonus();
  bonusofile<<"---------Output information of modified BonusBST1-------- "<<std::endl;
  int *p = aRandom.getArr4();
  for(int i = 0; i<10;i++) {deleteNode(rootPtr1,*(p+i));}
  bonusofile<<"the height of modified BonusBST1 is: "<<getHeight()<<std::endl;
  bonusofile<<"the nodes of modified BonusBST1 is: "<<getNumberOfNodes()<<std::endl;
  inorderBonus(rootPtr1);
  bonusofile<<"the result of isEmpty method before clear operation is: "<<isEmpty()<<std::endl;
  clear();
  bonusofile<<"the result of isEmpty method after clear operation is: "<<isEmpty()<<std::endl;
  bonusofile.close();
}
