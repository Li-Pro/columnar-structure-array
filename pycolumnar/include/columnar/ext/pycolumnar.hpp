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

#define PYCOLUMNAR_GEN_PYBIND11(...) \
    POST_STRUCT_DEF( \
        DO(PYCOLUMNAR_PYBIND11_PRE), \
        DO( PYCOLUMNAR_PYBIND11_CLASS ), \
         \
    )
