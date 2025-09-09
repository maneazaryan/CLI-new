#include "manage.h"
Manage* Manage::m_pManage=nullptr;
Manage* Manage::GetInstance()
{
	if(m_pManage==nullptr)
	{
		m_pManage =  new Manage();
	}
	return m_pManage;
}

void Manage::DeleteInstance()
{
	delete m_pManage;
	m_pManage = nullptr;
}

const std::multimap<int, Base*>& Manage::GetElements() const {
    return m_mElements;
}
Window* Manage::FindWindow(int pId)
{
		std::multimap<int, Base*>::iterator it = m_mElements.find(pId);
		if(it!= m_mElements.end())
		{
				Window* w= dynamic_cast<Window*>(it-> second);
				if(w)
				{
						return w;
				}
		}
		return nullptr;
}

void Manage::AddElement(Base* base)
{
		m_mElements.insert({base->GetpId(), base});
}
Manage::~Manage()
{
		for (std::map<int, Base*>::iterator it = m_mElements.begin(); it != m_mElements.end(); ++it)
				delete it->second;
}
