# ============================================================================
# Python Package Initialization
# ============================================================================
# This file makes the C++ extension module importable as a Python package.
# 
# CUSTOMIZATION:
# 1. Replace '_CPP_Lib' with your C++ module name (must match CPP_MODULE_NAME 
#    from CMakeLists.txt, typically prefixed with underscore)
# 2. Replace 'hello' with the actual functions/classes you want to expose
# 3. Update __all__ to list all public API elements
# ============================================================================

# Import from the compiled C++ extension module
# The module name here should match CPP_MODULE_NAME from CMakeLists.txt
from ._CPP_Lib import CPP_Lib

# Define the public API of this package
# List all functions, classes, and variables that should be accessible
# when users do: from your_module import *
__all__ = ["CPP_Lib"]

# ============================================================================
# Optional: Add version information
# ============================================================================
# __version__ = "0.1.0"

# ============================================================================
# Optional: Import additional Python-side utilities
# ============================================================================
# If you have pure Python helper functions or classes, import them here:
# from .utilities import helper_function
# __all__.append("helper_function")