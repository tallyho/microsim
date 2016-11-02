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

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>
#include <time.h>

#include "menu.h"
#include "game.h"
#include "util.h"
#include "activity_log.h"

struct termios orig_termios;

void reset_terminal_mode() {
    tcsetattr(0, TCSANOW, &orig_termios);
}

void setup_terminal_mode(void) {
    struct termios new_termios;

    /* take two copies - one for now, one for later */
    tcgetattr(0, &orig_termios);
    memcpy(&new_termios, &orig_termios, sizeof(new_termios));

    /* register cleanup handler, and set the new terminal mode */
    atexit(reset_terminal_mode);
    cfmakeraw(&new_termios);
    tcsetattr(0, TCSANOW, &new_termios);
}

int kbhit(void) {
    struct timeval tv = { 0L, 0L };
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(0, &fds);
    return select(1, &fds, NULL, NULL, &tv);
}

int getch(void) {
    int r;
    unsigned char c;
    if ((r = read(0, &c, sizeof(c))) < 0) {
        return r;
    } else {
        return c;
    }
}

int handle_input(void) {
    if (!kbhit()) {
        return 0;
    }

    char c = getch();
    tcflush(STDIN_FILENO, TCIFLUSH); // throw away the rest. only one at a time!

    if (c == 3 || c == 'q' || c == 'Q') {
        return 1; // ctrl-c, q, or Q
    }

    return menu_handle_input(c);
}

int main(int argc, char *argv[]) {
    time_t now;

    printf("Welcome to the Micromanager simulator\r\n");
    printf("You have been chosen as the manager for a failing business unit.\r\nPlease save the company!\r\n\n");

    setup_terminal_mode();
    activity_log_init();

    // Seed the RNG
    now = time(NULL);
    srand(now);
    printf("Random seed:%ld\r\n", now);
    activity_log("Random seed:%ld\r\n", now);

    game_init();
    menu_init();

    while (1) {
        clock_t begin = clock();
        
        if (handle_input()) {
            break; //user exited game
        }

        game_step();

        // sleep for the remainder of the step
        double secs = (clock() - begin) / CLOCKS_PER_SEC;
        if (secs < GAME_STEP_MS*1000) {
            struct timespec ts;
            ts.tv_sec = 0;
            ts.tv_nsec = (GAME_STEP_MS - secs*1000) * 1000000;
            nanosleep(&ts, NULL);
        }
        game.step++;
    }

    printf("\rBye!\n");

	return 0;
}
