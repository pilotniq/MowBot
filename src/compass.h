/*
 * Generic functions for compass 
 *
 * Originally written for robotic lawnmower project
 */

typdef uint16_t Heading;

/* Returns how far west of magnetic north true north is at a given position on earth,
   at the present time.  */
Heading compass_getDeclination( Longitude, Latitude );

Error compass_loadDriver( const char *name );
Error compass_getHeading( Heading *heading );
