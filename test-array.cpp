//lang::Cpp
#include <iostream>
#include <cmath>
#include <cfloat>
#include "array.h"

/*
 * HELPERS
 */
void OK(const char* msg) {
    printf("%s: OK\n", msg);
}


void FAIL() {
    std::cout<<"fail\n";
    exit(1);
}


void t_true(bool p) {
    if (!p) {
        FAIL();
    }
}


void t_false(bool p) {
    if (p) {
        FAIL();
    }
}


/*
 * OBJECT
 */
void testArrayObjectConstructor() {
    Array* array1 = new Array();
    Array* array2 = new Array(5000);
    delete array1;
    delete array2;
    OK("arrayObject constructor()");
}


void testArrayObjectLen() {
    Array* array1 = new Array(1);
    Array* array2 = new Array(5000);
    t_true(array1->len() == 0);
    t_true(array2->len() == 0);
    delete array1;
    delete array2;
    OK("arrayObject len()");
}

void testArrayObjectElementAt() {
    Array* array1 = new Array(10);
    Object* element1 = new Object();
    Object* element2 = new Object();
    array1->set(0, element1);
    array1->set(2, element2);
    t_true(array1->get(0)->equals(element1));
    t_true(array1->get(2)->equals(element2));
    delete array1;
    delete element1;
    delete element2;
    OK("arrayObject elementAt()");
}


void testArrayObjectIndexOf() {
    Array* array1 = new Array(10);
    Object* element1 = new Object();
    Object* element2 = new Object();
    Object* element3 = new Object();
    array1->set(0, element1);
    array1->set(2, element2);
    t_true(array1->indexOf(element1) == 0);
    t_true(array1->indexOf(element2) == 2);
    t_true(array1->indexOf(element3) > 2);
    delete array1;
    delete element1;
    delete element2;
    delete element3;
    OK("arrayObject indexOf()");
}


void testArrayObjectReplace() {
    Array* array1 = new Array(10);
    Object* element1 = new Object();
    Object* element2 = new Object();
    Object* element3 = new Object();
    array1->set(0, element1);
    array1->set(1, element2);
    array1->replace(0, element3);
    t_false(array1->get(0)->equals(element1));
    t_true(array1->get(0)->equals(element3));
    array1->replace(2, element1);
    t_true(array1->get(2)->equals(element1));
    delete array1;
    delete element1;
    delete element2;
    delete element3;
    OK("arrayObject replace()");
}


void testArrayObjectInsert() {
    Array* array1 = new Array(10);
    Object* element1 = new Object();
    Object* element2 = new Object();
    Object* element3 = new Object();
    Object* element4 = new Object();
    array1->set(0, element1);
    array1->set(1, element2);
    array1->insert(0, element3);
    t_true(array1->get(0)->equals(element3));
    t_true(array1->get(1)->equals(element1));
    t_true(array1->get(2)->equals(element2));
    array1->insert(2, element4);
    t_true(array1->get(0)->equals(element3));
    t_true(array1->get(1)->equals(element1));
    t_true(array1->get(2)->equals(element4));
    t_true(array1->get(3)->equals(element2));
    delete array1;
    delete element1;
    delete element2;
    delete element3;
    delete element4;
    OK("arrayObject insert()");
}


void testArrayObjectSet() {
    Array* array1 = new Array(10);
    Object* element1 = new Object();
    Object* element2 = new Object();
    Object* element3 = new Object();
    array1->set(0, element1);
    array1->set(9, element2);
    array1->set(4, element3);
    t_true(array1->get(0)->equals(element1));
    t_true(array1->get(9)->equals(element2));
    t_true(array1->get(4)->equals(element3));
    delete array1;
    delete element1;
    delete element2;
    delete element3;
    OK("arrayObject set()");
}


void testArrayObjectRemove() {
    Array* array1 = new Array(10);
    Object* element1 = new Object();
    Object* element2 = new Object();
    Object* element3 = new Object();
    array1->set(0, element1);
    array1->set(9, element2);
    array1->set(4, element3);
    Object* e1 = array1->remove(0);
    Object* e2 = array1->remove(8);
    Object* e3 = array1->remove(3);
    t_true(e1->equals(element1));
    t_true(e2->equals(element2));
    t_true(e3->equals(element3));
    delete array1;
    delete element1;
    delete element2;
    delete element3;
    OK("arrayObject remove()");
}


