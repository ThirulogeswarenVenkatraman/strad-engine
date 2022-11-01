#ifndef _PARTICLE__H
#define _PARTICLE__H

// #define NDEBUG
#include <assert.h>

#include "vector2d.h"
#include "float.h"

class Particle { // point masses
	Vector2 position;
	Vector2 velocity;
	Vector2 acceleration;

	strad drag; /* damping factor */
	strad InverseMass;

	Vector2 ForceAccumulator;
public:
	void Integrator(strad delta);

	strad getX() { return position.x; }
	strad getY() { return position.y; }
	strad getMass();

	void SetPosition(strad x, strad y);
	void SetVelocity(strad x, strad y);
	void SetAcceleration(strad x, strad y);

	void SetDamping(strad dampingFactor);
	void SetMass(strad mass);

	void ClearAccumulator() { ForceAccumulator.clear(); }
	void AddForce(const Vector2& force);
	bool isStaticBody();
};

#endif 
