#include "tp_math_utils/DistanceToRay.h"

namespace tp_math_utils
{

//##################################################################################################
// Copyright 2001 softSurfer, 2012 Dan Sunday
// This code may be freely used, distributed and modified for any purpose
// providing that this copyright notice is included with it.
// SoftSurfer makes no warranty for this code, and cannot be held
// liable for any real or imagined damage resulting from its use.
// Users of this code must verify correctness for their application.
float distanceToRay(const glm::vec3& point, const Ray& ray, glm::vec3& pointOnRay)
{
  glm::dvec3 v = ray.p1 - ray.p0;
  glm::dvec3 w = point - ray.p0;

  double c1 = glm::dot(w,v);
  double c2 = glm::dot(v,v);
  double b = c1 / c2;

  pointOnRay = glm::dvec3(ray.p0) + b * v;
  return glm::distance(point, pointOnRay);
}

}
