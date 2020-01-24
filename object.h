//lang::CwC

#pragma once
#include <cstdlib>

/**
 * @file object.h
 * @brief Implementation of Object class.
 * @author Aliaksei Petrusevich and Megha Rao
 */

/**
 * A base object class that represents the root of the class hierarchy.
 */
class Object {
	public:

		/*
		 * The default constructor for the Object class.
		 */
		Object() {
				
		}

		/**
		 * Returns true if this object is equal to the given object
		 * and false otherwise.
		 *
		 * @param other the other object used in the comparison
		 * @return true if this object is the same as the given object
		 * and false otherwise
		 */
		virtual bool equals(Object* other) {
			return this == other;	
		}

		/**
		 * Returns the hash value of this object.
		 *
		 * @return the hash value of this object
		 */
		virtual size_t hash() {
			return reinterpret_cast<size_t>(this);
		}

		/*
		 * The default destructor for the Object class.
		 */
		virtual ~Object() {
			
		}
};
