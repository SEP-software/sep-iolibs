project(SEPlib-io)
cmake_minimum_required(VERSION 2.8)


list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
set(CMAKE_POSITION_INDEPENDENT_CODE True)
#
#  SEPLIB can be built with or without shared libraries.
#  If shared libraries are desired, we suggest building
#  with shared libraries first using
#
#       cmake -DBUILD_SHARED_LIBS=True
#
#  and then rebuilding without shared libraries using
#
#       cmake -DBUILD_SHARED_LIBS=False
#
#  so that the standard program executables are
#  statically linked.
#
set(CMAKE_SKIP_INSTALL_RPATH False)
set(CMAKE_SKIP_RPATH False)

set(SEPlib-io_MAJOR_VERSION 9)
set(SEPlib-io_MINOR_VERSION 0)
set(SEPlib-io_VERSION_STRING
  ${SEPlib-io_MAJOR_VERSION}.${SEPlib-io_MINOR_VERSION})
enable_language(C OPTIONAL Fortran)

set(CMAKE_Fortran_MODULE_DIRECTORY  ${CMAKE_INSTALL_PREFIX}/include)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O2")

set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -g -O2")

include_directories("${PROJECT_BINARY_DIR}")
# Offer the user the choice of overriding the installation directories
set(INSTALL_LIB_DIR lib CACHE PATH "Installation directory for libraries")
set(INSTALL_CMAKE_DIR ${DEF_INSTALL_CMAKE_DIR} CACHE PATH
  "Installation directory for CMake files")

# Make relative paths absolute (needed later on)
foreach(p LIB BIN INCLUDE CMAKE)
  set(var INSTALL_${p}_DIR)
  if(NOT IS_ABSOLUTE "${${var}}")
    set(${var} "${CMAKE_INSTALL_PREFIX}/${${var}}")
  endif()
endforeach()



SET(SEPlib_DIRNAME_lib     ${CMAKE_INSTALL_PREFIX}/lib)
SET(SEPlib_DIRNAME_include ${CMAKE_INSTALL_PREFIX}/include)
SET(SEPlib_DIRNAME_cmake ${CMAKE_INSTALL_PREFIX}/cmake)

find_package(SU)
if(SU_LIBRARIES)
set(SU_SUPPORT true)
endif(SU_LIBRARIES)


INCLUDE (CheckIncludeFiles)
CHECK_INCLUDE_FILES(termios.h HAVE_TERMIOS_H)
CHECK_INCLUDE_FILES(termio.h HAVE_TERMIO_H)
CHECK_INCLUDE_FILES(stdio.h HAVE_STDIO_H)
CHECK_INCLUDE_FILES(stdlib.h HAVE_STDLIB_H)
CHECK_INCLUDE_FILES(string.h HAVE_STRING_H)
CHECK_INCLUDE_FILES(strings.h HAVE_STRINGS_H)
CHECK_INCLUDE_FILES(sys/ioctl.h HAVE_SYS_IOCTL_H)
CHECK_INCLUDE_FILES(sys/file.h HAVE_SYS_FILE_H)
CHECK_INCLUDE_FILES(sys/stat.h HAVE_SYS_STAT_H)
CHECK_INCLUDE_FILES(sys/tape.h HAVE_SYS_TAPE_H)
CHECK_INCLUDE_FILES(sys/uio.h HAVE_SYS_UIO_H)
CHECK_INCLUDE_FILES(sgtty.h HAVE_SGTTY_H)
CHECK_INCLUDE_FILES(signal.h HAVE_SIGNAL_H)
CHECK_INCLUDE_FILES(sys/types.h HAVE_SYS_TYPES_H)
CHECK_INCLUDE_FILES(sys/termios.h HAVE_SYS_TERMIOS_H)
CHECK_INCLUDE_FILES(sys/utsname.h HAVE_SYS_UTSNAME_H)
CHECK_INCLUDE_FILES(sys/param.h HAVE_SYS_PARAM_H)
CHECK_INCLUDE_FILES(unistd.h HAVE_UNISTD_H)
CHECK_INCLUDE_FILES(fcntl.h HAVE_FCNTL_H)
CHECK_INCLUDE_FILES(dirent.h HAVE_DIRENT_H)
CHECK_INCLUDE_FILES(sys/ndir.h HAVE_SYS_NDIR_H)
CHECK_INCLUDE_FILES(sys/dir.h HAVE_SYS_DIR_H)
CHECK_INCLUDE_FILES(ndir.h HAVE_NDIR_H)
CHECK_INCLUDE_FILES(limits.h HAVE_LIMITS_H)
CHECK_INCLUDE_FILES(errno.h HAVE_ERRNO_H)
CHECK_INCLUDE_FILES(sys/socket.h HAVE_SYS_SOCKET_H)
CHECK_INCLUDE_FILES(rpc/rpc.h HAVE_RPC_RPC_H)
CHECK_INCLUDE_FILES(rpc/types.h HAVE_RPC_TYPES_H)
CHECK_INCLUDE_FILES(ctime.h HAVE_CTIME_H)
CHECK_INCLUDE_FILES(utime.h HAVE_UTIME_H)

 



add_subdirectory(sep)
add_subdirectory(sep3d)
add_subdirectory(superset)
add_subdirectory(include)


install(FILES ${PROJECT_BINARY_DIR}/module/seplib  DESTINATION module)

configure_file (
  "${PROJECT_SOURCE_DIR}/sepConfig.h.in"
  "${PROJECT_BINARY_DIR}/sepConfig.h"
  )




###################

export(TARGETS sep sep3d superset FILE "${PROJECT_BINARY_DIR}/SEPlibTargets.cmake")
export(PACKAGE SEPlib)

configure_file(${PROJECT_SOURCE_DIR}/cmake/SEPlibConfig.cmake.in
  "${PROJECT_BINARY_DIR}/cmake/SEPlibConfig.cmake" @ONLY)
# ... for both
configure_file(${PROJECT_SOURCE_DIR}/cmake/SEPlibConfigVersion.cmake.in
  "${PROJECT_BINARY_DIR}/cmake/SEPlibConfigVersion.cmake" @ONLY)

install(FILES
  "${PROJECT_BINARY_DIR}/cmake/SEPlibConfig.cmake"
  "${PROJECT_BINARY_DIR}/cmake/SEPlibConfigVersion.cmake"
  DESTINATION "${SEPlib_DIRNAME_cmake}" COMPONENT dev)

install(EXPORT SEPlibTargets DESTINATION
  cmake COMPONENT dev)





include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${PROJECT_SOURCE_DIR}/LICENSE")
set(CPACK_PACKAGE_VERSION_MAJOR "${SEPlib-io_MAJOR_VERSION}")
set(CPACK_PACKAGE_VERSION_MINOR "${SEPlib-io_MINOR_VERSION}")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_PACKAGE_NAME "SEPlib-io")
set(CPACK_PACKAGE_CONTACT "Robert Clapp")
include(CPack)
