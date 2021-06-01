#pragma once

template <typename Container> class Iterable{
    public:
        Iterable() = default;
        virtual ~Iterable() = default;

        Container& operator=(const Container& other) = delete;
        Container& operator=(Container&& other) = delete;
        
        virtual void next() = 0;
        virtual bool has_next() = 0;
};