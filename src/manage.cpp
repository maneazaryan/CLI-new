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

const std::multimap<int, std::shared_ptr<Base>>& Manage::GetElements() const {
    return m_mElements;
}
std::shared_ptr<Window> Manage::FindWindow(int pId)
{
		std::multimap<int, std::shared_ptr<Base>>::iterator it = m_mElements.find(pId);
		if(it!= m_mElements.end())
		{
				std::shared_ptr<Window> w= std::dynamic_pointer_cast<Window>(it-> second);
				if(w)
				{
						return w;
				}
		}
		return nullptr;
}

void Manage::AddElement(std::shared_ptr<Base> base)
{
		m_mElements.insert({base->GetpId(), base});
}
