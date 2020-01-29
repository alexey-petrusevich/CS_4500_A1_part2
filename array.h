//lang::CwC
#pragma once
#include "object.h"
#include <cstring>
#include <assert.h>

/**
 * @file array.h
 * @brief Implementation of Array class.
 * @author Aliaksei Petrusevich and Megha Rao
 * @date January 26, 2020
 */

/**
 * Represents an array of Objects.
 */
class Array : public Object {
	public:


		/**
		 * Default constructor of this array.
		 */
		Array() : Object() {
		}


		/**
		 * Constructor of this array of Object.
		 *
		 * @param size the base size of this array
		 */
		Array(size_t size) : Object() {
		}


		/**
		 * Returns the number of elements in this array.
		 * 
		 * @return the number of elements of this array
		*/ 
		virtual size_t len() {
		}


		/**
		 * Function to return the element at the given index.
		 * 
		 * @param i the index of the element
		 * @return the element of the array at the given index 
		 */
		virtual Object elementAt(size_t i) {
		}


		/**
		 * Function to return the first index where the element exists.
		 * 
		 * @param element the object being search for
		 * @return the index of the array or >size() if element not found
		 */
		virtual size_t indexOf(Object element) {
		}


		/**
		 * Function to replace the element at the index with another element.
		 * 
		 * @param i index of the element 
		 * @param element the element the element at index i is being replaced with
		 * 
		 */
		virtual void replace(size_t i, Object element){
		}


		/**
		 * Function to insert an element at index i and shift all other 
		 * elements to the right by increasing the array size by 1.
		 * 
		 * @param i insertion index
		 * @param element new element of the array at the given index
		 */
		virtual void insert(size_t i, Object element) {
		}


		/**
		 * Set the element of the array at the given index 
		 * with the given element.
		 *
		 * @param i insertion index
		 * @param element the element to be inserted at the given index
		 */
		virtual void set(size_t i, Object element) {
		}


		/**
		 * Function to remove the element at index and shift remaining elements to the left,
		 * decreasing the array size by 1.
		 * 
		 * @param i index of the element being removed
		 * @return the object at the given index
		 */
		virtual Object remove(size_t i) {
		}


		/**
		 * Returns an element at the given index.
		 *
		 * @param index the index of the element
		 * @return the element of the array at the given index
		 */
		virtual Object get(size_t index) {
		}


		/**
		 * Function to split the array into two different arrays and returns
		 * the first half based on index Array = Array 1 + Array 2.
		 *
		 * @param i - index
		 * @return Array 1 (the first one)
		 */
		virtual Object* split(size_t i) {
		}


		/**
		 * Function to check whether the array is empty or not.
		 * 
		 * @return true if this array is empty and false otherwise
		 */
		virtual bool isEmpty() {
		}


		/**
		 * The destructor of this array.
		 */
		virtual ~Array() {
		}
};


/**
 * Represents an array of integers.
 */
class IntArray : public Object {
	public:


		/**
		 * Default constructor of this array.
		 */
		IntArray() : Object() {
		}


		/**
		 * Constructor of this array of integers.
		 *
		* @param size the base size of this array
		*/
		IntArray(size_t size) : Object() {
		}


		/**
		 * Returns the number of elements in this array.
		 * 
		 * @return the number of elements of this array
		*/ 
		virtual size_t len() {
		}


		/**
		 * Function to return the element at the given index.
		 * 
		 * @param i the index of the element
		 * @return the element of the array at the given index 
		 */
		virtual int elementAt(size_t i) {
		}


		/**
		 * Function to return the first index where the element exists.
		 * 
		 * @param element the object being search for
		 * @return the index of the array or >size() if element not found
		 */
		virtual size_t indexOf(int element) {
		}


		/**
		 * Function to replace the element at the index with another element.
		 * 
		 * @param i index of the element 
		 * @param element the element the element at index i is being replaced with
		 * 
		 */
		virtual void replace(size_t i, int element){
		}


		/**
		 * Function to insert an element at index i and shift all other 
		 * elements to the right by increasing the array size by 1.
		 * 
		 * @param i insertion index
		 * @param element new element of the array at the given index
		 */
		virtual void insert(size_t i, int element) {
		}


