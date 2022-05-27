/**
 * @author Chris Chou (chris.chou.c@nycu.edu.tw)
 * @brief basic columnar def
 * @date 2022-05-26
 * 
 * @copyright Copyright (c) 2022 Li-Pro
 */

#pragma once

#if !defined(COLUMNAR_NOINCLUDE)
    #include <cstddef>
    #include <memory>
#endif

#define COLUMNAR_JOIN_UNDERSCORE_0(x, y) x ## _ ## y
#define COLUMNAR_JOIN_UNDERSCORE_1(x, y) COLUMNAR_JOIN_UNDERSCORE_0(x, y)

#define COLUMNAR_MOD_C_ARRAY_MEMBER(Type, Name) Type Name[Num]
#define COLUMNAR_MOD_MEMBER(Type, Name) Type Name
#define COLUMNAR_MOD_ARRAY_MEMBER_ALLOCATOR_NAME(Type, Name) columnar_allocator_ ## Name
#define COLUMNAR_MOD_ARRAY_MEMBER_ALLOCATOR(Type, Name) Alloc<Type> COLUMNAR_MOD_ARRAY_MEMBER_ALLOCATOR_NAME(Type, Name)
#define COLUMNAR_MOD_ARRAY_MEMBER(Type, Name) Type * Name
#define COLUMNAR_MOD_ARRAY_CTOR__SIZE_T(Type, Name) Name(COLUMNAR_MOD_ARRAY_MEMBER_ALLOCATOR_NAME(Type, Name).allocate(count))
#define COLUMNAR_MOD_ARRAY_DTOR(Type, Name) COLUMNAR_MOD_ARRAY_MEMBER_ALLOCATOR_NAME(Type, Name).deallocate(Name, size)

#define COLUMNAR_MOD_HANDLE(Type, Name) constexpr Type & Name() { return main_obj->Name[at_pos]; }

#define COLUMNAR_DEF_TYPES_BLOCK(...) \
    template<template<typename> typename Alloc> struct array_generated_; \
    template<typename ArrayType> struct handle_generated_; \
    template<std::size_t Num> struct c_array_generated_; \
    \
    template<std::size_t Num> \
    using c_array_tmpl = c_array_generated_<Num>; \
    \
    template<template<typename> typename Alloc = std::allocator> \
    using array_tmpl = array_generated_<Alloc>; \
    \
    template<typename ArrayType> \
    using handle_tmpl = handle_generated_<ArrayType>; \
    \
    using array_t = array_tmpl<std::allocator>; \
    using handle_t = handle_tmpl<array_t>;

#define COLUMNAR_DEF_ARRAY_PRE(...) \
    template<template<typename S> typename Alloc> \
    struct array_generated_ \
    { \
        using columnar_handle_type = handle_generated_<array_generated_<Alloc>>; \
        const size_t size;

#define COLUMNAR_DEF_ARRAY_POST(...) \
        constexpr columnar_handle_type operator[] (std::size_t at) { return columnar_handle_type{at, (array_generated_<Alloc>*) this}; }; \
    };

#define COLUMNAR_DEF_HANDLE_PRE(...) \
    template<typename ArrayType> \
    struct handle_generated_ \
    { \
        std::size_t const at_pos; \
        ArrayType* const main_obj;

#define COLUMNAR_DEF_HANDLE_POST(...) \
    };

// Auto generated
#define N_EVEN_VA_ARGS_RET7(x1, x2, x3, x4, x5, x6, ret, ...) ret
#define N_EVEN_VA_ARGS(...) N_EVEN_VA_ARGS_RET7(__VA_ARGS__ 6, ARGERROR, 4, ARGERROR, 2, ARGERROR, 0)

// TODO: auto generate error ARGERROR

// Auto generated
#define COLUMNAR_DEF_MEMBER_0()
#define COLUMNAR_DEF_MEMBER_2(Type, Name, ...) COLUMNAR_MOD_MEMBER(Type, Name);
#define COLUMNAR_DEF_MEMBER_4(Type, Name, ...) COLUMNAR_MOD_MEMBER(Type, Name); COLUMNAR_DEF_MEMBER_2(__VA_ARGS__)
#define COLUMNAR_DEF_MEMBER_6(Type, Name, ...) COLUMNAR_MOD_MEMBER(Type, Name); COLUMNAR_DEF_MEMBER_4(__VA_ARGS__)