void testArrayObjectGet() {
    Array* array1 = new Array(10);
    Object* element1 = new Object();
    Object* element2 = new Object();
    Object* element3 = new Object();
    array1->set(0, element1);
    array1->set(9, element2);
    array1->set(4, element3);
    Object* e1 = array1->get(0);
    Object* e2 = array1->get(9);
    Object* e3 = array1->get(4);
    t_true(e1->equals(element1));
    t_true(e2->equals(element2));
    t_true(e3->equals(element3));
    delete array1;
    delete element1;
    delete element2;
    delete element3;
    OK("arrayObject get()");
}


void testArrayObjectSplit() {
    Array* array1 = new Array(10);
    Object* element1 = new Object();
    Object* element2 = new Object();
    Object* element3 = new Object();
    array1->set(0, element1);
    array1->set(9, element2);
    array1->set(4, element3);
    Array* array2 = array1->split(1);
    t_true(array2->len() == 1);
    t_true(array1->len() == 2);
    t_true(array2->get(0)->equals(element1));
    t_true(array1->get(7)->equals(element2));
    t_true(array1->get(2)->equals(element3));
    delete array1;
    delete array2;
    delete element1;
    delete element2;
    delete element3;
    OK("arrayObject split()");
}


void testArrayObjectIsEmpty() {
    Array* array1 = new Array(10);
    Object* element1 = new Object();
    Object* element2 = new Object();
    t_true(array1->isEmpty());
    array1->set(0, element1);
    t_false(array1->isEmpty());
    array1->set(9, element2);
    t_false(array1->isEmpty());
    array1->remove(0);
    t_false(array1->isEmpty());
    array1->remove(8);
    t_true(array1->isEmpty());
    delete array1;
    delete element1;
    delete element2;
    OK("arrayObject isEmpty()");
}


void testObjectArray() {
    testArrayObjectConstructor();
    testArrayObjectLen();
    testArrayObjectElementAt();
    testArrayObjectIndexOf();
    testArrayObjectReplace();
    testArrayObjectInsert();
    testArrayObjectSet();
    testArrayObjectRemove();
    testArrayObjectGet();
    testArrayObjectSplit();
    testArrayObjectIsEmpty();
}


/*
 * INTEGER
 */
void testArrayIntegerConstructor() {
    IntArray* array1 = new IntArray();
    IntArray* array2 = new IntArray(5000);
    delete array1;
    delete array2;
    OK("arrayInt constructor()");
}


void testArrayIntegerLen() {
    IntArray* array1 = new IntArray(1);
    IntArray* array2 = new IntArray(5000);
    t_true(array1->len() == 0);
    t_true(array2->len() == 0);
    delete array1;
    delete array2;
    OK("arrayInt len()");
}


void testArrayIntegerElementAt() {
    IntArray* array1 = new IntArray(10);
    int element1 = 1;
    int element2 = 2;
    array1->set(0, element1);
    array1->set(2, element2);
    t_true(array1->get(0) == element1);
    t_true(array1->get(2) == element2);
    delete array1;
    OK("arrayInt elementAt()");
}


void testArrayIntegerIndexOf() {
    IntArray* array1 = new IntArray(10);
    int element1 = 1;
    int element2 = 2;
    int element3 = 3;
    array1->set(0, element1);
    array1->set(2, element2);
    t_true(array1->indexOf(element1) == 0);
    t_true(array1->indexOf(element2) == 2);
    t_true(array1->indexOf(element3) > 10);
    delete array1;
    OK("arrayInt indexOf()");
}


void testArrayIntegerReplace() {
    IntArray* array1 = new IntArray(10);
    int element1 = 1;
    int element2 = 2;
    int element3 = 3;
    array1->set(0, element1);
    array1->set(1, element2);
    array1->replace(0, element3);
    t_false(array1->get(0) == element1);
    t_true(array1->get(0)  == element3);
    array1->replace(2, element1);
    t_true(array1->get(2) == element1);
    delete array1;
    OK("arrayInt replace()");
}


