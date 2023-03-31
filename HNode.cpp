/*
    HNode.cpp

    Implementation file for the HNode struct constructors
*/

#include "HNode.hpp"

// constructor for leaf nodes
HNode::HNode(const char& value, const int& weight) : value(value), weight(weight) {}

// constructor for internal nodes
HNode::HNode(HNode* left, HNode* right) : left(left),
                                          right(right), 
                                          weight(left->weight + right->weight) {}
