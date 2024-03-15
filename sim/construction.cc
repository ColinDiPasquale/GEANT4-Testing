#include "construction.hh"

MyDetectorConstruction::MyDetectorConstruction() {}

MyDetectorConstruction::~MyDetectorConstruction() {}


G4VPhysicalVolume *MyDetectorConstruction::Construct()
{
    G4NistManager *nist = G4NistManager::Instance(); // Just initializing the thing that holds all the material types
    G4Material *worldMat = nist->FindOrBuildMaterial("G4_Air"); // Volume is made of air
    
    G4Box *solidWorld = new G4Box("solidWorld", 0.5*m, 0.5*m, 0.5*m); // Setting size and shape of the volume. Here, it is a 1x1x1 box

    G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld"); // Implementing the logic

    G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicWorld, "physWorld", 0, false, 0, true); 
    // Putting everything together as well as defining certain things like mother volume and position in the world

    return physWorld;
}

