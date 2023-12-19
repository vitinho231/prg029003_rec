cmake_minimum_required(VERSION 3.26)

project(Lib_HashTable LANGUAGES C)

set(CMAKE_C_STANDARD 17)

add_library(Lib_HashTable
        main.c
        hash_pessoa.c
        hash_pessoa.h
        AnaliseTempo.h)

target_include_directories(Lib_HashTable PUBLIC include)

add_executable(Exec_HashTable main.c)
target_link_libraries(Exec_HashTable PRIVATE Lib_HashTable)

add_executable(Test_HashTable test_hash_pessoa.c)
target_link_libraries(Test_HashTable PRIVATE Lib_HashTable)

enable_testing()

add_test(
        NAME Test_HashTable
        COMMAND $<TARGET_FILE:Test_HashTable>
)

