//lang::Cpp
#include <iostream>
#include <cmath>
#include <cfloat>
#include "array.h"
#include "string.h"

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

String* string1;
String* string2;
String* string3;

Array* array1;
Array* array2;
Array* array3;

IntArray* ia1;
IntArray* ia2;
IntArray* ia3;

FloatArray* fa1;
FloatArray* fa2;
FloatArray* fa3;

BoolArray* ba1;
BoolArray* ba2;
BoolArray* ba3;

StrArray* sa1;
StrArray* sa2;
StrArray* sa3;


void setup() {
    string1 = new String();
    string2 = new String("hi");
    string3 = new String("hello");

    array1 = new Array();
    array2 = new Array(5000);
    array3 = new Array(10);

    ia1 = new IntArray();
    ia2 = new IntArray(5000);
    ia3 = new IntArray(10);

    fa1 = new FloatArray();
    fa2 = new FloatArray(5000);
    fa3 = new FloatArray(10);

    ba1 = new BoolArray();
    ba2 = new BoolArray(5000);
    ba3 = new BoolArray(10);

    sa1 = new StrArray();
    sa2 = new StrArray(5000);
    sa3 = new StrArray(10);
}

void teardown() {
    delete string1;
    delete string2;
    delete string3;

    delete array1;
    delete array2;
    delete array3;

    delete ia1;
    delete ia2;
    delete ia3;

    delete fa1;
    delete fa2;
    delete fa3;

    delete ba1;
    delete ba2;
    delete ba3;

    delete sa1;
    delete sa2;
    delete sa3;
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
    setup();
    t_true(array1->len() == 0);
    array1->pushBack(string1);
    t_true(array2->len() == 0);
    t_true(array1->len() == 1);
    teardown();
    OK("arrayObject len()");
}


void testArrayObjectIndexOf() {
    setup();
    array3->pushBack(string1);
    array3->pushBack(string2);
    t_true(array3->indexOf(string1) == 0);
    t_true(array3->indexOf(string2) == 1);
    t_true(array3->len() == 2);
    t_true(array3->indexOf(string3) > 2);
    teardown();
    OK("arrayObject indexOf()");
}


void testArrayObjectReplace() {
    setup();
    array1->pushBack(string1);
    array1->pushBack(string2);
    array1->replace(0, string3);
    t_false(array1->get(0)->equals(string1));
    t_true(array1->get(0)->equals(string3));
    array1->replace(1, string1);
    t_true(array1->get(1)->equals(string1));
    teardown();
    OK("arrayObject replace()");
}


void testArrayObjectInsert() {
    setup();
    array1->insert(0, string1);
    t_true(array1->len() == 1);
    t_true(array1->get(0)->equals(string1));
    array1->insert(0, string2);
    t_true(array1->len() == 2);
    t_true(array1->get(0)->equals(string2));
    t_true(array1->get(1)->equals(string1));
    array1->insert(2, string3);
    t_true(array1->get(0)->equals(string2));
    t_true(array1->get(1)->equals(string1));
    t_true(array1->get(2)->equals(string3));
    teardown();
    OK("arrayObject insert()");
}


void testArrayObjectSet() {
    setup();
    array1->pushBack(string1);
    t_true(array1->get(0)->equals(string1));
    array1->set(0, string2);
    t_true(array1->get(0)->equals(string2));
    t_true(array1->len() == 1);
    teardown();
    OK("arrayObject set()");
}


void testArrayObjectRemove() {
    setup();
    array1->pushBack(string1);
    array1->pushBack(string2);
    t_true(array1->get(0)->equals(string1));
    t_true(array1->len() == 2);
    Object* s1 = array1->remove(0);
    t_true(s1->equals(string1));
    t_true(array1->len() == 1);
    t_true(array1->get(0)->equals(string2));
    delete s1;
    teardown();
    OK("arrayObject remove()");
}


