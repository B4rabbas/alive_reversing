#pragma once

enum class AnimId
{
    Abe_Head_Gib,
    Abe_Arm_Gib,
    Abe_Body_Gib,

    BlindMud_Head_Gib,
    BlindMud_Arm_Gib,
    BlindMud_Body_Gib,

    Glukkon_Head_Gib,
    Glukkon_Arm_Gib,
    Glukkon_Body_Gib,

    Aslik_Head_Gib,
    Aslik_Arm_Gib,
    Aslik_Body_Gib,

    Dripik_Head_Gib,
    Dripik_Arm_Gib,
    Dripik_Body_Gib,

    Phleg_Head_Gib,
    Phleg_Arm_Gib,
    Phleg_Body_Gib,

    Fleech_Head_Gib,
    Fleech_Body_Gib,

    Metal_Gib,

    Slig_Head_Gib,
    Slig_Arm_Gib,
    Slig_Body_Gib,

    Slog_Head_Gib,
    Slog_Body_Gib,


};

enum class PalId
{
    Default, // Don't override the anims default pal
    BlindMud,
};

struct PalRecord
{
    PalId mId;
    const char* mBanName;
    int mResourceId;
};

struct AnimRecord
{
    AnimId mId;
    const char* mBanName;
    int mFrameTableOffset;
    short mMaxW;
    short mMaxH;
    int mResourceId;
    PalId mPalOverride;
};

const PalRecord& PalRec(PalId toFind);
const AnimRecord& AnimRec(AnimId toFind);

