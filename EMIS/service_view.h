#ifndef SERVICE_VIEW_H
#define SERVICE_VIEW_H

class ServiceView
{
public:
	virtual ~ServiceView(void)	{};
	virtual void menuSrc(void) = 0;
	virtual void addShelf(void) = 0;
	virtual void delShelf(void) = 0;
	virtual void listShelf(void) = 0;
	virtual void addGood(void) = 0;
	virtual void delGood(void) = 0;
	virtual void modGood(void) = 0;
	virtual void listGood(void) = 0;
	virtual void listAllGood(void) = 0;
};

#endif//SERVICE_VIEW_H