void testArrayObjectGet() {
    setup();
    array1->pushBack(string1);
    array1->pushBack(string2);
    t_true(array1->get(0)->equals(string1));
    t_true(array1->get(1)->equals(string2));
    teardown();
    OK("arrayObject get()");
}


void testArrayObjectSplit() {
    setup();
    array1->pushBack(string1);
    array1->pushBack(string2);
    array1->pushBack(string3);
    Array* a1 = array1->split(1);
    t_true(a1->len() == 1);
    t_true(array1->len() == 2);
    t_true(a1->get(0)->equals(string1));
    t_true(array1->get(0)->equals(string2));
    t_true(array1->get(1)->equals(string3));
    delete a1;
    teardown();
    OK("arrayObject split()");
}


void testArrayObjectIsEmpty() {
    setup();
    t_true(array1->isEmpty());
    array1->pushBack(string1);
    t_false(array1->isEmpty());
    array1->pushBack(string2);
    Object* s1 = array1->remove(0);
    t_false(array1->isEmpty());
    Object* s2 = array1->remove(0);
    t_true(array1->isEmpty());
    delete s1;
    delete s2;
    teardown();
    OK("arrayObject isEmpty()");
}

void testObjectArray() {
    testArrayObjectConstructor();
    testArrayObjectLen();
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
    setup();
    t_true(ia1->len() == 0);
    ia1->pushBack(1);
    t_true(ia2->len() == 0);
    t_true(ia1->len() == 1);
    teardown();
    OK("arrayInt len()");
}


void testArrayIntegerIndexOf() {
    setup();
    ia3->pushBack(1);
    ia3->pushBack(-1);
    t_true(ia3->indexOf(1) == 0);
    t_true(ia3->indexOf(-1) == 1);
    t_true(ia3->len() == 2);
    t_true(ia3->indexOf(3) > 2);
    teardown();
    OK("arrayInt indexOf()");
}


void testArrayIntegerReplace() {
    setup();
    ia1->pushBack(1);
    ia1->pushBack(2);
    ia1->replace(0, 3);
    t_false(ia1->get(0) == 1);
    t_true(ia1->get(0) == 3);
    ia1->replace(1, 1);
    t_true(ia1->get(1) == 1);
    teardown();
    OK("arrayInt replace()");
}


void testArrayIntegerInsert() {
    setup();
    ia1->insert(0, 1);
    t_true(ia1->len() == 1);
    t_true(ia1->get(0) == 1);
    ia1->insert(0, 2);
    t_true(ia1->len() == 2);
    t_true(ia1->get(0) == 2);
    t_true(ia1->get(1) == 1);
    ia1->insert(2, 3);
    t_true(ia1->get(0) == 2);
    t_true(ia1->get(1) == 1);
    t_true(ia1->get(2) == 3);
    teardown();
    OK("arrayInt insert()");
}


void testArrayIntegerSet() {
    setup();
    ia1->pushBack(1);
    t_true(ia1->get(0) == 1);
    ia1->set(0, 2);
    t_true(ia1->get(0) == 2);
    t_true(ia1->len() == 1);
    teardown();
    OK("arrayInt set()");
}


void testArrayIntegerRemove() {
    setup();
    ia1->pushBack(1);
    ia1->pushBack(2);
    t_true(ia1->get(0) == 1);
    t_true(ia1->len() == 2);
    int i1 = ia1->remove(0);
    t_true(i1 == 1);
    t_true(ia1->len() == 1);
    t_true(ia1->get(0) == 2);
    teardown();
    OK("arrayInt remove()");
}


void testArrayIntegerGet() {
    setup();
    ia1->pushBack(1);
    ia1->pushBack(2);
    t_true(ia1->get(0) == 1);
    t_true(ia1->get(1) == 2);
    teardown();
    OK("arrayInt get()");
}


void testArrayIntegerSplit() {
    setup();
    ia1->pushBack(1);
    ia1->pushBack(2);
    ia1->pushBack(3);
    IntArray* a1 = ia1->split(1);
    t_true(a1->len() == 1);
    t_true(ia1->len() == 2);
    t_true(a1->get(0) == 1);
    t_true(ia1->get(0) == 2);
    t_true(ia1->get(1) == 3);
    delete a1;
    teardown();
    OK("arrayInt split()");
}


