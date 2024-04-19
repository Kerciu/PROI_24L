#pragma once
#include <vector>
#include <memory>
#include "Figure.h"

class Collection
{
private:
	std::vector<std::unique_ptr<Figure>> pointerCollection;

	void createPointerIfAdded(const Figure& fig) {
		auto ptr = std::make_unique<Figure>(fig);
		pointerCollection.push_back(std::move(ptr));
	}
};
