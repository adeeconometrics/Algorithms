#pragma once

template <typename T> class Comparable{
    public:
        Comparable() = default;
        virtual ~Comparable() = default;

        T& operator=(const T& other) = delete;
        T& operator=(T&& other) = delete;
        bool operator==(const T& other) = 0;
        bool operator!=(const T& other) = 0;
        bool operator<(const T& other) = 0;
        bool operator>(const T& other) = 0; 
};