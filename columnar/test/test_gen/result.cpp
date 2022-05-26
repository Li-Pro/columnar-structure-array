#include "metadef.hpp"

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
        using columnar_handle_type = handle_generated_<c_array_generated_<Num>>;

        double a_double[Num];
        int an_int[Num];
        convertible* a_pconvertible[Num];

        constexpr columnar_handle_type operator[] (std::size_t at) { return columnar_handle_type{at, this}; };
    };

    template<template<typename S> typename Alloc>
    struct array_generated_
    {
        using columnar_handle_type = handle_generated_<array_generated_<Alloc>>;
        const size_t size;

        double * a_double; Alloc<double> columnar_allocator_a_double;
        int * an_int; Alloc<int> columnar_allocator_an_int;
        convertible* * a_pconvertible; Alloc<convertible*> columnar_allocator_a_pconvertible;

        array_generated_(size_t count): size(count), a_double(columnar_allocator_a_double.allocate(count)), an_int(columnar_allocator_an_int.allocate(count)), a_pconvertible(columnar_allocator_a_pconvertible.allocate(count)) {}
        ~array_generated_() { columnar_allocator_a_double.deallocate(a_double, size); columnar_allocator_an_int.deallocate(an_int, size); columnar_allocator_a_pconvertible.deallocate(a_pconvertible, size); }
        constexpr columnar_handle_type operator[] (std::size_t at) { return columnar_handle_type{at, this}; };
    };

    template<typename ArrayType>
    struct handle_generated_
    {
        std::size_t const at_pos;
        ArrayType* const main_obj;
        
        constexpr double & a_double() { return main_obj->a_double[at_pos]; }
        constexpr int & an_int() { return main_obj->an_int[at_pos]; }
        constexpr convertible* & a_pconvertible() { return main_obj->a_pconvertible[at_pos]; }
    };
};