void testArrayIntegerInsert() {
    IntArray* array1 = new IntArray(10);
    int element1 = 1;
    int element2 = 2;
    int element3 = 3;
    int element4 = 4;
    array1->set(0, element1);
    array1->set(1, element2);
    array1->insert(0, element3);
    t_true(array1->get(0) == element3);
    t_true(array1->get(1) == element1);
    t_true(array1->get(2) == element2);
    array1->insert(2, element4);
    t_true(array1->get(0) == element3);
    t_true(array1->get(1) == element1);
    t_true(array1->get(2) == element4);
    t_true(array1->get(3) == element2);
    delete array1;
    OK("arrayInt insert()");
}


void testArrayIntegerSet() {
    IntArray* array1 = new IntArray(10);
    int element1 = 1;
    int element2 = 2;
    int element3 = 3;
    array1->set(0, element1);
    array1->set(9, element2);
    array1->set(4, element3);
    t_true(array1->get(0) == element1);
    t_true(array1->get(9) == element2);
    t_true(array1->get(4) == element3);
    delete array1;
    OK("arrayInt set()");
}


void testArrayIntegerRemove() {
    IntArray* array1 = new IntArray(10);
    int element1 = 1;
    int element2 = 2;
    int element3 = 3;
    array1->set(0, element1);
    array1->set(9, element2);
    array1->set(4, element3);
    int e1 = array1->remove(0);
    int e2 = array1->remove(8);
    int e3 = array1->remove(3);
    t_true(e1 == element1);
    t_true(e2 == element2);
    t_true(e3 == element3);
    delete array1;
    OK("arrayInt remove()");
}


void testArrayIntegerGet() {
    IntArray* array1 = new IntArray(10);
    int element1 = 1;
    int element2 = 2;
    int element3 = 3;
    array1->set(0, element1);
    array1->set(9, element2);
    array1->set(4, element3);
    int e1 = array1->get(0);
    int e2 = array1->get(9);
    int e3 = array1->get(4);
    t_true(e1 == element1);
    t_true(e2 == element2);
    t_true(e3 == element3);
    delete array1;
    OK("arrayInt get()");
}


void testArrayIntegerSplit() {
    IntArray* array1 = new IntArray(10);
    int element1 = 1;
    int element2 = 2;
    int element3 = 3;
    array1->set(0, element1);
    array1->set(9, element2);
    array1->set(4, element3);
    IntArray* array2 = array1->split(1);
    t_true(array2->len() == 1);
    t_true(array1->len() == 2);
    t_true(array2->get(0) == element1);
    t_true(array1->get(7) == element2);
    t_true(array1->get(2) == element3);
    delete array1;
    delete array2;
    OK("arrayInt split()");
}


void testArrayIntegerIsEmpty() {
    IntArray* array1 = new IntArray(10);
    int element1 = 1;
    int element2 = 2;
    t_true(array1->isEmpty());
    array1->set(0, element1);
    t_false(array1->isEmpty());
    array1->set(9, element2);
    t_false(array1->isEmpty());
    array1->remove(0);
    t_false(array1->isEmpty());
    array1->remove(8);
    t_true(array1->isEmpty());
    delete array1;
    OK("arrayInt isEmpty()");
}


void testIntegerArray() {
    testArrayIntegerConstructor();
    testArrayIntegerLen();
    testArrayIntegerElementAt();
    testArrayIntegerIndexOf();
    testArrayIntegerReplace();
    testArrayIntegerInsert();
    testArrayIntegerSet();
    testArrayIntegerRemove();
    testArrayIntegerGet();
    testArrayIntegerSplit();
    testArrayIntegerIsEmpty();
}


/*
 * FLOAT
 */
void testArrayFloatConstructor() {
    FloatArray* array1 = new FloatArray();
    FloatArray* array2 = new FloatArray(5000);
    delete array1;
    delete array2;
    OK("arrayFloat constructor()");
}


void testArrayFloatLen() {
    FloatArray* array1 = new FloatArray(1);
    FloatArray* array2 = new FloatArray(5000);
    t_true(array1->len() == 0);
    t_true(array2->len() == 0);
    delete array1;
    delete array2;
    OK("arrayFloat len()");
}


void testArrayFloatElementAt() {
    FloatArray* array1 = new FloatArray(10);
    float element1 = 1;
    float element2 = 2;
    array1->set(0, element1);
    array1->set(2, element2);
    t_true(std::abs(array1->get(0) - element1) < DBL_EPSILON);
    t_true(std::abs(array1->get(2) - element2) < DBL_EPSILON);
    delete array1;
    OK("arrayFloat elementAt()");
}


