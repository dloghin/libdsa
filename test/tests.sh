# libdsa - tests script
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

#/bin/bash

# first step: make all tests (they will have .exe suffix)
make

TESTS=`ls | grep .exe`
NO_TESTS=`echo $TESTS | wc -w`
FAILED=0

# execute tests
export LD_LIBRARY_PATH=..

for TEST in ${TESTS[@]}
do
	echo "=== Test: $TEST ==="
	./$TEST
	if [ $? -ne 0 ]; then
		FAILED=$(($FAILED + 1))
	fi	
done

echo "==========================="
echo "Failed: $FAILED/$NO_TESTS"
echo "==========================="
