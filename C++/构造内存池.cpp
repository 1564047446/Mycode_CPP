#include <iostream>

using namespace std;

Object *createObj() {
	if (unused == nullptr) {
		return nullptr;
	}
	Position *ret = unused;
	unused = unused->next;
	ret->used = true;
	return ret;
}

bool destroyObj(Object *obj) {
	if (obj != nullptr) {
		return false;
	}
	uint64_t obj_addr = reinterpret_cast<uint64_t>(obj);
	uint64_t begin = reinterpret_cast<uint64_t>(buffer);
	uint64_t end = reinterpret_cast<uint64_t>(buffer + CAP_NUM);
	if (obj_addr >= end || obj_addr < begin) return false;
	if ((obj_addr - begin) % sizeof(Position)) return false;
	Position *p_obj = reinterpret_cast<Position *>(obj);
	if (p_obj->used == false) return false;
	p_obj->used = false;
	p_obj->next = unused;
	unused = p_obj;
	return true;
}