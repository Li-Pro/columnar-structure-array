#include "aos.hpp"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"

void test()
{
    // identical: raw object manipulation
    {
        convertible convert;
        convert.a_double = 3.0;
        convert.an_int = 5;
        convert.a_pconvertible = &convert;
    }
    
    // similar: carray
    {
        convertible::c_array_tmpl<5> convert;
        convert[0].a_double = 0.14159;
        convert[2].an_int = 3;
        convert[4].a_pconvertible = nullptr;
    }

    // similar: dynamic array
    {
        convertible::array_t convert(5);
        convert[0].a_double = 0.14159;
        convert[2].an_int = 3;
        convert[4].a_pconvertible = nullptr;
    }

    // similar: handle object
    {
        convertible::c_array_tmpl<1> convert;
        auto handle = convert[0];

        handle.a_double = 0.14159;
        handle.an_int = 3;
        handle.a_pconvertible = nullptr;
    }
}

#pragma GCC diagnostic pop
