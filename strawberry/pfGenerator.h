#ifndef PARTICLE_FORCE_GENERATOR__H
#define PARTICLE_FORCE_GENERATOR__H

#include "particle.h"
#include <string>
#include <vector>

class ParticleForceGenerator {
public:
	virtual void UpdateForce(Particle* particle, strad delta) = 0;
};

class GravityGenerator : public ParticleForceGenerator {
	Vector2 Gravity;
public:
	GravityGenerator(strad g) : Gravity{ 0.0, g } { }

	virtual void UpdateForce(Particle* particle, strad delta) override;
};

class ParticleForceRegistry {
	ParticleForceRegistry() = default;
	struct pfGenCombo {
		Particle* particle;
		ParticleForceGenerator* pforceGen;
	};

	std::vector<pfGenCombo> registrations;

public:
	static ParticleForceRegistry* getInstance();

	void UpdateForces(strad delta);
	void add(Particle* particle, ParticleForceGenerator* pfGen);
	
	~ParticleForceRegistry();
};

#endif