void testArrayIntegerIsEmpty() {
    setup();
    t_true(ia1->isEmpty());
    ia1->pushBack(1);
    t_false(ia1->isEmpty());
    ia1->pushBack(2);
    ia1->remove(0);
    t_false(ia1->isEmpty());
    ia1->remove(0);
    t_true(ia1->isEmpty());
    teardown();
    OK("arrayInt isEmpty()");
}


void testIntegerArray() {
    testArrayIntegerConstructor();
    testArrayIntegerLen();
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
    setup();
    t_true(fa1->len() == 0);
    fa1->pushBack(1.2);
    t_true(fa2->len() == 0);
    t_true(fa1->len() == 1);
    teardown();
    OK("arrayFloat len()");
}



void testArrayFloatIndexOf() {
    setup();
    fa3->pushBack(1.1);
    fa3->pushBack(-1.1);
    t_true(fa3->indexOf(1.1) == 0);
    t_true(fa3->indexOf(-1.1) == 1);
    t_true(fa3->len() == 2);
    t_true(fa3->indexOf(3.14) > 2);
    teardown();
    OK("arrayFloat indexOf()");
}


void testArrayFloatReplace() {
    setup();
    fa1->pushBack(0.1);
    fa1->pushBack(0.2);
    fa1->replace(0, 0.3);
    t_false(fa1->get(0) - 0.1 < 0.00001);
    t_true(fa1->get(0) - 0.3 < 0.00001);
    fa1->replace(1, 0.1);
    t_true(fa1->get(1) - 0.1 < 0.00001);
    teardown();
    OK("arrayFloat replace()");
}


void testArrayFloatInsert() {
    setup();
    fa1->insert(0, 0.1);
    t_true(fa1->len() == 1);
    t_true(fa1->get(0) - 0.1 < 0.00001);
    fa1->insert(0, 0.2);
    t_true(fa1->len() == 2);
    t_true(fa1->get(0) - 0.2 < 0.00001);
    t_true(fa1->get(1) - 0.1 < 0.00001);
    fa1->insert(2, 0.3);
    t_true(fa1->get(0) - 0.2 < 0.00001);
    t_true(fa1->get(1) - 0.1 < 0.00001);
    t_true(fa1->get(2) - 0.3 < 0.00001);
    teardown();
    OK("arrayFloat insert()");
}


void testArrayFloatSet() {
    setup();
    fa1->pushBack(0.1);
    t_true(fa1->get(0) - 0.1 < 0.00001);
    fa1->set(0, 0.2);
    t_true(fa1->get(0) - 0.2 < 0.00001);
    t_true(fa1->len() == 1);
    teardown();
    OK("arrayFloat set()");
}


void testArrayFloatRemove() {
    setup();
    fa1->pushBack(0.1);
    fa1->pushBack(0.2);
    t_true(fa1->get(0) - 0.1 < 0.00001);
    t_true(fa1->len() == 2);
    float f1 = fa1->remove(0);
    t_true(f1 - 0.1 < 0.00001);
    t_true(fa1->len() == 1);
    t_true(fa1->get(0) - 0.2 < 0.00001);
    teardown();
    OK("arrayFloat remove()");
}


void testArrayFloatGet() {
    setup();
    fa1->pushBack(0.1);
    fa1->pushBack(0.2);
    t_true(fa1->get(0) - 0.1 < 0.00001);
    t_true(fa1->get(1) - 0.2 < 0.00001);
    teardown();
    OK("arrayFloat get()");
}


