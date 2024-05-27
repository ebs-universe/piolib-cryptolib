/* gf256mul.c */
/*
    This file is part of the AVR-Crypto-Lib.
    Copyright (C) 2006-2015 Daniel Otte (bg@nerilex.org)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/* 
 * File:        gf256mul.c
 * Author:      Daniel Otte
 * Date:        2008-12-19
 * License:     GPLv3 or later
 * Description: peasant's algorithm for multiplication in GF(2^8)
 * 
 */

#include "cryptolib/gf256mul/gf256mul.h"

uint8_t gf256mul(uint8_t a, uint8_t b, uint8_t reducer) {
	uint8_t r = 0, c = 8;
	do {
	    if (a & 1) {
	        r ^= b;
	    }
	    a >>= 1;
	    if (b & 0x80) {
	        b ^= reducer;
	    }
	    b <<= 1;
	} while (--c);
	return r;
}
