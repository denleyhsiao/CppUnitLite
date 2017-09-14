set(sample TestHarness)

project(${sample})
set(SOURCE_DIR)
aux_source_directory(. SOURCE_DIR)
add_library(${sample} ${SOURCE_DIR})