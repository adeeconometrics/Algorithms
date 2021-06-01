#pragma once
#include <exception>

class null_exception: std::exception{
    const char* msg = "";
    const char* type = "null_exception";

    public:
        explicit null_exception() = default;
        explicit null_exception(const char* annotation):msg(annotation){}
        virtual ~null_exception() = default;
        const char* get_msg(){return msg;}
        const char* get_type(){return type;}
};