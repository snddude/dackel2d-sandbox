#include "sandbox.h"

int main(int argc, char *argv[])
{
    application_t sandbox;
    if (!sandbox_init(&sandbox, argc, argv))
        return -1;

    application_run(&sandbox);
    application_destroy(&sandbox);

    return 0;
}
