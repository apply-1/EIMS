#include "service_mode_impl.h"

void ServiceModeImpl::load(vector<Shelf>& shelfArr)
{
	ifstream ifs(DATA_SRV_PATH,ios::binary|ios::in);
	if(!ifs)	return;
	
	int index = -1;
	while(true)
	{
		Shelf shelf;
		int cnt = 0;
		ifs >> shelf >> cnt;
		if(!ifs.good())	break;
		shelfArr.push_back(shelf);
		index ++;
		for(int i=0; i<cnt; i++)
		{
			Good good;
			ifs >> good;
			shelfArr[index].goodArr.push_back(good);
		}
	}
	ifs.close();
}
	
void ServiceModeImpl::save(vector<Shelf>& shelfArr)
{
	ofstream ofs(DATA_SRV_PATH,ios::out|ios::binary);
	for(vector<Shelf>::iterator it=shelfArr.begin(); it!=shelfArr.end(); it++)
	{
		ofs << *it << " " << it->goodArr.size() << endl;
		for(vector<Good>::iterator git=it->goodArr.begin(); git!=it->goodArr.end(); git++)
		{
			ofs << *git << endl;
		}
	}
	ofs.close();
}
