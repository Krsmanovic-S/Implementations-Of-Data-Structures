#include <Queue.h>
#include <iostream>

template <typename T>
void Queue<T>::PrintQueue()
{
	std::cout << "Queue values from back to front: ";

	for (int i = m_QueueSize - 1; i >= 0; i--)
	{
		std::cout << m_QueueVector[i];

		if (i != 0) { std::cout << ", "; }
		else { std::cout << "." << '\n'; }
	}
}

template <typename T>
void Queue<T>::Push(T Val)
{
	m_QueueVector.push_back(Val);
	m_QueueSize++;
}

template <typename T>
void Queue<T>::Pop()
{
	if (m_QueueSize > 0)
	{
		m_QueueVector.erase(m_QueueVector.begin());
		m_QueueSize--;
	}
	else { std::cerr << "Cannot pop from an empty queue."; }
}
