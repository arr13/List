#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
using namespace std;

template <typename T>
class List
{
private:
	struct Node{
		T m_data;
		Node* m_next;
		Node* m_prev;

		Node(){
			m_next = NULL;
			m_prev = NULL;
		}

		Node(const T& data) {
			m_data = data;
			m_next = NULL;
			m_prev = NULL;
		}

	};
	Node* head;

public:
	List();
	List(T&);
	~List();
	void push_front(const T& value);
	void pop_front();
	void push_back(const T& value);
	void pop_back();
	T& front();
	T& back();
	class iterator{
		friend class List;
	public:
		iterator() : node(){}

		iterator(Node* n) {
			node = n;
		}
		
		T& operator*(){
			return node->m_data;
		}

		iterator operator++(){
			node = node->m_next;
			return *this;
		}

		iterator operator++(int number){
			node = node->m_next;
			return node;
		}

		bool operator!=(iterator it){
			return node != it.node;
		}
	private:
		Node* node;
	};

	iterator begin(){
		iterator it = head->m_next;
		return it;
	}

	iterator end(){
		iterator it = head->m_prev;
		it++;
		return it;
	}
	
	void insert(iterator it, const T& value);
	void erase(iterator it);
	int size();
	void clear();
	bool empty();
};

template <typename T>
List<T>::List() :head(new Node){
	head->m_prev = head->m_next = head;
}

template <typename T>
List<T>::List(T& data) : head(new Node(data)){
	head->m_prev = head->m_next = head;
}

template <typename T>
List<T>::~List(){
	while (!empty()) {
		pop_front();
	}
	delete head;
}

template <typename T>
void List<T>::push_front(const T& value){
	Node* front = head->m_next;
	Node* new_element = new Node(value);
	head->m_next = new_element;
	new_element->m_prev = head;
	front->m_prev = new_element;
	new_element->m_next = front;
}

template <typename T>
void List<T>::pop_front(){
	if (empty()) {
		cout << "Error pop front - list empty!" << endl;
	}
	Node* front = head->m_next;
	Node* new_front = front->m_next;
	head->m_next = new_front;
	new_front->m_prev = head;
	delete front;
}

template <typename T>
void List<T>::push_back(const T& value){
	Node* back = head->m_prev;
	Node* new_element = new Node(value);
	back->m_next = new_element;
	new_element->m_prev = back;
	head->m_prev = new_element;
	new_element->m_next = head;
}

template <typename T>
void List<T>::pop_back(){
	if (empty()) {
		cout << "Error pop front - list empty!" << endl;
	}
	Node* back = head->m_prev;
	Node* new_back = back->m_prev;
	new_back->m_next = head;
	head->m_prev = new_back;
	delete back;
}

template <typename T>
T& List<T>::front(){
	if (empty()){
		cout << "front() - list is empty!" << endl;
	}
	return head->m_next->m_data;
}

template <typename T>
T& List<T>::back(){
	if (empty()){
		cout << "front() - list is empty!" << endl;
	}
	return head->m_prev->m_data;
}

template <typename T>
void List<T>::insert(iterator it, const T& value){
	if (it.node == head->m_next){
		this->push_front(value);
		it.node = head->m_next;
	}
	else{
		Node *current = it.node;
		it.node = new Node;
		it.node->m_next = current;
		it.node->m_prev = current->m_prev;
		current->m_prev = it.node;
		current = it.node->m_prev;
		current->m_next = it.node;
		it.node->m_data = value;
	}
}

template <typename T>
void List<T>::erase(iterator it){
	if (it.node == head->m_next){
		this->pop_front();
		it.node = head->m_next;
	}
	if (it.node == head->m_prev){
		this->pop_back();
		it.node = head->m_prev;
	}
	Node* node_next = it.node->m_next;
	node_next->m_prev = it.node->m_prev;
	delete it.node;
	it.node = node_next->m_prev;
	it.node->m_next = node_next;
	it.node = node_next;
}

template <typename T>
int List<T>::size(){
	int counter = 0;
	Node* element = head->m_next;
	while (head != element){
		counter++;
		element = element->m_next;
	}
	return counter;
}

template <typename T>
void List<T>::clear(){
	while (!empty()) {
		pop_front();
	}
	delete head;
}

template <typename T>
bool List<T>::empty(){
	return head == head->m_prev;
}

#endif
