/**
 * @file AbstractArray.h
 * @author ddamiana
 * @brief Abstract Array Interface
 * @version 0.1
 * @date 2021-09-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */

# pragma once

template <typename T> class AbstractArray{
    public:
        AbstractArray() = default;
        AbstractArray(const AbstractArray&) = delete;
        AbstractArray(AbstractArray&&) = delete;
        virtual ~AbstractArray() = default;

        AbstractArray& operator=(const AbstractArray&) = delete;
        AbstractArray& operator=(AbstractArray&&) = delete;

        virtual T& operator[](size_t idx) = 0;
        virtual T& operator[](size_t idx) const = 0;
};