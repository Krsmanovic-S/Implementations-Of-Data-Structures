#pragma once

#include <vector>
#include <type_traits>
#include <string>

/// <summary>
/// Class representing a stack, 
/// a First-In-Last-Out data structure.
/// </summary>
template <typename T>
class Stack
{

public:

	/// <summary>
	/// Iterator class for the stack,
	/// used for traversing the stack.
	/// </summary>
	class Iterator
	{

	public:

		Iterator(Stack<T>* iteratedStack, int position) :
			m_stackPointer(iteratedStack), m_position(position) {}

		/// <summary>
		/// Overloading the * operator to return the value that is inside
		/// the stack at the position that the iterator specifies.
		/// </summary>
		/// <returns> Value inside the stack vector at iterator position. </returns>
		T& operator*() { return m_stackPointer->m_stackVector[m_position]; }

		// Overload the ++ operator to move to the next element.
		Iterator& operator++()
		{
			if (m_position < m_stackPointer->m_stackSize - 1) { m_position++; }
			else { m_position = -1; }

			return *this;
		}

		// Overload the != operator to compare iterators.
		bool operator!=(const Iterator& otherIterator)
		{
			return m_position != otherIterator.m_position;
		}

	private:

		// Pointer to the queue.
		Stack<T>* m_stackPointer;

		// Position inside the queue.
		int m_position;
	};

	/// <returns> Iterator pointing to the beginning of the stack. </returns>
	Stack<T>::Iterator begin() { return Iterator(this, 0); }

	/// <returns> Iterator pointing to the end of the stack. </returns>
	Stack<T>::Iterator end() { return Iterator(this, -1); }

	/// <summary>
	/// Constructor that initializes the empty 
	/// stack vector and the size variable to 0.
	/// </summary>
	Stack() 
	{
		static_assert(
			std::is_same<T, int>::value ||
			std::is_same<T, float>::value ||
			std::is_same<T, double>::value ||
			std::is_same<T, char>::value ||
			std::is_same<T, std::string>::value,
			"Type must be int, float, double, char, or std::string.");

		m_stackSize = 0;
		m_stackVector = {};
	};

	/// <summary>
	/// Prints the stack in the top (last) to bottom (first) order.
	/// </summary>
	void printStack();

	/// <summary>
	/// Pushes a value on top of the stack.
	/// </summary>
	/// <param name="Val:"> Value to be pushed. </param>
	void push(T data);

	/// <summary>
	/// Removes the top element from the stack.
	/// </summary>
	void pop();

	/// <returns> Value of the element on top of the stack. </returns>
	T top();

	/// <returns> True if the stack is empty, false otherwise. </returns>
	bool empty();

	/// <returns> Member variable representing the size of the stack. </returns>
	int getStackSize() const { return m_stackSize; }

private:

	// Vector holding all the elements of the stack.
	std::vector<T> m_stackVector;

	int m_stackSize;
};

