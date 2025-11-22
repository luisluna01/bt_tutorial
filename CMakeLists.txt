# Specify the minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(bt_training)

# Set BehaviorTree.CPP source and build directories
set(BT_CPP_DIR "${CMAKE_SOURCE_DIR}/../BehaviorTree.CPP")
set(BT_CPP_BUILD "${BT_CPP_DIR}/build")

# Include headers
include_directories(${BT_CPP_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/include)

# Link directories (if there are compiled static/dynamic libs)
link_directories(${BT_CPP_BUILD})

# Automatically collect all .cpp files inside src/tutorials
file(GLOB_RECURSE TUTORIAL_SOURCES CONFIGURE_DEPENDS "src/tutorials/*.cpp")

# Create one executable for each cpp file
foreach(TUTORIAL ${TUTORIAL_SOURCES})
    # Get filename without path and extension
    get_filename_component(FILENAME ${TUTORIAL} NAME_WE)

    # Define a target name based on the file
    set(TARGET_NAME "${FILENAME}_exec")

    # Create the executable
    add_executable(${TARGET_NAME} ${TUTORIAL})

    # Link against BehaviorTree.CPP
    target_link_libraries(${TARGET_NAME} PRIVATE behaviortree_cpp)
endforeach()
