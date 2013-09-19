# This file is part of SmallMath.
#
# SmallMath is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# SmallMath is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with SmallMath. If not, see <http://www.gnu.org/licenses/>.
#
# Copyright 2013 Chris Foster

cmake_minimum_required(VERSION 2.8)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
	message(FATAL_ERROR "In-source builds are not allowed!")
endif()

# Setup ===================================================

project(SmallMath)

set(PROJECT_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin/smallmath")
set(INCLUDE_INSTALL_DIRECTORY "${PROJECT_OUTPUT_DIRECTORY}/include/math")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_OUTPUT_DIRECTORY}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")

option(BUILD_STATIC "Build the library for static linking.  Otherwise a shared library will be built." TRUE)

if(MSVC)
	# Remove copious amounts of useless warnings
	if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
		string(REGEX REPLACE "/W[0-4]" "/W3" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
	else()
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W3")
	endif()
else(MSVC)
	set(CMAKE_CXX_FLAGS "-g -Wall")
endif(MSVC)

if(BUILD_INTERNAL)
	set_property(GLOBAL PROPERTY SMALLMATH_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/source")
	set_property(GLOBAL PROPERTY SMALLMATH_LIBRARY "smallmath")
endif()

# Source ==================================================

add_subdirectory(source)
