/* File Name: udp_network.h
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
#ifndef KR_UDPNETWORK_H_
#define KR_UDPNETWORK_H_ 2012062701

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
