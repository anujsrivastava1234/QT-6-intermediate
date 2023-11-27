# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/app2-2BasicDataTypes_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/app2-2BasicDataTypes_autogen.dir/ParseCache.txt"
  "app2-2BasicDataTypes_autogen"
  )
endif()
