#ifndef __PROJ2_QUEUE_HPP
#define __PROJ2_QUEUE_HPP

#include "runtimeexcept.hpp"

class QueueEmptyException : public RuntimeException 
{
public:
	QueueEmptyException(const std::string & err) : RuntimeException(err) {}
};


template<typename Object>

struct Node{
	Object data;
	Node* next;
};

template<typename Object>
class LLQueue
{
private:
	// fill in private member data here
	Node<Object>* head;
	Node<Object>* tail;
	size_t sizet;
public:
	LLQueue();

	// Note:  copy constructors are required.
	// Be sure to do a "deep copy" -- if I 
	// make a copy and modify one, it should not affect the other. 
	LLQueue(const LLQueue & st);
	LLQueue & operator=(const LLQueue & st);
	~LLQueue();
	

	size_t size() const noexcept;
	bool isEmpty() const noexcept;

	// We have two front() for the same reason the Stack in lecture week 2 had two top() functions.
	// If you do not know why there are two, your FIRST step needs to be to review your notes from that lecture.

	Object & front();
	const Object & front() const;

	void enqueue(const Object & elem);

// does not return anything.  Just removes. 
	void dequeue();
};
// TODO:  Fill in the functions here. 





template <typename Object>
LLQueue<Object>::LLQueue()
	:head{nullptr}, tail{nullptr}, sizet{0}
{
}

template <typename Object>
LLQueue<Object>::LLQueue(const LLQueue & st)
	:head{nullptr}, tail{nullptr}, sizet{0}
{
	auto curr = st.head;
	while(curr != nullptr)
	{
		enqueue(curr->data);
		curr = curr->next;

	}
}

template <typename Object>
LLQueue<Object> & LLQueue<Object>::operator=(const LLQueue & st)
{
	auto temp = head;
	while(temp != nullptr)
	{
		auto next = temp -> next;
		delete temp;
		temp = next;
	}
	sizet = 0;
	head = nullptr;
	tail = nullptr;
	auto curr = st.head;
	while(curr != nullptr)
	{
		enqueue(curr->data);
		curr = curr->next;

	}
	return *this;
}

template<typename Object>
LLQueue<Object>::~LLQueue()
{
		// You need to implement the destructor also.
	auto temp = head;
	while(temp != nullptr)
	{
		auto next = temp -> next;
		delete temp;
		temp = next;
	}
}

template<typename Object>
void LLQueue<Object>::enqueue(const Object & element)
{
	if(head == nullptr)
	{
		head = new Node<Object>{element, nullptr};
		tail = head;
	}
	else
	{
		tail->next = new Node<Object>{element, nullptr};
		tail = tail -> next;
	}
	sizet ++;
}





template<typename Object>
void LLQueue<Object>::dequeue()
{
	if(head == nullptr)
	{
		throw QueueEmptyException{"Queue already empty"};
	}
	else if(!head -> next)
	{
		Node<Object>* temp = head;
		head = nullptr;
		tail = nullptr;
		delete temp;
		sizet --;
	}
	else
	{
		Node<Object>* temp = head;
		head = temp -> next;
		delete temp;
		sizet --;
	}
}




template<typename Object>
Object & LLQueue<Object>::front()
{
	if(head == nullptr)
	{
		throw QueueEmptyException{"Queue already empty"};
	}
	else
	{
		return head->data;
	}
	
}




template<typename Object>
const Object & LLQueue<Object>::front() const
{
	if(head == nullptr)
	{
		throw QueueEmptyException{"Queue already empty"};
	}
	else
	{
		return head->data;
	}
}

template<typename Object>
size_t LLQueue<Object>::size() const noexcept
{
	return sizet;
}

template<typename Object>
bool LLQueue<Object>::isEmpty() const noexcept
{
	return head == nullptr;
	
}



#endif 
