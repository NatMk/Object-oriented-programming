#include "std_lib_facilities.h"
#include <fstream>
/*#include <string>
#include <vector>

using namespace std;
*/
class CreateRobotParts
{

private:

 	vector<Head> allHeads;
 	vector<Torso> allTorsos;
 	vector<Arm> allArms;
 	vector<Locomotor> allLocomotors;
 	vector<Battery> allBatteries;
public:

    CreateRobotParts() {}

 	void createHead();
 	void createTorso();
 	void createArm();
 	void createLocomotor();
 	void createBattery();
 	void showHeads();
 	void showTorsos();
 	void showArms();
 	void showLocomotors();
 	void showBatteries();
 	Torso getTorsoAt(int i);
 	Head getHeadAt(int i);
 	Arm getArmAt(int i);
 	Locomotor getLocomotorAt(int i);
 	Battery getBatteryAt(int i);
 	int getSizeOfHead();
 	int getSizeOfTorso();
 	int getSizeOfArm();
 	int getSizeOfLocomotor();
 	int getSizeOfBattery();
 	void displayParts();
        void saveParts();
        void saveProgramParts();
        void retrieveParts();
};

inline Torso CreateRobotParts::getTorsoAt(int i)
{
  return allTorsos.at(i);
}
inline Head CreateRobotParts::getHeadAt(int i)
{
  return allHeads.at(i);
}
inline Arm CreateRobotParts::getArmAt(int i)
{
  return allArms.at(i);
}
inline Locomotor CreateRobotParts::getLocomotorAt(int i)
{
  return allLocomotors.at(i);
}
inline Battery CreateRobotParts::getBatteryAt(int i)
{
  return allBatteries.at(i);
}
inline int CreateRobotParts::getSizeOfHead()
{
  return allHeads.size();
}
inline int CreateRobotParts::getSizeOfTorso()
{
  return allTorsos.size();
}
inline int CreateRobotParts::getSizeOfArm()
{
  return allArms.size();
}
inline int CreateRobotParts::getSizeOfLocomotor()
{
  return allLocomotors.size();
}
inline int CreateRobotParts::getSizeOfBattery()
{
  return allBatteries.size();
}


class Customer
{
    public:

        void setName(string n);
        string getName();

    private:

        string name;
};

class Head : public RobotParts
{
public:
  Head()
  {

  };
  Head(string n, int p, string t, double w, double c, string d) : RobotParts(n, p, t, w, c, d){};
  void displayHeads();
  void saveHeadToFile(fstream& myFile);
  void saveHeadToProgramFile(fstream& myFile);
};

class Locomotor : public RobotParts
{

  private:

     double powerConsumed;
     int maxSpeed;

  public:

  	Locomotor()
  	{
    
  	};
       Locomotor(string n, int p, string t, double w, double c, string d, double power, int speed) : RobotParts(n, p, t, w, c, d){
       powerConsumed = power;
       maxSpeed = speed;
  };
  void setPowerConsumed(double power);
  double getPowerConsumed();
  void setMaxSpeed(int speed);
  int getMaxSpeed();
  void displayLocomotor();
  void saveLocomotorToFile(fstream& myFile);
  void saveLocomotorToProgramFile(fstream& myFile);
};

class Orders
{
public:
  double getTotalPrice();
  void setTotalPrice(double price);
  double calculateShipping();
  void createOrders(RobotModels models, SalesAssociate associate);
  void getTime();
  int getOrderNumber();
  void setOrderNumber();
  void displayOrders();
  int orderHistory( string n );                                //add
  void viewCustBill( string n, RobotModels models);                                    //add
  double printOrderHistory( int i, int j );                         //add
  int salesHistory( string n );                                //add
  
private:
  double totalPrice = 0;
  double shippingCost;
  SalesAssociate associate;
  Customer customer;            //added
  
  int orderNumber;         // let the system generate a order # using random() or some function like that
  vector <int> quantities;
  vector<int> cart;
  string custName;
  vector <Orders> allOrders;
  string token;                     //add
  int index = 0;                    //add
  
};

class RobotModels
{
  friend class Orders;
private:
  struct model
 	{
    string modelName;
    string modelNumber;
    double modelPrice;
    Torso torso;
    Locomotor locomotor;
    Head head;
    vector<Arm> arms;
    vector<int> batteries;
 	};
 	vector <model> allModel;
 	int armSize;
 	int batterySize;
 	vector<double> partsCost;
 	double totalPartsCost;
  vector<int> fileIndexes;        // these indexes are store to a file for later use to access data
public:
  RobotModels();
  void createRobotModels(CreateRobotParts&);
  void displayRobotModel();
  double getTotalPartsCost();
  void calculateTotalPartsCost();
  void display(int index);
  double getModelPrice(int i);
  void saveModel();
  void saveProgramModel();
  void retrieveModel(CreateRobotParts &p);
  
};
inline double RobotModels::getTotalPartsCost()
{
  return totalPartsCost;
}

class SalesAssociate
{
    public:

      void setName(string n);
      string getName();

   private:
       string name;
};

class Torso : public RobotParts
{
private:
  int batteryCompartments;
public:
  Torso(string n, int p, string t, double w, double c, string d, int b) : RobotParts(n, p, t, w, c, d){
    batteryCompartments = b;
  };
  void setBatteryCompartments(int b);
  int getBatteryCompartments();
  Torso()
  {
    batteryCompartments = -1;
  }
  //friend ostream &operator<<(ostream &output, const Torso &t);
  void displayTorso(ostream &output, Torso &t);
  void displayTorso();
  void saveTorsoToFile(fstream& myFile);
  void saveTorsoToProgramFile(fstream& myFile);
};

class View
{
   public:
     View();
     void main_menu();
     void report_menu();
     void createParts_menu();
     void createModels_menu();
     void print_documentation();
     void userSelection();
     void customerOrderOptions();
     void salesOrderOptions();
};

class RobotParts
{
   protected:
   	string name;
   	int partNumber;
   	string type;
   	double weight;
   	double cost;
   	string description;

   public:
   	RobotParts(string n, int p, string t, double w, double c, string d);
   	RobotParts();
   	void setName(string n);
   	void setPartNumber(int p);
   	void setType(string t);
   	void setWeight(double w);
   	void setCost(double c);
   	void setDescription(string d);
   	string getName();
   	int getPartNumber();
   	string getType();
   	double getWeight();
   	double getCost();
   	string getDescription();

};

class Controller
{
     private:

        CreateRobotParts& parts;
        RobotModels& model;
        Orders& orders;

     public:

        Controller (CreateRobotParts& constructorOf, RobotModels& constructor, Orders& orderConst) : parts(constructorOf), model(constructor), orders(orderConst) {};
        void partsController();
        void modelController();
        void showControllerMenu();
        void ordersController();
        void customerController();
};

class Battery : public RobotParts
{
  private:

      double energyContained;

  public:

  Battery(string n, int p, string t, double w, double c, string d, double energy) : RobotParts(n, p, t, w, c, d)
  {
    energyContained = energy;
  };

  void setEnergyContained(double energy);
  double getEnergyContained();
  void displayBattery();
  void saveBatteryToFile(fstream& myFile);
  void saveBatteryToProgramFile(fstream& myFile);
};

class Arm : public RobotParts
{

  private:

  double powerConsumed;

  public:
  Arm()
  {

  };

