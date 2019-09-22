#ifndef STACK_HPP
#define STACK_HPP

#include <utility>
#include "node.hpp"

template<class T>
class Stack
{
    typedef SimpleNode<T> _Node;
    public:
        Stack()
        :m_top(nullptr),m_size(0) {}

        ~Stack() { this->clear(); }

        bool empty() { return (this->m_top==nullptr); }

        size_t size() { return this->m_size; };

        void swap(Stack<T> &other)
        {
            std::swap(this->m_top, other.m_top);
            std::swap(this->m_size, other.m_size);
        }

        void clear()
        {
            while(m_top != nullptr)
                this->pop();
        }

        void push(T data)
        {
            _Node *newHead { new _Node(data, this->m_top) };
            this->m_top = newHead;
            this->m_size++;
        }

        T pop()
        {
            if (this->m_top == nullptr)
            {
                T ret {};
                return ret;
            }

            _Node *newHead { this->m_top->next };
            T ret { this->m_top->data };
            delete m_top;
            m_top = newHead;
            this->m_size--;
            return ret;
        }

        const T top()
        {
            return this->m_top->data;
        }

    private:
        _Node *m_top;
        size_t m_size;
};

#endif //STACK_HPP
