#include "physics.hh"

MyPhysicsList::MyPhysicsList()
{
    RegisterPhysics (new G4EmStandardPhysics()); // Importing electromagnetic interaction physics
    RegisterPhysics (new G4OpticalPhysics()); // Importing optical photon interaction physics
}

MyPhysicsList::~MyPhysicsList()
{}