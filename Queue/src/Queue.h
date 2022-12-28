#pragma once

#include <vector>

template <typename T>
class Queue
{

public:

	Queue() 
	{
		m_QueueVector = {};
		m_QueueSize = 0;
	};

	void PrintQueue();

	void Push(T Val);

	void Pop();

	T Front() const;

	bool Empty();

	int GetQueueSize() const { return m_QueueSize; }

private:

	std::vector<T> m_QueueVector;

	int m_QueueSize;
};