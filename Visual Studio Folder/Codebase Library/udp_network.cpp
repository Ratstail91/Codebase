/* File Name: udp_network.cpp
 * Author: Kayne Ruse
 * Date: 16/5/2012
 * Copyright: (c) Kayne Ruse 2012
 * 
 * This file is part of Codebase Library.
 * 
 * Codebase Library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Codebase Library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with Codebase Library.  If not, see <http://www.gnu.org/licenses/>.
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

void UDPNetwork::Send(IPaddress add, void* data, int size) {
	m_pPacketOut->address = add;

	memcpy(m_pPacketOut->data, data, size);
	m_pPacketOut->len = size;

	SDLNet_UDP_Send(m_socket, -1, m_pPacketOut);
}

void UDPNetwork::Send(const char* ip, int port, void* data, int size) {
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
