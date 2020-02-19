/**
@file BST2.h
@author Song Jiang
@date April 21,2018
*/

#ifndef BST2_H
#define BST2_H

#include "BinaryNode.h"

class BST2{

public:
  BST2(); ///< Constructor
  ~BST2(); ///< Destructor
  bool add(const int& newData); ///< Add the node whose data equals newData into the tree.
  bool createTree();///< Create the tree.
  bool createTreeBonus(); ///< Create the bonus tree.
  /// This will clear the data of BST2 tree.
  void clear();
  /// This will print the date in the preorder, inorder and postorder.
  void BST2Display();
    /// This will print the bonus date in the preorder, inorder and postorder.
  void BST2DisplayBonus();

protected:
  /// Recursively finds where the given node should be placed and inserts it in a leaf at that point.
  BinaryNode* insertInorder(BinaryNode* subTreePtr, BinaryNode* newNode);
  /// Traverse in the preorder.
  void preorder(BinaryNode* treePtr) const;
  /// Traverse in the inorder.
  void inorder(BinaryNode* treePtr) const;
  /// Traverse in the postorder.
  void postorder(BinaryNode* treePtr) const;
  /// Traverse in the preorder(Bonus use).
  void preorderBonus(BinaryNode* treePtr) const;
  /// Traverse in the inorder(Bonus use).
  void inorderBonus(BinaryNode* treePtr) const;
  /// Traverse in the postorder(Bonus use).
  void postorderBonus(BinaryNode* treePtr) const;
  /// Recursively delete the left child, right child and then root.
  void deleteTree(BinaryNode* subTreePtr);

private:
  BinaryNode* rootPtr2; ///< Declare the root pointer of BST2 tree.
};

#endif//BST2_H
