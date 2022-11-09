#include "particle.h"
#include "pfGenerator.h"
#include "math.h"

void Particle::Integrator(strad delta)
{
	if (InverseMass <= 0.0f) {
		return;
	}
	
	assert(delta > 0.0f);
	ParticleForceRegistry::getInstance()->UpdateForces(delta);
	Vector2 ResultingAcceleration{ acceleration };

	/* updating linear position */
	position.addScaledVector(velocity, delta);
	/* resulting force */
	ResultingAcceleration.addScaledVector(ForceAccumulator, InverseMass);
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

	this->InverseMass = { ((strad)1.0) / mass };
}

strad Particle::getMass()
{
	if(((strad)1.0 / InverseMass) > 0.0) {
		return ((strad)1.0 / InverseMass);
	}
	else {
		return FLT_MAX;
	}
}

void Particle::AddForce(const Vector2& force)
{
	ForceAccumulator += force;
}

bool Particle::isStaticBody()
{
	if (((strad)1.0 / InverseMass) > 0.0f)
	{
		return true;
	}
	else { return false; }
}
