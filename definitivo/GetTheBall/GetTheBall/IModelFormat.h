#pragma once

class IModelFormat {
public:
	virtual int Load(char* filename) = 0;
	virtual void Draw() = 0;
};
