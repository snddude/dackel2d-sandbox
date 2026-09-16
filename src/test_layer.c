#include "test_layer.h"

static log_level_t dynamic_log_level = LogLevel_Error;

static void on_attach()
{
    log_error("Initial log level is set to LogLevel_Error (1) by application");
}

static void process_event(event_t *event)
{
    if (event->type == EventType_Key && event->key.pressed && !event->key.echo)
        switch (event->key.code)
        {
            case KeyCode_0:
                if (dynamic_log_level < LogLevel_Info)
                    dynamic_log_level++;
                else
                {
                    log_warning("Set log level to None");
                    dynamic_log_level = LogLevel_None;
                }

                set_log_level(dynamic_log_level);
                log_warning("Incremented log level to: %d", dynamic_log_level);
                break;
            case KeyCode_1:
                log_info("This is an informational message!");    
                break;
            case KeyCode_2:
                log_error("This is an error!");
                break;
            case KeyCode_3:
                log_warning("This is an warning!");
                break;
            default:
                break;
        }
}

void test_layer_init(layer_t *self)
{
    layer_init(self);
    self->on_attach_pfn = &on_attach;
    self->process_event_pfn = &process_event;
}
