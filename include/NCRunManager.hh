#ifndef NCRunManager_h
#define NCRunManager_h 1

#include "G4RunManager.hh"
#include "globals.hh"
#include "G4UIterminal.hh"
#include "G4UItcsh.hh"
#include "G4UImanager.hh"
#include "G4UIdirectory.hh"
#include "G4UIcmdWithAnInteger.hh"
#include "G4UIcmdWithoutParameter.hh"


class NCRunManager : public G4RunManager, public G4UImessenger
{
public:
  NCRunManager();
  ~NCRunManager();

  void SetNewValue(G4UIcommand *cmd, G4String args);

private:
  G4UIdirectory* fDirectory;
  G4UIcmdWithoutParameter* fSeedWithTimeCmd;
  G4UIcmdWithAnInteger* fSeedCmd;
};

#endif
