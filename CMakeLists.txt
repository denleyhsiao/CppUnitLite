cmake_minimum_required(VERSION 3.0)
project(CppUnitLite
  VERSION 0.1.0
  DESCRIPTION "Cpp unit test library"
  LANGUAGES CXX
)

configure_file(
  "${PROJECT_SOURCE_DIR}/CppUnitLiteConfig.h.in"
  "${PROJECT_BINARY_DIR}/CppUnitLiteConfig.h"
)
option(BUILD_STATIC_LIBRARY "Build static library" ON)
option(ENABLE_MEMORYLEAKWARN "Open memory leak warn" ON)
include("${PROJECT_SOURCE_DIR}/cmake/util.cmake")
getLibraryType(${BUILD_STATIC_LIBRARY} lib_type)
getMemoryLeakType(type)

add_library(${PROJECT_NAME} ${lib_type})
target_include_directories(${PROJECT_NAME}
  PUBLIC
    "$<INSTALL_INTERFACE:include>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/CppUnitLite>"
    "${PROJECT_BINARY_DIR}"
)
target_sources(${PROJECT_NAME}
  PRIVATE
    "${PROJECT_SOURCE_DIR}/src/CommandLineTestRunner.cpp"
    "${PROJECT_SOURCE_DIR}/src/EqualsFailure.cpp"
    "${PROJECT_SOURCE_DIR}/src/Failure.cpp"
    "${PROJECT_SOURCE_DIR}/src/SimpleString.cpp"
    "${PROJECT_SOURCE_DIR}/src/Test.cpp"
    "${PROJECT_SOURCE_DIR}/src/TestDefaultConfig.cpp"
    "${PROJECT_SOURCE_DIR}/src/TestRegistry.cpp"
    "${PROJECT_SOURCE_DIR}/src/TestResult.cpp"
    "${PROJECT_SOURCE_DIR}/src/${type}MemoryLeakWarning.cpp"
)

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
  EXPORT ${PROJECT_NAME}Targets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
install(DIRECTORY "${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME}"
  DESTINATION include
  PATTERN "*.h"
)

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_SOURCE_IGNORE_FILES
  "~$"
  "^${PROJECT_SOURCE_DIR}/.DS_Store"
  "^${PROJECT_SOURCE_DIR}/.gitignore"
  "^${PROJECT_SOURCE_DIR}/.git/"
  "^${PROJECT_SOURCE_DIR}/build/"
)
include(CPack)

add_subdirectory(example)
