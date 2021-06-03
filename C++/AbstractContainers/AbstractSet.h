#pragma once

template<typename T> class Set{
    public:
        Set() = default;
        virtual ~Set() = default;

        virtual void add(const T& obj) = 0;
        virtual void remove(const T& obj) = 0;
        virtual void diplay() const = 0;

        virtual bool is_element() const = 0;
        virtual bool is_empty() const = 0;
        virtual bool is_subset() const = 0;
        virtual bool is_complement() const = 0;

        virtual size_t size() const = 0;
};