#pragma once
//////////////////////////////////////////////////////////////////////////////////////////////////////
// File		: CommWork.h
// Version	: 1.0.1
// Date		: 2019.09.09
// Writer	: Lee, Seungmin (CDSL)
//////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _COMMWORK_H__
#define _COMMWORK_H__

#include "WorkBase.h"
#include "Comm.h"
#include "DataType.h"


//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Class Name	: CCommWork  : public CWorkBase
// Summury		: Communication work class
//////////////////////////////////////////////////////////////////////////////////////////////////////////
class CCommWork : public CWorkBase {

	// Define ////////////////////////////////////////////////////////
public:

protected:

private:


	// Method ////////////////////////////////////////////////////////
public:
	CCommWork(std::string name);
	virtual ~CCommWork();

	bool OpenPort(std::string name, int baudRate);
	void ClosePort();

protected:
	////////////////////////////////////////////////////////////////////////////////////////////
	// Method	: _execute(virtual)
	// Input	: None
	// Output	: None
	// Summury	: Execute ode work.
	////////////////////////////////////////////////////////////////////////////////////////////
	virtual void _execute();

private:


	// Member ////////////////////////////////////////////////////////
public:

protected:

private:

	std::string _memname_tar;
	std::string _memname_cur;
	ControlData_t _target, _current;

	CComm _comm;

	unsigned char _recvBuf[4096];
	unsigned char _writeBuf[4096];

	Packet_t _sendPacket;
	Packet_t _packet;
};

#endif