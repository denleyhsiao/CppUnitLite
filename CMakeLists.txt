cmake_minimum_required(VERSION 3.0)

set(PROJ_NAME CppUnitLite)
set(PROJ_VERSION_MAJOR 1)
set(PROJ_VERSION_MINOR 2)
set(PROJ_VERSION ${PROJ_VERSION_MAJOR}.${PROJ_VERSION_MINOR})
project (${PROJ_NAME} VERSION ${PROJ_VERSION} LANGUAGES CXX)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

include_directories("${CMAKE_SOURCE_DIR}/include/CppUnitLite"
  "${PROJECT_BINARY_DIR}"
  )
add_library(${PROJ_NAME} "")

target_sources(${PROJ_NAME}
  PRIVATE
  "${PROJECT_SOURCE_DIR}/src/Test.cpp"
  "${PROJECT_SOURCE_DIR}/src/TestRegistry.cpp"
  "${PROJECT_SOURCE_DIR}/src/TestResult.cpp"
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
