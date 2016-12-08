# libdsa - tests Makefile
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
CFLAGS=-Wall -I../src -g
LDFLAGS=-L.. -ldsa

SOURCES=$(wildcard test_*.c)
TARGETS=$(patsubst %.c,%.exe,$(SOURCES))

all: $(TARGETS)
	
%.exe: %.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

test_asynctask.exe: test_asynctask.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS) -pthread

clean:
	rm -f $(TARGETS)
