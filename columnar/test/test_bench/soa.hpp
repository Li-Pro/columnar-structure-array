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
        double a_double_[Num];
        int an_int_[Num];
        convertible* a_pconvertible_[Num];

        constexpr double & a_double(std::size_t const at_pos) { return a_double_[at_pos]; }
        constexpr int & an_int(std::size_t const at_pos) { return an_int_[at_pos]; }
        constexpr convertible* & a_pconvertible(std::size_t const at_pos) { return a_pconvertible_[at_pos]; }
    };

    template<template<typename S> typename Alloc>
    struct array_generated_
    {
        const size_t size;

        double * a_double_;
        int * an_int_;
        convertible* * a_pconvertible_;

        constexpr double & a_double(std::size_t const at_pos) { return a_double_[at_pos]; }
        constexpr int & an_int(std::size_t const at_pos) { return an_int_[at_pos]; }
        constexpr convertible* & a_pconvertible(std::size_t const at_pos) { return a_pconvertible_[at_pos]; }

        array_generated_(size_t count): size(count), a_double_(new double[count]), an_int_(new int[count]), a_pconvertible_(new convertible*[count]) {}
        ~array_generated_() { delete[] a_double_; delete[] an_int_; delete[] a_pconvertible_; }
    };

    // template<typename ArrayType>
    // using handle_generated_ = convertible;
};
