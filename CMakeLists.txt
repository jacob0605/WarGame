cmake_minimum_required(VERSION 3.15)
project(MyGameProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# include 및 src 디렉토리 추가
include_directories(${PROJECT_SOURCE_DIR}/include)

# src 디렉토리의 소스 파일 수집
file(GLOB_RECURSE SOURCES "src/*.cpp")

# 정적 라이브러리 생성
add_library(WarGame2 STATIC ${SOURCES})

# 테스트 디렉토리 추가
enable_testing()
add_subdirectory(tests)
