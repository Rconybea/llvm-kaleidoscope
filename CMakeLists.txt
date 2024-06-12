# medici/CMakeLists.txt

cmake_minimum_required(VERSION 3.10)

project(medici VERSION 1.0)

include(GNUInstallDirs)
include(cmake/xo-bootstrap-macros.cmake)

xo_cxx_toplevel_options3()

# ----------------------------------------------------------------
# c++ settings

# one-time project-specific c++ flags.  usually empty
#set(PROJECT_CXX_FLAGS "-Wstringop-overread")
#set(PROJECT_CXX_FLAGS "-fconcepts-diagnostics-depth=2")
add_definitions(${PROJECT_CXX_FLAGS})

# ----------------------------------------------------------------

# config.h.in <-> medici_sys library.
# Other libraries will explicitly depend on medici_sys
#
#configure_file(config.h.in ${PROJECT_BINARY_DIR}/include/xo/medici_sys/config.h)

# ----------------------------------------------------------------

set(SELF_EXE kaleidoscope)
set(SELF_SRCS kaleidoscope3.cpp)

xo_add_executable(${SELF_EXE} ${SELF_SRCS})
#xo_headeronly_dependency(${SELF_EXE} xxx)
#xo_dependency(${SELF_EXE} xxx)

#add_subdirectory(sys)
#add_subdirectory(example)
#add_subdirectory(utest)

# llvm dependency a bit non-standard

find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
message(STATUS "LLVM_DIR=${LLVM_DIR}")
message(STATUS "LLVM_DEFINITIONS=${LLVM_DEFINITIONS}")
message(STATUS "LLVM_INCLUDE_DIRS=[${LLVM_INCLUDE_DIRS}]")

separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})

message(STATUS "LLVM_DEFINITIONS_LIST=[${LLVM_DEFINITIONS_LIST}]")

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS_LIST})

# Now build our tools
#add_executable(simple-tool tool.cpp)

# Find the libraries that correspond to the LLVM components
# that we wish to use
llvm_map_components_to_libnames(llvm_libs support core irreader)

# Link against LLVM libraries
target_link_libraries(${SELF_EXE} ${llvm_libs})

# ----------------------------------------------------------------
# docs targets depend on all the other library/utest targets
#
#add_subdirectory(docs)

# ----------------------------------------------------------------
# dependencies

# for some reason,  this doesn't reliably bring in xo_flatstring dependency
#xo_headeronly_dependency(${SELF_LIB} xo_ratio)
#xo_headeronly_dependency(${SELF_LIB} xo_flatstring)
