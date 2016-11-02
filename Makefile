# MicroSim Project
#
# The MIT License (MIT)
#
# Copyright (c) 2016 LocalAreaGaming
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

CC       := gcc
RM       ?= rm
SHELL    := /bin/bash
TARGET   := microsim

SRCS     := $(wildcard *.c)
OBJS     := $(SRCS:.c=.o)
DEPS     := $(SRCS:.c=.d)

CFLAGS   += -Wall
CFLAGS   += -g -DDEBUG
CFLAGS   += -I.

# Default build rule
.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) -c -MP -MMD $(CFLAGS) -o $@ $<

.PHONY: clean
clean:
	$(RM) -rf $(OBJS) $(DEPS) $(TARGET)

# Add dependencies
-include $(DEPS)

# Clear out built-in build rules
.SUFFIXES:

# Debug print
print-%:
	@echo $*=$($*)
