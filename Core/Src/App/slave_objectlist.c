#include "esc_coe.h"
#include "utypes.h"
#include <stddef.h>

#ifndef HW_REV
#define HW_REV "1.0"
#endif

#ifndef SW_REV
#define SW_REV "1.0"
#endif

static const char acName1000[] = "Device Type";
static const char acName1008[] = "Device Name";
static const char acName1009[] = "Hardware Version";
static const char acName100A[] = "Software Version";
static const char acName1018[] = "Identity Object";
static const char acName1018_00[] = "Max SubIndex";
static const char acName1018_01[] = "Vendor ID";
static const char acName1018_02[] = "Product Code";
static const char acName1018_03[] = "Revision Number";
static const char acName1018_04[] = "Serial Number";
static const char acName1600[] = "LEDs";
static const char acName1600_00[] = "Max SubIndex";
static const char acName1600_01[] = "LED0";
static const char acName1600_02[] = "LED1";
static const char acName1601[] = "Led_Variable";
static const char acName1601_00[] = "Max SubIndex";
static const char acName1601_01[] = "Led_Variable";
static const char acName1601_02[] = "Padding 2";
static const char acName1A00[] = "Buttons";
static const char acName1A00_00[] = "Max SubIndex";
static const char acName1A00_01[] = "Button1";
static const char acName1A01[] = "Button_Variable";
static const char acName1A01_00[] = "Max SubIndex";
static const char acName1A01_01[] = "Button_Variable";
static const char acName1A02[] = "Button_Record";
static const char acName1A02_00[] = "Max SubIndex";
static const char acName1A02_01[] = "Button1";
static const char acName1A02_02[] = "Button2";
static const char acName1A02_03[] = "Padding 3";
static const char acName1C00[] = "Sync Manager Communication Type";
static const char acName1C00_00[] = "Max SubIndex";
static const char acName1C00_01[] = "Communications Type SM0";
static const char acName1C00_02[] = "Communications Type SM1";
static const char acName1C00_03[] = "Communications Type SM2";
static const char acName1C00_04[] = "Communications Type SM3";
static const char acName1C12[] = "Sync Manager 2 PDO Assignment";
static const char acName1C12_00[] = "Max SubIndex";
static const char acName1C12_01[] = "PDO Mapping";
static const char acName1C12_02[] = "PDO Mapping";
static const char acName1C13[] = "Sync Manager 3 PDO Assignment";
static const char acName1C13_00[] = "Max SubIndex";
static const char acName1C13_01[] = "PDO Mapping";
static const char acName1C13_02[] = "PDO Mapping";
static const char acName1C13_03[] = "PDO Mapping";
static const char acName6000[] = "Buttons";
static const char acName6000_00[] = "Max SubIndex";
static const char acName6000_01[] = "Button1";
static const char acName6001[] = "Button_Variable";
static const char acName6002[] = "Button_Record";
static const char acName6002_00[] = "Max SubIndex";
static const char acName6002_01[] = "Button1";
static const char acName6002_02[] = "Button2";
static const char acName7000[] = "LEDs";
static const char acName7000_00[] = "Max SubIndex";
static const char acName7000_01[] = "LED0";
static const char acName7000_02[] = "LED1";
static const char acName7001[] = "Led_Variable";
static const char acName8000[] = "Parameters";
static const char acName8000_00[] = "Max SubIndex";
static const char acName8000_01[] = "Multiplier";
static const char acName8000_02[] = "Hello";

