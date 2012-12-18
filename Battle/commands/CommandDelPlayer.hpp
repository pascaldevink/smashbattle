#ifndef __COMMAND_DEL_PLAYER__HPP__
#define __COMMAND_DEL_PLAYER__HPP__

#include "Command.hpp"

class CommandDelPlayer : public Command
{
public:

	CommandDelPlayer() : Command(Command::Types::DelPlayer) 
	{
		memset(&data, 0x00, sizeof(data));
	}
	~CommandDelPlayer() {	}

	virtual void * getData() { return &data; };
	virtual size_t getDataLen() { return sizeof(data); };

	struct
	{
		Uint32 time;
		char client_id;
	} data;
};


#endif //__COMMAND_DEL_PLAYER__HPP__