#ifndef SERVICE_MODE_H
#define SERVICE_MODE_H

#include "shelf.h"

class ServiceMode
{
public:
	virtual ~ServiceMode(void)	{}
	virtual void load(vector<Shelf>& shelfArr) = 0;
	virtual void save(vector<Shelf>& shelfArr) = 0;
};

#endif//SERVICE_MODE_H
