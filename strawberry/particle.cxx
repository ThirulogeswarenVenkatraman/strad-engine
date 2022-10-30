#include "particle.h"
//#include "pfGenerator.h"
#include "math.h"

void Particle::Integrator(strad delta)
{
	if (InverseMass <= 0.0f) {
		return;
	}
	
	assert(delta > 0.0f);

	/* updating linear position */
	position.addScaledVector(velocity, delta);

	Vector2 ResultingAcceleration{ acceleration };
	//ParticleForceRegistry::UpdateForces(delta);
	/* updating linear velocity */
	velocity.addScaledVector(ResultingAcceleration, delta);

	velocity *= powf(drag, delta);
	
	this->ClearAccumulator();
}

void Particle::SetPosition(strad x, strad y)
{
	this->position.x = { x };
	this->position.y = { y };
}

void Particle::SetVelocity(strad x, strad y)
{
	this->velocity.x = { x };
	this->velocity.y = { y };
}

void Particle::SetAcceleration(strad x, strad y)
{
	this->acceleration.x = { x };
	this->acceleration.y = { y };
}

void Particle::SetDamping(strad dampingFactor)
{
	this->drag = { dampingFactor };
}

void Particle::SetMass(strad mass)
{
	if (mass <= 0.0) return;

	this->InverseMass = { ((strad)1.0 / mass) };
}

void Particle::AddForce(const Vector2& force)
{
	ForceAccumulator += force;
}
