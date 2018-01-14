#include "std_lib_facilities.h"
#include "locomotor.h"

void Locomotor::setPowerConsumed(double power)
{
  powerConsumed = power;
}
void Locomotor::setMaxSpeed(int speed)
{
  maxSpeed = speed;
}
double Locomotor::getPowerConsumed()
{
  return powerConsumed;
}
int Locomotor::getMaxSpeed()
{
  return maxSpeed;
}

void Locomotor::displayLocomotor()
{
  cout << "\nName: " << RobotParts::getName() << endl;
  cout << "Part #: " << RobotParts::getPartNumber() << endl;
  cout << "Type: " << RobotParts::getType() << endl;
  cout << "Weight: " << RobotParts::getWeight() << endl;
  cout << "Cost: " << RobotParts::getCost() << endl;
  cout << "Description: " << RobotParts::getDescription() << endl;
  cout << "Power Consumed: " << getPowerConsumed() << endl;
  cout << "Maximum Speed: " << getMaxSpeed() << endl;
}
void Locomotor::saveLocomotorToFile(fstream& myFile)
{
  myFile << "\nName: " << RobotParts::getName() << endl;
  myFile << "Part #: " << RobotParts::getPartNumber() << endl;
  myFile << "Type: " << RobotParts::getType() << endl;
  myFile << "Weight: " << RobotParts::getWeight() << endl;
  myFile << "Cost: " << RobotParts::getCost() << endl;
  myFile << "Description: " << RobotParts::getDescription() << endl;
  myFile << "Power Consumed: " << getPowerConsumed() << endl;
  myFile << "Maximum Speed: " << getMaxSpeed() << endl;
}
void Locomotor::saveLocomotorToProgramFile(fstream& myFile)
{
  myFile << "#" << endl;
  myFile << RobotParts::getType() << endl;
  myFile << RobotParts::getPartNumber() << endl;
  myFile << RobotParts::getName() << endl;
  myFile << RobotParts::getWeight() << endl;
  myFile << RobotParts::getCost() << endl;
  myFile << RobotParts::getDescription() << endl;
  myFile << getPowerConsumed() << endl;
  myFile << getMaxSpeed() << endl;
}
