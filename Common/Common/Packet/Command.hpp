#ifndef _COMMON_PACKET_COMMAND_HPP_
#define _COMMON_PACKET_COMMAND_HPP_

enum Command {
    COMMAND_CL_BEGIN = 1001,
    COMMAND_LC_BEGIN = 2001,

    COMMAND_CG_BEGIN = 3001,
    COMMAND_GC_BEGIN = 4001,

    COMMAND_ML_BEGIN = 5001,
    COMMAND_LM_BEGIN = 6001,

    COMMAND_MG_BEGIN = 7001,
    COMMAND_GM_BEGIN = 8001,

    COMMAND_ZG_BEGIN = 9001,
    COMMAND_GZ_BEGIN = 10001,

    COMMAND_ZM_BEGIN = 11001,
    COMMAND_MZ_BEGIN = 12001,
};

#endif // _COMMON_PACKET_COMMAND_HPP_
