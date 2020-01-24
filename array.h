#pragma once
#include "object.h"
#include <cstring>
#include <assert.h>

/**
 * @file array.h
 * @brief Implementation of Array class.
 * @author Aliaksei Petrusevich and Megha Rao
 */

/**
 * Represents an array
 */
class Array : public Object{

	Object* array;
	size_t size;


	Array(size_t size) : Object() {
		array = new Object();
		size = 0;
	}

	/**
	 * Function to calculate the number of elements 
	 * 
	 * @param array - The array passed to calc length of
	 * @return the length 
	*/ 
	size_t len(Object* array) {
	}

	/**
	 * Function that checks if two arrays are equal 
	 * 
	 * @param array - second array
	 * @return bool - T or F
	 */
	bool equalArray(char** arr2) {
	}

	/**
	 * Function to return the element at the given index 
	 * 
	 * @param i - index 
	 * @return - the string in array index 
	 */
	char* elementAt(int i) {
	}

	/**
	 * Function to return the first index where the element exists
	 * 
	 * @param element - the string to be searched for 
	 * @return the index
	 */
	int indexOf(char* element) {
	}

	/**
	 * Function to replace the element at the index with another element 
	 * 
	 * @param i - index 
	 * @param element - replacemenet element 
	 * 
	 */
	void replace(int i, char* element){
	}

	/**
	 * Function to insert an element at index i and shift all other elements to the right by increasing the array size by 1 
	 * 
	 * @param i - index 
	 * @param element - new element in array
	 */
	void insert(int i, char* element) {
	}

	/**
	 * Function to remove the element at index and shift remaining elements to the left, decreasing the array size by 1 
	 * 
	 * @param i - index
	 */
	void remove(int i) {
	}

	/**
	 * Function to split the array into two different arrays and returns the first half based on index
	 * Array = Array 1 + Array 2
	 * @param i - index
	 * @return Array 1 (the first one)
	 */
	char** split(int i) {
	}

	/**
	 * Function to check whether the array is empty or not 
	 * 
	 * @param arr - the array to be checked
	 * @return bool - T or F 
	 */
	bool isEmpty(char** arr) {
	}

	/*
	 * The default destructor for the Object class.
	*/
	virtual ~Array() {
		delete this->array;		
	}

};
