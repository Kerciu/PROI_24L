#pragma once
#include <vector>
#include <memory>
#include "Figure.h"

class Collection
{
private:
	std::vector<std::unique_ptr<Figure>> pointerCollection;

public:
	Collection(std::unique_ptr<Figure> itemToCollect);
	Collection(std::vector<std::unique_ptr<Figure>> pointerCollection);

	inline void addItem(std::unique_ptr<Figure> item);
	inline std::unique_ptr<Figure> getLastItem();
};
