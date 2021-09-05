/**
 * @file AbstractArray.h
 * @author ddamiana
 * @brief Abstract Interface of Array-based Types
 * @version 0.1
 * @date 2021-09-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */

class AbstractArray {
public:
  AbstractArray() = default;
  AbstractArray(const AbstractArray &) = delete;
  AbstractArray(AbstractArray &&) = delete;
  virtual ~AbstractArray() = default;

  AbstractArray &operator=(const AbstractArray &) = delete;
  AbstractArray &operator=(AbstractArray &&) = delete;

  virtual int &operator[](size_t idx) = 0;
  virtual int &operator[](size_t idx) const = 0;
};