		/**
		 * Set the element of the array at the given index 
		 * with the given element.
		 *
		 * @param i insertion index
		 * @param element the element to be inserted at the given index
		 */
		virtual void set(size_t i, int element) {
		}


		/**
		 * Function to remove the element at index and shift remaining elements to the left,
		 * decreasing the array size by 1.
		 * 
		 * @param i index of the element being removed
		 * @return the element at the given index
		 */
		virtual int remove(size_t i) {
		}


		/**
		 * Returns an element at the given index.
		 *
		 * @param index the index of the element
		 * @return the element of the array at the given index
		 */
		virtual int get(size_t index) {
		}


		/**
		 * Function to split the array into two different arrays and returns
		 * the first half based on index Array = Array 1 + Array 2.
		 *
		 * @param i index
		 * @return Array 1 (the first one)
		 */
		virtual int* split(size_t i) {
		}


		/**
		 * Function to check whether the array is empty or not.
		 * 
		 * @return true if this array is empty and false otherwise
		 */
		virtual bool isEmpty() {
		}


		/**
		 * The destructor of this array.
		 */
		virtual ~IntArray() {
		}
};


/**
 * Represents an array of booleans.
 */
class BoolArray : public Object {
	public:
		

		/**
		 * Default constructor of this array.
		 */
		BoolArray() : Object() {
		}

	
		/**
		 * Constructor of this array of booleans.
		 *
		* @param size the base size of this array
		*/
		BoolArray(size_t size) : Object() {
		}


		/**
		 * Returns the number of elements in this array.
		 * 
		 * @return the number of elements of this array
		*/ 
		virtual size_t len() {
		}


		/**
		 * Function to return the element at the given index.
		 * 
		 * @param i the index of the element
		 * @return the element of the array at the given index 
		 */
		virtual bool elementAt(size_t i) {
		}


		/**
		 * Function to return the first index where the element exists.
		 * 
		 * @param element the object being search for
		 * @return the index of the array or >size() if element not found
		 */
		virtual size_t indexOf(bool element) {
		}


		/**
		 * Function to replace the element at the index with another element.
		 * 
		 * @param i index of the element 
		 * @param element the element the element at index i is being replaced with
		 * 
		 */
		virtual void replace(size_t i, bool element){
		}


		/**
		 * Function to insert an element at index i and shift all other 
		 * elements to the right by increasing the array size by 1.
		 * 
		 * @param i insertion index
		 * @param element new element of the array at the given index
		 */
		virtual void insert(size_t i, bool element) {
		}


		/**
		 * Set the element of the array at the given index 
		 * with the given element.
		 *
		 * @param i insertion index
		 * @param element the element to be inserted at the given index
		 */
		virtual void set(size_t i, bool element) {
		}


		/**
		 * Function to remove the element at index and shift remaining elements to the left,
		 * decreasing the array size by 1.
		 * 
		 * @param i index of the element being removed
		 * @return the element at the given index
		 */
		virtual bool remove(size_t i) {
		}


		/**
		 * Returns an element at the given index.
		 *
		 * @param index the index of the element
		 * @return the element of the array at the given index
		 */
		virtual bool get(size_t index) {
		}


		/**
		 * Function to split the array into two different arrays and returns
		 * the first half based on index Array = Array 1 + Array 2.
		 *
		 * @param i index
		 * @return Array 1 (the first one)
		 */
		virtual bool* split(size_t i) {
		}


		/**
		 * Function to check whether the array is empty or not.
		 * 
		 * @return true if this array is empty and false otherwise
		 */
		virtual bool isEmpty() {
		}


		/**
		 * Destructor for this array.
		 */
		~BoolArray() {
		}
};


/**
 * Represents an array of floats.
 */
class FloatArray : public Object {
	public:


		/**
		 * Default constructor of this array.
		 */
		FloatArray() : Object() {
		}


		/**
		 * Constructor of this array of floats.
		 *
		* @param size the base size of this array
		*/
		FloatArray(size_t size) : Object() {
		}


		/**
		 * Returns the number of elements in this array.
		 * 
		 * @return the number of elements of this array
		*/ 
		virtual size_t len() {
		}


		/**
		 * Function to return the element at the given index.
		 * 
		 * @param i the index of the element
		 * @return the element of the array at the given index 
		 */
		virtual float elementAt(size_t i) {
		}


