cmake_minimum_required(VERSION 3.14)

project(ccnc VERSION 1.0)

# Set the C standard
set(CMAKE_C_STANDARD 99)

# Add the src and inc directories to the include path
include_directories(${PROJECT_SOURCE_DIR}/inc)

# Source files for the application
set(APP_SRC_FILES
    src/main.c
    src/parse_args.c
)
add_executable(${PROJECT_NAME} ${APP_SRC_FILES})

set(target_list)

# Add test executables
add_executable(test_parse_args test/test_parse_args.c src/parse_args.c)
list(APPEND target_list test_parse_args)

add_custom_target(test)

# Build a run target for each item in the list
foreach(TARGET_LIST_ITEM ${target_list})
  target_link_libraries(${TARGET_LIST_ITEM} cmocka)  
  add_custom_target(${TARGET_LIST_ITEM}_run
    COMMAND ${TARGET_LIST_ITEM}
  )
  add_dependencies(test ${TARGET_LIST_ITEM}_run)
endforeach(TARGET_LIST_ITEM ${target_list})



