#pragma once

#include "FunctionFwd.hpp"
#include "PathData.hpp"
#include "Map.hpp"
#include "BaseAnimatedWithPhysicsGameObject.hpp"

START_NS_AO

enum class LevelIds : __int16;

enum class eDoorStates : __int16
{
    eOpen_0 = 0,
    eClosed_1 = 1,
    eOpening_2 = 2,
    eClosing_3 = 3,
};

struct Path_Door : public Path_TLV
{
    LevelIds field_18_level;
    __int16 field_1A_path;
    __int16 field_1C_camera;
    __int16 field_1E_scale;
    unsigned __int16 field_20_door_number;
    __int16 field_22_id;
    __int16 field_24_target_door_number;
    eDoorStates field_26_start_state;
    __int16 field_28_door_closed;
    __int16 field_2A_hubs[8];
    __int16 field_3A_wipe_effect;
    __int16 field_3C_movie_number;
    __int16 field_3E_x_offset;
    __int16 field_40_y_offset;
    __int16 field_42_wipe_x_org;
    __int16 field_44_wipe_y_org;
    __int16 field_46_abe_direction;
};
ALIVE_ASSERT_SIZEOF_ALWAYS(Path_Door, 0x48);

class Door : public BaseAnimatedWithPhysicsGameObject
{
public:

    EXPORT Door* ctor_40E010(Path_Door* pTlv, int tlvInfo);

    EXPORT BaseGameObject* dtor_40E710();

    virtual void VScreenChanged() override;

    EXPORT void VScreenChanged_40EDE0();

    virtual BaseGameObject* VDestructor(signed int flags) override;

    EXPORT Door* Vdtor_40EDF0(signed int flags);

    EXPORT BOOL vIsOpen_40E800();

    EXPORT void vOpen_40E810();

    EXPORT void vClose_40E830();

    EXPORT void vSetOpen_40E850();

    EXPORT void vSetClosed_40E860();

    EXPORT void PlaySound_40E780();

    virtual void VUpdate() override;

    EXPORT void VUpdate_40E870();

    int field_D4[4];
    int field_E4_tlvInfo;
    eDoorStates field_E8_start_state;
    __int16 field_EA_door_number;
    eDoorStates field_EC_current_state;
    __int16 field_EE_door_closed;
    __int16 field_F0_switch_id;
    __int16 field_F2_hubs_ids[8];
    __int16 field_102_pad;
};
ALIVE_ASSERT_SIZEOF(Door, 0x104);

END_NS_AO
