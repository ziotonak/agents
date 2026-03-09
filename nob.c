#define NOB_IMPLEMENTATION
#include "nob.h"

#define BUILD_FOLDER "build/"
#define VENDOR_FOLDER "vendor/"
#define SRC_FOLDER "src/"

int main(int argc, char **argv) {
    NOB_GO_REBUILD_URSELF(argc, argv);

    if (!nob_mkdir_if_not_exists(BUILD_FOLDER))
        return 1;

    Nob_Cmd cmd = {0};

    nob_cmd_append(&cmd, "cc");
    nob_cmd_append(&cmd, "-Wall", "-Wextra", "-ggdb");

    nob_cmd_append(&cmd, "-I", VENDOR_FOLDER);
    nob_cmd_append(&cmd, "-I", SRC_FOLDER);

    nob_cmd_append(&cmd, "-o", BUILD_FOLDER "main");

    nob_cmd_append(&cmd, SRC_FOLDER "main.c");
    nob_cmd_append(&cmd, VENDOR_FOLDER "sqlite3.c");
    nob_cmd_append(&cmd, VENDOR_FOLDER "sqlite-vec.c");

    nob_cmd_append(&cmd, "-lm");

    if (!nob_cmd_run_sync(cmd))
        return 1;

    return 0;
}
