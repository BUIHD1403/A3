#include "Queue.h"

template <class ElementType>
Queue<ElementType>::Queue()
{
	Count = 0;
	_Front_Pointer = nullptr;
	_Back_Pointer = nullptr;
}

template<class ElementType>
Queue<ElementType>::Queue(const Queue & aQueue)
{
	this->Count = aQueue.Count;

}