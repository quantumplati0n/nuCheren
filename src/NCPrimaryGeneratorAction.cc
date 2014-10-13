#include "NCPrimaryGeneratorAction.hh"

#include "G4GeneralParticleSource.hh"

NCPrimaryGeneratorAction::NCPrimaryGeneratorAction()
{
  fParticleGun = new G4GeneralParticleSource();
}

void NCPrimaryGeneratorAction::GeneratePrimaries(G4Event* event)
{
  fParticleGun->GeneratePrimaryVertex(event);
}