  Arm(string n, int p, string t, double w, double c, string d, double power) : RobotParts(n, p, t, w, c, d)
  {
      powerConsumed = power;
  };

  void setPowerConsumed(double power);
  double getPowerConsumed();
  void displayArm();
  void saveArmToFile(fstream& myFile);
  void saveArmToProgramFile(fstream& myFile);
};

void Customer::setName(string n)
{
    name = n;
}

string Customer::getName()
{
    return name;
}

void Arm::setPowerConsumed(double power)
{
  powerConsumed = power;
}
double Arm::getPowerConsumed()
{
  return powerConsumed;
}
void Arm::displayArm()
{
  cout << "\nName: " << RobotParts::getName() << endl;
  cout << "Part #: " << RobotParts::getPartNumber() << endl;
  cout << "Type: " << RobotParts::getType() << endl;
  cout << "Weight: " << RobotParts::getWeight() << endl;
  cout << "Cost: " << RobotParts::getCost() << endl;
  cout << "Description: " << RobotParts::getDescription() << endl;
  cout << "Power Consumed: " << getPowerConsumed() << endl;
}

void Arm::saveArmToFile(fstream& myFile)
{
  myFile << "\nName: " << RobotParts::getName() << endl;
  myFile << "Part #: " << RobotParts::getPartNumber() << endl;
  myFile << "Type: " << RobotParts::getType() << endl;
  myFile << "Weight: " << RobotParts::getWeight() << endl;
  myFile << "Cost: " << RobotParts::getCost() << endl;
  myFile << "Description: " << RobotParts::getDescription() << endl;
  myFile << "Power Consumed: " << getPowerConsumed() << endl;
}
void Arm::saveArmToProgramFile(fstream& myFile)
{
  myFile << "#" << endl;
  myFile << RobotParts::getType() << endl;
  myFile << RobotParts::getPartNumber() << endl;
  myFile << RobotParts::getName() << endl;
  myFile << RobotParts::getWeight() << endl;
  myFile << RobotParts::getCost() << endl;
  myFile << RobotParts::getDescription() << endl;
  myFile << getPowerConsumed() << endl;
}

void Battery::setEnergyContained(double energy)
{
  energyContained = energy;
}
double Battery::getEnergyContained()
{
  return energyContained;
}

void Battery::displayBattery()
{
  cout << "\nName: " << RobotParts::getName() << endl;
  cout << "Part #: " << RobotParts::getPartNumber() << endl;
  cout << "Type: " << RobotParts::getType() << endl;
  cout << "Weight: " << RobotParts::getWeight() << endl;
  cout << "Cost: " << RobotParts::getCost() << endl;
  cout << "Description: " << RobotParts::getDescription() << endl;
  cout << "Energy Contained: " << getEnergyContained() << endl;
}
void Battery::saveBatteryToFile(fstream& myFile)
{
  myFile << "\nName: " << RobotParts::getName() << endl;
  myFile << "Part #: " << RobotParts::getPartNumber() << endl;
  myFile << "Type: " << RobotParts::getType() << endl;
  myFile << "Weight: " << RobotParts::getWeight() << endl;
  myFile << "Cost: " << RobotParts::getCost() << endl;
  myFile << "Description: " << RobotParts::getDescription() << endl;
  myFile << "Energy Contained: " << getEnergyContained() << endl;
}
void Battery::saveBatteryToProgramFile(fstream& myFile)
{
  myFile << "#" << endl;
  myFile << RobotParts::getType() << endl;
  myFile << RobotParts::getPartNumber() << endl;
  myFile << RobotParts::getName() << endl;
  myFile << RobotParts::getWeight() << endl;
  myFile << RobotParts::getCost() << endl;
  myFile << RobotParts::getDescription() << endl;
  myFile << getEnergyContained() << endl;
}

void Controller::showControllerMenu()
{

  View newView;
  int key = 0;
  parts.retrieveParts();
  model.retrieveModel(parts);

  while (true)
  {
    newView.main_menu();
    cin >> key;
    switch (key)
    {
      case 1:
        partsController();
        break;
      case 2:
        modelController();
        break;
      case 3:
        parts.displayParts();
        break;
      case 4:
        model.displayRobotModel();
        break;
      case 5:
        ordersController();
        break;
      case 6:
        parts.saveParts();
        parts.saveProgramParts();
        model.saveModel();
        model.saveProgramModel();
        cout << "Robot parts and robot model have been saved. " << endl;
        break;
      case 7:
        cout << "exiting..." << endl;
        exit(0);
        break;
      case 8:
        newView.print_documentation();
        break;
      default:
        cout << "You didnt enter a valid command. Please try again..." << endl;
    }
  }
}

void Controller::partsController()
{
  double cmd = 0;
  View view;

while (cmd != 1.7)
{
    view.createParts_menu();
    cin >> cmd;

    if(cmd == 1.1)
      parts.createHead();

    else if(cmd == 1.2)
      parts.createTorso();

    else if(cmd == 1.3)
      parts.createArm();

    else if(cmd == 1.4)
      parts.createLocomotor();

    else if(cmd == 1.5)
      parts.createBattery();

    else if (cmd  == 1.6)
      parts.displayParts();

    else if(cmd == 1.7)
      cout << "returning to main menu...\n";

    else
      cout <<"\nXXXXX Invalid key XXXXX"<<endl;
  }
}
void Controller::modelController()
{

  double cmd = 0;
  int readKey;
  View view;
  model.createRobotModels(parts);
}
void Controller::ordersController()
{
  View newView;
  double key = 0;

  while( key != 3)
  {
    newView.userSelection();
    cin >> key;

    if( key == 1 )
    {
      SalesAssociate associate;
      string name;
      cout << "\nAssociate Name: ";
      cin.ignore();
      getline(cin, name);
      associate.setName(name);
      cout << associate.getName();

      while(key != 5.4)
      {
        newView.salesOrderOptions();
        cin >> key;

        if (key == 5.1)
        {
          orders.createOrders(model, associate);
        }
        else if(key == 5.2)
        {
          orders.displayOrders();
        }
        else if( key == 5.3 )
          orders.salesHistory( name );
      }
    }
    else if( key == 2 )
      customerController();

    else if( key == 3 )
      cout << "returning to main menu...\n";

    else
      cout << "\nXXXXX Invalid key, Try again XXXXX" << endl;
  }
}
void Controller::customerController()
{
  View newView;
  double key = 0;
  int tok;
  string name;
  cout << "\nCustomer Name: ";
  cin.ignore();
  getline(cin, name);

  while ( key != 5.3 )
  {
    newView.customerOrderOptions();                                                     //add
    cin >> key;

    if ( key == 5.1 )
      orders.orderHistory( name );

    else if ( key == 5.2 )
      orders.viewCustBill( name, model );                                         //call Order class to view customer's bill

    else if( key == 5.3 )
      cout << "returning to User Selection Menu...\n";

    else
      cout << "\nXXXXX Invalid key, Try again XXXXX" << endl;                 //basic err chk
  }
}