		/**
		 * Function to return the first index where the element exists.
		 * 
		 * @param element the object being search for
		 * @return the index of the array or >size() if element not found
		 */
		virtual size_t indexOf(float element) {
		}


		/**
		 * Function to replace the element at the index with another element.
		 * 
		 * @param i index of the element 
		 * @param element the element the element at index i is being replaced with
		 * 
		 */
		virtual void replace(size_t i, float element){
		}


		/**
		 * Function to insert an element at index i and shift all other 
		 * elements to the right by increasing the array size by 1.
		 * 
		 * @param i insertion index
		 * @param element new element of the array at the given index
		 */
		virtual void insert(size_t i, float element) {
		}


		/**
		 * Set the element of the array at the given index 
		 * with the given element.
		 *
		 * @param i insertion index
		 * @param element the element to be inserted at the given index
		 */
		virtual void set(size_t i, float element) {
		}


		/**
		 * Function to remove the element at index and shift remaining elements to the left,
		 * decreasing the array size by 1.
		 * 
		 * @param i index of the element being removed
		 * @return the element at the given index
		 */
		virtual float remove(size_t i) {
		}


		/**
		 * Returns an element at the given index.
		 *
		 * @param index the index of the element
		 * @return the element of the array at the given index
		 */
		virtual float get(size_t index) {
		}


		/**
		 * Function to split the array into two different arrays and returns
		 * the first half based on index Array = Array 1 + Array 2.
		 *
		 * @param i index
		 * @return Array 1 (the first one)
		 */
		virtual float* split(size_t i) {
		}


		/**
		 * Function to check whether the array is empty or not.
		 * 
		 * @return true if this array is empty and false otherwise
		 */
		virtual bool isEmpty() {
		}

		/**
		 * Destructor for this array.
		 */
		~FloatArray() {
		}
};


/**
 * Represents an array of Strings.
 */
class StrArray : public Object {
	public:
		/**
		 * Default constructor of this array.
		 */
		StrArray() : Array() {
		}


		/**
		 * Constructor of this array of floats.
		 *
		* @param size the base size of this array
		*/
		StrArray(size_t size) : Array(size) {
		}


		/**
		 * Returns the number of elements in this array.
		 * 
		 * @return the number of elements of this array
		*/ 
		virtual size_t len() {
		}


		/**
		 * Function to return the element at the given index.
		 * 
		 * @param i the index of the element
		 * @return the element of the array at the given index 
		 */
		virtual String elementAt(size_t i) {
		}


		/**
		 * Function to return the first index where the element exists.
		 * 
		 * @param element the object being search for
		 * @return the index of the array or >size() if element not found
		 */
		virtual size_t indexOf(String element) {
		}


		/**
		 * Function to replace the element at the index with another element.
		 * 
		 * @param i index of the element 
		 * @param element the element the element at index i is being replaced with
		 * 
		 */
		virtual void replace(size_t i, String element){
		}


		/**
		 * Function to insert an element at index i and shift all other 
		 * elements to the right by increasing the array size by 1.
		 * 
		 * @param i insertion index
		 * @param element new element of the array at the given index
		 */
		virtual void insert(size_t i, String element) {
		}


		/**
		 * Set the element of the array at the given index 
		 * with the given element.
		 *
		 * @param i insertion index
		 * @param element the element to be inserted at the given index
		 */
		virtual void set(size_t i, String element) {
		}


		/**
		 * Function to remove the element at index and shift remaining elements to the left,
		 * decreasing the array size by 1.
		 * 
		 * @param i index of the element being removed
		 * @return the element at the given index
		 */
		virtual String remove(size_t i) {
		}


		/**
		 * Returns an element at the given index.
		 *
		 * @param index the index of the element
		 * @return the element of the array at the given index
		 */
		virtual String get(size_t index) {
		}


		/**
		 * Function to split the array into two different arrays and returns
		 * the first half based on index Array = Array 1 + Array 2.
		 *
		 * @param i index
		 * @return Array 1 (the first one)
		 */
		virtual String* split(size_t i) {
		}


		/**
		 * Function to check whether the array is empty or not.
		 * 
		 * @return true if this array is empty and false otherwise
		 */
		virtual bool isEmpty() {
		}


		/**
		 * Destructor of this class.
		 */
		~StrArray() {
		}
};
