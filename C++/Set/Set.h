# pragma once
# define _SET_H
# ifndef _SET_H
# include <iostream>

template <typename T>
class Set{
    public:
        Set(){}
        ~Set(){}
        //general features
        void add(const T data);
        void remove(const T data);
        void clear();
        void display();

        // opserations
        Set set_intersection(Set &other);
        Set set_difference(Set &other);
        Set set_symmetric_diff(Set &other);
        Set set_complement(Set &other);
        Set set_product(Set &other);
        Set set_union(Set &other);

        //operators
        Set operator+();
        Set operator-();
        Set operator/();
        Set operator*();

        bool is_element(const T data);
        bool is_empty();
        bool is_subset(const Set &other);
        bool is_superset(const Set &other);

        int cardinality();
    
    private:
        int hash();
};

# endif 