#pragma once

#include <vector>

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

		Iterator(Stack<T>* InputStack, int Position) :
			m_StackPointer(InputStack), m_Position(Position) {};

		/// <summary>
		/// Overloading the * operator to return the value that is inside
		/// the stack at the position that the iterator specifies.
		/// </summary>
		/// <returns> Value inside the stack vector at iterator position. </returns>
		T& operator*() { return m_StackPointer->m_StackVector[m_Position]; }

		// Overload the ++ operator to move to the next element.
		Iterator& operator++()
		{
			if (m_Position < m_StackPointer->m_StackSize - 1) { m_Position++; }
			else { m_Position = -1; }

			return *this;
		}

		// Overload the != operator to compare iterators.
		bool operator!=(const Iterator& OtherIterator)
		{
			return m_Position != OtherIterator.m_Position;
		}

	private:

		// Pointer to the queue.
		Stack<T>* m_StackPointer;

		// Position inside the queue.
		int m_Position;
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
		m_StackSize = 0;
		m_StackVector = {};
	};

	/// <summary>
	/// Prints the stack in the top to bottom order.
	/// </summary>
	void PrintStack();

	/// <summary>
	/// Pushes a value on top of the stack.
	/// </summary>
	/// <param name="Val:"> Value to be pushed. </param>
	void Push(T Val);

	/// <summary>
	/// Removes the top element from the stack.
	/// </summary>
	void Pop();

	/// <returns> Value of the element on top of the stack. </returns>
	T Top();

	/// <returns> True if the stack is empty, false otherwise. </returns>
	bool Empty();

	/// <returns> Member variable representing the size of the stack. </returns>
	int GetStackSize() const { return m_StackSize; }

private:

	// Vector holding all the elements of the stack.
	std::vector<T> m_StackVector;

	int m_StackSize;
};

