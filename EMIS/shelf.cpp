#include "shelf.h"	

Shelf::Shelf(const char* name)
{
	strcpy(m_strName,name);
}

void Shelf::setId(int id)
{
	m_iId = id;
}

void Shelf::setName(const char* name)
{
	strcpy(m_strName,name);
}

int Shelf::getId(void)
{
	return m_iId;
}

char* Shelf::getName(void)
{
	return m_strName;
}

ostream& operator<<(ostream& os,const Shelf& shelf)
{
	return os << shelf.m_iId << " " << shelf.m_strName;
}

istream& operator>>(istream& is,Shelf& shelf)
{
	return is >> shelf.m_iId >> shelf.m_strName;
}