void CreateRobotParts::createHead()
{
  string name, type, description;
  int partNumber;
   double weight, cost;
   cin.ignore(1000, '\n');
   cout <<"******* CREATING HEAD **********\n";
   cout << "Name?: ";
   getline(cin, name);
   cout<< "Part Number?: ";
   cin >> partNumber;

   while(cin.fail())
  {
     	cin.clear();
   	cin.ignore(1000, '\n');
   	cerr <<"Not a valid answer. Try again.\n";
   	cout <<"Part Number?: ";
   	cin >> partNumber;
   }
   cin.ignore(1000, '\n');
   type = "Head";
   cout<<"Weight?: ";
   cin >> weight;
   while(cin.fail()){
   cin.clear();
   cin.ignore(1000, '\n');
   cerr <<"Not a valid answer. Try again.\n";
   cout <<"Weight?: ";
   cin >> weight;
   }
   cin.ignore(1000, '\n');
   cout <<"Cost?: ";
   cin >> cost;
   while(cin.fail()){
   cin.clear();
   cin.ignore(1000, '\n');
   cerr <<"Not a valid answer. Try again.\n";
   cout <<"Cost?: ";
   cin >> cost;
   }
   cin.ignore(1000, '\n');
   cout <<"Description?: ";
   getline(cin, description);
   Head h(name, partNumber, type, weight, cost, description);
  allHeads.push_back(h);
}
void CreateRobotParts::createTorso()
{
   string name, type, description;
   int partNumber, batteries;
   double weight, cost;
   cin.ignore();
   cout <<"******* CREATING TORSO **********\n";
   cout << "Name?: ";
   getline(cin, name);
   cout<< "Part Number?: ";
   cin >> partNumber;
   while(cin.fail()){
   cin.clear();
   cin.ignore(1000, '\n');
   cerr <<"Not a valid answer. Try again.\n";
   cout <<"Part Number?: ";
   cin >> partNumber;
   }
   cin.ignore(1000, '\n');
   type = "Torso";
   cout<<"Weight?: ";
   cin >> weight;
   cin.ignore();
   cout <<"Cost?: ";
   cin >> cost;
   while(cin.fail()){
   cin.clear();
   cin.ignore(1000, '\n');
   cerr <<"Not a valid answer. Try again.\n";
   cout <<"Cost?: ";
   cin >> cost;
   }
   cin.ignore();
   cout <<"Descritpion?: ";
   getline(cin, description);
   cout <<"How many battery compartment(s) does torso have (1, 2, or 3)?: ";
   cin >> batteries;
   while(cin.fail())
   {
      cin.clear();
      cin.ignore(1000, '\n');
      cerr <<"Not a valid answer. Try again.\n";
      cout <<"How many battery compartment(s) does torso have (1, 2, or 3)?: ";
      cin >> batteries;
      while(batteries < 1 || batteries > 3)
      {
          cout << batteries << " is out of range!" << endl;
          cout <<"How many battery compartment(s) does torso have (1, 2, or 3)?: ";
          cin >> batteries;
      }
   }
    cin.ignore();
    Torso t(name, partNumber, type, weight, cost, description, batteries);
    allTorsos.push_back(t);
}
void CreateRobotParts::createArm()
{
   string name, type, description;
   int partNumber;
   double weight, cost, powerConsumed;
   cin.ignore();
   cout <<"******* CREATING Arm **********\n";
   cout << "Name?: ";
   getline(cin, name);
   cout<< "Part Number?: ";
   cin >> partNumber;
   while(cin.fail()){
   cin.clear();
   cin.ignore(1000, '\n');
   cerr <<"Not a valid answer. Try again.\n";
   cout <<"Part Number?: ";
   cin >> partNumber;
   }
   cin.ignore();
   type = "Arm";
   cout<<"Weight?: ";
   cin >> weight;
   while(cin.fail()){
   cin.clear();
   cin.ignore(1000, '\n');
   cerr <<"Not a valid answer. Try again.\n";
   cout <<"Weight?: ";
   cin >> weight;
   }
   cin.ignore();
   cout <<"Cost?: ";
   cin >> cost;
   while(cin.fail()){
   cin.clear();
   cin.ignore(1000, '\n');
   cerr <<"Not a valid answer. Try again.\n";
   cout <<"Cost?: ";
   cin >> cost;
   }
   cin.ignore();
   cout <<"Description?: ";
   getline(cin, description);
   cout <<"Power consumed?: ";
   cin >> powerConsumed;
   while(cin.fail()){
   cin.clear();
   cin.ignore(1000, '\n');
   cerr <<"Not a valid answer. Try again.\n";
   cout <<"Power Consumed?: ";
   cin >> powerConsumed;
   }
   cin.ignore();
   Arm a(name, partNumber, type, weight, cost, description, powerConsumed);
  allArms.push_back(a);
}
void CreateRobotParts::createLocomotor()
{
   string name, type, description;
   int partNumber, maxSpeed;
   double weight, cost, powerConsumed;
   cin.ignore();
   cout <<"******* CREATING LOCOMOTOR **********\n";
   cout << "Name?: ";
   getline(cin, name);
   cout<< "Part Number?: ";
   cin >> partNumber;
   while(cin.fail()){
   cin.clear();
   cin.ignore(1000, '\n');
   cerr <<"Not a valid answer. Try again.\n";
   cout <<"Part Number?: ";
   cin >> partNumber;
   }
   type = "Locomotor";
   cout<<"Weight?: ";
   cin >> weight;
   while(cin.fail()){
   cin.clear();
   cin.ignore(1000, '\n');
   cerr <<"Not a valid answer. Try again.\n";
   cout <<"Weight?: ";
   cin >> weight;
   }
   cin.ignore();
   cout <<"Cost?: ";
   cin >> cost;
   while(cin.fail()){
   cin.clear();
   cin.ignore(1000, '\n');
   cerr <<"Not a valid answer. Try again.\n";
   cout <<"Cost?: ";
   cin >> cost;
   }
   cin.ignore();
   cout <<"Description?: ";
   getline(cin, description);
   cout <<"Power Consumed?: ";
   cin >> powerConsumed;
   while(cin.fail()){
   cin.clear();
   cin.ignore(1000, '\n');
   cerr <<"Not a valid answer. Try again.\n";
   cout <<"Power Consumed?: ";
   cin >> powerConsumed;
   }
   cin.ignore();
   cout <<"Max Speed?: ";
   cin >> maxSpeed;
   while(cin.fail()){
   cin.clear();
   cin.ignore(1000, '\n');
   cerr <<"Not a valid answer. Try again.\n";
   cout <<"Max Speed?: ";
   cin >> maxSpeed;
   }
   cin.ignore();
   Locomotor l(name, partNumber, type, weight, cost, description, powerConsumed, maxSpeed);
  allLocomotors.push_back(l);
}
void CreateRobotParts::createBattery(){
  string name, type, description;
  int partNumber, maxSpeed;
  double weight, cost, energyContained;
  cin.ignore();
   cout <<"******* CREATING BATTERY **********\n";
   cout << "Name?: ";
   getline(cin, name);
   cout<< "Part Number?: ";
   cin >> partNumber;
   while(cin.fail()){
   cin.clear();
   cin.ignore(1000, '\n');
   cerr <<"Not a valid answer. Try again.\n";
   cout <<"Part Number?: ";
   cin >> partNumber;
   }
   cin.ignore();
   type = "Battery";
   cout<<"Weight?: ";
   cin >> weight;
   while(cin.fail()){
   cin.clear();
   cin.ignore(1000, '\n');
   cerr <<"Not a valid answer. Try again.\n";
   cout <<"Weight?: ";
   cin >> weight;
   }
   cin.ignore();
   cout <<"Cost?: ";
   cin >> cost;
   while(cin.fail()){
   cin.clear();
   cin.ignore(1000, '\n');
   cerr <<"Not a valid answer. Try again.\n";
   cout <<"Cost?: ";
   cin >> cost;
   }
   cin.ignore();
   cout <<"Description?: ";
   getline(cin, description);
   cout <<"Energy Contained?: ";
   cin >> energyContained;
   while(cin.fail()){
   cin.clear();
   cin.ignore(1000, '\n');
   cerr <<"Not a valid answer. Try again.\n";
   cout <<"Energy Contained?: ";
   cin >> energyContained;
   }
   cin.ignore();
   Battery b(name, partNumber, type, weight, cost, description, energyContained);
  allBatteries.push_back(b);
}

