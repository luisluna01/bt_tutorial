# Specify the minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(bt_tutorial)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the installed BehaviorTree.CPP package
find_package(behaviortree_cpp REQUIRED)

# Include project headers
include_directories(include)

# Collect all behavior implementation files
file(GLOB BEHAVIOR_SOURCES "src/behaviors/*.cpp")

# Automatically collect all .cpp files inside src/tutorials
file(GLOB_RECURSE TUTORIAL_SOURCES CONFIGURE_DEPENDS "src/tutorials/*.cpp")

# Create one executable for each cpp file
foreach(TUTORIAL ${TUTORIAL_SOURCES})
    # Get filename without path and extension
    get_filename_component(FILENAME ${TUTORIAL} NAME_WE)

    # Define a target name based on the file
    set(TARGET_NAME "${FILENAME}_exec")

    # Create the executable
    add_executable(${TARGET_NAME} ${TUTORIAL} ${BEHAVIOR_SOURCES})

    # Link against BehaviorTree.CPP
    target_link_libraries(${TARGET_NAME} PRIVATE behaviortree_cpp::behaviortree_cpp)
endforeach()

# Copy XML files to build directory
file(GLOB XML_FILES "src/tutorials/*/*.xml")
foreach(XML_FILE ${XML_FILES})
    get_filename_component(XML_NAME ${XML_FILE} NAME)
    configure_file(${XML_FILE} ${CMAKE_BINARY_DIR}/${XML_NAME} COPYONLY)
endforeach()
