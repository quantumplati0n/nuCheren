#ifndef NCDetectorConstruction_h
#define NCDetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"

class G4PhysicalVolume;

class NCDetectorConstruction : public G4VUserDetectorConstruction
{
public:
  virtual G4VPhysicalVolume* Construct();
};

#endif
