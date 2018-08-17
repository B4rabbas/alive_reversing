#pragma once

#include "FunctionFwd.hpp"
#include "BaseGameObject.hpp"
#include "Psx.hpp"
#include "FixedPoint.hpp"

#pragma pack(push)
#pragma pack(2)
class Camera // TODO: May actually just be "ResourceList" ?
{
public:
    Camera();
public:
    EXPORT void ctor_480DD0();
    EXPORT void dtor_480E00();
    EXPORT static void CC On_Loaded_480ED0(Camera* pCamera);

    DynamicArrayT<BYTE*> field_0;
    BYTE** field_C_pCamRes;
    int field_10_camera_resource_id;
    __int16 field_14_xpos;
    __int16 field_16_ypos;
    __int16 field_18_path;
    __int16 field_1A_level;
    __int16 field_1C_camera_number;
    char field_1E_cam_name[12];
    int field_2A;
    __int16 field_2E;
    __int16 field_30_flags;
};
#pragma pack(pop)
ALIVE_ASSERT_SIZEOF(Camera, 0x32);

struct DirtyBits
{
    WORD mData[20]; // 20 Columns

    bool GetTile(int x, int y)
    {
        return mData[x] & (1 << y);
    }

    void SetTile(int x, int y, bool b)
    {
        if (b)
        {
            mData[x] |= 1 << y;
        }
        else
        {
            mData[x] &= ~(1 << y);
        }
    }
};

namespace Oddlib
{
    struct BitsLogic;
}

class ScreenManager : public BaseGameObject
{
public:
    // TODO
    EXPORT void sub_40EE10();

    EXPORT void MoveImage_40EB70();

    EXPORT void InvalidateRect_40EC90(int x, int y, signed int width, signed int height, int idx);
    EXPORT void InvalidateRect_40EC10(int x, int y, signed int width, signed int height);
    EXPORT void InvalidateRect_Layer3_40EDB0(int x, int y, signed int width, signed int height);

    EXPORT __int16 IsDirty_40EBC0(int idx, int x, int y);
    EXPORT void UnsetDirtyBits_40EDE0(int idx);
    EXPORT void UnsetDirtyBits_FG1_40ED70();

    virtual void VDestructor(signed int flags) override;

    void process_segment(WORD* aVlcBufferPtr, int xPos);
    void vlc_decode(WORD* aCamSeg, WORD* aDst);
    void vlc_decoder(int aR, int aG, int aB, signed int aWidth, int aVramX, int aVramY);
    void write_4_pixel_block(const Oddlib::BitsLogic& aR, const Oddlib::BitsLogic& aG, const Oddlib::BitsLogic& aB, int aVramX, int aVramY);

    EXPORT void sub_cam_vlc_40EF60(WORD** ppBits);

    EXPORT void ctor_40E3E0(BYTE** ppBits, FP_Point* pCameraOffset);
    
    EXPORT void Init_40E4B0(int ppBits);
   

    EXPORT void dtor_40E460(signed int flags);
    int next_bits();

private:
public:
    FP_Point* field_20_pCamPos;
    int field_24_screen_blocks;
    int field_28;
    PSX_RECT field_2C_rect;
    int field_34;
    __int16 field_38;
    unsigned __int16 field_3A;
    int field_3C;
    int field_40_flags;
    int field_44;
    int field_48;
    int field_4C;
    int field_50;
    int field_54;
    int field_58;
    int field_5C;
    int field_60;
    DirtyBits field_64_20x16_dirty_bits[8];

    signed int g_left7_array = 0;
    int g_right25_array = 0;
    unsigned short int* g_pointer_to_vlc_buffer = nullptr;
};
//ALIVE_ASSERT_SIZEOF(ScreenManager, 0x1A4u);

ALIVE_VAR_EXTERN(ScreenManager*, pScreenManager_5BB5F4);

namespace Test
{
    void ScreenManagerTests();
}
