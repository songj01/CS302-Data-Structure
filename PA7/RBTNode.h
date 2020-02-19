/**
@file RBTNode.h
@author Song Jiang
@date April 30,2018
*/


#ifndef RBT_NODE_H
#define RBT_NODE_H


enum Color {RED, BLACK};
/** Declare the node of tree, which have data,
    left and right child pointers.*/
class RBTNode{

  public:
    RBTNode(); ///< Constuctor
    RBTNode(const int&newData);
    void setData(const int& a);///< Set the data.
    void setLChildPtr(RBTNode* lcp);///< Set the left child pointer.
    void setRChildPtr(RBTNode* rcp);///< Set the right child pointer.
    void setParentPtr(RBTNode* parent);
    void setNodeColor(const Color &color);
    int getData() const; ///< Get the data.
    RBTNode* getLChildPtr() const;///< Get the left child pointer.
    RBTNode* getRChildPtr() const;///< Get the right child pointer.
    RBTNode* getParentPtr() const;///< Get the parent pointer.
    Color getNodeColor() const; ///< Get the color of node.

  private:
    int data; ///< Declare the data.
    RBTNode* lChildPtr; ///< Declare the left child pointer.
    RBTNode* rChildPtr; ///< Declare the right child pointer.
    RBTNode* parentPtr; ///< Declare parent pointer.
    Color  nodeColor; ///< Declare the color of pointer.
};


#endif//RBT_NODE_H