void testArrayFloatIndexOf() {
    FloatArray* array1 = new FloatArray(10);
    float element1 = 1;
    float element2 = 2;
    float element3 = 3;
    array1->set(0, element1);
    array1->set(2, element2);
    t_true(array1->indexOf(element1) == 0);
    t_true(array1->indexOf(element2) == 2);
    t_true(array1->indexOf(element3) > 10);
    delete array1;
    OK("arrayFloat indexOf()");
}


void testArrayFloatReplace() {
    FloatArray* array1 = new FloatArray(10);
    float element1 = 1;
    float element2 = 2;
    float element3 = 3;
    array1->set(0, element1);
    array1->set(1, element2);
    array1->replace(0, element3);
    t_false(std::abs(array1->get(0) - element1) < DBL_EPSILON);
    t_true(std::abs(array1->get(0)  - element3) < DBL_EPSILON);
    array1->replace(2, element1);
    t_true(std::abs(array1->get(2) - element1) < DBL_EPSILON);
    delete array1;
    OK("arrayFloat replace()");
}


void testArrayFloatInsert() {
    FloatArray* array1 = new FloatArray(10);
    float element1 = 1;
    float element2 = 2;
    float element3 = 3;
    float element4 = 4;
    array1->set(0, element1);
    array1->set(1, element2);
    array1->insert(0, element3);
    t_true(std::abs(array1->get(0) - element3) < DBL_EPSILON);
    t_true(std::abs(array1->get(1) - element1) < DBL_EPSILON);
    t_true(std::abs(array1->get(2) - element2) < DBL_EPSILON);
    array1->insert(2, element4);
    t_true(std::abs(array1->get(0) - element3) < DBL_EPSILON);
    t_true(std::abs(array1->get(1) - element1) < DBL_EPSILON);
    t_true(std::abs(array1->get(2) - element4) < DBL_EPSILON);
    t_true(std::abs(array1->get(3) - element2) < DBL_EPSILON);
    delete array1;
    OK("arrayFloat insert()");
}


void testArrayFloatSet() {
    FloatArray* array1 = new FloatArray(10);
    float element1 = 1;
    float element2 = 2;
    float element3 = 3;
    array1->set(0, element1);
    array1->set(9, element2);
    array1->set(4, element3);
    t_true(std::abs(array1->get(0) - element1) < DBL_EPSILON);
    t_true(std::abs(array1->get(9) - element2) < DBL_EPSILON);
    t_true(std::abs(array1->get(4) - element3) < DBL_EPSILON);
    delete array1;
    OK("arrayFloat set()");
}


void testArrayFloatRemove() {
    FloatArray* array1 = new FloatArray(10);
    float element1 = 1;
    float element2 = 2;
    float element3 = 3;
    array1->set(0, element1);
    array1->set(9, element2);
    array1->set(4, element3);
    float e1 = array1->remove(0);
    float e2 = array1->remove(8);
    float e3 = array1->remove(3);
    t_true(std::abs(e1 - element1) < DBL_EPSILON);
    t_true(std::abs(e2 - element2) < DBL_EPSILON);
    t_true(std::abs(e3 - element3) < DBL_EPSILON);
    delete array1;
    OK("arrayFloat remove()");
}


void testArrayFloatGet() {
    FloatArray* array1 = new FloatArray(10);
    float element1 = 1;
    float element2 = 2;
    float element3 = 3;
    array1->set(0, element1);
    array1->set(9, element2);
    array1->set(4, element3);
    float e1 = array1->get(0);
    float e2 = array1->get(9);
    float e3 = array1->get(4);
    t_true(std::abs(e1 - element1) < DBL_EPSILON);
    t_true(std::abs(e2 - element2) < DBL_EPSILON);
    t_true(std::abs(e3 - element3) < DBL_EPSILON);
    delete array1;
    OK("arrayFloat get()");
}


void testArrayFloatSplit() {
    FloatArray* array1 = new FloatArray(10);
    float element1 = 1;
    float element2 = 2;
    float element3 = 3;
    array1->set(0, element1);
    array1->set(9, element2);
    array1->set(4, element3);
    FloatArray* array2 = array1->split(1);
    t_true(array2->len() == 1);
    t_true(array1->len() == 2);
    t_true(std::abs(array2->get(0) - element1) < DBL_EPSILON);
    t_true(std::abs(array1->get(7) - element2) < DBL_EPSILON);
    t_true(std::abs(array1->get(2) - element3) < DBL_EPSILON);
    delete array1;
    delete array2;
    OK("arrayFloat split()");
}


