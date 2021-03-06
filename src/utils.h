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

#ifndef LIBDSA_UTILS_H
#define LIBDSA_UTILS_H

/**
 * @file utils.h
 * @brief Utilities Declarations
 */

#include "common.h"

int mylog2(int n);

void print_array_int(FILE* f, int* a, int n);

void print_matrix_int(FILE* f, int* a, int n, int m);
#endif
