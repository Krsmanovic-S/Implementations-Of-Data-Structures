#include <queue.h>
#include <iostream>

template <typename T>
void Queue<T>::printQueue()
{
	std::cout << "Queue values from back to front: ";

	for (int i = m_queueSize - 1; i >= 0; i--)
	{
		std::cout << m_queueVector[i];

		if (i != 0) { std::cout << ", "; }
		else { std::cout << "." << '\n'; }
	}
}

template <typename T>
void Queue<T>::push(T data)
{
	m_queueVector.push_back(data);
	m_queueSize++;
}

template <typename T>
void Queue<T>::pop()
{
	if (m_queueSize > 0)
	{
		m_queueVector.erase(m_queueVector.begin());
		m_queueSize--;
	}
	else { std::cerr << "Cannot pop from an empty queue."; }
}
