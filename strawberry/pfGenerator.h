#ifndef PARTICLE_FORCE_GENERATOR__H
#define PARTICLE_FORCE_GENERATOR__H

#include "particle.h"
#include <vector>

class ParticleForceGenerator {
public:
	virtual void UpdateForce(Particle* particle, strad delta) = 0;
};

class GravityGenerator : public ParticleForceGenerator {
	Vector2 Gravity;
public:
	GravityGenerator(strad g) : Gravity{ 0.0, -g } { }

	void UpdateForce(Particle* particle, strad delta) override {
		if (!particle->isStaticBody()) { return; }

		particle->AddForce(Gravity * particle->getMass());
	}
};

class ParticleForceRegistry {
protected:
	struct ParticleForceRegistration
	{
		Particle* particle;
		ParticleForceGenerator* pforceGen;
	};

	typedef std::vector<ParticleForceRegistration> Registry;
	static Registry registrations;

public:
	void add(Particle* particle, ParticleForceGenerator* pfGen);

	void remove(Particle* particle, ParticleForceGenerator* pfGen);

	void clear();

	static void UpdateForces(strad delta);
};

#endif
