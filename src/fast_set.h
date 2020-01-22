/**
 * Copyright 2019 Dumi Loghin
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

#ifndef LIBDSA_FAST_SET_H
#define LIBDSA_FAST_SET_H

/**
 * @file fast_set.h
 * @brief Fast Set of positive integers.
 */

#include "common.h"

int add(int n);

int delete(int n);

int contains(int n);

int pop();

int clear();

#endif /* LIBDSA_FAST_SET_H */
