//
// Created by aknight on 11/26/19.
//

#ifndef EX06_DYNAMICMEMORYMANAGEMENT_CSV30_H
#define EX06_DYNAMICMEMORYMANAGEMENT_CSV30_H

#include <glob.h>
#include <cstdlib>

class LeakProofClass {
    static size_t _references;
    static size_t _singles;
    static size_t _arrays;
    static size_t _allocated;

public:
    static size_t referenced() { return _references; }
    static size_t allocated() { return _allocated; }
    static bool created() { return _allocated > 0; }
    static size_t singles() { return _singles; }
    static size_t arrays() { return _arrays; }

public:
    void *operator new(size_t t) {
        _singles++;
        _references += t;
        _allocated += t;
        return ::new LeakProofClass();
    }

    void *operator new[](size_t t) {
        _references += t;
        _allocated += t;
        _arrays++;
        return ::new LeakProofClass();
    }

    void operator delete(void *p) {
        _references--;
        free(p);
    }

    void operator delete[](void *p, size_t t) {
        _references -= t;
        free(p);
    }
};

void doDynamicMemoryManagement();

#endif //EX06_DYNAMICMEMORYMANAGEMENT_CSV30_H
