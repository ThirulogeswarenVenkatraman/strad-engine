#include "pfGenerator.h"

void ParticleForceRegistry::add(Particle* particle, ParticleForceGenerator* pfGen)
{
	ParticleForceRegistry::ParticleForceRegistration reg;
	reg.particle = { particle };
	reg.pforceGen = { pfGen };
	registrations.push_back(reg);
}

void ParticleForceRegistry::remove(Particle* particle, ParticleForceGenerator* pfGen)
{
	
}

void ParticleForceRegistry::clear()
{
	registrations.clear();
}

void ParticleForceRegistry::UpdateForces(strad delta)
{
	Registry::iterator i{ registrations.begin() };
	for (; i != registrations.end(); i++) {
		i->pforceGen->UpdateForce(i->particle, delta);
	}
}