void testArrayFloatSplit() {
    setup();
    fa1->pushBack(0.1);
    fa1->pushBack(0.2);
    fa1->pushBack(0.3);
    FloatArray* a1 = fa1->split(1);
    t_true(a1->len() == 1);
    t_true(fa1->len() == 2);
    t_true(a1->get(0) - 0.1 < 0.00001);
    t_true(fa1->get(0) - 0.2 < 0.00001);
    t_true(fa1->get(1) - 0.3 < 0.00001);
    delete a1;
    teardown();
    OK("arrayFloat split()");
}


void testArrayFloatIsEmpty() {
    setup();
    t_true(fa1->isEmpty());
    fa1->pushBack(0.1);
    t_false(fa1->isEmpty());
    fa1->pushBack(0.2);
    fa1->remove(0);
    t_false(fa1->isEmpty());
    fa1->remove(0);
    t_true(fa1->isEmpty());
    teardown();
    OK("arrayFloat isEmpty()");
}


void testFloatArray() {
    testArrayFloatConstructor();
    testArrayFloatLen();
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
    setup();
    t_true(ba1->len() == 0);
    ba1->pushBack(true);
    t_true(ba2->len() == 0);
    t_true(ba1->len() == 1);
    teardown();
    OK("arrayBool len()");
}


void testArrayBoolIndexOf() {
    setup();
    ba3->pushBack(true);
    ba3->pushBack(false);
    t_true(ba3->indexOf(true) == 0);
    t_true(ba3->indexOf(false) == 1);
    t_true(ba3->len() == 2);
    t_true(ba1->indexOf(true) > 0);
    teardown();
    OK("arrayBool indexOf()");
}

void testArrayBoolReplace() {
    setup();
    ba1->pushBack(true);
    ba1->pushBack(false);
    ba1->replace(0, false);
    t_false(ba1->get(0) == true);
    t_true(ba1->get(0) == false);
    ba1->replace(1, true);
    t_true(ba1->get(1) == true);
    teardown();
    OK("arrayBool replace()");
}

void testArrayBoolInsert() {
    setup();
    ba1->insert(0, true);
    t_true(ba1->len() == 1);
    t_true(ba1->get(0) == true);
    ba1->insert(0, false);
    t_true(ba1->len() == 2);
    t_true(ba1->get(0) == false);
    t_true(ba1->get(1) == true);
    ba1->insert(2, true);
    t_true(ba1->get(0) == false);
    t_true(ba1->get(1) == true);
    t_true(ba1->get(2) == true);
    teardown();
    OK("arrayBool insert()");
}


void testArrayBoolSet() {
    setup();
    ba1->pushBack(true);
    t_true(ba1->get(0) == true);
    ba1->set(0, false);
    t_true(ba1->get(0) == false);
    t_true(ba1->len() == 1);
    teardown();
    OK("arrayBool set()");
}

void testArrayBoolRemove() {
    setup();
    ba1->pushBack(true);
    ba1->pushBack(false);
    t_true(ba1->get(0) == true);
    t_true(ba1->len() == 2);
    bool b1 = ba1->remove(0);
    t_true(b1 == true);
    t_true(ba1->len() == 1);
    t_true(ba1->get(0) == false);
    teardown();
    OK("arrayBool remove()");
}

void testArrayBoolGet() {
    setup();
    ba1->pushBack(true);
    ba1->pushBack(false);
    t_true(ba1->get(0) == true);
    t_true(ba1->get(1) == false);
    teardown();
    OK("arrayBool get()");
}


void testArrayBoolSplit() {
    setup();
    ba1->pushBack(true);
    ba1->pushBack(false);
    ba1->pushBack(false);
    BoolArray* b1 = ba1->split(1);
    t_true(b1->len() == 1);
    t_true(ba1->len() == 2);
    t_true(b1->get(0) == true);
    t_true(ba1->get(0) == false);
    t_true(ba1->get(1) == false);
    delete b1;
    teardown();
    OK("arrayBool split()");
}


void testArrayBoolIsEmpty() {
    setup();
    t_true(ba1->isEmpty());
    ba1->pushBack(true);
    t_false(ba1->isEmpty());
    ba1->pushBack(false);
    ba1->remove(0);
    t_false(ba1->isEmpty());
    ba1->remove(0);
    t_true(ba1->isEmpty());
    teardown();
    OK("arrayBool isEmpty()");
}


