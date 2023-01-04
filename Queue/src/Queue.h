#pragma once

#include <vector>
#include <type_traits>
#include <string>

/// <summary>
/// Class representing a queue,
/// a First-In-First-Out data structure.
/// </summary>
template <typename T>
class Queue
{

public:

	/// <summary>
	/// Iterator for navigating the queue.
	/// </summary>
	class Iterator
	{

	public:
		
		Iterator(Queue<T>* inputQueue, int position) : 
			m_queuePointer(inputQueue), m_position(position) {}

		/// <summary>
		/// Overloading the * operator to return the value that is inside
		/// the queue at the position that the iterator specifies.
		/// </summary>
		/// <returns> Value inside the queue vector at iterator position. </returns>
		T& operator*() { return m_queuePointer->m_queueVector[m_position]; }

		// Overload the ++ operator to move to the next element.
		Iterator& operator++() 
		{
			if (m_position < m_queuePointer->m_queueSize - 1) { m_position++; }
			else { m_position = -1; }

			return *this;
		}

		// Overload the != operator to compare iterators.
		bool operator!=(const Iterator& OtherIterator) 
		{ 
			return m_position != OtherIterator.m_position;
		}

	private:

		// Pointer to the queue.
		Queue<T>* m_queuePointer;  

		// Position inside the queue.
		int m_position;
	};

	/// <returns> Iterator pointing to the beginning of the queue. </returns>
	Queue<T>::Iterator begin() { return Iterator(this, 0); }

	/// <returns> Iterator pointing to the end of the queue. </returns>
	Queue<T>::Iterator end() { return Iterator(this, -1); }

public:

	Queue() 
	{
		static_assert(
			std::is_same<T, int>::value ||
			std::is_same<T, float>::value ||
			std::is_same<T, double>::value ||
			std::is_same<T, char>::value ||
			std::is_same<T, std::string>::value,
			"Type must be int, float, double, char, or std::string.");

		m_queueVector = {};
		m_queueSize = 0;
	}

	void printQueue();

	/// <summary>
	/// Pushes a value to the back of the queue.
	/// </summary>
	/// <param name="data: "> Data to be pushed onto the stack. </param>
	void push(T data);

	// Remove the value that is in front of the queue.
	void pop();

	/// <returns> First value from the queue. </returns>
	T front() const { return m_queueSize > 0 ? m_queueVector[0] : 0; }

	/// <returns> Last added value to the queue. </returns>
	T back() const { return m_queueSize > 0 ? m_queueVector[m_queueSize - 1] : 0; }

	/// <returns> True if the queue is empty, false otherwise. </returns>
	bool empty() const { return m_queueSize > 0 ? false : true; }

	int getQueueSize() const { return m_queueSize; }

private:

	// Vector for storing data that is inside the queue.
	std::vector<T> m_queueVector;

	int m_queueSize;
};