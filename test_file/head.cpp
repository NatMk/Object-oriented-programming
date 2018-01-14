#include "std_lib_facilities.h"
#include "head.h"
#include "robotParts.h"

void Head::displayHeads()
{
  cout << "\nName: " << RobotParts::getName() << endl;
  cout << "Part #: " << RobotParts::getPartNumber() << endl;
  cout << "Type: " << RobotParts::getType() << endl;
  cout << "Weight: " << RobotParts::getWeight() << endl;
  cout << "Cost: " << RobotParts::getCost() << endl;
  cout << "Description: " << RobotParts::getDescription() << endl;
}
void Head::saveHeadToFile(fstream& myFile)
{
  myFile << "\nName: " << RobotParts::getName() << endl;
  myFile << "Part #: " << RobotParts::getPartNumber() << endl;
  myFile << "Type: " << RobotParts::getType() << endl;
  myFile << "Weight: " << RobotParts::getWeight() << endl;
  myFile << "Cost: " << RobotParts::getCost() << endl;
  myFile << "Description: " << RobotParts::getDescription() << endl;
}

void Head::saveHeadToProgramFile(fstream& myFile)
{
  myFile << "#" << endl;
  myFile << RobotParts::getType() << endl;
  myFile << RobotParts::getPartNumber() << endl;
  myFile << RobotParts::getName() << endl;
  myFile << RobotParts::getWeight() << endl;
  myFile << RobotParts::getCost() << endl;
  myFile << RobotParts::getDescription() << endl;
}
