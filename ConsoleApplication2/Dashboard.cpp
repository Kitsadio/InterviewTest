#include "Dashboard.h"
#include "lua.hpp"
#include "easywsclient.hpp"

void Dashboard::Update(std::string state, std::string from)
{
	////attempted to use lua to handle the websocket but troubles with dependancies
	//lua_State *luaState = luaL_newstate();

	//luaL_dofile(luaState, "server.lua");

	//// close the Lua state
	//lua_close(luaState);

	easywsclient::WebSocket::pointer ws = easywsclient::WebSocket::from_url("ws://localhost:3000");

	try
	{
		//Check if nullptr to avoid crash
		if (ws != nullptr)
		{
			//Send both strings together and substr on other side
			ws->send(state + " " + from);

			delete ws;
		}
		else
		{
			//throw if couldn't connect to server
			throw 0;
		}
	}
	catch (...) {
		//Output for log
		std::cout << "COULDN'T CONNECT" << std::endl;
	}
}