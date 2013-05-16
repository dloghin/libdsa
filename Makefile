# libdsa - Makefile
#
# Copyright (C) 2012-2013  Dumi Loghin
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

CC=gcc
CFLAGS=-Wall -c -fPIC
LDFLAGS=

SOURCES = $(wildcard src/*.c)
OBJECTS = $(patsubst %.c,%.o,$(SOURCES))

LIB_NAME=libdsa

%.o: %.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

shared: $(OBJECTS)
	$(CC) -shared $^ -o $(LIB_NAME).so 

static: $(OBJECTS)
	ar rcs $(LIB_NAME).a $^
	
clean:
	rm -f $(LIB_NAME).so $(LIB_NAME).a $(OBJECTS)	
