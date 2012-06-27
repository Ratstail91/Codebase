/* File Name: udp_network.cpp
 * Author: Kayne Ruse
 * Date: 27/6/2012
 * Copyright: (c) Kayne Ruse 2012
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 * claim that you wrote the original software. If you use this software
 * in a product, an acknowledgment in the product documentation would be
 * appreciated but is not required.
 *
 * 2. Altered source versions must be plainly marked as such, and must not be
 * misrepresented as being the original software.
 *
 * 3. This notice may not be removed or altered from any source
 * distribution.
 *
 * Description:
 *     Manage UDP-based networking.
*/
#include <exception>
#include <string>
#include "udp_network.h"
using namespace std;

//-------------------------
//Public access members
//-------------------------

void UDPNetwork::Init(int port, int size) {
	if (SDLNet_Init()) {
		throw(exception("Failed to initialise SDL_net"));
	}

	if ( (m_socket = SDLNet_UDP_Open(port)) == NULL) {
		throw(exception("Failed to open a UDP socket"));
	}

	if ( (m_pPacketIn = SDLNet_AllocPacket(size)) == NULL) {
		throw(exception("Failed to allocate memory for UDP packet"));
	}

	if ( (m_pPacketOut = SDLNet_AllocPacket(size)) == NULL) {
		throw(exception("Failed to allocate memory for UDP packet"));
	}
}

void UDPNetwork::Quit() {
	SDLNet_FreePacket(m_pPacketOut);
	SDLNet_FreePacket(m_pPacketIn);
	SDLNet_UDP_Close(m_socket);
	SDLNet_Quit();
}

void UDPNetwork::Send(IPaddress add, const void* data, int size) {
	m_pPacketOut->address = add;

	memcpy(m_pPacketOut->data, data, size);
	m_pPacketOut->len = size;

	SDLNet_UDP_Send(m_socket, -1, m_pPacketOut);
}

void UDPNetwork::Send(const char* ip, int port, const void* data, int size) {
	//determine the address
	IPaddress add;

	if (SDLNet_ResolveHost(&add, ip, port)) {
		string sWhat = "Failed to resolve host: ";
		sWhat += ip;
		sWhat += ":";
		sWhat += port;
		throw(exception(sWhat.c_str()));
	}

	Send(add, data, size);
}

int UDPNetwork::Receive() {
	return SDLNet_UDP_Recv(m_socket, m_pPacketIn);
}

//-------------------------
//Accessors and mutators
//-------------------------

const void* UDPNetwork::GetDataOut() {
	return (void*)m_pPacketOut->data;
}

const void* UDPNetwork::GetDataIn() {
	return (void*)m_pPacketIn->data;
}

const UDPpacket* UDPNetwork::GetPacketOut() {
	return m_pPacketOut;
}

const UDPpacket* UDPNetwork::GetPacketIn() {
	return m_pPacketIn;
}

const UDPsocket* UDPNetwork::GetSocket() {
	return &m_socket;
}
