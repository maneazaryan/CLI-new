#pragma once
#include <string>
#include "base.h"
class Button: public Base{
        private:
                std::string m_button;
        public:
                Button (int id, std::string button, int pId, int row, int col ):
                        Base(id, row, col, pId), m_button(button) {}
		std::string GetButton()const;
                virtual void Print()const override;
};
