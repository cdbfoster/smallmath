# This file is part of SmallMathLib.
#
# SmallMathLib is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# SmallMathLib is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with SmallMathLib. If not, see <http://www.gnu.org/licenses/>.
#
# Copyright 2013 Chris Foster

cmake_minimum_required(VERSION 2.8)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
	message(FATAL_ERROR "In-source builds are not allowed!")
endif()

set(CMAKE_CXX_FLAGS "-Wall")

# Setup ===================================================

project(SmallMathLib)

set(PROJECT_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin/smallmathlib")
set(INCLUDE_OUTPUT_PATH "${PROJECT_OUTPUT_PATH}/include")
set(LIBRARY_OUTPUT_PATH "${PROJECT_OUTPUT_PATH}/lib")

option(BUILD_STATIC "Build the library for static linking.  Otherwise a shared library will be built." FALSE)

# Source ==================================================

add_subdirectory(source)
