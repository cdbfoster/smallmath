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

set(math_include
	Constants.hpp
	EulerAngles.hpp
	Matrix.hpp
	Quaternion.hpp
	Vector.hpp
)

set(math_source
	EulerAngles.cpp
	Matrix.cpp
	Quaternion.cpp
	Vector.cpp
)

# To allow us to include files with #include "math/File"
set(SOURCE "..")
include_directories(${SOURCE})

if(BUILD_STATIC)
	add_library(smallmath STATIC ${math_include} ${math_source})
else()
	add_library(smallmath SHARED ${math_include} ${math_source})
endif()

if(NOT BUILD_INTERNAL)
	install(FILES ${math_include}
			DESTINATION ${INCLUDE_OUTPUT_PATH}
	)
endif()
