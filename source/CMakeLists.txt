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

set(math_include
	math/Constants.hpp
	math/EulerAngles.hpp
	math/Matrix.hpp
	math/Quaternion.hpp
	math/Vector.hpp
)

set(math_source
	math/EulerAngles.cpp
	math/Matrix.cpp
	math/Quaternion.cpp
	math/Vector.cpp
)

if(BUILD_STATIC)
	add_library(smallmathlib STATIC ${math_include} ${math_source})
else()
	add_library(smallmathlib SHARED ${math_include} ${math_source})
endif()

install(FILES ${math_include}
		DESTINATION ${INCLUDE_OUTPUT_PATH}
)
