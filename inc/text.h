#pragma once
#include <string>
#include "base.h"
class Text: public Base{
        private:
                std::string m_text;
        public:
                Text(int id, int pId, int row, int col, std::string text);
		std::string GetText()const;
                virtual void Draw()const override;
};
