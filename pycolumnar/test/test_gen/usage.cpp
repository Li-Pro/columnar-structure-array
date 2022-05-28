#include <columnar/metadef.hpp>
#include <columnar/ext/pycolumnar.hpp>

COLUMNAR_STRUCT( convertible,
    
    COLUMNAR_DEF(
        double, a_double,
        int, an_int,
        convertible*, a_pconvertible,
    ),
    
    PYCOLUMNAR_GEN_PYBIND11,
) ;
