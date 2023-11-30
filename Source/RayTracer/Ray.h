#pragma once
#include "glm/glm.hpp"

struct ray_t
{
	ray_t() = default;
	ray_t(const glm::vec3& origin, const glm::vec3& direction) :
		origin{ origin },
		direction{ direction }
	{}

	glm::vec3 GetPoint(float distance) const { return glm::vec3(origin.x + distance, origin.y + distance, origin.z + distance); }

	glm::vec3 origin;
	glm::vec3 direction;
};