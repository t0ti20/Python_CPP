# Python C++ Extension Library

A minimal yet professional template to build Python extension modules with C++ using **pybind11** and **CMake**. This repository demonstrates how to integrate C++ logic into Python, providing a high-performance module ready for development and testing.

---

## 📂 Repository Structure

```

Python_CPP/
    ├── Hello.py                    # Example usage script
    ├── Library                     # Main library directory
    │   ├── CMakeLists.txt          # CMake build configuration
    │   ├── inc                     # C++ headers
    │   │   └── Counter.hpp         # Class/function declarations
    │   ├── pyproject.toml          # Python package metadata
    │   ├── python                  # Python package wrapper
    │   │   └── CPP_Lib
    │   │       └── __init__.py     # Python package initialization
    │   └── src                     # C++ source files
    │       ├── Counter.cpp         # C++ implementation
    │       └── Main.cpp            # pybind11 bindings
    └── README.md
```
---

## ⚙️ Features

- Expose C++ code directly to Python via **pybind11**
- Build system powered by **CMake**
- Cross-platform support (Linux/macOS/Windows)
- Editable development mode
- Example script included (`Hello.py`)  

---

## 🛠 Installation

### 1. Standard Install
```bash
cd Library
mkdir -p build && cd build
cmake ..
make
cmake --install .
```

## 💻 Usage

```python
import CPP_Lib

# Call the exposed C++ function
# Arguments: maxNumber (int), debugEnable (bool)
CPP_Lib.CPP_Lib(10, True)
```

### Example with Error Handling

```python
import CPP_Lib

def main():
    try:
        result = CPP_Lib.CPP_Lib(maxNumber=10, debugEnable=True)
        print("Success" if result == 0 else f"Returned code: {result}")
    except Exception as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    main()
```

---

## 🛠 Development Workflow

1. Edit C++ logic in `src/` and headers in `inc/`
2. Update pybind11 bindings in `src/Main.cpp`
3. Rebuild: `cmake && makes` inside `Library/`
4. Test with `Hello.py` or your own scripts

---

## 📌 Notes

* The compiled extension module is placed in `Library/build/`
* Python package is available under `CPP_Lib`
* Use `help(CPP_Lib)` in Python to explore functions

---

## 📜 License

This template is open for adaptation and use in your own projects.

