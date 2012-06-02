/* File Name: udp_network.h
 * Author: Kayne Ruse
 * Date: 2/6/2012
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
#ifndef KR_UDPNETWORK_H_
#define KR_UDPNETWORK_H_ 2012060201

#include "SDL_net.h"

class UDPNetwork {
public:
	/* Public access members */
	void Init(int port, int size = 512);
	void Quit();

	void Send(IPaddress add, const void* data, int size);
	void Send(const char* ip, int port, const void* data, int size);
	int Receive();

	/* Accessors and mutators */
	const void* GetDataOut();
	const void* GetDataIn();

	const UDPpacket* GetPacketOut();
	const UDPpacket* GetPacketIn();

	const UDPsocket* GetSocket();

private:
	/* Private access members */
	UDPsocket m_socket;
	UDPpacket* m_pPacketOut;
	UDPpacket* m_pPacketIn;
};

#endif
