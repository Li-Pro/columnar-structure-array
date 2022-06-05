# pycolumnar

## API model
- C++
    - libcolumnar extension
        - pybind11 generation flag: PYCOLUMNAR_GEN_PYBIND11

## Sample
```cpp
COLUMNAR_STRUCT( convertible,
    
    DEF(
        double, a_double,
        int, an_int,
        convertible*, a_pconvertible,
    ),
    
    (PYCOLUMNAR_GEN_PYBIND11, libconvertible,),
)
```