set(PROJ_NAME DequeTest)
project(${PROJ_NAME})
include_directories("${CMAKE_SOURCE_DIR}/include")
aux_source_directory("${PROJ_NAME}/" SOURCE_DIR)
add_executable(${PROJ_NAME} ${SOURCE_DIR})
target_link_libraries(${PROJ_NAME} CppUnitLite)

install (TARGETS ${PROJ_NAME} DESTINATION bin)
