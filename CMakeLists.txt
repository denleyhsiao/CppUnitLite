cmake_minimum_required(VERSION 3.0)

set(PROJ_NAME CppUnitLite)
set(PROJ_VERSION_MAJOR 0)
set(PROJ_VERSION_MINOR 1)
set(PROJ_VERSION ${PROJ_VERSION_MAJOR}.${PROJ_VERSION_MINOR})
project (${PROJ_NAME} VERSION ${PROJ_VERSION} LANGUAGES CXX)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

configure_file (
  "${PROJECT_SOURCE_DIR}/cmake/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )
option(BUILD_STATIC_LIBRARY "Build static library" ON)
option(ENABLE_MEMORYLEAKWARN "Open memory leak warn" ON)

include_directories("${CMAKE_SOURCE_DIR}/include/CppUnitLite"
  "${PROJECT_BINARY_DIR}"
  )
  
include("${PROJECT_SOURCE_DIR}/cmake/util.cmake")
getLibraryType(${BUILD_STATIC_LIBRARY} lib_type)
add_library(${PROJ_NAME} ${lib_type} "")
getMemoryLeakType(type)
target_sources(${PROJ_NAME}
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
  
install (TARGETS ${PROJ_NAME} DESTINATION lib)
install (DIRECTORY "${PROJECT_SOURCE_DIR}/include/"
           DESTINATION include)
           
include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE
  "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set (CPACK_PACKAGE_VERSION_MAJOR "${PROJ_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${PROJ_VERSION_MINOR}")
set(CPACK_SOURCE_IGNORE_FILES
  "~$"
  "^${PROJECT_SOURCE_DIR}/.DS_Store"
  "^${PROJECT_SOURCE_DIR}/.gitignore"
  "^${PROJECT_SOURCE_DIR}/.git/"
  "^${PROJECT_SOURCE_DIR}/build/"
  "^${PROJECT_SOURCE_DIR}/lib/"
  "^${PROJECT_SOURCE_DIR}/bin/"
)
include (CPack)

add_subdirectory(example)
