// ============================================================================
// Python C++ Extension Module - pybind11 Bindings
// ============================================================================
// This file defines the Python bindings for your C++ library using pybind11.
//
// CUSTOMIZATION GUIDE:
// 1. Replace "_CPP_Lib" with your C++ module name (must match CPP_MODULE_NAME 
//    from CMakeLists.txt, typically prefixed with underscore)
// 2. Replace "CPP_Lib" with your main function name
// 3. Update include headers to match your C++ classes/functions
// 4. Add bindings for all functions, classes, and enums you want to expose
// ============================================================================

#include <pybind11/pybind11.h>

// ============================================================================
// Include Your C++ Headers
// ============================================================================
// CHANGE THIS: Include your project's header files
#include "Counter.hpp"

// Optional: Include additional pybind11 headers for specific features
// #include <pybind11/stl.h>        // Automatic conversion for STL containers
// #include <pybind11/numpy.h>      // NumPy array support
// #include <pybind11/functional.h> // std::function support
// #include <pybind11/chrono.h>     // std::chrono support

// Namespace alias for convenience
namespace py = pybind11;

// ============================================================================
// C++ Function Implementations
// ============================================================================
// CHANGE THIS: Replace with your actual C++ functions

/**
 * @brief Main C++ library function
 * 
 * @param maxNumber Maximum number to count to
 * @param debugEnable Enable debug output
 * @return int Status code (0 for success)
 */
int CPP_Lib(int maxNumber, bool debugEnable)
{
    // Create a Counter to count up to maxNumber with debug enabled
    Counter counter(maxNumber, debugEnable);
    counter.startCounting();

    return 0;
}

// ============================================================================
// Additional C++ Functions (Examples)
// ============================================================================
// Add more functions here that you want to expose to Python

// Example: Simple function
// int add(int a, int b) {
//     return a + b;
// }

// Example: Function with default arguments
// double compute(double x, double y = 1.0) {
//     return x * y;
// }

// Example: Function returning a vector
// std::vector<int> get_numbers(int count) {
//     std::vector<int> result;
//     for(int i = 0; i < count; ++i) {
//         result.push_back(i);
//     }
//     return result;
// }

// ============================================================================
// Python Module Definition
// ============================================================================
// CHANGE THIS: Replace "_CPP_Lib" with your module name
// This name MUST match CPP_MODULE_NAME in CMakeLists.txt

PYBIND11_MODULE(_CPP_Lib, m) {
    // Module docstring (shown in Python when doing help(module))
    m.doc() = "C++ Library Python Extension Module";

    // ========================================================================
    // Function Bindings
    // ========================================================================
    // CHANGE THIS: Replace "CPP_Lib" with your function names
    
    // Basic function binding
    m.def("CPP_Lib", 
          &CPP_Lib, 
          "Run the counter with given parameters",
          py::arg("maxNumber"),      // Named argument
          py::arg("debugEnable")     // Named argument
    );

    // ========================================================================
    // Additional Function Binding Examples
    // ========================================================================
    
    // Example: Function with default arguments
    // m.def("add", 
    //       &add, 
    //       "Add two integers",
    //       py::arg("a"), 
    //       py::arg("b")
    // );

    // Example: Function with default parameter values
    // m.def("compute", 
    //       &compute, 
    //       "Compute x * y",
    //       py::arg("x"), 
    //       py::arg("y") = 1.0  // Default value
    // );

    // Example: Function with keyword-only arguments
    // m.def("get_numbers",
    //       &get_numbers,
    //       "Generate a list of numbers",
    //       py::arg("count")
    // );

    // ========================================================================
    // Class Bindings
    // ========================================================================
    // CHANGE THIS: Add bindings for your C++ classes
    
    // Example: Binding the Counter class
    // py::class_<Counter>(m, "Counter", "A counter class")
    //     .def(py::init<int, bool>(), 
    //          py::arg("maxNumber"), 
    //          py::arg("debugEnable") = false)
    //     .def("startCounting", 
    //          &Counter::startCounting, 
    //          "Start counting")
    //     .def("getCount", 
    //          &Counter::getCount, 
    //          "Get current count")
    //     .def_readwrite("maxNumber", 
    //                    &Counter::maxNumber, 
    //                    "Maximum number to count to");

    // ========================================================================
    // Enum Bindings
    // ========================================================================
    
    // Example: Binding an enum
    // py::enum_<YourEnum>(m, "YourEnum", "Enum description")
    //     .value("VALUE1", YourEnum::VALUE1, "First value")
    //     .value("VALUE2", YourEnum::VALUE2, "Second value")
    //     .export_values();  // Make values accessible as module.VALUE1

    // ========================================================================
    // Constants and Variables
    // ========================================================================
    
    // Example: Module-level constants
    // m.attr("PI") = 3.14159265358979323846;
    // m.attr("VERSION") = "0.1.0";
    // m.attr("MAX_SIZE") = 1000;

    // ========================================================================
    // Exception Bindings
    // ========================================================================
    
    // Example: Custom exception binding
    // py::register_exception<YourCustomException>(m, "YourCustomException");

    // ========================================================================
    // Submodules
    // ========================================================================
    
    // Example: Creating a submodule
    // py::module_ sub = m.def_submodule("submodule", "Submodule description");
    // sub.def("sub_function", &sub_function, "Submodule function");
}

// ============================================================================
// QUICK REFERENCE GUIDE
// ============================================================================
// 
// Common pybind11 Patterns:
//
// 1. FUNCTION BINDING:
//    m.def("func_name", &func_name, "docstring", py::arg("param1"));
//
// 2. CLASS BINDING:
//    py::class_<ClassName>(m, "ClassName", "docstring")
//        .def(py::init<Type1, Type2>())
//        .def("method", &ClassName::method);
//
// 3. PROPERTY BINDING:
//    .def_readwrite("var", &ClassName::var)     // Read-write property
//    .def_readonly("var", &ClassName::var)      // Read-only property
//    .def_property("var", &getter, &setter)     // Custom getter/setter
//
// 4. OPERATOR OVERLOADING:
//    .def(py::self + py::self)                  // operator+
//    .def("__repr__", &ClassName::toString)     // str() representation
//
// 5. NUMPY ARRAYS:
//    py::array_t<double> for numpy arrays (requires #include <pybind11/numpy.h>)
//
// 6. STL CONTAINERS:
//    Automatic conversion (requires #include <pybind11/stl.h>)
//
// For more details, see: https://pybind11.readthedocs.io/
// ============================================================================