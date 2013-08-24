/*
  gpio.c
*/
#include <assert.h>
#include <stddef.h>

#include <voxi/util/driver.h>
#include <voxi/util/err.h>

#include "gpio.h"

typedef Error (*InitFunc)();
typedef Error (*AllocFunc)( int number, Direction direction, Pin *pin );
typedef Error (*SetFunc)( Pin pin, int value );
typedef Error (*GetFunc)( Pin pin, int *value );

static struct sFunctions
{
  InitFunc init;
  AllocFunc allocate;
  SetFunc set;
  GetFunc get;
} functions = { NULL, NULL, NULL, NULL };

sDriverFunctionInfo functionInfo[] = {
  { "init", offsetof( struct sFunctions, init ) },
  { "allocate", offsetof( struct sFunctions, allocate ) },
  { "set", offsetof( struct sFunctions, set ) },
  { "get", offsetof( struct sFunctions, get ) }
};

/*
 * start of code
 */
Error gpio_init( const char *driverName )
{
  Error error;
  SharedLibrary shlib;
  int apiVersion;

  error = driverOpen( driverName, &apiVersion, &shlib );
  if( error != NULL )
  {
    error = ErrNew( ERR_APP, 0, error, "Failed to open driver" );
    
    goto ERROR_1;
  }

  error = driverLoadFunctions( shlib, 4, functionInfo, &functions );
  if( error != NULL )
  {
    error = ErrNew( ERR_APP, 0, error, "Failed to load driver functions" );
    
    goto ERROR_2;
  }

  error = functions.init();

 ERROR_2:
  driverClose( shlib );

 ERROR_1:
  return error;
}

Error gpio_allocate( int number, Direction direction, Pin *pin )
{
  assert( functions.allocate != NULL );

  return functions.allocate( number, direction, pin );
}

Error gpio_set( Pin pin, int value )
{
  assert( functions.set != NULL );

  return functions.set( pin, value );
}

Error gpio_get( Pin pin, int *value )
{
  assert( functions.get != NULL );

  return functions.get( pin, value );
}
