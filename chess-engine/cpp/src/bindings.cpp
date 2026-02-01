#include <pybind11/pybind11.h>
#include <pybind11/stl.h> // for vector, string, etc

#include "engine.hpp"

namespace py = pybind11;

PYBIND11_MODULE(chess_engine_cpp, m)
{
    m.doc() = "Chess engine Python Bindings"
}