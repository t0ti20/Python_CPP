# ============================================================================
# Python Usage Example - C++ Extension Module
# ============================================================================
# This script demonstrates how to use the C++ extension module from Python.
#
# WHAT'S HAPPENING:
# 1. Python imports the package "CPP_Lib" (the Python package name)
# 2. Inside that package, Python loads the compiled C++ module "_CPP_Lib.so"
#    (or "_CPP_Lib.pyd" on Windows)
# 3. The __init__.py file in the CPP_Lib package exposes the C++ functions
# 4. We can then call C++ functions as if they were native Python functions
#
# NAMING CONVENTION:
# - Package name (Python): "CPP_Lib" (what you import)
# - C++ module name: "_CPP_Lib" (the compiled .so/.pyd file, with underscore)
# - Function name: "CPP_Lib" (the actual function from C++)
#
# CUSTOMIZATION:
# Replace "CPP_Lib" with your package/function names throughout
# ============================================================================

# ============================================================================
# Import the C++ Extension Module
# ============================================================================
# CHANGE THIS: Replace "CPP_Lib" with your package name (from pyproject.toml)
# This imports the Python package, which internally loads the C++ extension
import CPP_Lib

# Alternative import styles:
# from CPP_Lib import CPP_Lib  # Import specific function
# import CPP_Lib as cpp        # Import with alias


# ============================================================================
# Alternative Calling Patterns
# ============================================================================

# Using keyword arguments (more explicit and readable)
# CPP_Lib.CPP_Lib(maxNumber=10, debugEnable=True)

# Using keyword arguments in different order
# CPP_Lib.CPP_Lib(debugEnable=True, maxNumber=10)

# Mixing positional and keyword arguments
# CPP_Lib.CPP_Lib(10, debugEnable=True)

# ============================================================================
# Working with Return Values
# ============================================================================

# Capture the return value (if the C++ function returns something)
# result = CPP_Lib.CPP_Lib(10, True)
# print(f"Function returned: {result}")

# ============================================================================
# Error Handling
# ============================================================================

# Wrap C++ calls in try-except to handle exceptions
# try:
#     CPP_Lib.CPP_Lib(10, True)
# except Exception as e:
#     print(f"Error occurred: {e}")

# ============================================================================
# Type Checking and Validation
# ============================================================================

# Python will automatically convert compatible types
# CPP_Lib.CPP_Lib(10, True)      # Correct types
# CPP_Lib.CPP_Lib(10, 1)         # int converted to bool automatically
# CPP_Lib.CPP_Lib(10.5, True)    # float converted to int automatically

# But incompatible types will raise TypeError:
# CPP_Lib.CPP_Lib("10", True)    # TypeError: incompatible function arguments

# ============================================================================
# Getting Help
# ============================================================================

# View module documentation
# print(help(CPP_Lib))

# View function documentation
# print(help(CPP_Lib.CPP_Lib))

# List all available functions in the module
# print(dir(CPP_Lib))

# ============================================================================
# Complete Example with Best Practices
# ============================================================================

def main():
    """
    Main function demonstrating best practices for using C++ extensions.
    """
    # Configuration parameters
    max_count = 10
    enable_debug = True
    
    try:
        # Call the C++ function with clear, named arguments
        result = CPP_Lib.CPP_Lib(
            maxNumber=max_count,
            debugEnable=enable_debug
        )
        
        # Handle the result
        if result == 0:
            print("Counter executed successfully!")
        else:
            print(f"Counter returned code: {result}")
            
    except TypeError as e:
        print(f"Type error: {e}")
        print("Make sure arguments are of correct type (int, bool)")
        
    except Exception as e:
        print(f"Unexpected error: {e}")


if __name__ == "__main__":
    main()