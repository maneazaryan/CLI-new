#pragma once
#include <string>
#include "base.h"
class Button: public Base{
        private:
                std::string m_button;
        public:
                Button (int id, int pId, int row , int col, std::string button);
				std::string GetButton()const;
                virtual void Draw()const override;
};