void testArrayFloatIsEmpty() {
    FloatArray* array1 = new FloatArray(10);
    float element1 = 1;
    float element2 = 2;
    t_true(array1->isEmpty());
    array1->set(0, element1);
    t_false(array1->isEmpty());
    array1->set(9, element2);
    t_false(array1->isEmpty());
    array1->remove(0);
    t_false(array1->isEmpty());
    array1->remove(8);
    t_true(array1->isEmpty());
    delete array1;
    OK("arrayFloat isEmpty()");
}


void testFloatArray() {
    testArrayFloatConstructor();
    testArrayFloatLen();
    testArrayFloatElementAt();
    testArrayFloatIndexOf();
    testArrayFloatReplace();
    testArrayFloatInsert();
    testArrayFloatSet();
    testArrayFloatRemove();
    testArrayFloatGet();
    testArrayFloatSplit();
    testArrayFloatIsEmpty();
}

/*
 * BOOLEAN
 */
void testArrayBoolConstructor() {
    BoolArray* array1 = new BoolArray();
    BoolArray* array2 = new BoolArray(5000);
    delete array1;
    delete array2;
    OK("arrayBool constructor()");
}


void testArrayBoolLen() {
    BoolArray* array1 = new BoolArray(1);
    BoolArray* array2 = new BoolArray(5000);
    t_true(array1->len() == 0);
    t_true(array2->len() == 0);
    delete array1;
    delete array2;
    OK("arrayBool len()");
}


void testArrayBoolElementAt() {
    BoolArray* array1 = new BoolArray(10);
    bool element1 = true;
    bool element2 = false;
    array1->set(0, element1);
    array1->set(2, element2);
    t_true(array1->get(0) == element1);
    t_true(array1->get(2) == element2);
    delete array1;
    OK("arrayBool elementAt()");
}


void testArrayBoolIndexOf() {
    BoolArray* array1 = new BoolArray(10);
    bool element1 = true;
    bool element2 = false;
    bool element3 = true;
    array1->set(0, element1);
    array1->set(2, element2);
    t_true(array1->indexOf(element1) == 0);
    t_true(array1->indexOf(element2) == 2);
    t_true(array1->indexOf(element3) == 0);
    delete array1;
    OK("arrayBool indexOf()");
}


void testArrayBoolReplace() {
    BoolArray* array1 = new BoolArray(10);
    bool element1 = true;
    bool element2 = false;
    bool element3 = true;
    array1->set(0, element1);
    array1->set(1, element2);
    array1->replace(0, element3);
    t_true(array1->get(0) == element1);
    t_true(array1->get(0)  == element3);
    array1->replace(2, element1);
    t_true(array1->get(2) == element1);
    delete array1;
    OK("arrayBool replace()");
}


void testArrayBoolInsert() {
    BoolArray* array1 = new BoolArray(10);
    bool element1 = true;
    bool element2 = false;
    bool element3 = true;
    bool element4 = false;
    array1->set(0, element1);
    array1->set(1, element2);
    array1->insert(0, element3);
    t_true(array1->get(0) == element3);
    t_true(array1->get(1) == element1);
    t_true(array1->get(2) == element2);
    array1->insert(2, element4);
    t_true(array1->get(0) == element3);
    t_true(array1->get(1) == element1);
    t_true(array1->get(2) == element4);
    t_true(array1->get(3) == element2);
    delete array1;
    OK("arrayBool insert()");
}


void testArrayBoolSet() {
    BoolArray* array1 = new BoolArray(10);
    bool element1 = true;
    bool element2 = false;
    bool element3 = true;
    array1->set(0, element1);
    array1->set(9, element2);
    array1->set(4, element3);
    t_true(array1->get(0) == element1);
    t_true(array1->get(9) == element2);
    t_true(array1->get(4) == element3);
    delete array1;
    OK("arrayBool set()");
}


