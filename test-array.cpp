//lang::Cpp
#include <iostream>
#include "array.h"

/*
 * HELPERS
 */
void OK(const char* msg) {
	printf("%s: OK\n", msg);
}


void FAIL() {
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
	t_true(arrar1->len() == 1);
	t_true(array2->len() == 5000);
	delete array1;
	delete array2;
	OK("arrayObject len()");
}


void testArrayObjectEqualArray() {
	Array* array1 = new Array(10);
	Array* array2 = new Array(10);
	Object* element1 = new Object();
	Object* element2 = new Object();
	t_true(array1->equalArray(array2));
	t_true(array2->equalArray(array1));
	array1->set(0, element1);
	t_false(array1->equalArray(array2));
	t_false(array2->equalArary(array1));
	array2->set(0, element1);
	t_true(array1->equalArray(array2));
	t_true(array2->equalArray(array1));
	array2->set(1, element2);
	t_false(array1->equalArray(array2));
	t_false(array2->equalArary(array1));
	array1->set(1, element2);
	t_true(array1->equalArray(array2));
	t_true(array2->equalArray(array1));
	delete array1;
	delete array2;
	delete element1;
	delete element2;
	OK("arrayObject equalArray()");
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
	OK("testObject elementAt()");
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
	t_true(array1->indexOf(element3) > 10);
	delete array1;
	delete element1;
	delete element2;
	OK("testObject indexOf()");
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
	t_true(array1->get(0)->euqlas(element3));
	array1->replace(2, element1);
	t_true(array1->get(2)->equals(element1));
	delete array1;
	delete element1;
	delete element2;
	delete element3;
	OK("testObject replace()");
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
	t_true(array1->get(0)->equal(element3));
	t_true(array1->get(1)->equal(element1));
	t_true(array1->get(2)->equal(element2));
	array1->insert(2, element4);
	t_true(array1->get(0)->equal(element3));
	t_true(array1->get(1)->equal(element1));
	t_true(array1->get(2)->equal(element4));
	t_true(array1->get(3)->equal(element2));
	delete array1;
	delete element1;
	delete element2;
	delete element3;
	delete element4;
	OK("testObject insert()");
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
	OK("testObject set()");
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
	Object* e3 = array1->remove(2);
	t_true(e1->equals(element1));
	t_true(e2->equals(element2));
	t_true(e3->equals(element3));
	delete array1;
	delete element1;
	delete element2;
	delete element3;
	OK("testObject remove()");
}


void testArrayObjectGet() {
	Array* array1 = new Array(10);
	Object* element1 = new Object();
	Object* element2 = new Object();
	Object* element3 = new Object();
	array1->set(0, element1);
	array1->set(9, element2);
	array1->set(4, element3);
	Object* e1 = array1->remove(0);
	Object* e2 = array1->remove(9);
	Object* e3 = array1->remove(4);
	t_true(e1->equals(element1));
	t_true(e2->equals(element2));
	t_true(e3->equals(element3));
	delete array1;
	delete element1;
	delete element2;
	delete element3;
	OK("testObject get()");
}


void testArrayObjectSplit() {
	Array* array1 = new Array(10);
	Object* element1 = new Object();
	Object* element2 = new Object();
	Object* element3 = new Object();
	array1->set(0, element1);
	array1->set(9, element2);
	array1->set(4, element3);
	Object** array2 = array1->split(1);
	t_true(array2->len() == 2);
	t_true(array1->len() == 8);
	t_true(array2->get(0)->equals(element1));
	t_true(array2->get(1)->equals(element2));
	t_true(array1->get(0)->equals(element3));
	delete array1;
	delete array2;
	delete element1;
	delete element2;
	delete element3;
	OK("testObject split()");
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
	array1->remove(0);
	t_true(array1->isEmpty());
	delete array1;
	delete element1;
	delete element2;
	OK("testObject isEmpty()");
}


