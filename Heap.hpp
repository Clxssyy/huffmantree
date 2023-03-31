/*
    Heap.hpp

    Include file for the Heap class
*/

#ifndef HEAP_HPP
#define HEAP_HPP

#include "HNode.hpp"
#include <vector>

class Heap {
protected:
    // holds the tree
    std::vector<HNode*> tree;

    // index of the last element added
    int position = 0;

public:
    // number of nodes in the tree
    int count=0;

    // constructor & destructor
    Heap() { tree.resize(2); }
    ~Heap() {}

    // add an element to the tree
    void enqueue( HNode*);

    // fix the heap from a specific index up
    void fix_up(const int& index);

    // remove the smallest element
    HNode* dequeue();

    // fix the tree after replacing the smallest element
    void fix_down(const int& index);

    // remove all nodes from the tree
    void clear();
};

#endif
