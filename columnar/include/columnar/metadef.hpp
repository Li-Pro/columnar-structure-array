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

#define COLUMNAR_APPEND_UNDERSCORE_0(x) x ## _
#define COLUMNAR_APPEND_UNDERSCORE(x) COLUMNAR_APPEND_UNDERSCORE_0(x)

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

// TODO: remove_cv

// TODO: pointer-like array type

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
#define N_VA_ARGS_RET10(x1, x2, x3, x4, x5, x6, x7, x8, x9, ret, ...) ret
#define N_VA_ARGS(...) N_VA_ARGS_RET10(__VA_ARGS__ 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)

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
#define COLUMNAR_STATEMENT_MAP_EXT_CALL_0(MapFunc, ...) MapFunc(__VA_ARGS__)
#define COLUMNAR_STATEMENT_MAP_EXT_CALL(...) COLUMNAR_STATEMENT_MAP_EXT_CALL_0(__VA_ARGS__)

// Auto generated
#define COLUMNAR_STATEMENT_MAP_EXT_CALL_LV2_0(MapFunc, ...) MapFunc(__VA_ARGS__)
#define COLUMNAR_STATEMENT_MAP_EXT_CALL_LV2(...) COLUMNAR_STATEMENT_MAP_EXT_CALL_LV2_0(__VA_ARGS__)

// Auto generated
#define COLUMNAR_STATEMENT_MAP_EXT_CALL_LV3_0(MapFunc, ...) MapFunc(__VA_ARGS__)
#define COLUMNAR_STATEMENT_MAP_EXT_CALL_LV3(...) COLUMNAR_STATEMENT_MAP_EXT_CALL_LV3_0(__VA_ARGS__)

// Auto generated
#define COLUMNAR_STATEMENT_MAP2_EXT_CALL_0(MapFunc, ...) MapFunc(__VA_ARGS__)
#define COLUMNAR_STATEMENT_MAP2_EXT_CALL(...) COLUMNAR_STATEMENT_MAP2_EXT_CALL_0(__VA_ARGS__)

// Auto generated
#define COLUMNAR_DEF_HANDLE_0()
#define COLUMNAR_DEF_HANDLE_2(Type, Name, ...) COLUMNAR_MOD_HANDLE(Type, Name)
#define COLUMNAR_DEF_HANDLE_4(Type, Name, ...) COLUMNAR_MOD_HANDLE(Type, Name) COLUMNAR_DEF_HANDLE_2(__VA_ARGS__)
#define COLUMNAR_DEF_HANDLE_6(Type, Name, ...) COLUMNAR_MOD_HANDLE(Type, Name) COLUMNAR_DEF_HANDLE_4(__VA_ARGS__)

// Auto generated
#define COLUMNAR_STATEMENT_MAP_0(...) // error
#define COLUMNAR_STATEMENT_MAP_1(...)
#define COLUMNAR_STATEMENT_MAP_2(MapFunc, First, ...) MapFunc(First)
#define COLUMNAR_STATEMENT_MAP_3(MapFunc, First, ...) MapFunc(First) COLUMNAR_STATEMENT_MAP_2(MapFunc, __VA_ARGS__)
#define COLUMNAR_STATEMENT_MAP_4(MapFunc, First, ...) MapFunc(First) COLUMNAR_STATEMENT_MAP_3(MapFunc, __VA_ARGS__)
#define COLUMNAR_STATEMENT_MAP_5(MapFunc, First, ...) MapFunc(First) COLUMNAR_STATEMENT_MAP_4(MapFunc, __VA_ARGS__)
#define COLUMNAR_STATEMENT_MAP_6(MapFunc, First, ...) MapFunc(First) COLUMNAR_STATEMENT_MAP_5(MapFunc, __VA_ARGS__)