void testObjectArray() {
	testArrayObjectConstructor();
	testArrayObjectLen();
	testArrayObjectEqualArray();
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

void testArrayObjectConstructor() {
	IntArray* array1 = new IntArray();
	IntArray* array2 = new IntArray(5000);
	delete array1;
	delete array2;
	OK("arrayObject constructor()");
}


void testArrayObjectLen() {
	IntArray* array1 = new IntArray(1);
	IntArray* array2 = new IntArray(5000);
	t_true(arrar1->len() == 1);
	t_true(array2->len() == 5000);
	delete array1;
	delete array2;
	OK("arrayObject len()");
}


void testArrayObjectEqualArray() {
	IntArray* array1 = new IntArray(10);
	IntArray* array2 = new IntArray(10);
	Object* element1 = new Object();
	Object* element2 = new Object();
	t_true(array1->equalArray(array2));
	t_true(array2->equalArray(array1));
	array1->set(0, element1);
	t_false(array1->equalArray(array2));
	t_false(array2->equalArary(array1));
	array2->set(0, element1);
	t_true(array1->equalArray(array2));
	t_true(array2->equalArray(array1));
	array2->set(1, element2);
	t_false(array1->equalArray(array2));
	t_false(array2->equalArary(array1));
	array1->set(1, element2);
	t_true(array1->equalArray(array2));
	t_true(array2->equalArray(array1));
	delete array1;
	delete array2;
	delete element1;
	delete element2;
	OK("arrayObject equalArray()");
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
	OK("testObject elementAt()");
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
	t_true(array1->indexOf(element3) > 10);
	delete array1;
	delete element1;
	delete element2;
	OK("testObject indexOf()");
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
	t_true(array1->get(0)->euqlas(element3));
	array1->replace(2, element1);
	t_true(array1->get(2)->equals(element1));
	delete array1;
	delete element1;
	delete element2;
	delete element3;
	OK("testObject replace()");
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
	t_true(array1->get(0)->equal(element3));
	t_true(array1->get(1)->equal(element1));
	t_true(array1->get(2)->equal(element2));
	array1->insert(2, element4);
	t_true(array1->get(0)->equal(element3));
	t_true(array1->get(1)->equal(element1));
	t_true(array1->get(2)->equal(element4));
	t_true(array1->get(3)->equal(element2));
	delete array1;
	delete element1;
	delete element2;
	delete element3;
	delete element4;
	OK("testObject insert()");
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
	OK("testObject set()");
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
	Object* e3 = array1->remove(2);
	t_true(e1->equals(element1));
	t_true(e2->equals(element2));
	t_true(e3->equals(element3));
	delete array1;
	delete element1;
	delete element2;
	delete element3;
	OK("testObject remove()");
}


void testArrayObjectGet() {
	Array* array1 = new Array(10);
	Object* element1 = new Object();
	Object* element2 = new Object();
	Object* element3 = new Object();
	array1->set(0, element1);
	array1->set(9, element2);
	array1->set(4, element3);
	Object* e1 = array1->remove(0);
	Object* e2 = array1->remove(9);
	Object* e3 = array1->remove(4);
	t_true(e1->equals(element1));
	t_true(e2->equals(element2));
	t_true(e3->equals(element3));
	delete array1;
	delete element1;
	delete element2;
	delete element3;
	OK("testObject get()");
}


void testArrayObjectSplit() {
	Array* array1 = new Array(10);
	Object* element1 = new Object();
	Object* element2 = new Object();
	Object* element3 = new Object();
	array1->set(0, element1);
	array1->set(9, element2);
	array1->set(4, element3);
	Object** array2 = array1->split(1);
	t_true(array2->len() == 2);
	t_true(array1->len() == 8);
	t_true(array2->get(0)->equals(element1));
	t_true(array2->get(1)->equals(element2));
	t_true(array1->get(0)->equals(element3));
	delete array1;
	delete array2;
	delete element1;
	delete element2;
	delete element3;
	OK("testObject split()");
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
	array1->remove(0);
	t_true(array1->isEmpty());
	delete array1;
	delete element1;
	delete element2;
	OK("testObject isEmpty()");
}


void testObjectArray() {
	testArrayObjectConstructor();
	testArrayObjectLen();
	testArrayObjectEqualArray();
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
 * FLOAT
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
	t_true(arrar1->len() == 1);
	t_true(array2->len() == 5000);
	delete array1;
	delete array2;
	OK("arrayObject len()");
}


void testArrayObjectEqualArray() {
	Array* array1 = new Array(10);
	Array* array2 = new Array(10);
	Object* element1 = new Object();
	Object* element2 = new Object();
	t_true(array1->equalArray(array2));
	t_true(array2->equalArray(array1));
	array1->set(0, element1);
	t_false(array1->equalArray(array2));
	t_false(array2->equalArary(array1));
	array2->set(0, element1);
	t_true(array1->equalArray(array2));
	t_true(array2->equalArray(array1));
	array2->set(1, element2);
	t_false(array1->equalArray(array2));
	t_false(array2->equalArary(array1));
	array1->set(1, element2);
	t_true(array1->equalArray(array2));
	t_true(array2->equalArray(array1));
	delete array1;
	delete array2;
	delete element1;
	delete element2;
	OK("arrayObject equalArray()");
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
	OK("testObject elementAt()");
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
	t_true(array1->indexOf(element3) > 10);
	delete array1;
	delete element1;
	delete element2;
	OK("testObject indexOf()");
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
	t_true(array1->get(0)->euqlas(element3));
	array1->replace(2, element1);
	t_true(array1->get(2)->equals(element1));
	delete array1;
	delete element1;
	delete element2;
	delete element3;
	OK("testObject replace()");
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
	t_true(array1->get(0)->equal(element3));
	t_true(array1->get(1)->equal(element1));
	t_true(array1->get(2)->equal(element2));
	array1->insert(2, element4);
	t_true(array1->get(0)->equal(element3));
	t_true(array1->get(1)->equal(element1));
	t_true(array1->get(2)->equal(element4));
	t_true(array1->get(3)->equal(element2));
	delete array1;
	delete element1;
	delete element2;
	delete element3;
	delete element4;
	OK("testObject insert()");
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
	OK("testObject set()");
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
	Object* e3 = array1->remove(2);
	t_true(e1->equals(element1));
	t_true(e2->equals(element2));
	t_true(e3->equals(element3));
	delete array1;
	delete element1;
	delete element2;
	delete element3;
	OK("testObject remove()");
}


void testArrayObjectGet() {
	Array* array1 = new Array(10);
	Object* element1 = new Object();
	Object* element2 = new Object();
	Object* element3 = new Object();
	array1->set(0, element1);
	array1->set(9, element2);
	array1->set(4, element3);
	Object* e1 = array1->remove(0);
	Object* e2 = array1->remove(9);
	Object* e3 = array1->remove(4);
	t_true(e1->equals(element1));
	t_true(e2->equals(element2));
	t_true(e3->equals(element3));
	delete array1;
	delete element1;
	delete element2;
	delete element3;
	OK("testObject get()");
}


void testArrayObjectSplit() {
	Array* array1 = new Array(10);
	Object* element1 = new Object();
	Object* element2 = new Object();
	Object* element3 = new Object();
	array1->set(0, element1);
	array1->set(9, element2);
	array1->set(4, element3);
	Object** array2 = array1->split(1);
	t_true(array2->len() == 2);
	t_true(array1->len() == 8);
	t_true(array2->get(0)->equals(element1));
	t_true(array2->get(1)->equals(element2));
	t_true(array1->get(0)->equals(element3));
	delete array1;
	delete array2;
	delete element1;
	delete element2;
	delete element3;
	OK("testObject split()");
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
	array1->remove(0);
	t_true(array1->isEmpty());
	delete array1;
	delete element1;
	delete element2;
	OK("testObject isEmpty()");
}


void testObjectArray() {
	testArrayObjectConstructor();
	testArrayObjectLen();
	testArrayObjectEqualArray();
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
 * BOOLEAN
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
	t_true(arrar1->len() == 1);
	t_true(array2->len() == 5000);
	delete array1;
	delete array2;
	OK("arrayObject len()");
}


void testArrayObjectEqualArray() {
	Array* array1 = new Array(10);
	Array* array2 = new Array(10);
	Object* element1 = new Object();
	Object* element2 = new Object();
	t_true(array1->equalArray(array2));
	t_true(array2->equalArray(array1));
	array1->set(0, element1);
	t_false(array1->equalArray(array2));
	t_false(array2->equalArary(array1));
	array2->set(0, element1);
	t_true(array1->equalArray(array2));
	t_true(array2->equalArray(array1));
	array2->set(1, element2);
	t_false(array1->equalArray(array2));
	t_false(array2->equalArary(array1));
	array1->set(1, element2);
	t_true(array1->equalArray(array2));
	t_true(array2->equalArray(array1));
	delete array1;
	delete array2;
	delete element1;
	delete element2;
	OK("arrayObject equalArray()");
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
	OK("testObject elementAt()");
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
	t_true(array1->indexOf(element3) > 10);
	delete array1;
	delete element1;
	delete element2;
	OK("testObject indexOf()");
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
	t_true(array1->get(0)->euqlas(element3));
	array1->replace(2, element1);
	t_true(array1->get(2)->equals(element1));
	delete array1;
	delete element1;
	delete element2;
	delete element3;
	OK("testObject replace()");
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
	t_true(array1->get(0)->equal(element3));
	t_true(array1->get(1)->equal(element1));
	t_true(array1->get(2)->equal(element2));
	array1->insert(2, element4);
	t_true(array1->get(0)->equal(element3));
	t_true(array1->get(1)->equal(element1));
	t_true(array1->get(2)->equal(element4));
	t_true(array1->get(3)->equal(element2));
	delete array1;
	delete element1;
	delete element2;
	delete element3;
	delete element4;
	OK("testObject insert()");
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
	OK("testObject set()");
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
	Object* e3 = array1->remove(2);
	t_true(e1->equals(element1));
	t_true(e2->equals(element2));
	t_true(e3->equals(element3));
	delete array1;
	delete element1;
	delete element2;
	delete element3;
	OK("testObject remove()");
}


void testArrayObjectGet() {
	Array* array1 = new Array(10);
	Object* element1 = new Object();
	Object* element2 = new Object();
	Object* element3 = new Object();
	array1->set(0, element1);
	array1->set(9, element2);
	array1->set(4, element3);
	Object* e1 = array1->remove(0);
	Object* e2 = array1->remove(9);
	Object* e3 = array1->remove(4);
	t_true(e1->equals(element1));
	t_true(e2->equals(element2));
	t_true(e3->equals(element3));
	delete array1;
	delete element1;
	delete element2;
	delete element3;
	OK("testObject get()");
}


void testArrayObjectSplit() {
	Array* array1 = new Array(10);
	Object* element1 = new Object();
	Object* element2 = new Object();
	Object* element3 = new Object();
	array1->set(0, element1);
	array1->set(9, element2);
	array1->set(4, element3);
	Object** array2 = array1->split(1);
	t_true(array2->len() == 2);
	t_true(array1->len() == 8);
	t_true(array2->get(0)->equals(element1));
	t_true(array2->get(1)->equals(element2));
	t_true(array1->get(0)->equals(element3));
	delete array1;
	delete array2;
	delete element1;
	delete element2;
	delete element3;
	OK("testObject split()");
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
	array1->remove(0);
	t_true(array1->isEmpty());
	delete array1;
	delete element1;
	delete element2;
	OK("testObject isEmpty()");
}


void testObjectArray() {
	testArrayObjectConstructor();
	testArrayObjectLen();
	testArrayObjectEqualArray();
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
 * STRING
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
	t_true(arrar1->len() == 1);
	t_true(array2->len() == 5000);
	delete array1;
	delete array2;
	OK("arrayObject len()");
}


void testArrayObjectEqualArray() {
	Array* array1 = new Array(10);
	Array* array2 = new Array(10);
	Object* element1 = new Object();
	Object* element2 = new Object();
	t_true(array1->equalArray(array2));
	t_true(array2->equalArray(array1));
	array1->set(0, element1);
	t_false(array1->equalArray(array2));
	t_false(array2->equalArary(array1));
	array2->set(0, element1);
	t_true(array1->equalArray(array2));
	t_true(array2->equalArray(array1));
	array2->set(1, element2);
	t_false(array1->equalArray(array2));
	t_false(array2->equalArary(array1));
	array1->set(1, element2);
	t_true(array1->equalArray(array2));
	t_true(array2->equalArray(array1));
	delete array1;
	delete array2;
	delete element1;
	delete element2;
	OK("arrayObject equalArray()");
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
	OK("testObject elementAt()");
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
	t_true(array1->indexOf(element3) > 10);
	delete array1;
	delete element1;
	delete element2;
	OK("testObject indexOf()");
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
	t_true(array1->get(0)->euqlas(element3));
	array1->replace(2, element1);
	t_true(array1->get(2)->equals(element1));
	delete array1;
	delete element1;
	delete element2;
	delete element3;
	OK("testObject replace()");
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
	t_true(array1->get(0)->equal(element3));
	t_true(array1->get(1)->equal(element1));
	t_true(array1->get(2)->equal(element2));
	array1->insert(2, element4);
	t_true(array1->get(0)->equal(element3));
	t_true(array1->get(1)->equal(element1));
	t_true(array1->get(2)->equal(element4));
	t_true(array1->get(3)->equal(element2));
	delete array1;
	delete element1;
	delete element2;
	delete element3;
	delete element4;
	OK("testObject insert()");
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
	OK("testObject set()");
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
	Object* e3 = array1->remove(2);
	t_true(e1->equals(element1));
	t_true(e2->equals(element2));
	t_true(e3->equals(element3));
	delete array1;
	delete element1;
	delete element2;
	delete element3;
	OK("testObject remove()");
}


void testArrayObjectGet() {
	Array* array1 = new Array(10);
	Object* element1 = new Object();
	Object* element2 = new Object();
	Object* element3 = new Object();
	array1->set(0, element1);
	array1->set(9, element2);
	array1->set(4, element3);
	Object* e1 = array1->remove(0);
	Object* e2 = array1->remove(9);
	Object* e3 = array1->remove(4);
	t_true(e1->equals(element1));
	t_true(e2->equals(element2));
	t_true(e3->equals(element3));
	delete array1;
	delete element1;
	delete element2;
	delete element3;
	OK("testObject get()");
}


void testArrayObjectSplit() {
	Array* array1 = new Array(10);
	Object* element1 = new Object();
	Object* element2 = new Object();
	Object* element3 = new Object();
	array1->set(0, element1);
	array1->set(9, element2);
	array1->set(4, element3);
	Object** array2 = array1->split(1);
	t_true(array2->len() == 2);
	t_true(array1->len() == 8);
	t_true(array2->get(0)->equals(element1));
	t_true(array2->get(1)->equals(element2));
	t_true(array1->get(0)->equals(element3));
	delete array1;
	delete array2;
	delete element1;
	delete element2;
	delete element3;
	OK("testObject split()");
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
	array1->remove(0);
	t_true(array1->isEmpty());
	delete array1;
	delete element1;
	delete element2;
	OK("testObject isEmpty()");
}


void testObjectArray() {
	testArrayObjectConstructor();
	testArrayObjectLen();
	testArrayObjectEqualArray();
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
 * MAIN
 */
int main() {
	testObjectArray();
	testIntArray();
	testFloatArray();
	testBoolArray();
	testStrArray();
	return 0;
}
