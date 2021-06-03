#pragma once

template<typename T> class Queue{
    public:
        Queue() = default;
        virtual ~Queue() = default;

        virtual void push(const T& obj) = 0;
        virtual void pop() = 0;
        virtual void enqueue(const T& obj) = 0;
        virtual void dequeue() = 0;
        virtual void diplay() const;
        
        virtual const T& top() const = 0;
        virtual const T& bottom() const = 0;
};