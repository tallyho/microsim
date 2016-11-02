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

#ifndef _RANDOM_H_
#define _RANDOM_H_

void rand_init(uint32_t seed);
uint32_t rand_uint32_max(uint32_t max);
uint32_t rand_uint32_range(uint32_t start, uint32_t stop);
uint32_t rand_uint32(void);
float rand_float(void);
float rand_float12(void);
float rand_float01(void);
float rand_floatOC(void);
float rand_floatOO(void);
double rand_32double(void);

#endif /* _RANDOM_H_ */
