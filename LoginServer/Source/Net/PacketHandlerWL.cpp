#include "PacketHandlerWL.hpp"

#include <Metazion/Share/Misc/MemoryInputStream.hpp>

#include "Common/Packet/PacketML.hpp"
#include "Common/Packet/PacketLM.hpp"

#include "ServerApp.hpp"

void PacketHandlerWL::Handle(ServerSocketWL* socket
    , int command, const void* data, int length) {
    ::printf("Command[%d] data[%p] length[%d]\n", command, data, length);

    switch (command) {
    case COMMAND_ML_CONNECTED:
        HandleMLConnected(socket, data, length);
        break;
    case COMMAND_ML_DISCONNECTED:
        HandleMLDisconnected(socket, data, length);
        break;
    case COMMAND_ML_SERVERLOGIN:
        HandleMLServerLogin(socket, data, length);
        break;
    default: break;
    }
}

void PacketHandlerWL::HandleMLConnected(ServerSocketWL* socket
    , const void* data, int length) {

}

void PacketHandlerWL::HandleMLDisconnected(ServerSocketWL* socket
    , const void* data, int length) {

}

void PacketHandlerWL::HandleMLServerLogin(ServerSocketWL* socket
    , const void* data, int length) {
    NS_MZ_SHARE::MemoryInputStream inputStream;
    inputStream.Attach(data, length);

    int8_t id = 0;
    inputStream.ReadInt8(id);

    auto serverGroup = g_serverApp->m_serverGroupManager.GetServerGroup(id);
    if (NS_MZ::IsNull(serverGroup)) {
        return;
    }

    int8_t status = 0;
    inputStream.ReadInt8(status);

    serverGroup->SetStatus(status);

    int8_t addressSize = 0;
    inputStream.ReadInt8(addressSize);

    for (auto index = 0; index < addressSize; ++index) {
        uint32_t ip = 0;
        inputStream.ReadUint32(ip);
        uint16_t port = 0;
        inputStream.ReadUint16(port);

        NS_MZ_NET::Address address;
        address.m_ip = ip;
        address.m_port = port;

        serverGroup->AppendAddress(address);
    }
}