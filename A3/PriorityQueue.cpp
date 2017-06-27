#include "PriorityQueue.h"

template<class ElementType>
PriorityQueue<ElementType>::PriorityQueue()
{
	_Front_Index=0;
	_Back_Index=0;
	ElementCount=0;
}

template<class ElementType>
int PriorityQueue<ElementType>::getElementCount() const
{
	return ElementCount;
}

template<class ElementType>
bool PriorityQueue<ElementType>::isEmpty() const
{
	if (ElementCount == 0)
	{
		return true;
	}
	else
		return false;
}

template<class ElementType>
bool PriorityQueue<ElementType>::enqueue(const ElementType& newElement)
{
	bool result = false;
	bool moved = false;
	int location = 0;
	if (ElementCount < MAX_QUEUE)
	{
		for (int index = 0; index < ElementCount && moved!=true; index++)
		{
			if (elements[index] > newElement)
			{
				for (int shift = elementCount; shift > index; shift--)
				{
					elements[shift] = elements[shift - 1];
				}
				moved = true;
				location = index;
			}
		}
	}
	elements[location] = newElement;
	_Back_Index = (_Back_Index + 1) % MAX_QUEUE;
	result = true;
	ElementCount++;
	return result;
}

template<class ElementType>
bool PriorityQueue<ElementType>::dequeue()
{
	bool result = false;
	if (!isEmpty())
	{
		_Front_Index = (_Front_Index + 1) % MAX_QUEUE;
		ElementCount--;
		result = true;
	}
	return result;
}

template <class ElementType>
ElementType PriorityQueue<ElementType>::peek() const throw(EmptyDataCollectionException)
{
	if (isEmpty())
	{
		throw PreConditionViolated{ "Empty Queue" };
	}
	return elements[_Front_Index];
}