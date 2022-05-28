#include <columnar/metadef.hpp>

struct convertible
{
    double a_double;
    int an_int;
    convertible* a_pconvertible;

    template<template<typename> typename Alloc> struct array_generated_;
    template<typename ArrayType> struct handle_generated_;
    template<std::size_t Num> struct c_array_generated_;

    template<std::size_t Num>
    using c_array_tmpl = c_array_generated_<Num>;

    template<template<typename> typename Alloc = std::allocator>
    using array_tmpl = array_generated_<Alloc>;

    template<typename ArrayType>
    using handle_tmpl = handle_generated_<ArrayType>;

    // constexpr auto c_array_t(size_t count) { }
    using array_t = array_tmpl<std::allocator>;
    using handle_t = handle_tmpl<array_t>;

    template<size_t Num>
    struct c_array_generated_
    {
        using columnar_handle_type = convertible &;
        convertible data[Num];

        constexpr columnar_handle_type operator[] (std::size_t at) { return (columnar_handle_type) data[at]; };
    };

    template<template<typename S> typename Alloc>
    struct array_generated_
    {
        using columnar_handle_type = convertible &;
        const size_t size;

        convertible* data;

        array_generated_(size_t count): size(count), data(new convertible[count]) {}
        ~array_generated_() { delete[] data; }
        constexpr columnar_handle_type operator[] (std::size_t at) { return (columnar_handle_type) data[at]; };
    };

    // template<typename ArrayType>
    // using handle_generated_ = convertible;
};