// Auto generated
#define COLUMNAR_STATEMENT_MAP_EXT_0(...) // error
#define COLUMNAR_STATEMENT_MAP_EXT_1(...) // error
#define COLUMNAR_STATEMENT_MAP_EXT_2(...)
#define COLUMNAR_STATEMENT_MAP_EXT_3(MapFunc, Args, First, ...) COLUMNAR_STATEMENT_MAP_EXT_CALL(MapFunc, First, COLUMNAR_VA_ARGS_EXPAND Args)
#define COLUMNAR_STATEMENT_MAP_EXT_4(MapFunc, Args, First, ...) COLUMNAR_STATEMENT_MAP_EXT_CALL(MapFunc, First, COLUMNAR_VA_ARGS_EXPAND Args) COLUMNAR_STATEMENT_MAP_EXT_3(MapFunc, Args, __VA_ARGS__)
#define COLUMNAR_STATEMENT_MAP_EXT_5(MapFunc, Args, First, ...) COLUMNAR_STATEMENT_MAP_EXT_CALL(MapFunc, First, COLUMNAR_VA_ARGS_EXPAND Args) COLUMNAR_STATEMENT_MAP_EXT_4(MapFunc, Args, __VA_ARGS__)
#define COLUMNAR_STATEMENT_MAP_EXT_6(MapFunc, Args, First, ...) COLUMNAR_STATEMENT_MAP_EXT_CALL(MapFunc, First, COLUMNAR_VA_ARGS_EXPAND Args) COLUMNAR_STATEMENT_MAP_EXT_5(MapFunc, Args, __VA_ARGS__)

// Auto generated
#define COLUMNAR_STATEMENT_MAP_EXT_LV2_0(...) // error
#define COLUMNAR_STATEMENT_MAP_EXT_LV2_1(...) // error
#define COLUMNAR_STATEMENT_MAP_EXT_LV2_2(...)
#define COLUMNAR_STATEMENT_MAP_EXT_LV2_3(MapFunc, Args, First, ...) COLUMNAR_STATEMENT_MAP_EXT_CALL_LV2(MapFunc, First, COLUMNAR_VA_ARGS_EXPAND Args)
#define COLUMNAR_STATEMENT_MAP_EXT_LV2_4(MapFunc, Args, First, ...) COLUMNAR_STATEMENT_MAP_EXT_CALL_LV2(MapFunc, First, COLUMNAR_VA_ARGS_EXPAND Args) COLUMNAR_STATEMENT_MAP_EXT_LV2_3(MapFunc, Args, __VA_ARGS__)
#define COLUMNAR_STATEMENT_MAP_EXT_LV2_5(MapFunc, Args, First, ...) COLUMNAR_STATEMENT_MAP_EXT_CALL_LV2(MapFunc, First, COLUMNAR_VA_ARGS_EXPAND Args) COLUMNAR_STATEMENT_MAP_EXT_LV2_4(MapFunc, Args, __VA_ARGS__)
#define COLUMNAR_STATEMENT_MAP_EXT_LV2_6(MapFunc, Args, First, ...) COLUMNAR_STATEMENT_MAP_EXT_CALL_LV2(MapFunc, First, COLUMNAR_VA_ARGS_EXPAND Args) COLUMNAR_STATEMENT_MAP_EXT_LV2_5(MapFunc, Args, __VA_ARGS__)

// Auto generated
#define COLUMNAR_STATEMENT_MAP_EXT_LV3_0(...) // error
#define COLUMNAR_STATEMENT_MAP_EXT_LV3_1(...) // error
#define COLUMNAR_STATEMENT_MAP_EXT_LV3_2(...)
#define COLUMNAR_STATEMENT_MAP_EXT_LV3_3(MapFunc, Args, First, ...) COLUMNAR_STATEMENT_MAP_EXT_CALL_LV3(MapFunc, First, COLUMNAR_VA_ARGS_EXPAND Args)
#define COLUMNAR_STATEMENT_MAP_EXT_LV3_4(MapFunc, Args, First, ...) COLUMNAR_STATEMENT_MAP_EXT_CALL_LV3(MapFunc, First, COLUMNAR_VA_ARGS_EXPAND Args) COLUMNAR_STATEMENT_MAP_EXT_LV3_3(MapFunc, Args, __VA_ARGS__)
#define COLUMNAR_STATEMENT_MAP_EXT_LV3_5(MapFunc, Args, First, ...) COLUMNAR_STATEMENT_MAP_EXT_CALL_LV3(MapFunc, First, COLUMNAR_VA_ARGS_EXPAND Args) COLUMNAR_STATEMENT_MAP_EXT_LV3_4(MapFunc, Args, __VA_ARGS__)
#define COLUMNAR_STATEMENT_MAP_EXT_LV3_6(MapFunc, Args, First, ...) COLUMNAR_STATEMENT_MAP_EXT_CALL_LV3(MapFunc, First, COLUMNAR_VA_ARGS_EXPAND Args) COLUMNAR_STATEMENT_MAP_EXT_LV3_5(MapFunc, Args, __VA_ARGS__)

