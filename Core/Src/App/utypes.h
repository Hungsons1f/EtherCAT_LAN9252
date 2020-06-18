#ifndef __UTYPES_H__
#define __UTYPES_H__

#include "cc.h"

/* Object dictionary storage */

typedef struct
{
   /* Inputs */

   struct
   {
      uint8_t Button1;
   } Buttons;
   uint8_t Button_Variable;
   struct
   {
      uint8_t Button1;
      uint8_t Button2;
   } Button_Record;

   /* Outputs */

   struct
   {
      uint8_t LED0;
      uint8_t LED1;
   } LEDs;
   uint8_t Led_Variable;

   /* Parameters */

   struct
   {
      uint32_t Multiplier;
      uint8_t Hello;
   } Parameters;

} _Objects;

extern _Objects Obj;

#endif /* __UTYPES_H__ */
