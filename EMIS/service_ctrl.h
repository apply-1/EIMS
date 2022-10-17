#ifndef SERVICE_CTRL_H
#define SERVICE_CTRL_H

#include "shelf.h"
#include "good.h"

class ServiceCtrl
{
public:
	virtual ~ServiceCtrl(void)	{}
	virtual bool addShelf(Shelf& shelf) = 0;
	virtual int delShelf(int id) = 0;
	virtual vector<Shelf>& listShelf(void) = 0;
	virtual bool addGood(int id,Good& good) = 0;
	virtual bool delGood(int id) = 0;
	virtual bool modGood(int id,Good& good) = 0;
	virtual Shelf* listGood(int id) = 0;
	virtual vector<Shelf>& listAllGood(void) = 0;
};

#endif//SERVICE_CTRL_H
