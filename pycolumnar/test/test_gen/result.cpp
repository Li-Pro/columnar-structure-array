#include <columnar/metadef.hpp>
#include <columnar/ext/pycolumnar.hpp>

struct convertible
{
    COLUMNAR_DEF(
        double, a_double,
        int, an_int,
        convertible*, a_pconvertible,
    )
};

PYBIND11_MODULE(libconvertible, libconvertible) {
    auto py_columnar_class = \
        pybind11::class_<convertible>(libconvertible, "convertible")
            .def_readwrite("a_double", &convertible::a_double)
            .def_readwrite("an_int", &convertible::an_int)
            .def_readwrite("a_pconvertible", &convertible::a_pconvertible)
    ;
    
    auto py_columnar_array_class = \
        pybind11::class_<convertible::array_t>(py_columnar_class, "array_t")
            .def_readonly("size", &convertible::array_t::size)
            .def("__getitem__", &convertible::array_t::operator[])
    ;

    auto py_columnar_handle_class = \
        pybind11::class_<convertible::handle_t>(py_columnar_class, "handle_t")
            .def("a_double", &convertible::handle_t::a_double, pybind11::return_value_policy::reference)
            .def("an_int", &convertible::handle_t::an_int, pybind11::return_value_policy::reference)
            .def("a_pconvertible", &convertible::handle_t::a_pconvertible, pybind11::return_value_policy::reference)
    ;
}
