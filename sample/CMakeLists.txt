set(samples DequeTest StackTest TemplateDequeTest)
foreach(sample ${samples})
  project(${sample})
  include_directories("${CMAKE_SOURCE_DIR}/include")
  
  set(SOURCE_DIR)
  aux_source_directory("./${sample}/" SOURCE_DIR)
  add_executable(${sample} ${SOURCE_DIR})
  target_link_libraries(${sample} CppUnitLite)
endforeach(sample)

add_subdirectory(TestHarness)