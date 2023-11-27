# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/appwebassemblyTest_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/appwebassemblyTest_autogen.dir/ParseCache.txt"
  "appwebassemblyTest_autogen"
  )
endif()
