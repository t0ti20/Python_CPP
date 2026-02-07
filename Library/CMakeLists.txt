# ============================================================================
# CMake Configuration for Python C++ Extension Module
# ============================================================================
# This is a generic template for building Python extension modules using 
# pybind11. Customize the variables in the "Project Configuration" section
# to adapt this template to your specific project.
# ============================================================================

cmake_minimum_required(VERSION 3.15)

# ============================================================================
# Project Configuration
# ============================================================================
# Customize these variables for your project:

# Set your project name (used for CMake project and default module name)
set(PROJECT_NAME "CPP_Lib")

# Set your Python module name (the name users will import in Python)
# If not set, defaults to PROJECT_NAME
set(PYTHON_MODULE_NAME "${PROJECT_NAME}")

# Set the internal C++ module name (typically prefixed with underscore)
# This is the actual .so/.pyd file that will be generated
set(CPP_MODULE_NAME "_${PYTHON_MODULE_NAME}")

# Set C++ standard version (11, 14, 17, 20, etc.)
set(CPP_STANDARD 17)

# Define source and include directories
set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/inc")
set(PYTHON_WRAPPER_DIR "${CMAKE_CURRENT_SOURCE_DIR}/python/${PYTHON_MODULE_NAME}")

# ============================================================================
# Project Declaration
# ============================================================================
project(${PROJECT_NAME} LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD ${CPP_STANDARD})
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

message(STATUS "==============================================")
message(STATUS "Building: ${PROJECT_NAME}")
message(STATUS "Python module: ${PYTHON_MODULE_NAME}")
message(STATUS "C++ module: ${CPP_MODULE_NAME}")
message(STATUS "C++ standard: C++${CPP_STANDARD}")
message(STATUS "==============================================")

# ============================================================================
# Find Required Dependencies
# ============================================================================

# Find Python interpreter and development files
find_package(Python3 REQUIRED COMPONENTS Interpreter Development)
message(STATUS "Python executable: ${Python3_EXECUTABLE}")
message(STATUS "Python version: ${Python3_VERSION}")

# Locate pybind11 CMake configuration
execute_process(
    COMMAND ${Python3_EXECUTABLE} -m pybind11 --cmakedir
    OUTPUT_VARIABLE pybind11_DIR
    OUTPUT_STRIP_TRAILING_WHITESPACE
    RESULT_VARIABLE PYBIND11_RESULT
)

# Check if pybind11 was found
if(NOT PYBIND11_RESULT EQUAL 0)
    message(FATAL_ERROR "pybind11 not found. Install it via: pip install pybind11")
endif()

find_package(pybind11 CONFIG REQUIRED)
message(STATUS "pybind11 found at: ${pybind11_DIR}")

# ============================================================================
# Collect Source Files
# ============================================================================

# Recursively find all .cpp files under the source directory
file(GLOB_RECURSE CPP_SOURCES "${SOURCE_DIR}/*.cpp")

if(NOT CPP_SOURCES)
    message(WARNING "No C++ source files found in ${SOURCE_DIR}")
endif()

message(STATUS "Found This C++ source files:")
foreach(source ${CPP_SOURCES})
    message(STATUS "  - ${source}")
endforeach()

# ============================================================================
# Collect Header Files and Directories
# ============================================================================

# Recursively find all header files (.h and .hpp) under the include directory
file(GLOB_RECURSE HEADER_FILES 
    "${INCLUDE_DIR}/*.h" 
    "${INCLUDE_DIR}/*.hpp"
)

# Extract unique directories from the header files
# This allows nested include directory structures
set(HEADER_DIRS "")
foreach(header_file ${HEADER_FILES})
    get_filename_component(header_dir ${header_file} DIRECTORY)
    list(APPEND HEADER_DIRS ${header_dir})
endforeach()

# Remove duplicate directories
list(REMOVE_DUPLICATES HEADER_DIRS)

message(STATUS "Header include directories:")
foreach(dir ${HEADER_DIRS})
    message(STATUS "  - ${dir}")
endforeach()

# ============================================================================
# Build the Python Extension Module
# ============================================================================

# Create the pybind11 extension module
# This automatically handles Python-specific compilation flags
pybind11_add_module(${CPP_MODULE_NAME} ${CPP_SOURCES})

# Add include directories to the target
# PRIVATE means these includes are only used when building this target
target_include_directories(${CPP_MODULE_NAME} PRIVATE ${HEADER_DIRS})

# Optional: Add compile options for warnings and optimizations
# Uncomment and customize as needed:
# target_compile_options(${CPP_MODULE_NAME} PRIVATE
#     $<$<CXX_COMPILER_ID:MSVC>:/W4>
#     $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -pedantic>
# )

# Optional: Link additional libraries if needed
# target_link_libraries(${CPP_MODULE_NAME} PRIVATE your_library_here)

# ============================================================================
# Installation Configuration
# ============================================================================

# Automatically detect Python site-packages installation path
execute_process(
    COMMAND ${Python3_EXECUTABLE} -c "import site; print(site.getsitepackages()[0])"
    OUTPUT_VARIABLE PYTHON_SITE_PACKAGES
    OUTPUT_STRIP_TRAILING_WHITESPACE
    RESULT_VARIABLE SITE_PACKAGES_RESULT
)

if(NOT SITE_PACKAGES_RESULT EQUAL 0)
    message(FATAL_ERROR "Failed to detect Python site-packages directory")
endif()

# Define the installation path for the module
set(MODULE_INSTALL_DIR "${PYTHON_SITE_PACKAGES}/${PYTHON_MODULE_NAME}")

message(STATUS "Installation target: ${MODULE_INSTALL_DIR}")

# Install the compiled C++ extension module (.so on Linux/Mac, .pyd on Windows)
install(TARGETS ${CPP_MODULE_NAME}
        LIBRARY DESTINATION ${MODULE_INSTALL_DIR}
        RUNTIME DESTINATION ${MODULE_INSTALL_DIR}  # For Windows .pyd files
)

# Install the Python wrapper __init__.py file
# This makes the module importable as a Python package
install(FILES "${PYTHON_WRAPPER_DIR}/__init__.py"
        DESTINATION ${MODULE_INSTALL_DIR}
)

# Optional: Install additional Python files if they exist
# file(GLOB PYTHON_FILES "${PYTHON_WRAPPER_DIR}/*.py")
# install(FILES ${PYTHON_FILES} DESTINATION ${MODULE_INSTALL_DIR})

# ============================================================================
# Summary
# ============================================================================
message(STATUS "==============================================")
message(STATUS "Configuration complete!")
message(STATUS "Build command: cmake --build .")
message(STATUS "Install command: cmake --install .")
message(STATUS "==============================================")