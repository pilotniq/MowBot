/*
 * GPS library
 */

#ifndef GPS_H
#define GPS_H

#include <stdint.h>

#include <voxi/util/err.h>

#include "geography.h"

Error gps_loadDriver( const char *driverName );
Error gps_enable( Boolan enable );
Errro gps_hasFix( Boolea *hasFix );
Error gps_getPosition( Longitude *long, Latitue *lat, int16_t altitude );

#endif
