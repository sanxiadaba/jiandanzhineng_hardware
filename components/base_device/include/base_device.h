
#include "mqtt_client.h"
#include "cJSON.h"
#include "driver/ledc.h"




#define DEVICE_TJS 1
#define DEVICE_TD01 2
#define DEVICE_TYPE_INDEX DEVICE_TD01

#if DEVICE_TYPE_INDEX == DEVICE_TJS
    #define DEVICE_TYPE_NAME "TJS"
    #include "tjs.h"
#elif DEVICE_TYPE_INDEX == DEVICE_TD01
    #define DEVICE_TYPE_NAME "TD01"
    #include "TD01.h"
#endif


    

void mqtt_msg_process(char *topic, int topic_len, char *data, int data_len);
void set_property(char *property_name, cJSON *property_value, int msg_id);
void get_property(char *property_name, int msg_id);
void device_init(void);
void device_first_ready(void);
static void report_all_properties(void);
static void heartbeat_task(void);