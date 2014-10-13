#ifndef NCPrimaryGeneratorAction_h
#define NCPrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"

class G4Event;
class G4GeneralParticleSource;

class NCPrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction {
public:
  virtual void GeneratePrimaries(G4Event*);
  NCPrimaryGeneratorAction();

private:
  G4GeneralParticleSource* fParticleGun;
};

#endif