void testBoolArray() {
    testArrayBoolConstructor();
    testArrayBoolLen();
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
    setup();
    t_true(sa1->len() == 0);
    sa1->pushBack(string1);
    t_true(sa2->len() == 0);
    t_true(sa1->len() == 1);
    teardown();
    OK("arrayString len()");
}

void testArrayStringIndexOf() {
    setup();
    sa3->pushBack(string1);
    sa3->pushBack(string2);
    t_true(sa3->indexOf(string1) == 0);
    t_true(sa3->indexOf(string2) == 1);
    t_true(sa3->len() == 2);
    t_true(sa3->indexOf(string3) > 2);
    teardown();
    OK("arrayString indexOf()");
}


void testArrayStringReplace() {
    setup();
    sa1->pushBack(string1);
    sa1->pushBack(string2);
    sa1->replace(0, string3);
    t_false(sa1->get(0)->equals(string1));
    t_true(sa1->get(0)->equals(string3));
    sa1->replace(1, string1);
    t_true(sa1->get(1)->equals(string1));
    teardown();
    OK("arrayString replace()");
}


void testArrayStringInsert() {
    setup();
    sa1->insert(0, string1);
    t_true(sa1->len() == 1);
    t_true(sa1->get(0)->equals(string1));
    sa1->insert(0, string2);
    t_true(sa1->len() == 2);
    t_true(sa1->get(0)->equals(string2));
    t_true(sa1->get(1)->equals(string1));
    sa1->insert(2, string3);
    t_true(sa1->get(0)->equals(string2));
    t_true(sa1->get(1)->equals(string1));
    t_true(sa1->get(2)->equals(string3));
    teardown();
    OK("arrayString insert()");
}


void testArrayStringSet() {
    setup();
    sa1->pushBack(string1);
    t_true(sa1->get(0)->equals(string1));
    sa1->set(0, string2);
    t_true(sa1->get(0)->equals(string2));
    t_true(sa1->len() == 1);
    teardown();
    OK("arrayString set()");
}


void testArrayStringRemove() {
    setup();
    sa1->pushBack(string1);
    sa1->pushBack(string2);
    t_true(sa1->get(0)->equals(string1));
    t_true(sa1->len() == 2);
    String* s1 = sa1->remove(0);
    t_true(s1->equals(string1));
    t_true(sa1->len() == 1);
    t_true(sa1->get(0)->equals(string2));
    delete s1;
    teardown();
    OK("arrayString remove()");
}

void testArrayStringGet() {
    setup();
    sa1->pushBack(string1);
    sa1->pushBack(string2);
    t_true(sa1->get(0)->equals(string1));
    t_true(sa1->get(1)->equals(string2));
    teardown();
    OK("arrayString get()");
}

void testArrayStringSplit() {
    setup();
    sa1->pushBack(string1);
    sa1->pushBack(string2);
    sa1->pushBack(string3);
    StrArray* a1 = sa1->split(1);
    t_true(a1->len() == 1);
    t_true(sa1->len() == 2);
    t_true(a1->get(0)->equals(string1));
    t_true(sa1->get(0)->equals(string2));
    t_true(sa1->get(1)->equals(string3));
    delete a1;
    teardown();
    OK("arrayString split()");
}

void testArrayStringIsEmpty() {
    setup();
    t_true(sa1->isEmpty());
    sa1->pushBack(string1);
    t_false(sa1->isEmpty());
    sa1->pushBack(string2);
    String* s1 = sa1->remove(0);
    t_false(sa1->isEmpty());
    String* s2 = sa1->remove(0);
    t_true(sa1->isEmpty());
    delete s1;
    delete s2;
    teardown();
    OK("arrayString isEmpty()");
}


void testStrArray() {
    testArrayStringConstructor();
    testArrayStringLen();
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
