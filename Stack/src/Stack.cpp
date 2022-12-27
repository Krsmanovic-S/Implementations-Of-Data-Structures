#include <Stack.h>
#include <iostream>

template<typename T>
void Stack<T>::Push(T Val)
{
	m_StackVector.push_back(Val);
	m_StackSize++;
}

template<typename T>
void Stack<T>::Pop()
{
	if (m_StackSize != 0)
	{
		m_StackVector.pop_back();
		m_StackSize--;
	}
	else { std::cerr << "Cannot pop from an empty stack." << '\n'; }
}

template<typename T>
inline T Stack<T>::Top()
{
	if (m_StackSize != 0)
	{
		return m_StackVector[m_StackSize - 1];
	}
	
	return 0;
}

template<typename T>
inline bool Stack<T>::Empty()
{
	return m_StackSize > 0 ? false : true;
}

template<typename T>
void Stack<T>::PrintStack()
{
	std::cout << "Stack order of elements from top to bottom: ";

	for (int i = m_StackSize - 1; i >= 0; i--)
	{
		std::cout << m_StackVector[i];

		if (i != 0) { std::cout << ", "; }
		else { std::cout << "." << '\n'; }
	}

	std::cout << '\n';
}