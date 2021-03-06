#include "stdafx_ao.h"
#include "Function.hpp"
#include "ZapLine.hpp"
#include "stdlib.hpp"
#include "ResourceManager.hpp"
#include "Map.hpp"

void ZapLine_ForceLink() {}

START_NS_AO

BaseGameObject* ZapLine::VDestructor(signed int flags)
{
    return Vdtor_479B20(flags);
}

BaseGameObject* ZapLine::dtor_478E90()
{
    SetVTable(this, 0x4BCDE8);
    ResourceManager::FreeResource_455550(field_E8_ppRes);
    ao_delete_free_450770(field_128_buf1);
    ao_delete_free_450770(field_12C_buf2);
    ao_delete_free_450770(field_130_buf3);
    return dtor_417D10();
}

ZapLine* ZapLine::ctor_4789A0(FP x1, FP y1, FP x2, FP y2, __int16 aliveTime, signed __int16 type, __int16 layer)
{
    ctor_417C10();
    field_11A_type = type;
    SetVTable(this, 0x4BCDE8);
    field_4_typeId = Types::eZapLine_94;

    int frameTable = 0;
    if (type == 1)
    {
        field_120_count_per_part = 20;
        field_11E_part_count = 12;
        frameTable = 228;
        field_11C_tPageAbr = 3;
    }
    else if (type == 0)
    {
        field_120_count_per_part = 10;
        field_11E_part_count = 28;
        frameTable = 240;
        field_11C_tPageAbr = 1;
    }

    BYTE** ppRes = ResourceManager::GetLoadedResource_4554F0(ResourceManager::Resource_Animation, 355, 1, 0);
    Animation_Init_417FD0(frameTable, 9, 9, ppRes, 1);

    field_10_anim.field_4_flags.Clear(AnimFlags::eBit15_bSemiTrans);
    field_10_anim.field_C_layer = layer;
    field_122_pSprts_count = field_11E_part_count * field_120_count_per_part;

    field_E8_ppRes = ResourceManager::Allocate_New_Locked_Resource_454F80(ResourceManager::Resource_Spline, 0, 48 * field_122_pSprts_count);
    field_124_pSprts = reinterpret_cast<ZapLineSprites*>(*field_E8_ppRes);

    field_128_buf1 = reinterpret_cast<PSX_Point*>(alloc_450740(sizeof(PSX_Point) * field_122_pSprts_count));
    field_12C_buf2 = reinterpret_cast<ZapPoint*>(alloc_450740(sizeof(ZapPoint) * field_120_count_per_part));
    field_130_buf3 = reinterpret_cast<FP_Point*>(alloc_450740(sizeof(FP_Point) * field_11E_part_count));

    field_118_max_alive_time = aliveTime;

    field_A8_xpos = x1;
    field_AC_ypos = y1;

    field_E4_state = 0;
    field_116_alive_timer = 0;

    if (field_10_anim.field_4_flags.Get(AnimFlags::eBit13_Is8Bit))
    {
        field_114_tPageMode = 1;
    }
    else if (field_10_anim.field_4_flags.Get(AnimFlags::eBit14_Is16Bit))
    {
        field_114_tPageMode = 2;
    }
    else
    {
        field_114_tPageMode = 0;
    }

    BYTE u0 = field_10_anim.field_84_vram_rect.x & 0x3F;
    if (field_114_tPageMode == 1)
    {
        u0 = 2 * u0;
    }
    else if (!field_114_tPageMode)
    {
        u0 = 4 * u0;
    }

    auto pFrameHeader = reinterpret_cast<FrameHeader*>(&(*field_10_anim.field_20_ppBlock)[field_10_anim.Get_FrameHeader_403A00(-1)->field_0_frame_header_offset]);

    const BYTE frameW = pFrameHeader->field_4_width;
    const BYTE frameH = pFrameHeader->field_5_height;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < field_11E_part_count; j++)
        {
            for (int k = 0; k < field_120_count_per_part; k++)
            {
                  Prim_Sprt* pSprt = &field_124_pSprts[(j * field_120_count_per_part) + k].field_0_sprts[i];
                  Sprt_Init(pSprt);

                  Poly_Set_SemiTrans_498A40(&pSprt->mBase.header, 1);
                  Poly_Set_Blending_498A00(&pSprt->mBase.header, 1);
                  SetClut(pSprt, static_cast<short>(PSX_getClut_496840(
                      field_10_anim.field_8C_pal_vram_xy.field_0_x,
                      field_10_anim.field_8C_pal_vram_xy.field_2_y)));

                  SetUV0(pSprt, u0, field_10_anim.field_84_vram_rect.y & 0xFF);
                  pSprt->field_14_w = frameW - 1;
                  pSprt->field_16_h = frameH - 1;
            }
        }
    }

    sub_478CF0(x1, y1, x2, y2);

    return this;
}

ZapLine* ZapLine::Vdtor_479B20(signed int flags)
{
    dtor_478E90();
    if (flags & 1)
    {
        ao_delete_free_447540(this);
    }
    return this;
}

void ZapLine::sub_478CF0(FP /*x1*/, FP /*y1*/, FP /*x2*/, FP /*y2*/)
{
    NOT_IMPLEMENTED();
}

void ZapLine::VScreenChanged()
{
    VScreenChanged_479B00();
}

void ZapLine::VScreenChanged_479B00()
{
    if (gMap_507BA8.field_28_cd_or_overlay_num != gMap_507BA8.GetOverlayId_4440B0())
    {
        field_6_flags.Set(BaseGameObject::eDead_Bit3);
    }
}

void ZapLine::VRender(int** ppOt)
{
    VRender_479840(ppOt);
}

void ZapLine::VRender_479840(int** /*ppOt*/)
{
    NOT_IMPLEMENTED();
}

void ZapLine::VUpdate()
{
    VUpdate_4796B0();
}

void ZapLine::VUpdate_4796B0()
{
    NOT_IMPLEMENTED();
}

END_NS_AO
