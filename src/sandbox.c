#include "sandbox.h"

bool sandbox_init(application_t *self)
{
    if (!application_init(self))
        return false;

    window_set_title(&self->main_window, "Sandbox");
    window_set_size(&self->main_window, 800, 600);

    return true;
}
