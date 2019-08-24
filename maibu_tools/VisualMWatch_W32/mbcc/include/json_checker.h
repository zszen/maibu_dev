#ifndef _JSON_CHECKER_H
#define _JSON_CHECKER_H

#include <stdint.h>
#include <stdbool.h>

int8_t maibu_get_json_str(const char* json, const char*key, char *value_out, int value_out_size);
int8_t maibu_get_json_int(const char* json, const char*key, int32_t *value_out);

#endif
