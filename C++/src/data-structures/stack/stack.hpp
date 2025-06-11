#pragma once

namespace stack
{
    template <typename T>
    struct Node
    {
        T value;
        Node<T> *prev = nullptr;

        Node(T val) : value(val) {};
    };

    template <typename T>
    struct Stack
    {
        int length = 0;
        Node<T> *head = nullptr;

        void push(T value);
        T pop();
        T peek();
    };
}

#include "stack.tpp"