void CreateRobotParts::showHeads()
{
  if(allHeads.size() == 0)
  {
 	cout << "No available heads.\n";
  }
  else
  {
 	int i;
 	for(i=0; i < allHeads.size(); i++)
        cout <<i<<") "<< allHeads.at(i).getName()<<endl;
  }

}
void CreateRobotParts::showTorsos()
{
  if(allTorsos.size() == 0)
  {
    cout << "No available torsos.\n";
  }
  else
  {
 	int i;
 	for(i=0; i < allTorsos.size(); i++)
        cout <<i<<") "<< allTorsos.at(i).getName()<<endl;
  }
}
void CreateRobotParts::showArms()
{
  if(allArms.size() == 0)
  {
      cout << "No available arms.\n";
  }
  else
  {
      int i;
      for(i=0; i < allArms.size(); i++)
      cout <<i<<") "<<allArms.at(i).getName()<<endl;
  }
}
void CreateRobotParts::showLocomotors()
{
   if(allLocomotors.size() == 0)
    {
       cout << "No available locomotors.\n";
    }
  else
   {
 	int i;
 	for(i=0; i < allLocomotors.size(); i++)
        cout <<i<<") "<<allLocomotors.at(i).getName()<<endl;
    }
}

void CreateRobotParts::showBatteries(){
  if(allBatteries.size() == 0){
 			cout << "No available batteries.\n";
  }
  else{
 			int i;
 			for(i=0; i < allBatteries.size(); i++)
        cout <<i<<") "<<allBatteries.at(i).getName()<<endl;
  }
}

void CreateRobotParts::displayParts()
{
  cout << "_______________________________________" << endl;
  cout << "\n********  Head Display ************" << endl;
  cout << "_______________________________________" << endl;

  if(allHeads.size() == 0)
    cout << "\nNo head created\n";
  else
    for(int i = 0; i < allHeads.size(); i++)
      allHeads[i].displayHeads();
  cout << "_______________________________________" << endl;
  cout << "\n********  Arm Display ************" << endl;
  cout << "_______________________________________" << endl;
  if(allArms.size() == 0)
    cout << "\nNo Arms created\n";

  else
    for(int i = 0; i < allArms.size(); i++)

      allArms[i].displayArm();
  cout << "_______________________________________" << endl;
  cout << "\n********  Torso Display ************" << endl;
  cout << "_______________________________________" << endl;

  if(allTorsos.size() == 0)
    cout << "\nNo Torso created\n";
  else
    for(int i = 0; i < allTorsos.size(); i++)
      allTorsos[i].displayTorso();
  cout << "_______________________________________" << endl;
  cout << "\n********  Locomotor Display ************" << endl;
  cout << "_______________________________________" << endl;

  if(allLocomotors.size() == 0)
    cout << "\nNo Locomotors created\n";
  else
    for(int i = 0; i < allLocomotors.size(); i++)
      allLocomotors[i].displayLocomotor();
  cout << "_______________________________________" << endl;
  cout << "\n********  Battery Display ************" << endl;
  cout << "_______________________________________" << endl;

  if(allBatteries.size() == 0)
    cout << "\nNo Battery created\n";

  else
    for(int i = 0; i < allBatteries.size(); i++)
      allBatteries[i].displayBattery();
}

void CreateRobotParts::saveParts()
{
  string fileName;
  fstream myFile;
  myFile.open("Robot_Parts.txt", ios::out | ios::trunc);

  if (!myFile)
    throw runtime_error("canít open output file " + fileName);

  myFile << "_______________________________________" << endl;
  myFile << "\n********  Head Display ************" << endl;
  myFile << "_______________________________________" << endl;

  if(allHeads.size() == 0)
    myFile << "\nNo head created\n";

  else

    for(int i = 0; i < allHeads.size(); i++)
      allHeads[i].saveHeadToFile(myFile);

  myFile << "_______________________________________" << endl;
  myFile << "\n********  Arm Display ************" << endl;
  myFile << "_______________________________________" << endl;

  if(allArms.size() == 0)
    myFile << "\nNo Arms created\n";

  else

    for(int i = 0; i < allArms.size(); i++)
      allArms[i].saveArmToFile(myFile);

  myFile << "_______________________________________" << endl;
  myFile << "\n********  Torso Display ************" << endl;
  myFile << "_______________________________________" << endl;

  if(allTorsos.size() == 0)
    myFile << "\nNo Torso created\n";

  else

    for(int i = 0; i < allTorsos.size(); i++)
      allTorsos[i].saveTorsoToFile(myFile);
  myFile << "_______________________________________" << endl;
  myFile << "\n********  Locomotor Display ************" << endl;
  myFile << "_______________________________________" << endl;

  if(allLocomotors.size() == 0)
    myFile << "\nNo Locomotors created\n";

  else

    for(int i = 0; i < allLocomotors.size(); i++)
      allLocomotors[i].saveLocomotorToFile(myFile);

  myFile << "_______________________________________" << endl;
  myFile << "\n********  Battery Display ************" << endl;
  myFile << "_______________________________________" << endl;
  if(allBatteries.size() == 0)
    myFile << "\nNo Battery created\n";
  else
    for(int i = 0; i < allBatteries.size(); i++)
      allBatteries[i].saveBatteryToFile(myFile);
  myFile << endl;
  myFile.close();
}

