#include "Server.h"
#include "../WMTS/WMTSI.h"
#include <string>
#include <Windows.h>
#include <time.h>
#include <cstdlib>
#include <iostream>

/*
void outOfMem()
{
	std::cerr << "Unable to satisfy request for memory\n" << std::endl;
	time_t nowtime;
	time(&nowtime);
	tm* cur = localtime(&nowtime);
	std::cout << cur->tm_year + 1900 << "/" << cur->tm_mon << "/" << cur->tm_mday<< " " 
		<< cur->tm_hour << ":" << cur->tm_min << ":" << cur->tm_sec << std::endl;
	std::abort();
}

Server::Server(void)
{
	std::cout << "start server " << std::endl;
}

Server::~Server(void)
{
	std::cout << "end the server: ";
	time_t nowtime;
	time(&nowtime);
	tm* cur = localtime(&nowtime);
	std::cout << cur->tm_year + 1900 << "/" << cur->tm_mon << "/" 
		<< cur->tm_mday<< " " << cur->tm_hour << ":" << cur->tm_min << ":" << cur->tm_sec << std::endl;
}

int
	main(int argc, char* argv[])
{
	//
	// Set the 'BuildId' property displayed in the IceGridAdmin GUI
	//
	
	std::set_new_handler(outOfMem);

	Ice::InitializationData initData;
	initData.properties = Ice::createProperties();
	initData.properties->setProperty("BuildId", std::string("Ice ") + ICE_STRING_VERSION);

	std::cout << "main: " << GetCurrentThreadId() << std::endl;

	Server app;
	
	int status = app.main(argc, argv, initData);

	return status;
}

int
	Server::run(int argc, char*[])
{
	if(argc > 1)
	{
		std::cerr << appName() << ": too many arguments" << std::endl;
		return EXIT_FAILURE;
	}

	std::cout << "main ServerRun: " << GetCurrentThreadId() << std::endl;

	Ice::PropertiesPtr properties = communicator()->getProperties();	
	Ice::ObjectAdapterPtr adapter = communicator()->createObjectAdapter("OWSServerAdapter");
	std::string name, cfgDir;

	name = properties->getProperty("Identity1");
	cfgDir = properties->getProperty("TileEngineCfgFile");
	Ice::Identity id1 = communicator()->stringToIdentity(name);
	WMTSMODULE::WMTSPtr wmts = new WMTSI(name, cfgDir);
	adapter->add(wmts, id1);
	
	adapter->activate();
	communicator()->waitForShutdown();
	
	return EXIT_SUCCESS;
}
*/

int main(int argc, char* argv[])
{
	WMTSServerApplication app;
	return app.main(argc, argv, "WMTS.cfg");
}

int WMTSServerApplication::run( int argc, char* argv[] )
{
	::Ice::ObjectAdapterPtr adapter = communicator()->createObjectAdapter("OWSServerAdapter");

	WMTSMODULE::WMTSPtr servant = new WMTSI("wmts", "TileEngine.cfg");

	adapter->add(servant, communicator()->stringToIdentity("WMTS"));
	adapter->activate();

	communicator()->waitForShutdown();
	return 0;
}