// Auto generated
#define COLUMNAR_STATEMENT_MAP2_0()
#define COLUMNAR_STATEMENT_MAP2_2(MapFunc, First, Second, ...) MapFunc(First, Second)
#define COLUMNAR_STATEMENT_MAP2_4(MapFunc, First, Second, ...) MapFunc(First, Second) COLUMNAR_STATEMENT_MAP2_2(MapFunc, __VA_ARGS__)
#define COLUMNAR_STATEMENT_MAP2_6(MapFunc, First, Second, ...) MapFunc(First, Second) COLUMNAR_STATEMENT_MAP2_4(MapFunc, __VA_ARGS__)

// TODO: N_EVEN_VA_ARGS -> N_VA_ARGS
#define COLUMNAR_STATEMENT_MAP2_EXT_0(...) // error
#define COLUMNAR_STATEMENT_MAP2_EXT_1(...) // error
#define COLUMNAR_STATEMENT_MAP2_EXT_2(...)
#define COLUMNAR_STATEMENT_MAP2_EXT_3(...) // error
#define COLUMNAR_STATEMENT_MAP2_EXT_4(MapFunc, Args, First, Second, ...) COLUMNAR_STATEMENT_MAP2_EXT_CALL(MapFunc, First, Second, COLUMNAR_VA_ARGS_EXPAND Args)
#define COLUMNAR_STATEMENT_MAP2_EXT_5(...) // error
#define COLUMNAR_STATEMENT_MAP2_EXT_6(MapFunc, Args, First, Second, ...) COLUMNAR_STATEMENT_MAP2_EXT_CALL(MapFunc, First, Second, COLUMNAR_VA_ARGS_EXPAND Args) COLUMNAR_STATEMENT_MAP2_EXT_4(MapFunc, Args, __VA_ARGS__)
#define COLUMNAR_STATEMENT_MAP2_EXT_7(...) // error
#define COLUMNAR_STATEMENT_MAP2_EXT_8(MapFunc, Args, First, Second, ...) COLUMNAR_STATEMENT_MAP2_EXT_CALL(MapFunc, First, Second, COLUMNAR_VA_ARGS_EXPAND Args) COLUMNAR_STATEMENT_MAP2_EXT_6(MapFunc, Args, __VA_ARGS__)

#define COLUMNAR_STATEMENT_MAP_EXT_LV2(...) \
    COLUMNAR_JOIN_UNDERSCORE_1(COLUMNAR_STATEMENT_MAP_EXT_LV2, N_VA_ARGS(__VA_ARGS__)) (__VA_ARGS__)

#define COLUMNAR_STATEMENT_MAP_EXT_LV3(...) \
    COLUMNAR_JOIN_UNDERSCORE_1(COLUMNAR_STATEMENT_MAP_EXT_LV3, N_VA_ARGS(__VA_ARGS__)) (__VA_ARGS__)

#define COLUMNAR_STATEMENT_MAP(...) \
    COLUMNAR_JOIN_UNDERSCORE_1(COLUMNAR_STATEMENT_MAP, N_VA_ARGS(__VA_ARGS__)) (__VA_ARGS__)

// map(func, (args...), list)
#define COLUMNAR_STATEMENT_MAP_EXT(...) \
    COLUMNAR_JOIN_UNDERSCORE_1(COLUMNAR_STATEMENT_MAP_EXT, N_VA_ARGS(__VA_ARGS__)) (__VA_ARGS__)

#define COLUMNAR_STATEMENT_MAP2(...) \
    COLUMNAR_JOIN_UNDERSCORE_1(COLUMNAR_STATEMENT_MAP2, N_EVEN_VA_ARGS(__VA_ARGS__)) (__VA_ARGS__)

