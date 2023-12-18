# CMakeList.txt : CMake project for KonkeyDong, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (KonkeyDong "KonkeyDong.cpp" "KonkeyDong.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET KonkeyDong PROPERTY CXX_STANDARD 20)
endif()
