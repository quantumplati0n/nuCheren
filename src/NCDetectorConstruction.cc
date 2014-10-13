#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4Colour.hh"
#include "G4VisAttributes.hh"

//Include library NCDetectorConstruction.hh
#include "NCDetectorConstruction.hh"

using namespace CLHEP;

G4VPhysicalVolume* NCDetectorConstruction::Construct() 
{
  //Get material from NIST database
  G4NistManager* man = G4NistManager::Instance();

  //To fill the "world" volume with vacuum
  G4Material* vacuum = man->FindOrBuildMaterial("G4_Galactic", false);

  //Get hydrogen and carbon from NIST database to use for detector material       
  //G4Element* hydrogen = man->FindOrBuildElement("H");
  //G4Element* carbon = man->FindOrBuildElement("C");

  //Define detector material-- Get from NIST database
  //G4Material* detectorMat = new G4Material("EJ-301", 0.87*g/cm3, 2);
  //detectorMat->AddElement(carbon, 8);
  //detectorMat->AddElement(hydrogen, 10);
  G4Material* H20 = man->FindOrBuildMaterial("G4_WATER");

  //Attributes? 
  G4VisAttributes* glassVisAtt = new G4VisAttributes(G4Colour(0.5, 0.5, 0.5, 0.3));

  //Creating a detector in 3 steps
  //The first step involves generating a "World Box" that you can put your 
  //Logical volume into
  G4Box* worldBox = new G4Box("worldBox", 125.0*m, 75.0*m, 525.0*m);

  //The second step is to construst the actual logical volume. 
  //Have the solid created above-- worldBox. Fill it with "Vacuum" and name it
  //"worldL"
  G4LogicalVolume* worldL = new G4LogicalVolume(worldBox, vacuum, "worldL");
        worldL->SetVisAttributes(G4VisAttributes::Invisible);

  //Need to position your abstract logical volume and make it physical.
  //A physical volume is simply a placed instance of the logical volume created
  //Here there is an exception for the rule that a physical volume must be placed inside a
  //"mother" volume. It has a null "mother" as its pointer. Hence the 0 after the name
  //"world"
  G4VPhysicalVolume* physWorld = new G4PVPlacement(0, G4ThreeVector(), worldL, "world", 0, false, 0, true);      
  //G4double inch = 2.54*cm;
  //Okay now create a logical volume (detector) to place in the world "mother" volume created above:
  //First create a solid with name "detectorS"
  //of radius 130 m and of length of 1000 meters
  //Dimensions based on the extent of all of IceCube PMTs
  G4Tubs* detectorS = new G4Tubs("detectorS", 0, 1000*m, 500*m, 0, 2.0*pi);
  //Now construct the logical volume by giving the solid attributes...
  //Creates a logical volume called "detectorL"
  //Use the solid cylinder "detectorS" created above, fill with H20
  G4LogicalVolume* detectorL = new G4LogicalVolume(detectorS, H20, "detectorL");
  //Visual Attributes? 
  detectorL->SetVisAttributes(glassVisAtt);
  //Make the logical volume "physical". Name detector, "detector"
  //Assume that all you want to do is place your "detectorL" logical volume
  //into the "worldL" 
  new G4PVPlacement(G4Transform3D::Identity,detectorL, "detector", worldL, false, 0, true);

  return physWorld;
}
