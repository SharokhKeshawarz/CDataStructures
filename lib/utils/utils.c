#include "../include/utils.h"

void get_current_time(char *buffer, size_t size)
{
    time_t now = time(NULL);  // Get the current time
    struct tm *tm_info = localtime(&now);  // Convert time to struct tm (local time)

    // Format the time into the buffer: [HH:MM:SS - MM/DD/YYYY]
    strftime(buffer, size, "[%H:%M:%S - %m/%d/%Y]", tm_info);
}
