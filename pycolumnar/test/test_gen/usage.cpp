#include <columnar/metadef.hpp>
#include <columnar/ext/pycolumnar.hpp>

COLUMNAR_STRUCT( convertible,
    
    DEF(
        double, a_double,
        int, an_int,
        convertible*, a_pconvertible,
    ),
    
    (PYCOLUMNAR_GEN_PYBIND11, libconvertible,),
)
