#include "pfGenerator.h"

ParticleForceRegistry* ParticleForceRegistry::getInstance()
{
	static ParticleForceRegistry* heapPFRegistry{ new ParticleForceRegistry() };
	return heapPFRegistry;
}

ParticleForceRegistry::~ParticleForceRegistry() {
	registrations.clear();
	fprintf(stdout, "Destroyed ParticleForceRegistry\n");
}

void ParticleForceRegistry::UpdateForces(strad delta)
{
	std::vector<pfGenCombo>::iterator i{ registrations.begin() };
	for (; i != registrations.end(); i++) {
		i->pforceGen->UpdateForce(i->particle, delta);
	}
}

void ParticleForceRegistry::add(Particle* particle, ParticleForceGenerator* pfGen)
{
	ParticleForceRegistry::pfGenCombo reg;
	reg.particle = { particle };
	reg.pforceGen = { pfGen };
	registrations.push_back(reg);
}
/*
	//	Gravity 
*/
void GravityGenerator::UpdateForce(Particle* particle, strad delta)
{
	//if (!particle->isStaticBody()) { return; }
	particle->AddForce(Gravity * particle->getMass());
}
