/*
 * MicroSim Project
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 LocalAreaGaming
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/*
 * This file contains a much better RNG (using the Mersenne Twister algorithm) 
 * and correctly implements range functions that do not introduce modulo bias.
 *
 * This implementation is not thread safe.
 */

#include <stdint.h>
#include <assert.h>

#include "tinymt32.h"
#include "random.h"

/* Global shared random state */
static tinymt32_t state;

/*
 * Initializes RNG with particular seed
 */
void rand_init(uint32_t seed) {
    tinymt32_init(&state, seed);
}

/**
 * This function outputs 32-bit unsigned integer up to but not including a 
 * maximum value from internal state.
 * @return 32-bit unsigned integer r (0 <= r <  max)
 */
uint32_t rand_uint32_max(uint32_t max) {
    return rand_uint32_range(0, max);
}

/**
 * This function outputs 32-bit unsigned integer within a range from internal 
 * state.
 * @return 32-bit unsigned integer r (start <= r < stop)
 */
uint32_t rand_uint32_range(uint32_t start, uint32_t stop) {
    uint32_t x;
    uint32_t n;

    assert(start <= stop);
    n = stop - start;

    if (n == 0) {
        return 0;
    }

    do {
        x = rand_uint32();
    } while (x >= UINT32_MAX - UINT32_MAX % n);

    x %= n;
    x += start;

    return x;
}

/**
 * This function outputs 32-bit unsigned integer from internal state.
 * @return 32-bit unsigned integer r (0 <= r < 2^32)
 */
uint32_t rand_uint32(void) {
    return tinymt32_generate_uint32(&state);
}

/**
 * This function outputs floating point number from internal state.
 * This function is implemented using multiplying by (1 / 2^24).
 * floating point multiplication is faster than using union trick in
 * my Intel CPU.
 * @return floating point number r (0.0 <= r < 1.0)
 */
float rand_float(void) {
    return tinymt32_generate_float(&state);
}

/**
 * This function outputs floating point number from internal state.
 * This function is implemented using union trick.
 * @return floating point number r (1.0 <= r < 2.0)
 */
float rand_float12(void) {
    return tinymt32_generate_float12(&state);
}

/**
 * This function outputs floating point number from internal state.
 * This function is implemented using union trick.
 * @return floating point number r (0.0 <= r < 1.0)
 */
float rand_float01(void) {
    return tinymt32_generate_float01(&state);
}

/**
 * This function outputs floating point number from internal state.
 * This function may return 1.0 and never returns 0.0.
 * @return floating point number r (0.0 < r <= 1.0)
 */
float rand_floatOC(void) {
    return tinymt32_generate_floatOC(&state);
}

/**
 * This function outputs floating point number from internal state.
 * This function returns neither 0.0 nor 1.0.
 * @return floating point number r (0.0 < r < 1.0)
 */
float rand_floatOO(void) {
    return tinymt32_generate_floatOO(&state);
}

/**
 * This function outputs double precision floating point number from
 * internal state. The returned value has 32-bit precision.
 * In other words, this function makes one double precision floating point
 * number from one 32-bit unsigned integer.
 * @return floating point number r (0.0 < r <= 1.0)
 */
double rand_32double(void) {
    return tinymt32_generate_32double(&state);
}
