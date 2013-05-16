/**
 * Copyright 2012 Dumi Loghin
 *
 * This file is part of libdsa.
 *
 * libdsa is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * libdsa is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser Public License for more details.
 *
 * You should have received a copy of the GNU Lesser Public License
 * along with libdsa.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBDSA_COMMON_H
#define LIBDSA_COMMON_H

/**
 * @file common.h
 * @brief Common Declarations
 */

#include <stdlib.h>
#include <stdio.h>

enum _e_ret_code {
	EBOUNDS = -3,
	ENULL = -2,
	EALLOC = -1,
	SUCCESS = 0
};

#endif
