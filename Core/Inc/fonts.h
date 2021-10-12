/* vim: set ai et ts=4 sw=4: */
#ifndef __FONTS_H__
#define __FONTS_H__

#include <stdint.h>

typedef struct {
    const uint16_t *data;
} FontDef;


extern FontDef Bellmt_27x26;
extern FontDef BerlinSansFB_22x23;
extern FontDef Microsoft_Yi_Baiti14x15;
extern FontDef Segoe_Print29x43;
extern FontDef Mistral_14x23;

#endif // __FONTS_H__
