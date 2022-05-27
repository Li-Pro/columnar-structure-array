#include "soa.hpp"

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
        convert.a_double(0) = 0.14159;
        convert.an_int(2) = 3;
        convert.a_pconvertible(4) = nullptr;
    }

    // similar: dynamic array
    {
        convertible::array_t convert(5);
        convert.a_double(0) = 0.14159;
        convert.an_int(2) = 3;
        convert.a_pconvertible(4) = nullptr;
    }

    // similar: no handle available, test with singleton
    {
        const size_t idx = 0;

        convertible::c_array_tmpl<1> convert;
        auto handle = convert;

        handle.a_double(idx) = 0.14159;
        handle.an_int(idx) = 3;
        handle.a_pconvertible(idx) = nullptr;
    }
}
