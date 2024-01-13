# CMakeList.txt : CMake project for MOS, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

set(PROJECT_NAME	"Minecraft_Open_Source")
set(EXECUTABLE_NAME "MinecraftOS")
set(GLFW_DIR		"external/glfw")
set(GLM_DIR			"external/glm")

project (${PROJECT_NAME})

# Add source to this project's executable.
add_executable (${EXECUTABLE_NAME} "src/main.cpp" )


find_package(Vulkan REQUIRED)
target_include_directories(${EXECUTABLE_NAME} PRIVATE ${Vulkan_INCLUDE_DIRS})
target_link_libraries(${EXECUTABLE_NAME} ${Vulkan_LIBRARIES})

set(GLFW_BUILD_DOCS		OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS	OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(${GLFW_DIR})
target_link_libraries(${EXECUTABLE_NAME} glfw)

add_subdirectory(${GLM_DIR})
target_link_libraries(${EXECUTABLE_NAME} glm)



if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${EXECUTABLE_NAME} PROPERTY CXX_STANDARD 20)
endif()
# TODO: Add tests and install targets if needed.