void CreateRobotParts::saveProgramParts()
{
  string fileName;
  fstream myFile;

  myFile.open("Parts_Program_File.txt", ios::out | ios::trunc);
  if (!myFile)
    throw runtime_error("canít open output file " + fileName);

  if(allHeads.size() == 0)
  {
    myFile << "#" << endl;
    myFile << "\nNo head created\n";
  }
  else

    for(int i = 0; i < allHeads.size(); i++)
      allHeads[i].saveHeadToProgramFile(myFile);

  if(allArms.size() == 0)
  {
    myFile << "#" << endl;
    myFile << "\nNo Arms created\n";
  }
  else

    for(int i = 0; i < allArms.size(); i++)
      allArms[i].saveArmToProgramFile(myFile);

  if(allTorsos.size() == 0)
  {
    myFile << "#" << endl;
    myFile << "\nNo Torso created\n";
  }
  else
    for(int i = 0; i < allTorsos.size(); i++)
      allTorsos[i].saveTorsoToProgramFile(myFile);

  if(allLocomotors.size() == 0)
  {
    myFile << "#" << endl;
    myFile << "\nNo Locomotors created\n";
  }
  else

    for(int i = 0; i < allLocomotors.size(); i++)
      allLocomotors[i].saveLocomotorToProgramFile(myFile);

  if(allBatteries.size() == 0)
  {
    myFile << "#" << endl;
    myFile << "\nNo Battery created\n";
  }
  else

    for(int i = 0; i < allBatteries.size(); i++)
      allBatteries[i].saveBatteryToProgramFile(myFile);
    myFile.close();
}
void CreateRobotParts::retrieveParts ()
{
  string line;
  ifstream readFile;
  string name;
  int partNumber;
  string type;
  double weight;
  double cost;
  string description;
  int batteries;
  double energyContained;
  double powerConsumed;
  int maxSpeed;

  readFile.open("Parts_Program_File.txt", ios::in);

  if (readFile)
  {
     while (getline(readFile, line))
    {

      if(line == "#")
        continue;

      if(line == "Head")
      {
        type = line;
        getline(readFile, line);
        partNumber = atoi(line.c_str());
        getline(readFile, line);
        name = line;
        getline(readFile, line);
        weight = atof(line.c_str());
        getline(readFile, line);
        cost = atof(line.c_str ());
        getline(readFile, line);
        description = line;
        Head h(name, partNumber, type, weight, cost, description);
        allHeads.push_back(h);
      }
      else if(line == "Torso")
      {
        type = line;
        getline(readFile, line);
        partNumber = atoi(line.c_str());
        getline(readFile, line);
        name = line;
        getline(readFile, line);
        weight = atof(line.c_str());
        getline(readFile, line);
        cost = atof(line.c_str ());
        getline(readFile, line);
        description = line;
        getline(readFile, line);
        batteries = atoi(line.c_str());
        Torso t(name, partNumber, type, weight, cost, description, batteries);
        allTorsos.push_back(t);
      }
      else if(line == "Battery")
      {
        type = line;
        getline(readFile, line);
        partNumber = atoi(line.c_str());
        getline(readFile, line);
        name = line;
        getline(readFile, line);
        weight = atof(line.c_str());
        getline(readFile, line);
        cost = atof(line.c_str ());
        getline(readFile, line);
        description = line;
        getline(readFile, line);
        energyContained = atof(line.c_str());
        Battery b(name, partNumber, type, weight, cost, description, energyContained);  // create a new instance of battery
        allBatteries.push_back(b);
      }
      else if(line == "Arm")
      {
        type = line;
        getline(readFile, line);
        partNumber = atoi(line.c_str());
        getline(readFile, line);
        name = line;
        getline(readFile, line);
        weight = atof(line.c_str());
        getline(readFile, line);
        cost = atof(line.c_str ());
        getline(readFile, line);
        description = line;
        getline(readFile, line);
        powerConsumed = atof(line.c_str());
        Arm a(name, partNumber, type, weight, cost, description, powerConsumed);  // Create new instance of arm
        allArms.push_back(a);
      }
      else if (line == "Locomotor")
      {
        type = line;
        getline(readFile, line);
        partNumber = atoi(line.c_str());
        getline(readFile, line);
        name = line;
        getline(readFile, line);
        weight = atof(line.c_str());
        getline(readFile, line);
        cost = atof(line.c_str ());
        getline(readFile, line);
        description = line;
        getline(readFile, line);
        powerConsumed = atof(line.c_str());
        getline(readFile, line);
        maxSpeed = atoi(line.c_str());
        Locomotor l(name, partNumber, type, weight, cost, description, powerConsumed, maxSpeed); // create new instance
        allLocomotors.push_back(l);
      }
      else;
    }
    readFile.close();
  }
  else
    cout << "There was no file to retrieve data from for robot parts." << endl;
}
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

