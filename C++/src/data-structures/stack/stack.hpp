#pragma once

namespace stack
{
    template <typename T>
    struct Node
    {
        T value;
        Node<T> *prev = nullptr;
    };

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