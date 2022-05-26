#include "metadef.hpp"

struct convertible
{
    COLUMNAR_DEF(
        double, a_double,
        int, an_int,
        convertible*, a_pconvertible,
    )
};
