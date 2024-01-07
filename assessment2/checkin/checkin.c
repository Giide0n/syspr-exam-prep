// This won't work on macOS and has to be executed on linux.
// The following command can be used to start a docker Container running alpine and gcc installed.
// docker run -it --rm -v "$(pwd)":/usr/src/myapp -w /usr/src/myapp alpine /bin/sh -c "apk add --no-cache gcc musl-dev; /bin/sh"
#include <mqueue.h>

int main(int argc, char *argv[]) {
}