#define COLUMNAR_STATEMENT_MAP2_EXT(...) \
    COLUMNAR_JOIN_UNDERSCORE_1(COLUMNAR_STATEMENT_MAP2_EXT, N_VA_ARGS(__VA_ARGS__)) (__VA_ARGS__)

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

// TODO: isolate statement recursion level
//     func(PrevLvStatement, ...)
//     PREV_STATEMENT_3() PREV_STATEMENT_2
#define COLUMNAR_STATEMENT_DO_0(Target, ...) Target(__VA_ARGS__)
#define COLUMNAR_STATEMENT_FOR_0(List, Pre, Loop, Post, ...) \
    Pre(__VA_ARGS__) \
    COLUMNAR_STATEMENT_MAP_EXT(Loop, (__VA_ARGS__), COLUMNAR_VA_ARGS_EXPAND List) \
    Post(__VA_ARGS__)

#define COLUMNAR_STATEMENT_FOR2_0(List, Pre, Loop, Post, ...) \
    Pre(__VA_ARGS__) \
    COLUMNAR_STATEMENT_MAP2_EXT(Loop, (__VA_ARGS__), COLUMNAR_VA_ARGS_EXPAND List) \
    Post(__VA_ARGS__)

#define COLUMNAR_STATEMENT_FOREACH_0(List, Target, ...) \
    COLUMNAR_STATEMENT_MAP_EXT(Target, (__VA_ARGS__), COLUMNAR_VA_ARGS_EXPAND List)

#define COLUMNAR_STATEMENT_FOREACH2_0(List, Target, ...) \
    COLUMNAR_STATEMENT_MAP2_EXT(Target, (__VA_ARGS__), COLUMNAR_VA_ARGS_EXPAND List)

#define COLUMNAR_STATEMENT_NOP(...)

#define COLUMNAR_STATEMENT_DO(...) COLUMNAR_STATEMENT_DO_0(__VA_ARGS__)
#define COLUMNAR_STATEMENT_FOR(...) COLUMNAR_STATEMENT_FOR_0(__VA_ARGS__)
#define COLUMNAR_STATEMENT_FOR2(...) COLUMNAR_STATEMENT_FOR2_0(__VA_ARGS__)
#define COLUMNAR_STATEMENT_FOREACH(...) COLUMNAR_STATEMENT_FOREACH_0(__VA_ARGS__)
#define COLUMNAR_STATEMENT_FOREACH2(...) COLUMNAR_STATEMENT_FOREACH2_0(__VA_ARGS__)

#define COLUMNAR_STATEMENT_EXPAND_DO(Target) Target
#define COLUMNAR_STATEMENT_EXPAND_FOR(Pre, Loop, Post) Pre, Loop, Post

#define COLUMNAR_STATEMENT_EXPAND_0(Statement) COLUMNAR_STATEMENT_EXPAND ## _ ## Statement // COLUMNAR_JOIN_UNDERSCORE_1(COLUMNAR_STATEMENT_EXPAND, Statement)
#define COLUMNAR_STATEMENT_EXPAND(Statement) COLUMNAR_STATEMENT_EXPAND_0(Statement)

#define COLUMNAR_STATEMENT_NAME_DO(...) COLUMNAR_STATEMENT_DO
#define COLUMNAR_STATEMENT_NAME_FOR(...) COLUMNAR_STATEMENT_FOR

#define COLUMNAR_STATEMENT_NAME_0(Statement) COLUMNAR_STATEMENT_NAME ## _ ## Statement // COLUMNAR_JOIN_UNDERSCORE_1(COLUMNAR_STATEMENT_NAME, Statement)
#define COLUMNAR_STATEMENT_NAME(Statement) COLUMNAR_STATEMENT_NAME_0(Statement)

#define COLUMNAR_STRIPFUNC_DEF(...) (__VA_ARGS__)

#define COLUMNAR_STRIPFUNC_0(Statement) COLUMNAR_JOIN_UNDERSCORE_1(COLUMNAR_STRIPFUNC, Statement)
#define COLUMNAR_STRIPFUNC(Statement) COLUMNAR_STRIPFUNC_0(Statement)