// Auto generated
#define COLUMNAR_DEF_C_ARRAY_MEMBER_0()
#define COLUMNAR_DEF_C_ARRAY_MEMBER_2(Type, Name, ...) COLUMNAR_MOD_C_ARRAY_MEMBER(Type, Name); 
#define COLUMNAR_DEF_C_ARRAY_MEMBER_4(Type, Name, ...) COLUMNAR_MOD_C_ARRAY_MEMBER(Type, Name); COLUMNAR_DEF_C_ARRAY_MEMBER_2(__VA_ARGS__)
#define COLUMNAR_DEF_C_ARRAY_MEMBER_6(Type, Name, ...) COLUMNAR_MOD_C_ARRAY_MEMBER(Type, Name); COLUMNAR_DEF_C_ARRAY_MEMBER_4(__VA_ARGS__)

// Auto generated
#define COLUMNAR_DEF_ARRAY_MEMBER_0()
#define COLUMNAR_DEF_ARRAY_MEMBER_2(Type, Name, ...) COLUMNAR_MOD_ARRAY_MEMBER(Type, Name); COLUMNAR_MOD_ARRAY_MEMBER_ALLOCATOR(Type, Name);
#define COLUMNAR_DEF_ARRAY_MEMBER_4(Type, Name, ...) COLUMNAR_MOD_ARRAY_MEMBER(Type, Name); COLUMNAR_MOD_ARRAY_MEMBER_ALLOCATOR(Type, Name); COLUMNAR_DEF_ARRAY_MEMBER_2(__VA_ARGS__)
#define COLUMNAR_DEF_ARRAY_MEMBER_6(Type, Name, ...) COLUMNAR_MOD_ARRAY_MEMBER(Type, Name); COLUMNAR_MOD_ARRAY_MEMBER_ALLOCATOR(Type, Name); COLUMNAR_DEF_ARRAY_MEMBER_4(__VA_ARGS__)

// Auto generated
#define COLUMNAR_DEF_ARRAY_CTOR__SIZE_T_0()
#define COLUMNAR_DEF_ARRAY_CTOR__SIZE_T_2(Type, Name, ...) COLUMNAR_MOD_ARRAY_CTOR__SIZE_T(Type, Name)
#define COLUMNAR_DEF_ARRAY_CTOR__SIZE_T_4(Type, Name, ...) COLUMNAR_MOD_ARRAY_CTOR__SIZE_T(Type, Name), COLUMNAR_DEF_ARRAY_CTOR__SIZE_T_2(__VA_ARGS__)
#define COLUMNAR_DEF_ARRAY_CTOR__SIZE_T_6(Type, Name, ...) COLUMNAR_MOD_ARRAY_CTOR__SIZE_T(Type, Name), COLUMNAR_DEF_ARRAY_CTOR__SIZE_T_4(__VA_ARGS__)

// Auto generated
#define COLUMNAR_DEF_ARRAY_DTOR_0()
#define COLUMNAR_DEF_ARRAY_DTOR_2(Type, Name, ...) COLUMNAR_MOD_ARRAY_DTOR(Type, Name);
#define COLUMNAR_DEF_ARRAY_DTOR_4(Type, Name, ...) COLUMNAR_MOD_ARRAY_DTOR(Type, Name); COLUMNAR_DEF_ARRAY_DTOR_2(__VA_ARGS__)
#define COLUMNAR_DEF_ARRAY_DTOR_6(Type, Name, ...) COLUMNAR_MOD_ARRAY_DTOR(Type, Name); COLUMNAR_DEF_ARRAY_DTOR_4(__VA_ARGS__)

// Auto generated
#define COLUMNAR_DEF_HANDLE_0()
#define COLUMNAR_DEF_HANDLE_2(Type, Name, ...) COLUMNAR_MOD_HANDLE(Type, Name)
#define COLUMNAR_DEF_HANDLE_4(Type, Name, ...) COLUMNAR_MOD_HANDLE(Type, Name) COLUMNAR_DEF_HANDLE_2(__VA_ARGS__)
#define COLUMNAR_DEF_HANDLE_6(Type, Name, ...) COLUMNAR_MOD_HANDLE(Type, Name) COLUMNAR_DEF_HANDLE_4(__VA_ARGS__)

