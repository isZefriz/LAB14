#include <assert.h>
#include "libs/dataStructures/vector/vector.c"

void test_pushBack_emptyVector() {
    vector v = createVector(3);
    pushBack(&v, 2);
    pushBack(&v, 4);
    pushBack(&v, 6);

    assert(v.size == 3 && v.capacity == 3 && v.data[0] == 2 && v.data[1] == 4
           && v.data[2] == 6);
}

void test_pushBack_fullVector() {
    vector v = createVector(3);
    pushBack(&v, 2);
    pushBack(&v, 4);
    pushBack(&v, 6);
    pushBack(&v, 42);

    assert(v.size == 4 && v.capacity == 4);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert (v.size == 1);
    popBack(&v);
    assert (v.size == 0);
    assert (v.capacity == 1);
}

void test_atVector_notEmptyVector() {
    vector v = createVector(3);
    v.size = 3;
    v.data[0] = 1;
    v.data[1] = 2;
    v.data[2] = 3;
    assert(*atVector(&v, 1) == 2);
}

void test_atVector_requestToLastElement() {
    vector v = createVector(5);
    v.size = 5;
    v.data[0] = 1;
    v.data[1] = 2;
    v.data[2] = 3;
    v.data[3] = 4;
    v.data[4] = 5;
    assert(*atVector(&v, v.size - 1) == 5);
}

void test_back_oneElementInVector() {
    vector v = createVector(1);
    v.size = 1;
    v.data[0] = 1;
    assert(*back(&v) == 1);
}

void test_front_oneElementInVector() {
    vector v = createVector(1);
    v.size = 1;
    v.data[0] = 1;
    assert(*front(&v) == 1);
}

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}

int main() {
    vector v = createVector(SIZE_MAX);
    test();

    return 0;
}
