/**
@file BST1.h
@author Song Jiang
@date April 21,2018
*/


#ifndef BST1_H
#define BST1_H
#include "BinaryNode.h"

class BST1{
  public:
    BST1(); ///< Constructor
    ~BST1(); ///< Destructor
    /// Check if the tree is empty, it will return true if empty, or return false.
    bool isEmpty() const;
    /// Get the height of tree.
    int getHeight() const;
    /// Get the numbers of node.
    int getNumberOfNodes() const;
    bool add(const int& newData);///< Add the node whose data equals newData into the tree.
    void createTree(); ///< Create the tree.
    void createTreeBonus();///< Create the bonus tree.
    /// This will clear the data of BST1 tree.
    void clear();
   /// Print the informations of BST1 tree, such as height, nunbers of node.
    void BST1Print();
    /// Print the informations of BST1 bonus tree, such as height, nunbers of node.
    void BST1PrintBonus();

  protected:
    /// Recursively calculate the height of tree.
    int getHeightHelper(BinaryNode* subTreePtr) const;
    /// Recursively calculate the numbers of node.
    int getNumberOfNodesHelper(BinaryNode* subTreePtr) const;
    /// Recursively finds where the given node should be placed and inserts it in a leaf at that point.
    BinaryNode* insertInorder(BinaryNode* subTreePtr, BinaryNode* newNode);
    /// Search the leftmost node in the right subtree of the node
    BinaryNode* leftmostNode(BinaryNode* nodePtr);
    /// Recursively delete the left child, right child and then root.
    void deleteTree(BinaryNode* subTreePtr);
    /// Traverse in the inorder.
    void inorder(BinaryNode* treePtr)const;
    /// Traverse in the inorder(Bonus use).
    void inorderBonus(BinaryNode* treePtr)const;
    /// Removes the given target value from the tree while maintaining a binary search tree.
    BinaryNode* deleteNode(BinaryNode * subTreePtr, const int& target);

  private:
    BinaryNode* rootPtr1; ///< Declare the root pointer of BST1 tree.
};

#endif//BST1_H
