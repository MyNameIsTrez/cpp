#pragma once

#include <cstdint>

struct Data;

class Serializer
{
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

private:
	Serializer();
	Serializer(const Serializer &src);
	virtual ~Serializer();
	Serializer &operator=(const Serializer &src);
};
