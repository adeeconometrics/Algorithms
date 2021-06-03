#pragma once

template<typename T> class Stack{
    public:
        Stack() = default;
        virtual ~Stack() = default;

        virtual void push(const T& obj) = 0;
        virtual void pop() = 0;
        virtual void diplay() const = 0;
        virtual const T& top() const = 0;
        virtual const T& bottom() const = 0;
};