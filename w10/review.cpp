//review for test2(final)


/*
20 marks walkthrough
explanations 10
programming question 10

1. first walkthrough using, algorithm stuff- wrapper for, for loops, bumping counts, 
sort 2 for loops
what is the output of the following program add 4 and 40 :)

lambda functions https://scs.senecac.on.ca/~oop345/pages/content/funct.html#lam

for each (iterators) // 


transform  - https://scs.senecac.on.ca/~oop345/pages/content/algor.html
vector in and get vector out, 1 vector in 1 vector out, 2 vector in 1 vector out
zip

2. walkthrough with threading - 
threadvar.join();

vector of threads;

int num nt = 4;
vector<thread> threads;

mutex test; // not on the test
test.lock;

for (int i = 0; i < nt; i++)
  threads[i] = thread(bind(foo, fooargs, begin, end)); //use bind //accumulate to add up then print out do not pass foo() in bind
  
for (auto& i : threads)
  i.join();
  
bit operators & figuring odd or even, check last bit for 0 or 1

simple, parallel.


3. benefits of standard vector and list explain
vector insert/delete is bad and expensive moving things up and down, contiguous block fast random access.

list - random access is expensive, insert and delete is cheap just deal with the iterator/pointer and change it to point to new value.

emplace - vec.push_back(Dog("Kappa")); // copy constructor then move.
vec.emplace_back("Kappa"); // constructs in the vector knows the constructor.

lambda - got capture variables to use inside the lambda

function object is a class - member functions can be used before round bracket operator, anything u can do with class u can do

show 3 ways 2d vector can be printed. vector vector strings.
range base 4
for(auto& vecs : vecvec)
  for(auto& st:vecs)
    cout << st << endl;

iterators/indices.

smart pointers - simple class that deals with memory on initiation so you dont have memory leaks on exceptions

compositions, aggregations, association /labs for managers
comp - rooms in a building // destro building destroy rooms
agg -  Association where there is ownership and child objects can not belong to another parent object. duck can be in only 1 pond.
association -  where all objects have their own lifecycle and there is no owner. students and colleges.

part and part manager

void Composition()
{
  // Composition: 
  // The parent contains or is composed of the children.
  // A 'death' relationship.  Destroying the parent, destroys the children.

  // A house contains rooms.
  // Run over a house with a bulldozer and the rooms are destroyed
  class House { 
    class Room {std::string name; public:Room(std::string n) : name(n){}};
    std::list<Room*> rooms; 
  public:
    void AddRoom(std::string name) {rooms.push_back(new Room(name));}
    ~House() { for(auto& e : rooms) delete e; } 
  }; 

  House myHouse;
  myHouse.AddRoom("kitchen");
  myHouse.AddRoom("dining room");
  myHouse.AddRoom("bedroom 1");
  myHouse.AddRoom("bedroom 2");
  myHouse.AddRoom("bedroom 3");
  myHouse.AddRoom("bathroom");
  myHouse.AddRoom("basement");
}

void Association()
{
  // Association: A relationship between two or more objects where all objects 
  // have their own lifecycle and there is no owwner.

  // Clubs and people are independent.  The club can fold or a person can die 
  // without destroying the other.
  class Person; class Club;
  class Person { std::list<Club> clubs; };     // people can belong to multiple clubs
  class Club   { std::list<Person> members; }; // clubs have more than one member

  class Student; class College;
  class Student {
    std::list<College*> colleges;  // can enroll in more than one college
  public:
    void AddCollege(College* college) { colleges.push_back(college); }
  };
  class College {
    std::list<Student*> students;
  public:
    void AddStudent(Student* student) { students.push_back(student); }
  };

  College Seneca;
  College Centennial;
  College Sheridan;

  Student Tom;
  Student Dick;
  Student Jane;
  Student Mary;
  
  Tom.AddCollege(&Seneca);
  Tom.AddCollege(&Sheridan);

  Seneca.AddStudent(&Tom);
  Sheridan.AddStudent(&Tom);

  Dick.AddCollege(&Seneca);
  Seneca.AddStudent(&Dick);
  
  Jane.AddCollege(&Seneca);
  Seneca.AddStudent(&Jane);
  
  Mary.AddCollege(&Centennial);
  Centennial.AddStudent(&Mary);
  
}

void Aggregation()
{
  // Aggregation: Specialized form of Association where all objects have their 
  // own lifecycle but there is ownership.  
  // This a "whole-part" or "a-part-of" relationship.
  // There is one parent but no lifetime dependency of the child.
  // Child object cannot belong to another parent object.
  // "has-a" relationship

  // A motor can exist without a car.
  // A car can exist without a motor
  // A motor can only be in one car.
  class Motor{ };
  class Car{
    Motor* motor;  // A car "has-a" motor.
  public:
    Car()         : motor(nullptr) {}
    Car(Motor* m) : motor(m)       {}
    void newMotor(Motor* m) { if(motor) delete motor; motor = m; }
    Motor* pullMotor() { Motor* ret = motor; motor = nullptr; return ret; }
    ~Car() { if(motor) delete motor; }
  };

  // A duck can exist without a pond
  // A pond can exist without a duck
  // A duck can only be in one pond.
  class Duck {};
  class Pond {
    std::list<Duck> ducks;
    public:
    void AddDuck(Duck duck) { ducks.push_back(duck); }
  };

  Pond golden;
  Pond oxbow;

  Duck donald;
  Duck ronald;
  Duck daffy;
  Duck black;
  Duck bad;
  Duck good;
  Duck evil;
  Duck neutral;

  golden.AddDuck(donald);
  golden.AddDuck(ronald);
  golden.AddDuck(daffy);
  golden.AddDuck(black);
  golden.AddDuck(good);
  golden.AddDuck(neutral);

  oxbow.AddDuck(bad);
  oxbow.AddDuck(evil);
}

int main(int argc, char*argv[])
{
  if(argc == 1) {
    cerr << "Usage: " << argv[0] << " graphviz-dot-file-list\n";
    return 1;
  }

  vector<string> dotLocations {
    "/usr/bin/dot",                                       // default UNIX
    "/usr/local/bin/dot",                                 // sometimes a UNIX package is installed in /usr/local
    "C:/\"Program Files (x86)\"/Graphviz2.38/bin/dot.exe" // a known DOS location for graphviz 2.38 (current package as of Nov 25, 2017)
  };

  string dot;
  for(auto& e: dotLocations) {
    auto fileexist = [] (string file) {fstream f(file, ios::in); return f.is_open();};
    if( fileexist(e) ) {
      dot = move(e);
      break;
    }
}

*/
