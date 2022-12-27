#pragma once

#include <vector>

template <typename T>
class Stack
{

public:

	/// <summary>
	/// Default constructor that initializes the empty 
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

	/// <summary>
	/// Vector holding all the elements of the stack,
	/// used for pushing, poping and printing.
	/// </summary>
	std::vector<T> m_StackVector;

	int m_StackSize;
};

