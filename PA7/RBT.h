/**
@file RBT.h
@author Song Jiang
@date April 30,2018
*/


#ifndef RBT_H
#define RBT_H


#include "RBTNode.h"
#include "RandomData.h"

class RBT{
  public:
    RBT(); ///< Constructor
    ~RBT(); ///< Destructor
    /// Check if the tree is empty, it will return true if empty, or return false.
    bool isEmpty() const;
    /// Get the height of tree.
    int getHeight() const;
    bool add(const int& newData);///< Add the node whose data equals newData into the tree.
    void createTree(); ///< Create the tree.
    /// This will clear the data of tree.
    void clear();
   /// Print the informations.
    void RBTPrint();

  protected:
    /// Recursively calculate the height of tree.
    int getHeightHelper(RBTNode* subTreePtr) const;
    /// Recursively insert node.
    RBTNode* insertRBT(RBTNode* subTreePtr, RBTNode* newNode);
    /// Left rotation
    void leftRotation(RBTNode* subTreePtr, RBTNode* newNode);
    /// Right Rotation
    void rightRotation(RBTNode* subTreePtr, RBTNode* newNode);
    /// Insert fix up.
    void BRTFixup(RBTNode* subTreePtr, RBTNode* newNode);
    /// Delete the node.
    void deleteTree(RBTNode* subTreePtr);
    /// Traverse in the preorder.
    void preorder(RBTNode* treePtr);
    /// Traverse in the inorder.
    void inorder(RBTNode* treePtr);
    /// Removes the given target value from the tree while maintaining a binary search tree.
    RBTNode* deleteNode(RBTNode * subTreePtr, const int& target);
    /// Visit the data of node.
    void visited(const int &data);

  private:
    RBTNode* rootPtr; ///< Declare the root pointer of BST1 tree.
    int intcount;///< Declare the number of nodes which will be inserted
    int Visited[rumbers];///< Declare the array whihc contain the date of node.
    int sum;///< the sum of all of datas.
};

#endif//RBT_H
