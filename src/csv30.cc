//
// Created by aknight on 11/26/19.
//
#include "csv30.h"

size_t LeakProofClass::_references = 0;
size_t LeakProofClass::_allocated = 0;
size_t LeakProofClass::_singles = 0;
size_t LeakProofClass::_arrays = 0;

void doDynamicMemoryManagement() {
    // Put your code here to allocate a single LeakProofClass instance
    LeakProofClass *obj1 = new LeakProofClass();

    // Put your code here to allocate an array of LeakProofClass instances
    LeakProofClass *arr = new LeakProofClass[5];

    // Be sure to delete all instances created in this function here.
    delete(obj1);
    delete[](arr);
}