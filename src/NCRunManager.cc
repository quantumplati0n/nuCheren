#include <iostream>

#include "G4PhysListFactory.hh"

#include "NCRunManager.hh"
#include "NCDetectorConstruction.hh"
#include "NCSteppingAction.hh"
#include "NCEventAction.hh"
#include "NCPrimaryGeneratorAction.hh"

NCRunManager::NCRunManager() {
  SetUserInitialization(new NCDetectorConstruction);
  SetUserInitialization((new G4PhysListFactory)
			->GetReferencePhysList("QGSP_BERT_HP"));

  SetUserAction(new NCPrimaryGeneratorAction);
  NCEventAction *eventAction = new NCEventAction;
  SetUserAction(eventAction);
  SetUserAction(new NCSteppingAction(eventAction));

  fDirectory = new G4UIdirectory("/NC/");
  fDirectory->SetGuidance("Parameters for nuCheren");

  fSeedWithTimeCmd = new G4UIcmdWithoutParameter("/NC/seedWithTime", this);
  fSeedWithTimeCmd->SetGuidance("Seed RNG with UNIX time");
}

NCRunManager::~NCRunManager() {
}

void NCRunManager::SetNewValue(G4UIcommand *cmd, G4String args)
{
  if (cmd == fSeedWithTimeCmd) {
    int seed = time(0);
    G4Random::setTheSeed(seed);
    std::cout << "Seed: " << seed << std::endl;
  } else if (cmd == fSeedCmd) {
    G4int seed = fSeedCmd->GetNewIntValue(args);
    G4Random::setTheSeed(seed);
    std::cout << "Seed: " << seed << std::endl;
  }
}
