/*
 * geography.h
 *
 * Functions related to longitude & latitude
 *
 */
#ifndef GEOGRAPHY_H
#define GEPGRAPHY_H

#include <stdint.h>

/*
 * The circumference of the Earth is approx. 40 000 km at the equator.
 * Mapped to a 32 bit number, the resolution would be 9 mm. Better than GPS, 
 * sufficient.
 */
typedef int32_t Longitude, Latitude;
typdef int16_t Altitude;

typedef struct sGeoPosition 
{
  Longitude longitude;
  Latitude latitude;
  Altitude altitude;
} sGeoPosition, *GeoPosition;

typedef uint16_t Heading;

/* Returns how far west of magnetic north true north is at a given position on earth,
   at the present time.  */
Heading geography_getDeclination( Longitude, Latitude );

/* distance is in centimeters */
Heading geography_getDirection( const GeoPosition here, const GeoPosition there, 
				uint32_t *distanceCM );

/* Add functions to convert Longitude / Latitude to strings with various formatting 
   (decimals, degrees/minutes */
#endif