const _objd SDO1000[] =
{
  {0x0, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1000, 0x01901389, NULL},
};
const _objd SDO1008[] =
{
  {0x0, DTYPE_VISIBLE_STRING, 56, ATYPE_RO, acName1008, 0, "lan9252"},
};
const _objd SDO1009[] =
{
  {0x0, DTYPE_VISIBLE_STRING, 0, ATYPE_RO, acName1009, 0, HW_REV},
};
const _objd SDO100A[] =
{
  {0x0, DTYPE_VISIBLE_STRING, 0, ATYPE_RO, acName100A, 0, SW_REV},
};
const _objd SDO1018[] =
{
  {0x00, DTYPE_UNSIGNED8, 8, ATYPE_RO, acName1018_00, 4, NULL},
  {0x01, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1018_01, 0x1543, NULL},
  {0x02, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1018_02, 1234, NULL},
  {0x03, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1018_03, 1, NULL},
  {0x04, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1018_04, 0x00000000, NULL},
};
const _objd SDO1600[] =
{
  {0x00, DTYPE_UNSIGNED8, 8, ATYPE_RO, acName1600_00, 2, NULL},
  {0x01, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1600_01, 0x70000108, NULL},
  {0x02, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1600_02, 0x70000208, NULL},
};
const _objd SDO1601[] =
{
  {0x00, DTYPE_UNSIGNED8, 8, ATYPE_RO, acName1601_00, 2, NULL},
  {0x01, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1601_01, 0x70010001, NULL},
  {0x02, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1601_02, 0x00000007, NULL},
};
const _objd SDO1A00[] =
{
  {0x00, DTYPE_UNSIGNED8, 8, ATYPE_RO, acName1A00_00, 1, NULL},
  {0x01, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1A00_01, 0x60000108, NULL},
};
const _objd SDO1A01[] =
{
  {0x00, DTYPE_UNSIGNED8, 8, ATYPE_RO, acName1A01_00, 1, NULL},
  {0x01, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1A01_01, 0x60010008, NULL},
};
const _objd SDO1A02[] =
{
  {0x00, DTYPE_UNSIGNED8, 8, ATYPE_RO, acName1A02_00, 3, NULL},
  {0x01, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1A02_01, 0x60020101, NULL},
  {0x02, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1A02_02, 0x60020201, NULL},
  {0x03, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1A02_03, 0x00000006, NULL},
};
const _objd SDO1C00[] =
{
  {0x00, DTYPE_UNSIGNED8, 8, ATYPE_RO, acName1C00_00, 4, NULL},
  {0x01, DTYPE_UNSIGNED8, 8, ATYPE_RO, acName1C00_01, 1, NULL},
  {0x02, DTYPE_UNSIGNED8, 8, ATYPE_RO, acName1C00_02, 2, NULL},
  {0x03, DTYPE_UNSIGNED8, 8, ATYPE_RO, acName1C00_03, 3, NULL},
  {0x04, DTYPE_UNSIGNED8, 8, ATYPE_RO, acName1C00_04, 4, NULL},
};
const _objd SDO1C12[] =
{
  {0x00, DTYPE_UNSIGNED8, 8, ATYPE_RO, acName1C12_00, 2, NULL},
  {0x01, DTYPE_UNSIGNED16, 16, ATYPE_RO, acName1C12_01, 0x1600, NULL},
  {0x02, DTYPE_UNSIGNED16, 16, ATYPE_RO, acName1C12_02, 0x1601, NULL},
};
const _objd SDO1C13[] =
{
  {0x00, DTYPE_UNSIGNED8, 8, ATYPE_RO, acName1C13_00, 3, NULL},
  {0x01, DTYPE_UNSIGNED16, 16, ATYPE_RO, acName1C13_01, 0x1A00, NULL},
  {0x02, DTYPE_UNSIGNED16, 16, ATYPE_RO, acName1C13_02, 0x1A01, NULL},
  {0x03, DTYPE_UNSIGNED16, 16, ATYPE_RO, acName1C13_03, 0x1A02, NULL},
};
const _objd SDO6000[] =
{
  {0x00, DTYPE_UNSIGNED8, 8, ATYPE_RO, acName6000_00, 1, NULL},
  {0x01, DTYPE_UNSIGNED8, 8, ATYPE_RO, acName6000_01, 0, &Obj.Buttons.Button1},
};
const _objd SDO6001[] =
{
  {0x0, DTYPE_UNSIGNED8, 8, ATYPE_RO | ATYPE_TXPDO, acName6001, 0, &Obj.Button_Variable},
};
const _objd SDO6002[] =
{
  {0x00, DTYPE_UNSIGNED8, 8, ATYPE_RO, acName6002_00, 2, NULL},
  {0x01, DTYPE_BOOLEAN, 1, ATYPE_RO | ATYPE_TXPDO, acName6002_01, 0, &Obj.Button_Record.Button1},
  {0x02, DTYPE_BOOLEAN, 1, ATYPE_RO | ATYPE_TXPDO, acName6002_02, 0, &Obj.Button_Record.Button2},
};
const _objd SDO7000[] =
{
  {0x00, DTYPE_UNSIGNED8, 8, ATYPE_RO, acName7000_00, 2, NULL},
  {0x01, DTYPE_UNSIGNED8, 8, ATYPE_RO, acName7000_01, 0, &Obj.LEDs.LED0},
  {0x02, DTYPE_UNSIGNED8, 8, ATYPE_RO, acName7000_02, 0, &Obj.LEDs.LED1},
};
const _objd SDO7001[] =
{
  {0x0, DTYPE_BOOLEAN, 1, ATYPE_RO | ATYPE_RXPDO, acName7001, 0, &Obj.Led_Variable},
};
const _objd SDO8000[] =
{
  {0x00, DTYPE_UNSIGNED8, 8, ATYPE_RO, acName8000_00, 2, NULL},
  {0x01, DTYPE_UNSIGNED32, 32, ATYPE_RW, acName8000_01, 0, &Obj.Parameters.Multiplier},
  {0x02, DTYPE_UNSIGNED8, 8, ATYPE_RO, acName8000_02, 0, &Obj.Parameters.Hello},
};

const _objectlist SDOobjects[] =
{
  {0x1000, OTYPE_VAR, 0, 0, acName1000, SDO1000},
  {0x1008, OTYPE_VAR, 0, 0, acName1008, SDO1008},
  {0x1009, OTYPE_VAR, 0, 0, acName1009, SDO1009},
  {0x100A, OTYPE_VAR, 0, 0, acName100A, SDO100A},
  {0x1018, OTYPE_RECORD, 4, 0, acName1018, SDO1018},
  {0x1600, OTYPE_RECORD, 2, 0, acName1600, SDO1600},
  {0x1601, OTYPE_RECORD, 2, 0, acName1601, SDO1601},
  {0x1A00, OTYPE_RECORD, 1, 0, acName1A00, SDO1A00},
  {0x1A01, OTYPE_RECORD, 1, 0, acName1A01, SDO1A01},
  {0x1A02, OTYPE_RECORD, 3, 0, acName1A02, SDO1A02},
  {0x1C00, OTYPE_ARRAY, 4, 0, acName1C00, SDO1C00},
  {0x1C12, OTYPE_ARRAY, 2, 0, acName1C12, SDO1C12},
  {0x1C13, OTYPE_ARRAY, 3, 0, acName1C13, SDO1C13},
  {0x6000, OTYPE_RECORD, 1, 0, acName6000, SDO6000},
  {0x6001, OTYPE_VAR, 0, 0, acName6001, SDO6001},
  {0x6002, OTYPE_RECORD, 2, 0, acName6002, SDO6002},
  {0x7000, OTYPE_RECORD, 2, 0, acName7000, SDO7000},
  {0x7001, OTYPE_VAR, 0, 0, acName7001, SDO7001},
  {0x8000, OTYPE_RECORD, 2, 0, acName8000, SDO8000},
  {0xffff, 0xff, 0xff, 0xff, NULL, NULL}
};