#define COLUMNAR_DEF_MEMBER(...) \
    COLUMNAR_JOIN_UNDERSCORE_1(COLUMNAR_DEF_MEMBER, N_EVEN_VA_ARGS(__VA_ARGS__)) (__VA_ARGS__)

#define COLUMNAR_DEF_TYPES(...) \
    COLUMNAR_DEF_TYPES_BLOCK(__VA_ARGS__)

#define COLUMNAR_DEF_ARRAY_CTOR__SIZE_T_PRE(...) \
    array_generated_(size_t count): size(count)

#define COLUMNAR_DEF_ARRAY_CTOR__SIZE_T_POST(...) \
    {}

#define COLUMNAR_DEF_ARRAY_CTOR__SIZE_T(...) \
    COLUMNAR_DEF_ARRAY_CTOR__SIZE_T_PRE(__VA_ARGS__), \
    COLUMNAR_JOIN_UNDERSCORE_1(COLUMNAR_DEF_ARRAY_CTOR__SIZE_T, N_EVEN_VA_ARGS(__VA_ARGS__)) (__VA_ARGS__) \
    COLUMNAR_DEF_ARRAY_CTOR__SIZE_T_POST(__VA_ARGS__)

#define COLUMNAR_DEF_ARRAY_DTOR_PRE(...) \
    ~array_generated_() {

#define COLUMNAR_DEF_ARRAY_DTOR_POST(...) \
    }

#define COLUMNAR_DEF_ARRAY_DTOR(...) \
    COLUMNAR_DEF_ARRAY_DTOR_PRE(__VA_ARGS__) \
    COLUMNAR_JOIN_UNDERSCORE_1(COLUMNAR_DEF_ARRAY_DTOR, N_EVEN_VA_ARGS(__VA_ARGS__)) (__VA_ARGS__) \
    COLUMNAR_DEF_ARRAY_DTOR_POST(__VA_ARGS__)

#define COLUMNAR_DEF_C_ARRAY_PRE(...) \
    template<size_t Num> \
    struct c_array_generated_ \
    { \
        using columnar_handle_type = handle_generated_<c_array_generated_<Num>>;

#define COLUMNAR_DEF_C_ARRAY_POST(...) \
        constexpr columnar_handle_type operator[] (std::size_t at) { return columnar_handle_type{at, (c_array_generated_<Num>*) this}; }; \
    };
    

#define COLUMNAR_DEF_C_ARRAY(...) \
    COLUMNAR_DEF_C_ARRAY_PRE(__VA_ARGS__) \
    COLUMNAR_JOIN_UNDERSCORE_1(COLUMNAR_DEF_C_ARRAY_MEMBER, N_EVEN_VA_ARGS(__VA_ARGS__)) (__VA_ARGS__) \
    COLUMNAR_DEF_C_ARRAY_POST(__VA_ARGS__)

#define COLUMNAR_DEF_ARRAY(...) \
    COLUMNAR_DEF_ARRAY_PRE(__VA_ARGS__) \
    COLUMNAR_JOIN_UNDERSCORE_1(COLUMNAR_DEF_ARRAY_MEMBER, N_EVEN_VA_ARGS(__VA_ARGS__)) (__VA_ARGS__) \
    COLUMNAR_DEF_ARRAY_CTOR__SIZE_T(__VA_ARGS__) \
    COLUMNAR_DEF_ARRAY_DTOR(__VA_ARGS__) \
    COLUMNAR_DEF_ARRAY_POST(__VA_ARGS__)

#define COLUMNAR_DEF_HANDLE(...) \
    COLUMNAR_DEF_HANDLE_PRE(__VA_ARGS__) \
    COLUMNAR_JOIN_UNDERSCORE_1(COLUMNAR_DEF_HANDLE, N_EVEN_VA_ARGS(__VA_ARGS__)) (__VA_ARGS__) \
    COLUMNAR_DEF_HANDLE_POST(__VA_ARGS__)

#define COLUMNAR_DEF(...) \
    COLUMNAR_DEF_MEMBER(__VA_ARGS__) \
    COLUMNAR_DEF_TYPES(__VA_ARGS__) \
    COLUMNAR_DEF_C_ARRAY(__VA_ARGS__) \
    COLUMNAR_DEF_ARRAY(__VA_ARGS__) \
    COLUMNAR_DEF_HANDLE(__VA_ARGS__)
