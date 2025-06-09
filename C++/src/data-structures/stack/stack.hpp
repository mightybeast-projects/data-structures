#pragma once
#include "stack-node.hpp"

namespace Stack
{
    using namespace StackNode;

    template <typename T>
    class Stack
    {
    public:
        int length = 0;
        Node<T> *head = nullptr;

        Stack();

        void push(T value);
        T pop();
        T peek();
    };
}

#include "stack.tpp"