oid Locomotor::setPowerConsumed(double power){
  powerConsumed = power;
}
void Locomotor::setMaxSpeed(int speed){
  maxSpeed = speed;
}
double Locomotor::getPowerConsumed(){
  return powerConsumed;
}
int Locomotor::getMaxSpeed(){
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

oid Orders::createOrders(RobotModels models, SalesAssociate associate)  //add
{
  Orders ordr;
  ordr.associate = associate;
  
  string name;
  int choice, key, quantity;
  cout <<"\n\n******* CREATING ORDER **********\n";
  cout << "\nEnter customer Name: ";
  cin.ignore();
  getline(cin, name);
  
  ordr.customer.setName( name );                         //chgd
  //custName = customer.getName();                    //chgd
  
  
  while(key != 2)
  {
    //cin.ignore();
    cout << endl;
    cout << "What would you like to do?" << endl;
    cout << "1) Select from catalog" << endl;
    cout << "2) Checkout" << endl;
    cout << "Command: ";
    cin >> key;
    
    if(key == 1)
    {
      models.displayRobotModel();
      cout << "Enter catalog number: ";
      cin >> choice;
      cout << "Enter quantity: ";
      cin >> quantity;
      ordr.quantities.push_back(quantity);
      ordr.cart.push_back(choice);
    }
    else if(key == 2)
    {
      cout << "\n\n******* CHECKOUT SUMMARY *******" << endl;
      cout << "Customer: " << name << endl;
      ordr.setOrderNumber();
      cout << "Order number: " << ordr.getOrderNumber() << endl;
      cout << "Date: ";
      getTime();
      
      for(int i = 0; i < ordr.cart.size(); i++)
      {
        double price = 0;
        price = models.getModelPrice(ordr.cart[i]) * ordr.quantities[i];
        ordr.setTotalPrice(price);
        models.display(ordr.cart[i]);
        cout << "\tQuantity: x" << ordr.quantities[i] << endl;
        cout << endl;
        
      }
      
      cout << "\nSubTotal: $" << ordr.getTotalPrice();
      allOrders.push_back(ordr);
    }
    else
      cout <<"\nXXXXX Invalid key, Try again XXXXX"<< endl;
  }
  
  
}

void Orders::setTotalPrice(double price)
{
  totalPrice += price;
}

double Orders::getTotalPrice()
{
  return totalPrice;
}

void Orders::getTime()
{
  // current date/time based on current system
  time_t now = time(0);
  
  // convert now to string form
  char* dt = ctime(&now);
  
  cout  << dt << endl;
  
}

void Orders::setOrderNumber()
{
  orderNumber = rand() % 100000000;
}
int Orders::getOrderNumber()
{
  return orderNumber;
  
}

void Orders::displayOrders()
{
  cout << endl;
  cout << "_____________________________________________" << endl;
  cout << "\t******** Display Orders ********" << endl;
  cout << "_____________________________________________" << endl;
  for (int i = 0; i < allOrders.size(); i++)
  {
    cout << endl;
    cout << i << ". ";
    cout << "Customer Name: " << allOrders[i].customer.getName() << endl;             //chgd
    cout << endl;
    cout << "   Order Number: " << allOrders[i].orderNumber << endl;
    cout << "   Sold By: " << allOrders[i].associate.getName()<< endl;
    /*   for(int j = 0; j < allOrders[i].cart.size(); j++)
     {
     cout << "   Products: " << allOrders[i].cart[j] << endl;
     cout << "   Quantity: " << allOrders[i].quantities[j] << endl;
     }
     
     */
    cout << "   Total Price: " << allOrders[i].totalPrice << endl;
    
  }
  if (allOrders.size() == 0)
    cout << "\nNo model created" << endl;
}

/*----------------------------------------------------------------------------------------------------------------------*/
int Orders::orderHistory( string n )
{
  token = n;
  double total = 0;
  int cnt = 0;
  int cmd = 0; //for next function to determine if user is BC or SA
  
  cout << endl;
  cout << "----------------------------------------" << endl;
  cout << "|      Robbie Robot Shop Order         |" << endl;
  cout << "________________________________________" << endl;
  cout << endl;
  cout << "Customer Name: " << n << endl;
  
  for ( int i = 0; i < allOrders.size(); i++ )
  {
    string custName = allOrders[i].customer.getName();
    if ( token.compare( custName ) == 0)              //chgd
    {
      total += printOrderHistory( i, cmd );
      cnt++;
      index = 1;
    }
  }
  
  if( index != 1 && allOrders.size() != 0 )
  {
    cout << "You have no orders. ";
    return 1;
  }
  else if ( index != 1 && allOrders.size() == 0 )             //check if any orders are stored
  {
    cout << endl << "No sales have been made." << endl << endl << "Returning to user selection Menu..." << endl;
    return 1;
  }
  
  cout << endl << "Total Orders: " << cnt << "     Total Balance Due: " << total << endl << endl;
  return 0;
}


/*----------------------------------------------------------------------------------------------------------------------*/

int Orders::salesHistory( string n )
{
  token = n;
  int cnt = 0;
  double total = 0;
  int cmd = 1; 
  
  cout << endl;
  cout << "----------------------------------------" << endl;
  cout << "|       Staff Sales Report             |" << endl;
  cout << "________________________________________" << endl;
  cout << endl;
  cout << "Employee: " << n << endl;
  
  for ( int i = 0; i < allOrders.size(); i++ )
  {
    string custName = allOrders[i].associate.getName();
    if ( token.compare( custName ) == 0)              
    {
      total += printOrderHistory( i, cmd );
      cnt++;
      index = 1;
    }
  }
  
  if( index != 1 && allOrders.size() != 0 )
  {
    cout << "You made no sales. ";
    return 1;
  }
  else if ( index != 1 && allOrders.size() == 0 )    
  {
    cout << endl << "The company made no sales." << endl << endl << "Returning to user selection Menu..." << endl;
    return 1;
  }
  
  cout << endl << "Total Sales: " << cnt << "     Total Sales Revenue: " << total << endl << endl;
  return 0;
}

double Orders::printOrderHistory( int x, int y )
{
  if ( y == 1 ) 
  {
    cout << endl;
    cout << "   Order Number: " << allOrders[x].orderNumber << endl;
    cout << "   Total Price: " << allOrders[x].totalPrice << endl;
    cout << endl;
    return allOrders[x].totalPrice;
  }
  else if ( y == 0 ) 
  {
    cout << endl;
    cout << x << ". ";
    cout << endl;
    cout << "   Order Number: " << allOrders[x].orderNumber << endl;
    cout << "   Sold By: " << allOrders[x].associate.getName()<< endl;
    cout << "   Total Price: " << allOrders[x].totalPrice << endl;
    return allOrders[x].totalPrice;
  }
}
/*----------------------------------------------------------------------------------------------------------------------*/
void Orders::viewCustBill( string n, RobotModels models)
{
  int cmd = orderHistory( n );
  
  if ( cmd == 1 )
    return;
  
  cout << endl << endl << "Enter index of the order to view: ";
  cin >> cmd;
  
  cout << endl;
  cout << "----------------------------------------" << endl;
  cout << "|      Robbie Robot Shop Invoice       |" << endl;
  cout << "________________________________________" << endl;
  cout << endl;
  cout << "Customer Name: " << allOrders[cmd].customer.getName() << endl;
  cout << "   Order Number: " << allOrders[cmd].orderNumber << endl;
  cout << "   Products: " << endl;
  for(int j = 0; j < allOrders[cmd].cart.size(); j++)
  {
    
    models.display(allOrders[cmd].cart[j]);
    cout << "\tQuantity: x" << allOrders[cmd].quantities[j] << endl;
    cout << endl;
  }
 cout << "   Total Price: " << allOrders[cmd].totalPrice << endl;
}

RobotModels::RobotModels()
{
  // these are the default values if it is not changed
  int armSize = 0;
 	int batterySize = 0;
 	double totalPartsCost = 0;
}
int readInput()
{
  int index;
  
  cout << "\nSelect: ";
  cin >> index;
  return index;
}
void RobotModels::createRobotModels(CreateRobotParts &p){
  
  model mdl;
  int index;
  char ch;
  
  cin.ignore();
  cout << endl;
  cout <<"What is your Model Name?: ";
  getline(cin, mdl.modelName);
  cout <<"What is your Model Number?: ";
  cin >> mdl.modelNumber;
  cin.ignore();
  
  
  cout << "\nPlease choose a head: " << endl;
  p.showHeads();
  if (p.getSizeOfHead() != 0)
  {
    index = readInput();
    mdl.head = p.getHeadAt(index);
    mdl.batteries.push_back(0);             // push_back(0) because head doesn't need a battery
    partsCost.push_back(p.getHeadAt(index).getCost());
    fileIndexes.push_back(index);
  }
  
  cout << "\nPlease choose arms: " << endl;
  int counter = 2;
  p.showArms();
  if (p.getSizeOfArm() != 0)
  {
    cout << "Select 2 arms " << endl;
    do{
      index = readInput();
      while (index < 0 || index > p.getSizeOfArm())
      {
        cout << index << " is out of range.\nTry again...\n" << endl;
        p.showArms();
        cout << "Select 2 arms " << endl;
        index = readInput();
      }
      mdl.arms.push_back(p.getArmAt(index));
      partsCost.push_back(p.getArmAt(index).getCost());
      fileIndexes.push_back(index);
      counter--;
    }while(counter > 0 && counter < 2);
    mdl.batteries.push_back(0);
  }
  
  cout << "\nPlease choose a torso: " << endl;
  p.showTorsos();
  if (p.getSizeOfTorso() != 0)
  {
    index = readInput();
    mdl.batteries.push_back(p.getTorsoAt(index).getBatteryCompartments());   // this is the number of batteries that can fit in torso
    mdl.torso = p.getTorsoAt(index);
    partsCost.push_back(p.getTorsoAt(index).getCost());
    fileIndexes.push_back(index);
  }
  
  cout << "\nPlease choose a locomotor: " << endl;
  p.showLocomotors();
  if (p.getSizeOfLocomotor() != 0)
  {
    index = readInput();
    mdl.locomotor = p.getLocomotorAt(index);
    mdl.batteries.push_back(0);
    partsCost.push_back(p.getLocomotorAt(index).getCost());
    fileIndexes.push_back(index);
    
  }

  calculateTotalPartsCost();
  cout << "\nThe total cost of all components for model " << mdl.modelName << " is " << totalPartsCost << "." << endl;
  cout << "What price would you like to sell " << mdl.modelName << " for? ";
  cin >> mdl.modelPrice;
  if(mdl.modelPrice < totalPartsCost)
  {
    cout << "\nWARNING! " << "You will NOT make any profit if you set " << mdl.modelName << " price to $" << mdl.modelPrice << endl;
    cout << "Are you sure that's what you want to set model price to (y/n): ";
    cin >> ch;
    if (ch == 'n' || ch == 'N')
    {
      cout << "\nWhat price would you like to sell " << mdl.modelName << " for? ";
      cin >> mdl.modelPrice;
    }
  }
  allModel.push_back(mdl);
  armSize = mdl.arms.size();
  batterySize = mdl.batteries.size();
  fileIndexes.push_back(-1);          // -1 is pushed to keep track of when a model ended

}
void RobotModels::calculateTotalPartsCost()
{
  totalPartsCost = 0;                        // ensure totalPartsCost is zero before start adding
  for(int i = 0; i < partsCost.size(); i++)
    totalPartsCost += partsCost[i];
  while (partsCost.size() != 0) // delete all elements that was in partsCost, so partsCost can store next model cost
    partsCost.pop_back();
}
void RobotModels::displayRobotModel()
{
  cout << endl;
  cout << "_____________________________________________" << endl;
  cout << "\t******** Display Models ********" << endl;
  cout << "_____________________________________________" << endl;
  for (int i = 0; i < allModel.size(); i++)
  {
    cout << endl;
    cout << i << ". ";
    cout << "Model Name: " << allModel[i].modelName << endl;
    cout << "   Model Number: " << allModel[i].modelNumber << endl;
    cout << "   Types of components that made up model " << allModel[i].modelName << endl;
    cout << "\tHead: " << allModel[i].head.getName() << endl;
    if (armSize == 0)
      cout << "Arms: None " << endl;
    else
      for (int j = 0; j < armSize; j++)
        cout << "\tArms: " << allModel[i].arms[j].getName() << endl;
    cout << "\tTorso: " << allModel[i].torso.getName() << endl;
    cout << "\tLocomotor: " << allModel[i].locomotor.getName() << endl;
    if (batterySize != 0)
      cout << "\tBatteries: " << allModel[i].batteries[i] << endl;
    else
      cout << "\tBatteries: None" << endl;
    cout << "   Model Price: $" << allModel[i].modelPrice << endl;
  }
  if (allModel.size() == 0)
    cout << "\nNo model created" << endl;
}

void RobotModels::display(int i)
{
  cout << "\tModel Name: " << allModel[i].modelName << endl;
  cout << "\tModel Number: " << allModel[i].modelNumber << endl;
  cout << "\tModel Price: $" << allModel[i].modelPrice << endl;
}

double RobotModels::getModelPrice(int i)
{
  return allModel[i].modelPrice;
}

void RobotModels::saveModel()
{
  string fileName;
  fstream myFile;
  myFile.open("Robot_Model.txt", ios::out | ios::in | ios::trunc);
  if (!myFile)       // if myFile stream is corrupted
    throw runtime_error("canít open output file " + fileName);
  
  myFile << endl;
  myFile << "_____________________________________________" << endl;
  myFile << "\t******** Display Models ********" << endl;
  myFile << "_____________________________________________" << endl;
  for (int i = 0; i < allModel.size(); i++)
  {
    myFile << endl;
    myFile << "Model Name: " << allModel[i].modelName << endl;
    myFile << "Model Number: " << allModel[i].modelNumber << endl;
    myFile << "Types of components that made up model " << allModel[i].modelName << endl;
    myFile << "\tHead: " << allModel[i].head.getName() << endl;
    if (armSize == 0)
      myFile << "Arms: None " << endl;
    else
      for (int j = 0; j < armSize; j++)
        myFile << "\tArms: " << allModel[i].arms[j].getName() << endl;
    myFile << "\tTorso: " << allModel[i].torso.getName() << endl;
    myFile << "\tLocomotor: " << allModel[i].locomotor.getName() << endl;
    if (batterySize != 0)
      myFile << "\tBatteries: " << allModel[i].batteries[i] << endl;
    else
      myFile << "\tBatteries: None" << endl;
    myFile << "Model Price: $" << allModel[i].modelPrice << endl;
  }
  if (allModel.size() == 0)
    myFile << "\nNo model created" << endl;
  myFile.close();  // close file after use
}

void RobotModels::saveProgramModel()
{
  string fileName;
  fstream myFile;
  
  myFile.open("Model_Program_File.txt", ios::out | ios::in | ios::trunc);
  if (!myFile)       // if myFile stream is corrupted
    throw runtime_error("canít open output file " + fileName);
  
  int lastIndexRead = 0;        // stores last index when it reach -1, so the index for -1 is store in lastIndexRead
  for (int i = 0; i < allModel.size(); i++)
  {
    myFile << "#" << endl;                  // prints # to signal when a new model starts
    myFile << allModel[i].modelName << endl;
    myFile << allModel[i].modelNumber << endl;
    
    for(int j = lastIndexRead; j < fileIndexes.size(); j++)
    {
      if(fileIndexes[j] == -1)       // exit loop if reach to the end of a model
      {
        lastIndexRead = j;         // stores index for -1, so that we can keep track of when the first model created
        lastIndexRead++;           // add 1 so that we can go to the next index for the next model stored
        break;
      }
      myFile << fileIndexes[j] << endl;
    }
    myFile << allModel[i].batteries[i] << endl;
    myFile << allModel[i].modelPrice << endl;
  }
  
  myFile.close();  // close file after use
  
}
void RobotModels::retrieveModel(CreateRobotParts &p)
{
  string line;
  ifstream readFile;
  model mdl;
  int index;
  double price;
  armSize = 2;         // this is the number of arms read and created
  batterySize = 0;     // stores the number of batteries encounter
  
  readFile.open("Model_Program_File.txt", ios::in);     // open the file to read from
  if (readFile)       // if myFile stream is corrupted, throw an exception to the runtime_error
  {
    while (getline(readFile, line))     // read data from the file -> Model_Program_File.txt
    {
      if(line == "#")
        continue;                           // continue onto next line
      mdl.modelName = line;                   // set model name to the line just get, which it should modelName
      getline(readFile, line);                // get the next line after modelName-> should be the model number
      mdl.modelNumber = line;                 // set modelNumber to line
      getline(readFile, line);                // should be an index of the head selected be user-> this information will
      // be pass to head to get whatever the user selected initially
      
      index = atoi(line.c_str());             // since line came in as a string, we need to first convert it to an integer
      mdl.head = p.getHeadAt(index);          // pass the index to head and set the head in model to whatever the user select initially
      fileIndexes.push_back(index);
      
      getline(readFile, line);                // this should get the next index for the first arm
      index = atoi(line.c_str());             // again, convert string to an integer
      mdl.arms.push_back(p.getArmAt(index));  // store the arm into the model vector
      fileIndexes.push_back(index);
      
      getline(readFile, line);                // this should get the next index for the second arm
      index = atoi(line.c_str());             // again, convert string to an integer
      mdl.arms.push_back(p.getArmAt(index));  // store the arm into the model
      fileIndexes.push_back(index);
      
      getline(readFile, line);                // get the next line, this line should be torso
      index = atoi(line.c_str());             // since line came in as a string, we need to first convert it to an integer
      mdl.torso = p.getTorsoAt(index);        // pass the index to torso and set the torso in model to whatever the user select initially
      fileIndexes.push_back(index);
      
      getline(readFile, line);                // get the next line, this line should be Locomotor
      index = atoi(line.c_str());             // since line came in as a string, we need to first convert it to an integer
      mdl.locomotor = p.getLocomotorAt(index);// pass the index to locomotor and set the locomotor in model to whatever the user select initially
      fileIndexes.push_back(index);
      
      getline(readFile, line);                // next information that comes into line is battery
      index = atoi(line.c_str());             // since line came in as a string, we need to first convert it to an integer
      mdl.batteries.push_back(index);         // stores battery into model
      batterySize++;
      getline(readFile, line);                // this is the final line that should be get, and it should be the model price
      price = atof(line.c_str());             // convert the price to double
      mdl.modelPrice = price;                 // set the model price to price
      allModel.push_back(mdl);                // push created model onto allModel
      fileIndexes.push_back(-1);              // keep track of when a model is created
    }
    readFile.close();         
}
  else
    cout << "There was no file to retrieve data from for robot model." << endl;
  
}
 

RobotParts::RobotParts()
    {
        name = "None";
        partNumber = -1;
        type = "None";
        weight = 0.0;
        cost = 0.0;
        description = "None";

    }
	RobotParts::RobotParts(string n, int p, string t, double w, double c, string d){
   		name = n;
   		partNumber = p;
   		type = t;
   		weight = w;
   		cost = c;
   		description = d;
   	}

   	void RobotParts::setName(string n){
   		name =n;
   	}
   	void RobotParts::setPartNumber(int p){
   		partNumber = p;
   	}
   	void RobotParts::setType(string t){
   		type = t;
   	}
   	void RobotParts::setWeight(double w){
   		weight =w;
   	}
   	void RobotParts::setCost(double c){
   		cost = c;
   	}
   	void RobotParts::setDescription(string d){
   		description = d;
   	}
   	string RobotParts::getName(){
   		return name;
   	}
   	int RobotParts::getPartNumber(){
   		return partNumber;
   	}
   	string RobotParts::getType(){
   		return type;
   	}
   	double RobotParts::getWeight(){
   		return weight;
   	}
   	double RobotParts::getCost(){
   		return cost;
   	}
   	string RobotParts::getDescription(){
   		return description;
   	}
 


void SalesAssociate::setName(string n) { name = n; }
string SalesAssociate::getName() { return name; }

void Torso::setBatteryCompartments(int b){
  batteryCompartments = b;
}
int Torso::getBatteryCompartments(){
  return batteryCompartments;
}
ostream &operator<<(ostream &output, Torso &t)
{
  output << "Torso Name: " << t.getName() << endl;
  output << "Torso Part #: " << t.getPartNumber() << endl;
  output << "Torso Type: " << t.getType() << endl;
  output << "Torso Weight: " << t.getWeight() << endl;
  output << "Torso Cost: " << t.getCost() << endl;
  output << "Torso Description: " << t.getDescription() << endl;
  output << "Torso Battery Compartments: " << t.getBatteryCompartments() << endl;
  
}
void Torso::displayTorso(ostream &output, Torso &t)
{
  output << t << endl;
}
void Torso::displayTorso()
{
  cout << "\nName: " << RobotParts::getName() << endl;
  cout << "Part #: " << RobotParts::getPartNumber() << endl;
  cout << "Type: " << RobotParts::getType() << endl;
  cout << "Weight: " << RobotParts::getWeight() << endl;
  cout << "Cost: " << RobotParts::getCost() << endl;
  cout << "Description: " << RobotParts::getDescription() << endl;
  cout << "Battery Compartments: " << getBatteryCompartments() << endl;
}
void Torso::saveTorsoToFile(fstream& myFile)
{
  myFile << "\nName: " << RobotParts::getName() << endl;
  myFile << "Part #: " << RobotParts::getPartNumber() << endl;
  myFile << "Type: " << RobotParts::getType() << endl;
  myFile << "Weight: " << RobotParts::getWeight() << endl;
  myFile << "Cost: " << RobotParts::getCost() << endl;
  myFile << "Description: " << RobotParts::getDescription() << endl;
  myFile << "Battery Compartments: " << getBatteryCompartments() << endl;
}
void Torso::saveTorsoToProgramFile(fstream& myFile)       // save all to a file that only this program can read from to retrieve data
{
  myFile << "#" << endl;            // # is used to figure out when to start and stop grabbing data
  myFile << RobotParts::getType() << endl;
  myFile << RobotParts::getPartNumber() << endl;
  myFile << RobotParts::getName() << endl;
  myFile << RobotParts::getWeight() << endl;
  myFile << RobotParts::getCost() << endl;
  myFile << RobotParts::getDescription() << endl;
  myFile << getBatteryCompartments() << endl;
}

View::View(){
  //default constructor
}

void View::main_menu(){
  cout << endl<<endl;
  cout << "Main Menu\n**************\n";
  cout << "1) Create Parts\n";
  cout << "2) Create Model\n";
  cout << "3) Display Parts\n";
  cout << "4) Display Model\n";
  cout << "5) Order Menu\n";
  cout << "6) Save\n";
  cout << "7) Quit\n";
  cout << "8) View Documentation.\n";
  cout << "Command?: ";
}
void View::createParts_menu(){
  cout << endl<<endl;
  cout << "Parts Menu\n**************\n";
  cout << "1.1) Create Head\n";
  cout << "1.2) Create Torso\n";
  cout << "1.3) Create Arm\n";
  cout << "1.4) Create Locomotor\n";
  cout << "1.5) Create Battery\n";
  cout << "1.6) Display Parts\n";
  cout << "1.7) Main Menu\n";
  cout << "Command?: ";
}
void View::createModels_menu(){
  cout << endl<<endl;
  cout << "Models Menu\n**************\n";
  cout << "2.1) Choice Head\n";
  cout << "2.2) Choice Torso\n";
  cout << "2.3) Choice Arm\n";
  cout << "2.4) Choice Locomotor\n";
  cout << "2.5) Choice Battery\n";
  cout << "2.6) Main Menu\n";
  cout << "Command?: ";
}
void View::report_menu(){
  cout << endl<<endl;
  cout << "Report Menu\n**************\n";
  cout << "2.1) View Robot Catalog\n";
  cout << "Command?: ";
}
void View::userSelection()
{
  cout << endl<<endl;
  cout << "Select a User Type\n**************\n";
  cout << "1) Sales Associate\n";
  cout << "2) Customer\n";
  cout << "3) Main Menu\n";
  cout << "Command?: ";
}
void View::customerOrderOptions()
{
  cout << endl<<endl;
  cout << "Order Menu\n**************\n";
  cout << "5.1) Print Order History\n";
  cout << "5.2) View Your Bill\n";
  cout << "5.3) User Selection Menu\n";
  cout << "Command?: ";
}
void View::salesOrderOptions()
{
  cout << endl<<endl;
  cout << "Order Menu\n**************\n";
  cout << "5.1) Create New Order\n";
  cout << "5.2) Print Order Log\n";
  cout << "5.3) Print Sales Associates Order Log\n";
  cout << "5.4) User Selection Menu\n";
  cout << "Command?: ";
}
void View::print_documentation(){
  cout << "Robbie Robots Shop Manager is a protoype proposal package, featuring a text menu or command line interface.\n";
  cout <<"IMPORTANT.\n";
  cout <<"You must create a robot part of each (head, torso, arm, locomotor, battery) before you save.\n";
}

int main()
{
    CreateRobotParts robotPartConstruct;
    RobotModels modelsConstruct;
    Orders ordersConst;
    Controller controller(robotPartConstruct, modelsConstruct, ordersConst);
    controller.showControllerMenu();
    return 0;
}
