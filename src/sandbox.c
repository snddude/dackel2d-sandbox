#include "sandbox.h"

bool sandbox_init(application_t *self, int argc, char *argv[])
{
    if (!application_init(self, argc, argv))
        return false;

    window_set_title(&self->main_window, "Sandbox");
    window_set_size(&self->main_window, 800, 600);

    return true;
}
