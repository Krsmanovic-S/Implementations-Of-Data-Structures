#pragma once

#include <vector>

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
		
		Iterator(Queue<T>* InputQueue, int Position) : 
			m_QueuePointer(InputQueue), m_Position(Position) {};

		/// <summary>
		/// Overloading the * operator to return the value that is inside
		/// the queue at the position that the iterator specifies.
		/// </summary>
		/// <returns> Value inside the queue vector at iterator position. </returns>
		T& operator*() { return m_QueuePointer->m_QueueVector[m_Position]; }

		// Overload the ++ operator to move to the next element.
		Iterator& operator++() 
		{
			if (m_Position < m_QueuePointer->m_QueueSize - 1) { m_Position++; }
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
		Queue<T>* m_QueuePointer;  

		// Position inside the queue.
		int m_Position;
	};

	/// <returns> Iterator pointing to the beginning of the queue. </returns>
	Queue<T>::Iterator begin() { return Iterator(this, 0); }

	/// <returns> Iterator pointing to the end of the queue. </returns>
	Queue<T>::Iterator end() { return Iterator(this, -1); }

public:

	Queue() 
	{
		m_QueueVector = {};
		m_QueueSize = 0;
	};

	void PrintQueue();

	// Pushes a value to the back of the queue.
	void Push(T Val);

	// Remove the value that is in front of the queue.
	void Pop();

	/// <returns> First value from the queue. </returns>
	T Front() const { return m_QueueSize > 0 ? m_QueueVector[0] : 0; }

	/// <returns> Last added value to the queue. </returns>
	T Back() const { return m_QueueSize > 0 ? m_QueueVector[m_QueueSize - 1] : 0; }

	/// <returns> True if the queue is empty, false otherwise. </returns>
	bool Empty() const { return m_QueueSize > 0 ? false : true; }

	int GetQueueSize() const { return m_QueueSize; }

private:

	// Vector for storing data that is inside the queue.
	std::vector<T> m_QueueVector;

	int m_QueueSize;
};