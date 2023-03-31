/*
    Heap.cpp

    Implementation file for the Heap class
*/

#include "Heap.hpp"

// add an element to the tree
void Heap::enqueue(HNode* node) {

    // expand the heap if necessary
    if (++position >= tree.size())
        tree.resize(position * 2);

    // add the new node at the next avaliable spot
    tree[position] = node;

    // fix the heap from the last node added
    fix_up(position);
    
    // increment node count
    count++;
}

// fix the heap from a specific index up
void Heap::fix_up(const int& index) {
    // get the parent index
    int parent = index / 2;

    // if the parent is bigger, swap the nodes
    if (parent > 0 && *tree[index] < *tree[parent]) {
      HNode* temp = tree[index];
      tree[index] = tree[parent];
      tree[parent] = temp;

      // recursively heapify up
      fix_up(parent);
    }
}

// remove the smallest element (root)
HNode* Heap::dequeue() {
    // get the root node
    HNode* root = tree[1];

    // move the last node added to the root
    tree[1] = tree[position--];

    // recursively heapify from the new root
    fix_down(1);

    // decrement node count
    count--;

    // return the old root node
    return root;
}

// fix the tree after replacing the smallest element
void Heap::fix_down(const int& index) {
    // get the child indices
    int left_child = index * 2;
    int right_child = left_child + 1;

    // check if children are smaller
    int parent = index;

    if (left_child <= position && *tree[left_child] < *tree[parent])
        parent = left_child;
    if (right_child <= position && *tree[right_child] < *tree[parent])
        parent = right_child;

    // if the parent is different than the current node, swap them
    if (parent != index) {
        HNode* temp = tree[index];
        tree[index] = tree[parent];
        tree[parent] = temp;

        // recursively heapify down
        fix_down(parent);
    }
}

// remove all HNodes from the heap
void Heap::clear() {
    // delete all the nodes in the tree
    for (int i = 1; i <= position; i++) {
      delete tree[i];
      tree[i] = nullptr;
    }

    // reset the position and count
    position = 0;
    count = 0;

    // resize the tree to its initial capacity
    tree.resize(2);
}
