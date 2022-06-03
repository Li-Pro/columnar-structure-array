/**
 * @author Chris Chou (chris.chou.c@nycu.edu.tw)
 * @brief basic columnar def
 * @date 2022-05-28
 * 
 * @copyright Copyright (c) 2022 Li-Pro
 */

#pragma once

#include <columnar/metadef.hpp>

#include <pybind11/pybind11.h>

// #define PYCOLUMNAR_PYBIND11_CLASS_PRE
// #define PYCOLUMNAR_PYBIND11_CLASS_LOOP
// #define PYCOLUMNAR_PYBIND11_CLASS_POST

// #define PYCOLUMNAR_PYBIND11_CLASS(...) \
//     FOREACH( \
//         PYCOLUMNAR_PYBIND11_PRE, \
//     ),

#define PYCOLUMNAR_PYBIND11_PRE(Libname, ClsName, ClsDef) \
    PYBIND11_MODULE(Libname, Libname) {

#define PYCOLUMNAR_PYBIND11_POST(Libname, ClsName, ClsDef) \
    }

#define PYCOLUMNAR_PYBIND11_CLASS_FIELD(Type, Name, ClsName, ...) \
    .def_readwrite(#Name, &ClsName::Name)

#define PYCOLUMNAR_PYBIND11_CLASS(Libname, ClsName, ClsDef) \
    auto py_columnar_class = \
        pybind11::class_<ClsName>(Libname, #ClsName) \
            COLUMNAR_STATEMENT_FOREACH2(ClsDef, PYCOLUMNAR_PYBIND11_CLASS_FIELD, ClsName) \
    ;

#define PYCOLUMNAR_PYBIND11_ARRAY_CLASS(Libname, ClsName, ClsDef) \
    auto py_columnar_array_class = \
        pybind11::class_<ClsName::array_t>(py_columnar_class, "array_t") \
            .def_readonly("size", &ClsName::array_t::size) \
            .def("__getitem__", &ClsName::array_t::operator[]) \
    ;

#define PYCOLUMNAR_PYBIND11_HANDLE_CLASS_FIELD(Type, Name, ClsName, ...) \
    .def(#Name, &ClsName::handle_t::Name, pybind11::return_value_policy::reference)

#define PYCOLUMNAR_PYBIND11_HANDLE_CLASS(Libname, ClsName, ClsDef) \
    auto py_columnar_handle_class = \
        pybind11::class_<ClsName::handle_t>(py_columnar_class, "handle_t") \
            COLUMNAR_STATEMENT_FOREACH2(ClsDef, PYCOLUMNAR_PYBIND11_HANDLE_CLASS_FIELD, ClsName) \
    ;

#define PYCOLUMNAR_PYBIND11(Libname, ClsName, ClsDef, ...) \
    PYCOLUMNAR_PYBIND11_PRE(Libname, ClsName, ClsDef) \
    PYCOLUMNAR_PYBIND11_CLASS(Libname, ClsName, ClsDef) \
    PYCOLUMNAR_PYBIND11_ARRAY_CLASS(Libname, ClsName, ClsDef) \
    PYCOLUMNAR_PYBIND11_HANDLE_CLASS(Libname, ClsName, ClsDef) \
    PYCOLUMNAR_PYBIND11_POST(Libname, ClsName, ClsDef)

#define PYCOLUMNAR_GEN_PYBIND11(...) \
    POST_STRUCT_DEF( \
        DO(PYCOLUMNAR_PYBIND11), \
    ),