#define COLUMNAR_VA_ARGS_EXPAND_0(...) __VA_ARGS__
#define COLUMNAR_VA_ARGS_EXPAND(...) COLUMNAR_VA_ARGS_EXPAND_0(__VA_ARGS__)
#define COLUMNAR_VA_ARGS_EXPAND_DEF(...) COLUMNAR_VA_ARGS_EXPAND(__VA_ARGS__)
// #define COLUMNAR_VA_ARGS_PASS(Func, ...) Func(__VA_ARGS__)

#define COLUMNAR_FLAG_NAME_0(Name, ...) Name
#define COLUMNAR_FLAG_NAME(...) COLUMNAR_FLAG_NAME_0(__VA_ARGS__)

#define COLUMNAR_FLAG_ARGS_0(Name, ...) __VA_ARGS__
#define COLUMNAR_FLAG_ARGS(...) COLUMNAR_FLAG_ARGS_0(__VA_ARGS__)

#define COLUMNAR_EVENT_FIRE_STATEMENT(Statement, ...) COLUMNAR_STATEMENT_NAME(Statement) (COLUMNAR_STATEMENT_EXPAND(Statement), __VA_ARGS__)

// hook: STRUCT_DEF
// Auto generated
#define COLUMNAR_EVENT_PRE_STRUCT_DEF__PRE_STRUCT_DEF(...) __VA_ARGS__ // COLUMNAR_EVENT_FIRE(__VA_ARGS__)
#define COLUMNAR_EVENT_PRE_STRUCT_DEF__POST_STRUCT_DEF(...) // no match

#define COLUMNAR_EVENT_POST_STRUCT_DEF__PRE_STRUCT_DEF(...) // no match
#define COLUMNAR_EVENT_POST_STRUCT_DEF__POST_STRUCT_DEF(...) __VA_ARGS__ // COLUMNAR_EVENT_FIRE(__VA_ARGS__)

#define COLUMNAR_EVENT_LOOKUP_0(FlagEvent, LookupEvent) COLUMNAR_EVENT ## _ ## LookupEvent ## __ ## FlagEvent // COLUMNAR_JOIN_UNDERSCORE_1(COLUMNAR_APPEND_UNDERSCORE(COLUMNAR_JOIN_UNDERSCORE_1(COLUMNAR_EVENT, LookupEvent)), FlagEvent)
#define COLUMNAR_EVENT_LOOKUP(...) COLUMNAR_EVENT_LOOKUP_0(__VA_ARGS__)

#define COLUMNAR_EVENT_FIRE_FROM_LIST(FlagEvent, LookupEvent, ...) \
    COLUMNAR_STATEMENT_MAP_EXT(COLUMNAR_EVENT_FIRE_STATEMENT, (__VA_ARGS__), COLUMNAR_EVENT_LOOKUP(FlagEvent, LookupEvent))

#define COLUMNAR_REGISTER_EVENT_IN_LIST(List, Event, ...) \
    COLUMNAR_STATEMENT_MAP_EXT_LV2(COLUMNAR_EVENT_FIRE_FROM_LIST, (Event, COLUMNAR_FLAG_ARGS(COLUMNAR_VA_ARGS_EXPAND List) __VA_ARGS__), COLUMNAR_FLAG_NAME(COLUMNAR_VA_ARGS_EXPAND List)())

#define COLUMNAR_STRUCT(ClsName, ClsDef, ...) \
    COLUMNAR_STATEMENT_MAP_EXT_LV3(COLUMNAR_REGISTER_EVENT_IN_LIST, (PRE_STRUCT_DEF, ClsName, COLUMNAR_STRIPFUNC(ClsDef),), __VA_ARGS__) \
    struct ClsName \
    { \
        COLUMNAR_DEF(COLUMNAR_VA_ARGS_EXPAND COLUMNAR_STRIPFUNC(ClsDef)) \
    }; \
    COLUMNAR_STATEMENT_MAP_EXT_LV3(COLUMNAR_REGISTER_EVENT_IN_LIST, (POST_STRUCT_DEF, ClsName, COLUMNAR_STRIPFUNC(ClsDef),), __VA_ARGS__)

#define COLUMNAR_CLASS(...)

#define COLUMNAR_GEN(...)
