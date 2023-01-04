#include <stack.h>
#include <iostream>

template<typename T>
void Stack<T>::push(T data)
{
	m_stackVector.push_back(data);
	m_stackSize++;
}

template<typename T>
void Stack<T>::pop()
{
	if (m_stackSize != 0)
	{
		std::cout << "Poped the top of the stack which is: " << m_stackVector[m_stackSize - 1] << '\n';

		m_stackVector.pop_back();
		m_stackSize--;
	}
	else { std::cerr << "Cannot pop from an empty stack." << '\n'; }
}

template<typename T>
inline T Stack<T>::top()
{
	if (m_stackSize != 0)
	{
		return m_stackVector[m_stackSize - 1];
	}
	
	return 0;
}

template<typename T>
inline bool Stack<T>::empty()
{
	return m_stackSize > 0 ? false : true;
}

template<typename T>
void Stack<T>::printStack()
{
	std::cout << "Stack order of elements from top to bottom: ";

	for (int i = m_stackSize - 1; i >= 0; i--)
	{
		std::cout << m_stackVector[i];

		if (i != 0) { std::cout << ", "; }
		else { std::cout << "." << '\n'; }
	}

	std::cout << '\n';
}