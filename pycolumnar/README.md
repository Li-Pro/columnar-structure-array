# pycolumnar

## API model
- Python
    - Tuple array
        - class `colist`
    - Tuple binding helper
        - class `named_tuple`
    - Prebuild named tuple types
        - common
            - 2 elements of some fundamental types: `pair`
            - 3 elements of some fundamental types: `triple`
            - 4 elements of some fundamental types: `quad`
            - 5 elements of some fundamental types: `quint`
        - geometry
            - 2 elements of **single** fundamental numeric type: `vec2`
            - 3 elements of **single** fundamental numeric type: `vec3`
            - 4 elements of **single** fundamental numeric type: `vec2pair`
            - 6 elements of **single** fundamental numeric type: `vec3pair`, `vec2triple`
            - 9 elements of **single** fundamental numeric type: `vec3triple`
    - Prebuild base tuple types
        - any type
            - 2 elements of some fundamental types: `tup2`
            - 3 elements of some fundamental types: `tup3`
            - 4 elements of some fundamental types: `tup4`
            - 5 elements of some fundamental types: `tup5`
        - single type
            - 2 elements of **single** fundamental numeric type: `unitup2`
            - 3 elements of **single** fundamental numeric type: `unitup3`
            - 4 elements of **single** fundamental numeric type: `unitup4`
            - 5 elements of **single** fundamental numeric type: `unitup5`
            - 6 elements of **single** fundamental numeric type: `unitup6`
            - 7 elements of **single** fundamental numeric type: `unitup7`
            - 8 elements of **single** fundamental numeric type: `unitup8`
            - 9 elements of **single** fundamental numeric type: `unitup9`
    - Tuple generator (static, requires compilation)
        - base class `base_tuple`
- C++
    - tuple generator
    - libcolumnar extension
        - pybind11 generation flag: PYCOLUMNAR_GEN_PYBIND11

## Sample
```
from columnar  import colist, named_tuple, pair

x = colist(pair(int, float))

x.append((3, .141592))
x.append((1, .414214))
x.append((2, .718281))
print(x)  # [(3, 0.141592), (1, 0.414214), (2, 0.718281)]

class TupleBasedType(named_tuple):
    x = _tuple_args(float)
    y = _tuple_args(float)

t = TupleBasedType()
print(t)  # (0.0, 0.0)

t.x = 3.0
t.y = 2.0
print(t)  # (3.0, 2.0)

tuplist = colist(TupleBasedType)
tuplist.append(t)
tuplist.append((2.0, 3.0))
print(t)  # [(3.0, 2.0), (2.0, 3.0)]
```
