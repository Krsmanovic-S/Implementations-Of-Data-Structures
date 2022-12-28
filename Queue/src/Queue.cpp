#include <Queue.h>
#include <iostream>

template <typename T>
void Queue<T>::PrintQueue()
{
	std::cout << "Queue values from back to front: ";

	for (int i = 0; i < m_QueueSize; i++)
	{
		std::cout << m_QueueVector[i];

		if (i != m_QueueSize - 1) { std::cout << ", "; }
		else { std::cout << "." << '\n'; }
	}
}

template <typename T>
void Queue<T>::Push(T Val)
{
	m_QueueVector.insert(m_QueueVector.begin(), Val);
	m_QueueSize++;
}

template <typename T>
void Queue<T>::Pop()
{
	if (m_QueueSize > 0)
	{
		m_QueueVector.pop_back();
		m_QueueSize--;
	}
	else { std::cerr << "Cannot pop from an empty queue."; }
}

template <typename T>
T Queue<T>::Front() const
{
	return m_QueueSize > 0 ? m_QueueVector[m_QueueSize - 1] : 0;
}

template <typename T>
bool Queue<T>::Empty()
{
	return m_QueueSize > 0 ? true : false;
}