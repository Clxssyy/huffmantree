/*
    HNode.hpp

    Include file for the HNode struct
*/

#ifndef HNODE_HPP
#define HNODE_HPP

// the nodes used for our encoding trees
// they will be used for both the encoding tree and the minheap
struct HNode {

    HNode* left = 0;
    HNode* right = 0;

    // set the default value to "*" and change it when you have an actual value
    // this way you dont have to worry about setting it for combined nodes
    char value = '*';
    int weight = 0;

    // create a new node from a string and its value
    // you must implement this function
    HNode(const char& value, const int& weight);

    // create a new node from two existing nodes
    // you must implement this function
    HNode(HNode* left, HNode* right);

    // this will delete all children when the destructor is called
    // this is ok because we will never call the destructor until we are done with the entire tree
    ~HNode() { delete left; delete right; }

    // overloading comparison operators
    // when comparing two pointers to HNode, make sure to de-reference them first
    // i.e. if (*node_pointer1 < *node_pointer2) ...
    bool operator<(const HNode& h) { return weight < h.weight; }
    bool operator<=(const HNode& h) { return weight <= h.weight; }
};

#endif
