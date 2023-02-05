cmake_minimum_required(VERSION 3.19)
project(MOYFClient)

set(CMAKE_CXX_STANDARD 20)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(${PROJECT_NAME} main.cc)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        MOYFNetworking
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        MOYFNetworking
    PRIVATE
        Threads::Threads
)