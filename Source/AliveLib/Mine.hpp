#pragma once

#include "FunctionFwd.hpp"
#include "BaseGameObject.hpp"
#include "BaseAliveGameObject.hpp"
#include "Path.hpp"
#include "Factory.hpp"
#include "Animation.hpp"

void Mine_ForceLink();

struct Path_Mine
{
    Path_TLV field_0_mBase;
    __int16 field_10_num_patterns;
    __int16 field_12_pattern;
    __int16 field_14_scale;
    __int16 field_16_disabled_resources;
    int field_18_persists_offscreen;
};
ALIVE_ASSERT_SIZEOF(Path_Mine, 0x1C);

enum Mine_Flags_1BC
{
    e1BC_Bit0 = 0x1,
    e1BC_Bit1 = 0x2,
};

class Mine : public BaseAliveGameObject
{
public:
    virtual void VUpdate() override;
    virtual void VRender(int** pOrderingTable) override;
    virtual void VDestructor(signed int flags) override;
    virtual void VScreenChanged() override;

    EXPORT Mine * ctor_46B120(Path_Mine *pPath, TlvItemInfoUnion tlv);

    EXPORT void Render_46B7A0(int ** pOt);
public:
    BYTE field_116[2];
    WORD field_118;
    WORD field_11A_disabled_resources;
    TlvItemInfoUnion field_11C_tlv;
    DWORD field_120_gnframe;
    AnimationEx field_124_animation;
    BitField32<Mine_Flags_1BC> field_1BC_flags;
};
ALIVE_ASSERT_SIZEOF(Mine, 0x1C0);