void testArrayBoolRemove() {
    BoolArray* array1 = new BoolArray(10);
    bool element1 = true;
    bool element2 = false;
    bool element3 = true;
    array1->set(0, element1);
    array1->set(9, element2);
    array1->set(4, element3);
    bool e1 = array1->remove(0);
    bool e2 = array1->remove(8);
    bool e3 = array1->remove(3);
    t_true(e1 == element1);
    t_true(e2 == element2);
    t_true(e3 == element3);
    delete array1;
    OK("arrayBool remove()");
}


void testArrayBoolGet() {
    BoolArray* array1 = new BoolArray(10);
    bool element1 = true;
    bool element2 = false;
    bool element3 = true;
    array1->set(0, element1);
    array1->set(9, element2);
    array1->set(4, element3);
    bool e1 = array1->get(0);
    bool e2 = array1->get(9);
    bool e3 = array1->get(4);
    t_true(e1 == element1);
    t_true(e2 == element2);
    t_true(e3 == element3);
    delete array1;
    OK("arrayBool get()");
}


void testArrayBoolSplit() {
    BoolArray* array1 = new BoolArray(10);
    bool element1 = true;
    bool element2 = false;
    bool element3 = true;
    array1->set(0, element1);
    array1->set(9, element2);
    array1->set(4, element3);
    BoolArray* array2 = array1->split(1);
    t_true(array2->len() == 1);
    t_true(array1->len() == 2);
    t_true(array2->get(0) == element1);
    t_true(array1->get(7) == element2);
    t_true(array1->get(2) == element3);
    delete array1;
    delete array2;
    OK("arrayBool split()");
}


void testArrayBoolIsEmpty() {
    BoolArray* array1 = new BoolArray(10);
    bool element1 = true;
    bool element2 = false;
    t_true(array1->isEmpty());
    array1->set(0, element1);
    t_false(array1->isEmpty());
    array1->set(9, element2);
    t_false(array1->isEmpty());
    array1->remove(0);
    t_false(array1->isEmpty());
    array1->remove(8);
    t_true(array1->isEmpty());
    delete array1;
    OK("arrayBool isEmpty()");
}


void testBoolArray() {
    testArrayBoolConstructor();
    testArrayBoolLen();
    testArrayBoolElementAt();
    testArrayBoolIndexOf();
    testArrayBoolReplace();
    testArrayBoolInsert();
    testArrayBoolSet();
    testArrayBoolRemove();
    testArrayBoolGet();
    testArrayBoolSplit();
    testArrayBoolIsEmpty();
}


/*
 * STRING
 */
void testArrayStringConstructor() {
    StrArray* array1 = new StrArray();
    StrArray* array2 = new StrArray(0);
    delete array1;
    delete array2;
    OK("arrayString constructor()");
}


void testArrayStringLen() {
    StrArray* array1 = new StrArray(1);
    StrArray* array2 = new StrArray(0);
    t_true(array1->len() == 0);
    t_true(array2->len() == 0);
    delete array1;
    delete array2;
    OK("arrayString len()");
}


void testArrayStringElementAt() {
    StrArray* array1 = new StrArray(10);
    String* element1 = new String("a");
    String* element2 = new String("b");
    array1->set(0, element1);
    array1->set(2, element2);
    t_true(array1->get(0)->equals(element1));
    t_true(array1->get(2)->equals(element2));
    delete array1;
    delete element1;
    delete element2;
    OK("arrayString elementAt()");
}


void testArrayStringIndexOf() {
    StrArray* array1 = new StrArray(10);
    String* element1 = new String("a");
    String* element2 = new String("b");
    String* element3 = new String("c");
    array1->set(0, element1);
    array1->set(2, element2);
    t_true(array1->indexOf(element1) == 0);
    t_true(array1->indexOf(element2) == 2);
    t_true(array1->indexOf(element3) > 10);
    delete array1;
    delete element1;
    delete element2;
    delete element3;
    OK("arrayString indexOf()");
}


void testArrayStringReplace() {
    StrArray* array1 = new StrArray(10);
    String* element1 = new String("a");
    String* element2 = new String("b");
    String* element3 = new String("c");
    array1->set(0, element1);
    array1->set(1, element2);
    array1->replace(0, element3);
    t_false(array1->get(0)->equals(element1));
    t_true(array1->get(0)->equals(element3));
    array1->replace(2, element1);
    t_true(array1->get(2)->equals(element1));
    delete array1;
    delete element1;
    delete element2;
    delete element3;
    OK("arrayString replace()");
}


