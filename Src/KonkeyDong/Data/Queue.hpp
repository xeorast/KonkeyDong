#pragma once

#include <stdexcept>
#include <iostream>

namespace kd::collections
{
	template <typename T>
	class Node {
	public:
		T data;
		Node<T>* next;

		Node(const T& value) : data(value), next(nullptr) {}
	};

	template <typename T>
	class Queue {
	private:
		Node<T>* front;
		Node<T>* rear;

	public:
		Queue() : front(nullptr), rear(nullptr) {}

		~Queue() {
			while (!IsEmpty()) {
				Dequeue();
			}
		}

		void Enqueue(const T& value) {
			Node<T>* newNode = new Node<T>(value);
			if (IsEmpty()) {
				front = rear = newNode;
			}
			else {
				rear->next = newNode;
				rear = newNode;
			}
		}

		void Dequeue() {
			if (!IsEmpty()) {
				Node<T>* temp = front;
				front = front->next;
				delete temp;
				if (front == nullptr) {
					rear = nullptr;
				}
			}
		}

		T& Peek() const {
			if (front != nullptr)
			{
				return front->data;
			}

			// todo: other exception type
			throw std::logic_error("Cannot peek empty queue.");
		}

		bool IsEmpty() const {
			return front == nullptr;
		}
	};
}
