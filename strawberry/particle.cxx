#include "particle.h"
#include "math.h"

void particle::Integrator(strad delta)
{
	if (InverseMass <= 0.0f) {
		return;
	}
	
	assert(delta > 0.0f);

	/* updating linear position */
	position.addScaledVector(velocity, delta);

	Vector2 ResultingAcceleration{ acceleration };
	/* updating linear velocity */
	velocity.addScaledVector(ResultingAcceleration, delta);

	velocity *= powf(drag, delta);
	
	this->ClearAccumulator();
}

void particle::SetPosition(strad x, strad y)
{
	this->position.x = { x };
	this->position.y = { y };
}

void particle::SetVelocity(strad x, strad y)
{
	this->velocity.x = { x };
	this->velocity.y = { y };
}

void particle::SetAcceleration(strad x, strad y)
{
	this->acceleration.x = { x };
	this->acceleration.y = { y };
}

void particle::SetDamping(strad dampingFactor)
{
	this->drag = { dampingFactor };
}

void particle::SetMass(strad mass)
{
	if (mass <= 0.0) return;

	this->InverseMass = { ((strad)1.0 / mass) };
}

void particle::AddForce(const Vector2& force)
{
	ForceAccumulator += force;
}
