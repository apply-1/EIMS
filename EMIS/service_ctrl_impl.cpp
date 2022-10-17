#include "service_mode_impl.h"
#include "service_ctrl_impl.h"

ServiceCtrlImpl::ServiceCtrlImpl(void)
{
	srcMode = new ServiceModeImpl;
	srcMode->load(shelfArr);
}

ServiceCtrlImpl::~ServiceCtrlImpl(void)
{
	srcMode->save(shelfArr);
	delete srcMode;
}


bool ServiceCtrlImpl::addShelf(Shelf& shelf)
{
	shelf.setId(get_shelfid());
	shelfArr.push_back(shelf);
	return true;
}

int ServiceCtrlImpl::delShelf(int id)
{
	vector<Shelf>::iterator it;
	for(it=shelfArr.begin(); it!=shelfArr.end(); it++)
	{
		if(id == it->getId())
		{
			shelfArr.erase(it);
			return true;
		}
	}
	return false;
}

vector<Shelf>& ServiceCtrlImpl::listShelf(void)
{
	return shelfArr;
}

bool ServiceCtrlImpl::addGood(int id,Good& good)
{
	for(unsigned int i=0; i<shelfArr.size(); i++)
	{
		if(id == shelfArr[i].getId())
		{
			good.setId(get_goodid());
			shelfArr[i].goodArr.push_back(good);
			return true;
		}
	}
	return false;
}

bool ServiceCtrlImpl::delGood(int id)
{
	for(vector<Shelf>::iterator it=shelfArr.begin(); it!=shelfArr.end(); it++)
	{
		for(vector<Good>::iterator git=it->goodArr.begin(); git!=it->goodArr.end(); git++)
		{
			if(id == git->getId())
			{
				it->goodArr.erase(git);
				return true;
			}
		}	
	}
	return false;
}

bool ServiceCtrlImpl::modGood(int id,Good& good)
{
	for(vector<Shelf>::iterator it=shelfArr.begin(); it!=shelfArr.end(); it++)
	{
		for(vector<Good>::iterator git=it->goodArr.begin(); git!=it->goodArr.end(); git++)
		{
			if(id == git->getId())
			{
				if(good.getName())
					git->setName(good.getName());
				if(good.getDate())
					git->setDate(good.getDate());
				if(good.getPhone())
					git->setPhone(good.getPhone());					
				return true;
			}
		}	
	}
	return false;
}

Shelf* ServiceCtrlImpl::listGood(int id)
{
	for(vector<Shelf>::iterator it=shelfArr.begin(); it!=shelfArr.end(); it++)
	{
		if(id == it->getId())
		{
			return &(*it);
		}
	}
	return NULL;
}

vector<Shelf>& ServiceCtrlImpl::listAllGood(void)
{
	return shelfArr;
}