void testArrayStringInsert() {
    StrArray* array1 = new StrArray(10);
    String* element1 = new String("a");
    String* element2 = new String("b");
    String* element3 = new String("c");
    String* element4 = new String("d");
    array1->set(0, element1);
    array1->set(1, element2);
    array1->insert(0, element3);
    t_true(array1->get(0)->equals(element3));
    t_true(array1->get(1)->equals(element1));
    t_true(array1->get(2)->equals(element2));
    array1->insert(2, element4);
    t_true(array1->get(0)->equals(element3));
    t_true(array1->get(1)->equals(element1));
    t_true(array1->get(2)->equals(element4));
    t_true(array1->get(3)->equals(element2));
    delete array1;
    delete element1;
    delete element2;
    delete element3;
    delete element4;
    OK("arrayString insert()");
}


void testArrayStringSet() {
    StrArray* array1 = new StrArray(10);
    String* element1 = new String("a");
    String* element2 = new String("b");
    String* element3 = new String("c");
    array1->set(0, element1);
    array1->set(9, element2);
    array1->set(4, element3);
    t_true(array1->get(0)->equals(element1));
    t_true(array1->get(9)->equals(element2));
    t_true(array1->get(4)->equals(element3));
    delete array1;
    delete element1;
    delete element2;
    delete element3;
    OK("arrayString set()");
}


void testArrayStringRemove() {
    StrArray* array1 = new StrArray(10);
    String* element1 = new String("a");
    String* element2 = new String("b");
    String* element3 = new String("c");
    array1->set(0, element1);
    array1->set(9, element2);
    array1->set(4, element3);
    String* e1 = array1->remove(0);
    String* e2 = array1->remove(8);
    String* e3 = array1->remove(3);
    t_true(e1->equals(element1));
    t_true(e2->equals(element2));
    t_true(e3->equals(element3));
    delete array1;
    delete element1;
    delete element2;
    delete element3;
    OK("arrayString remove()");
}


void testArrayStringGet() {
    StrArray* array1 = new StrArray(10);
    String* element1 = new String("a");
    String* element2 = new String("b");
    String* element3 = new String("c");
    array1->set(0, element1);
    array1->set(9, element2);
    array1->set(4, element3);
    String* e1 = array1->get(0);
    String* e2 = array1->get(9);
    String* e3 = array1->get(4);
    t_true(e1->equals(element1));
    t_true(e2->equals(element2));
    t_true(e3->equals(element3));
    delete array1;
    delete element1;
    delete element2;
    delete element3;
    OK("arrayString get()");
}


void testArrayStringSplit() {
    StrArray* array1 = new StrArray(10);
    String* element1 = new String("a");
    String* element2 = new String("b");
    String* element3 = new String("c");
    array1->set(0, element1);
    array1->set(9, element2);
    array1->set(4, element3);
    StrArray* array2 = array1->split(1);
    t_true(array2->len() == 1);
    t_true(array1->len() == 2);
    t_true(array2->get(0)->equals(element1));
    t_true(array1->get(7)->equals(element2));
    t_true(array1->get(2)->equals(element3));
    delete array1;
    delete array2;
    delete element1;
    delete element2;
    delete element3;
    OK("arrayString split()");
}


void testArrayStringIsEmpty() {
    StrArray* array1 = new StrArray(10);
    String* element1 = new String("a");
    String* element2 = new String("b");
    t_true(array1->isEmpty());
    array1->set(0, element1);
    t_false(array1->isEmpty());
    array1->set(9, element2);
    t_false(array1->isEmpty());
    array1->remove(0);
    t_false(array1->isEmpty());
    array1->remove(8);
    t_true(array1->isEmpty());
    delete array1;
    delete element1;
    delete element2;
    OK("arrayString isEmpty()");
}


void testStrArray() {
    testArrayStringConstructor();
    testArrayStringLen();
    testArrayStringElementAt();
    testArrayStringIndexOf();
    testArrayStringReplace();
    testArrayStringInsert();
    testArrayStringSet();
    testArrayStringRemove();
    testArrayStringGet();
    testArrayStringSplit();
    testArrayStringIsEmpty();
}


/*
 * MAIN
 */
int main() {
    testObjectArray();
    testIntegerArray();
    testFloatArray();
    testBoolArray();
    testStrArray();
    OK("All tests");
    return 0;
}
