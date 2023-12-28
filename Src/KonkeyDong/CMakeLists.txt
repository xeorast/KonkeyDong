# CMakeList.txt : CMake project for KonkeyDong, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.12)

# Add source to this project's executable.
add_executable (KonkeyDong "Main.cpp" "Components/Graphics.hpp" "Components/Graphics.cpp" "Components/Window.hpp" "Components/Window.cpp" "Components/Texture.hpp" "Components/Texture.cpp" "Components/Timer.hpp" "Components/Timer.cpp" "Data/Time.hpp" "GameObjects/Entity.hpp" "GameObjects/Entity.cpp" "Data/Vec2.hpp" "Utils.h" "Components/Keyboard.hpp" "Components/Keyboard.cpp" "Data/Queue.hpp")

set_property(TARGET KonkeyDong PROPERTY CXX_STANDARD 20)

if ((MSVC) AND (MSVC_VERSION GREATER_EQUAL 1914))
	target_compile_options(KonkeyDong PUBLIC "/Zc:__cplusplus")
endif()

#link SDL2
set(SDL2_DIR ${CMAKE_SOURCE_DIR}/SDL2/cmake/)
find_package(SDL2 REQUIRED)

target_link_libraries(KonkeyDong SDL2::SDL2 SDL2::SDL2main)

# copy .dlls to output folder
add_custom_command(TARGET KonkeyDong POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy 
  $<TARGET_RUNTIME_DLLS:KonkeyDong> $<TARGET_FILE_DIR:KonkeyDong>
  COMMAND_EXPAND_LISTS
  )

# copy assets to output folder
add_custom_command(TARGET KonkeyDong POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory 
  ${CMAKE_CURRENT_SOURCE_DIR}/assets ${CMAKE_CURRENT_BINARY_DIR}/assets
  )
