#pragma once

template <typename Container> class Iterable{
    public: 
        typedef Container value_type;

    public:
        Iterable() = default;
        Iterable(const Container& other) =  delete; // stl iterators are copy-constructible
        Iterable(Container&& other) = delete;
        
        virtual ~Iterable() = default;

        Iterable<Container>& operator=(const Iterable<Container>& other) = delete;
        Iterable<Container>& operator=(Iterable<Container>&& other) = delete;
        Iterable<Container>& operator++() = 0;
        Iterable<Container>& operator++(int) = 0;

        bool operator==(const Iterable<Container>& other) = 0;
        bool operator!=(const Iterable<Container>& other) = 0;
        
        virtual void next() = 0;
        virtual bool has_next() = 0;

    private: 
        size_t m_size{0};
};

template <typename Container> class Forward_Iterable{
    public: 
        typedef Container value_type;
        typedef value_type *pointer_type;

    public:
        Forward_Iterable() = default;
        Forward_Iterable(pointer_type ptr): m_ptr(ptr){}
        Forward_Iterable(const Container& other) =  delete;
        Forward_Iterable(Container&& other) = delete;
        
        virtual ~Forward_Iterable() = default;

        Forward_Iterable<Container>& operator=(const Forward_Iterable<Container>& other) = delete;
        Forward_Iterable<Container>& operator=(Forward_Iterable<Container>&& other) = delete;
        Forward_Iterable<Container>& operator++() = 0;
        Forward_Iterable<Container>& operator++(int) = 0;

        bool operator==(const Forward_Iterable<Container>& other) = 0;
        bool operator!=(const Forward_Iterable<Container>& other) = 0;

        virtual void next() = 0;
        virtual bool has_next() = 0;

    private:
        pointer_type m_ptr{nullptr};
};

template <typename Container> class Bidirectional_Iterable{
    public:
        typedef Container value_type;
        typedef value_type* pointer_type;
        typedef value_type& reference_type;

    public:
        Bidirectional_Iterable() = default;
        Bidirectional_Iterable(pointer_type ptr): m_ptr(ptr){}
        Bidirectional_Iterable(const Container& other) = delete;
        Bidirectional_Iterable(Container&& other) = delete;

        virtual ~Bidirectional_Iterable() = default;

        Bidirectional_Iterable<Container>& operator=(const Bidirectional_Iterable<Container>& other) = delete;
        Bidirectional_Iterable<Container>& operator=(Bidirectional_Iterable<Container>&& other) = delete;

        virtual Bidirectional_Iterable<Container>& operator++() = 0;
        virtual Bidirectional_Iterable<Container>& operator++(int) = 0; 
        virtual Bidirectional_Iterable<Container>& operator--() = 0;
        virtual Bidirectional_Iterable<Container>& operator--(int) = 0;

        virtual reference_type operator*() = 0;
        virtual pointer_type operator->() = 0;

        virtual bool operator==(const Bidirectional_Iterable<Container>& rhs) = 0;
        virtual bool operator!=(const Bidirectional_Iterable<Container>& rhs) = 0;

        virtual void front_inserter(const value_type& data) = 0;
        virtual void back_inserter(const value_type& data) = 0; 

    private:
        pointer_type m_ptr{nullptr};
};

template <typename Container> class Random_Iterable{
    public:
        typedef Container value_type;
        typedef value_type* pointer_type;
        typedef value_type& reference_type;

    public:
        Random_Iterable() = default;
        Random_Iterable(pointer_type ptr): m_ptr(ptr){}
        Random_Iterable(const Container& other) = delete;
        Random_Iterable(Container&& other) = delete;

        virtual ~Random_Iterable() = default;

        Random_Iterable<Container>& operator=(const Random_Iterable<Container>& other) = delete;
        Random_Iterable<Container>& operator=(Random_Iterable<Container>&& other) = delete;

        virtual Random_Iterable<Container>& operator++() = 0;
        virtual Random_Iterable<Container>& operator++(int) = 0; 
        virtual Random_Iterable<Container>& operator--() = 0;
        virtual Random_Iterable<Container>& operator--(int) = 0;

        virtual reference_type operator*() = 0;
        virtual pointer_type operator->() = 0;

        virtual bool operator==(const Random_Iterable<Container>& rhs) = 0;
        virtual bool operator!=(const Random_Iterable<Container>& rhs) = 0;

        virtual void operator[](size_t idx) = 0;
        virtual void front_inserter(const value_type& data) = 0;
        virtual void back_inserter(const value_type& data) = 0; 
        virtual void inserter(const value_type& data) = 0;

    private:
        pointer_type m_ptr{nullptr};
};