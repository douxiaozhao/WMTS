#pragma once
#include <Ice/Ice.h>

/*
 * @brief Ice��������
 */
/*
class Server :
	public Ice::Application
{
public:
	Server(void);
	~Server(void);
	virtual int run(int argc, char*[]);
};
*/


class WMTSServerApplication : virtual public Ice::Application{
public:
	virtual int run (int, char*[]);
};