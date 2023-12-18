# CMakeList.txt : CMake project for KonkeyDong, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (KonkeyDong "KonkeyDong.cpp" "KonkeyDong.h")

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

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET KonkeyDong PROPERTY CXX_STANDARD 20)
endif()
