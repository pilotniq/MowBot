/*
 * gpio.h
 */
#ifndef GPIO_H
#define GPIO_H

#include <voxi/util/err.h>

typedef struct sPin *Pin;
typedef enum { INPUT, OUTPUT } Direction;

Error gpio_init( const char *driver );
Error gpio_allocate( int number, Direction direction, Pin *pin );
Error gpio_set( Pin pin, int value );
Error gpio_get( Pin pin, int *value );

#endif
