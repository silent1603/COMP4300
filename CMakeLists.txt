cmake_minimum_required(VERSION 3.28)
project(game LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.x
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

file(GLOB_RECURSE CPP_SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE HEADER_SOURCES ${CMAKE_SOURCE_DIR}/src/*.h)
add_executable(game)
source_group(TREE "${CMAKE_SOURCE_DIR}" PREFIX "" FILES ${CPP_SOURCES} ${HEADER_SOURCES})
target_sources(game PUBLIC ${CPP_SOURCES} ${HEADER_SOURCES})
target_include_directories(game PUBLIC ${CMAKE_SOURCE_DIR}/src)
target_compile_features(game PRIVATE cxx_std_17)
target_link_libraries(game PRIVATE SFML::Graphics SFML::System SFML::Window SFML::Network SFML::Audio SFML::Main)

add_custom_target(copy_data
	COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different 
        "${CMAKE_SOURCE_DIR}/data/"
        "$<TARGET_FILE_DIR:game>/data"
    COMMENT "Copying data"
)
add_dependencies(game copy_data)
