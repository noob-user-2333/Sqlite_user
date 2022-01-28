cmake_minimum_required(VERSION 3.21)
project(sqlite_use)

set(CMAKE_CXX_STANDARD 14)

add_executable(sqlite_use main.cpp Sqlite.h Sqlite.cpp sqlite3.c sqlite3.h SqliteData.h)

target_link_libraries(${CMAKE_PROJECT_NAME} pthread)
target_link_libraries(${CMAKE_PROJECT_NAME} dl)