// AE specific resource ids
enum AEResourceID
{
    kUnknownResID_0 = 0,
    kDemoResID = 1,
    kAbebasicResID = 10,
    kAbepullResID = 11,
    kAbepickResID = 12,
    kAbebombResID = 13,
    kAbethrowResID = 14,
    kAbewaspResID = 16,
    kAberingResID = 17,
    kAbesmashResID = 19,
    kAbefallResID = 20,
    kAbestoneResID = 21,
    kAbecrushResID = 22,
    kAbeblowResID = 25,
    kAbeknbkResID = 26,
    kAbeknfdResID = 27,
    kAbeknokzResID = 28,
    kAbeyawnResID = 31,
    kAberubResID = 32,
    kAbesizeResID = 33,
    kAbebordResID = 34,
    kAbeeyesResID = 35,
    kAbebuttResID = 36,
    kAbenutsResID = 37,
    kAbepnlkResID = 38,
    kAbewizzResID = 39,
    kAbetalkResID = 40,
    kAbehoistResID = 42,
    kAbeedgeResID = 43,
    kAbeswingResID = 44,
    kAbedoorResID = 45,
    kAbewellResID = 47,
    kAbeommResID = 48,
    kAbeliftResID = 53,
    kAbebsic1ResID = 55,
    kDovbasicResID = 60,
    kWaspResID = 61,
    kHintflyResID = 62,
    kBatBasicResID = 63,
    kFireFlyResID = 64,
    kDovshootResID = 66,
    kAbemorphResID = 117,
    kAbegasResID = 118,
    kShrmorphResID = 121,
    kUnknownResID_125 = 125,
    kAbespeakResID = 130,
    kAbeintroResID = 131,
    kAbespek2ResID = 132,
    kHappyiconResID = 201,
    kAngryiconResID = 202,
    kNormaliconResID = 203,
    kBgexpldResID = 300,
    kExplo2ResID = 301,
    kAlrmFlarResID = 302,
    kDustResID = 303,
    kHubFireResID = 304,
    kVaporResID = 305,
    kSlurgResID = 306,
    kGreeterResID = 307,
    kOmmflareResID = 312,
    kPortalTerminatorID = 313,
    kSparksResID = 314,
    kSpotliteResID = 316,
    kSkiddustResID = 317,
    kSmokeResID = 318,
    kBigflashResID = 319,
    kWorkwhelResID = 320,
    kHoneyResID = 337,
    kWellLeafResID = 341,
    kSquibResID = 343,
    kZflashResID = 344,
    kFxflareResID = 348,
    kDeathFlareResID = 349,
    kAberockResID = 350,
    kPortliteResID = 351,
    kPortlitResID = 353,
    kSquibSmokeResID = 354,
    kSplineResID = 355,
    kDrpRockResID = 357,
    kStickResID = 358,
    kShellResID = 360,
    kGlowResID = 361,
    kDoaexploResID = 363,
    kMetalResID = 365,
    kBloodropResID = 366,
    kOptflareResID = 367,
    kWdropResID = 368,
    kSplashResID = 369,
    kAntResID = 370,
    kDanliteResID = 371,
    kSmallExplo2ResID = 372,
    kUnknownResID_374 = 374,
    kTorturedMudTearsResID = 375,
    kSlgbasicResID = 412,
    kSlgsleepResID = 413,
    kSlgknbkResID = 414,
    kSlgedgeResID = 415,
    kSlgsmashResID = 416,
    kSlgzshotResID = 417,
    kSlgknfdResID = 418,
    kSlgleverResID = 419,
    kSlgliftResID = 420,
    kSligBlowResID = 423,
    kSlgbeatResID = 426,
    kUnknownResID_448 = 448,
    bUnknownResID_449 = 449,
    kFlySligResID = 450,
    kMudscrubResID = 510,
    kMudchslResID = 511,
    kMudidleResID = 512,
    kMudoduckResID = 514,
    kAbeworkResID = 515,
    kMudltusResID = 516,
    kMudbtlnkResID = 517,
    kTorturedMud = 518,
    kMudangryResID = 530,
    kMudsadResID = 531,
    kMudwiredResID = 532,
    kMudblindResID = 533,
    kMudsickResID = 534,
    kMudombieResID = 550,
    kDogbasicResID = 570,
    kDogrstnResID = 571,
    kDogattkResID = 572,
    kDogknfdResID = 573,
    kDogidleResID = 574,
    kSlogBlowResID = 576,
    kUnknownResID_580 = 580,
    kUnknownResID_590 = 590,
    kBoneResID = 591,
    kArjbasicResID = 600,
    kArjeatResID = 601,
    kArjclimbResID = 604,
    kArjpumpResID = 605,
    kArjscrchResID = 609,
    kArjwaspResID = 610,
    kArjjumpResID = 611,
    kArjponceResID = 614,
    kArjfalrkResID = 615,
    kArsbasicResID = 700,
    kArseatResID = 701,
    kArsprceResID = 702,
    kArsskwrResID = 703,
    kArswhirlResID = 704,
    kArshowlResID = 705,
    kArsdanceResID = 706,
    kArssackResID = 707,
    kArsdeadResID = 708,
    kArsroarResID = 709,
    kArsgrwlResID = 710,
    kArschewResID = 711,
    kArscrshResID = 713,
    kGlkbasicResID = 800,
    kUnknownResID_801 = 801,
    kGlukAslikResID = 802,
    kUnknownResID_803 = 803,
    kGlukDripikResID = 804,
    kUnknownResID_805 = 805,
    kGlukPhlegResID = 806,
    kUnknownResID_807 = 807,
    kGlukredResID = 825,
    kGlukgrenResID = 826,
    kGlukblueResID = 827,
    kGlukaquaResID = 828,
    kFleechResID = 900,
    kRopesResID = 1000,
    kPulleyResID = 1001,
    kP2c2bagResID = 1002,
    kP5c1wlkResID = 1003,
    kP6c1trapResID = 1004,
    kBombResID = 1005,
    kGrenflshResID = 1006,
    kP4c5hiveResID = 1008,
    kSwitchResID = 1009,
    kBombflshResID = 1011,
    kP2c3HiveResID = 1013,
    kPullringResID = 1014,
    kP6c4tubeResID = 1017,
    kP7c1spikResID = 1018,
    kHammerResID = 1019,
    kCrystalResID = 1030,
    kLiftResID = 1032,
    kLandmineResID = 1036,
    kTbombResID = 1037,
    kBGStarResID = 1039,
    kMineflshResID = 1040,
    kP1c3tubeResID = 1050,
    kUnknownResID_1053 = 1053,
    kUnknwonResID_1057 = 1057,
    kDebrisID00 = 1105,
    kTubeResID = 1200,
    kF2zballResID = 2001,
    kF2stnbalResID = 2002,
    kF2stnsckResID = 2003,
    kChimeResID = 2005,
    kF2eyeorbResID = 2008,
    kMaimGameResID = 2006,
    kF2rockResID = 2007,
    kPupilResID = 2009,
    kTriggerResID = 2010,
    kF2p3dorResID = 2012,
    kUnknownResID_2013 = 2013,
    kFlintLockResID = 2017,
    kRockdoorResID = 2018,
    kHubdoorResID = 2019,
    kSlamResID = 2020,
    kGourdResID = 2028,
    kMeatResID = 2023,
    kF2ChimeBallResID = 2024,
    kF2ChimeRackResID = 2025,
    kWebResID = 2034,
    kRockShadowResID = 2035,
    kTestanimResID = 2000,
    kMovebombResID = 3006,
    kD2elumResID = 4002,
    kElecwallResID = 6000,
    kMotionResID = 6001,
    kMflareResID = 6002,
    kMeatsawResID = 6003,
    kGrenadeResID = 6005,
    kR1sdoorResID = 6006,
    kR1buttonResID = 6008,
    kR1bpipeResID = 6009,
    kUnknownResID_6027 = 6027,
    kTwnkleResID = 7012,
    kControlsResID = 8000,
    kDoorResID = 8001,
    kHighliteResID = 8002,
    kHighlitePalResID = 8003,
    kLoadingResID = 8010,
    kAbeCarResId = 113,
    kStatusLightResID = 373,
    kEvilFartResID = 6017,
    kDrillResID = 6004,
    kUnknownResID_6013 = 6013,
    kUnknownResID_6016 = 6016,
    kSligSpeakResID = 140,
    kGlukkonSpeakResID = 150,
    kParamiteSpeakResID = 160,
    kScrabSpeakResID = 170,
};
