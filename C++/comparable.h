#pragma once

template <typename T> class Comparable{
    public:
        Comparable() = default;
        Comparable(const T& other)  = delete;
        Comparable(T&& other) = delete;
        
        virtual ~Comparable() = default;

        T& operator=(const T& other) = delete;
        T& operator=(T&& other) = delete;
        
        virtual bool operator==(const T& other) = 0;
        virtual bool operator!=(const T& other) = 0;
        virtual bool operator<(const T& other) = 0;
        virtual bool operator>(const T& other) = 0; 
};